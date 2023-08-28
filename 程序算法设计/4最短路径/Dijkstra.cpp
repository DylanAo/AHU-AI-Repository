#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

const int MAX_NODES = 11;  // 最大节点数

struct Edge {
    int v;
    int weight;
};

struct Node {
    int distance;
    bool visited;
};

Edge e[MAX_NODES][MAX_NODES];  // 邻接矩阵
Node nodes[MAX_NODES];  // 节点数组

void addEdge(int u, int v, int weight) {
    e[u][v] = {v, weight};
}

int findMinDistance(int n) {
    int minDist = numeric_limits<int>::max();
    int minNode = -1;

    for (int i = 0; i < n; i++) {
        if (!nodes[i].visited && nodes[i].distance < minDist) {
            minDist = nodes[i].distance;
            minNode = i;
        }
    }

    return minNode;
}

void dijkstra(int n, int s) {
    for (int i = 0; i < n; i++) {
        nodes[i].distance = numeric_limits<int>::max();
        nodes[i].visited = false;
    }
    nodes[s].distance = 0;

    for (int i = 0; i < n; i++) {
        int u = findMinDistance(n);
        nodes[u].visited = true;

        for (int v = 0; v < n; v++) {
            if (e[u][v].v != -1) {
                int weight = e[u][v].weight;
                if (!nodes[v].visited && nodes[u].distance + weight < nodes[v].distance) {
                    nodes[v].distance = nodes[u].distance + weight;
                }
            }
        }
    }
}

int main() {
    int n = 11;  // 节点数

    // 初始化邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            e[i][j] = {-1, 0};
        }
    }

    // 添加边
    addEdge(0, 1, 2);
    addEdge(0, 2, 5);
    addEdge(1, 3, 1);
    addEdge(1, 4, 3);
    addEdge(2, 5, 8);
    addEdge(3, 6, 4);
    addEdge(4, 6, 2);
    addEdge(4, 7, 3);
    addEdge(5, 7, 1);
    addEdge(6, 8, 3);
    addEdge(7, 9, 2);
    addEdge(8, 10, 2);
    addEdge(9, 10, 4);

    string source;
    cout << "Enter the source node: ";
    cin >> source;

    int sourceIndex = source[0] - 'A';  // 将源节点标识符转换为索引

    dijkstra(n, sourceIndex);

    // 打印最短路径结果
    for (int i = 0; i < n; i++) {
        char nodeName = 'A' + i;  // 将索引转换为节点标识符
        cout << "Node " << nodeName << ": ";
        if (nodes[i].distance == numeric_limits<int>::max())
            cout << "Unreachable";
        else
            cout << nodes[i].distance;
        cout << endl;
    }

    system("pause");
    return 0;
}