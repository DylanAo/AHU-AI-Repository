#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;
const int ROW = 4, COL = 4;// 定义迷宫大小
int visited[ROW][COL] = { 0 };//访问二维数组存储，默认为未访问
int mp[ROW][COL] = {
    { 0, 1, 1, 1 },
    { 0, 0, 0, 0 },
    { 0, 1, 0, 1 },
    { 0, 1, 0, 0 },
};//初始迷宫
struct Node
{
    int x, y;//x是竖坐标，y是横坐标
};

int maze[ROW][COL] =
{
    { 0, 1, 1, 1 },
    { 0, 0, 0, 0 },
    { 0, 1, 0, 1 },
    { 0, 1, 0, 0 },
};//初始迷宫

void BFS(Node start, Node end)
{
    queue<Node> q;//队列存储节点
    Node pre[ROW][COL];//前驱节点坐标二维数组

    q.push(start);//起点入队列
    visited[start.x][start.y] = 1; //标记起点为已访问

    Node cur;//当前节点

    Node adj[4] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };//相邻节点数组

    while (!q.empty())
    {
        cur = q.front();
        q.pop();//取出队头节点
        //cout << "此时队列头节点为(" << cur.x << ", " << cur.y << ")" << endl;//可以删了
        if (cur.x == end.x && cur.y == end.y)//判断是否到达终点
        {
            cout << "到达终点" << endl;

            // 输出路径
            stack<Node> s;
            Node p = cur;
            while (!(p.x == start.x && p.y == start.y))
            {
                s.push(p);
                p = pre[p.x][p.y];
            }
            s.push(start);

            cout << "路径为：" << endl;
            while (!s.empty())
            {
                p = s.top();
                s.pop();
                cout << "(" << p.x << ", " << p.y << ")" << endl;
            }
            return;
        }

        for (int i = 0; i < 4; i++)//遍历本节点的相邻节点
        {
            int nx = cur.x + adj[i].x, ny = cur.y + adj[i].y;//nx，ny为临近节点坐标

            if (nx < 0 || nx >= ROW || ny < 0 || ny >= COL || visited[nx][ny] == 1 || mp[nx][ny] == 1)//判断相邻节点
                continue;//若已越界或已访问或不可行，则继续访问下一个临近节点

            struct Node temp;//若未越界且未访问且可行，则本节点入队且标记已访问
            temp.x = nx;
            temp.y = ny;
            q.push(temp);
            //cout << "此时将(" << temp.x << ", " << temp.y << ")入队" << endl;//可以删了
            visited[nx][ny] = 1;
            pre[nx][ny] = cur; //记录前驱节点
        }
        //printf("\n");//可以删了
    }
    cout << "搜索失败" << endl;//队列为空，搜索失败
}

int main()
{
    Node start = { 0, 0 };
    Node end = { 3, 3 };//初始化起点与终点

    BFS(start, end);//开始搜索

    return 0;
}