# 最短路径问题
## 底层实现
### 节点与图的结构
```cpp
struct site_information {
	int departure;
	int destination;
	int weight;
};

class Graph {
private:
	site_information site[SIDE_NUM];
	int map[POINT_NUM][POINT_NUM];
	int path[POINT_NUM][POINT_NUM];
	bool dijstra(int point_index);

public:
	Graph(int departure[], int destination[], int weight[]);
	void print(int departure, int destination);
	void print();
};
```
一个有向图的边包含三个数据，即起点、终点、权重<br>
图的功能就是用迪杰斯特拉算法来计算最短路径<br>
图中存储以下部分:
1. 边的权重信息
2. 图的邻接矩阵
3. 每个节点的最短路径
### 图功能的实现
#### 图中数据的构建(构造函数)
```cpp
Graph::Graph(int departure[], int destination[], int weight[]) {
	// 储存节点和边的信息
	for (int i = 0; i < SIDE_NUM; i++) {
		site[i].departure = departure[i];
		site[i].destination = destination[i];
		site[i].weight = weight[i];
	}

	//构建邻接矩阵
	for (int i = 0; i < POINT_NUM; i++) {
		for (int j = 0; j < POINT_NUM; j++) {
			map[i][j] = INFINITE;
		}
	}
	for (int i = 0; i < SIDE_NUM; i++) {
		for (int j = 0; j < SIDE_NUM; j++) {
			for (int site_index = 0; site_index < SIDE_NUM; site_index++) {
				if (site[site_index].departure == i && site[site_index].destination == j) {
					map[i][j] = site[site_index].weight;
					map[j][i] = site[site_index].weight;
					site_index++;
				}
			}
		}
	}

	//迪杰斯特拉求每个节点的最短路径
	for (int i = 0; i < POINT_NUM; i++) {
		for (int j = 0; j < POINT_NUM; j++) {
			path[i][j] = INFINITE;
		}
	}
	for (int point_index = 0; point_index < POINT_NUM; point_index++) {
		dijstra(point_index);
	}
}
```
从上述代码中可以看到，就是在用遍历进行边信息构建和临界矩阵的构建，最后通过迪杰斯特拉算法求得最短路径
#### 迪杰斯特拉算法
```cpp
bool Graph::dijstra(int point_index) {
	bool now_point_set[POINT_NUM];
	int now_point_weight[POINT_NUM];
	for (int index = 0; index < POINT_NUM; index++) {
		now_point_set[index] = false;
		now_point_weight[index] = map[point_index][index];
		if (now_point_weight[index] < INFINITE) {
			path[point_index][index] = point_index;
		}
		else{
			path[point_index][index] = NO_PRODROMAL;
		}
	}
	now_point_set[point_index] = true;
	now_point_weight[point_index] = 0;

	for (int i = 0; i < POINT_NUM; i++) {
		int now_min_weight = INFINITE;
		int now_min_point = point_index;
		for (int w = 0; w < POINT_NUM; w++) {
			if (!now_point_set[w] && now_point_weight[w] < now_min_weight) {
				now_min_point = w;
				now_min_weight = now_point_weight[w];
			}
		}
		now_point_set[now_min_point] = true;
		for (int w = 0; w < POINT_NUM; w++) {
			if (!now_point_set[w] && now_point_set[now_min_point] + map[now_min_point][w]) {
				now_point_weight[w] = now_point_set[now_min_point] + map[now_min_point][w];
				path[point_index][w] = now_min_point;
			}
		}
	}
}
```
迪杰斯特拉算法本质上还是基于贪心算法实现的，就是在找当前权重最小的边，且不会成环
#### 输出
```cpp
void Graph::print(int departure, int destination) {
	if (path[departure][destination] == -1) {
		cout << "在" << point_names[departure] << " 和 " << point_names[destination] << " 之间没有路,或者你已经在这了!";
	}
	else {
		int now_point = departure;
		cout << point_names[departure] << " - >";
		while (path[destination][now_point] != -1) {
			if (path[destination][now_point] == destination) {
				cout << point_names[path[destination][now_point]];
				break;
			}
			else {
				cout << point_names[path[destination][now_point]] << " - >";
				now_point = path[destination][now_point];
			}
		}
	}
	cout << endl;
}

void Graph::print() {
	for (int i = 0; i < POINT_NUM; i++) {
		cout << endl << "****" << "您所在的位置为: " << point_names[i] << "****" << endl;
		for (int j = 0; j < POINT_NUM; j++) {
			print(i, j);
		}
	}
}
```
print方法在这里重载了一下，通过无参的print方法可调用有参的print方法，在有参print方法中调换起点与终点，即完成了输出<br>
>在迪杰斯特拉算法中，我们计算出路径其实是反这的，所以把终点给起点，起点给终点即可完成正向的输出
## 调用我所提供的接口
1. 提供基本信息
   ```cpp
   int departure[SIDE_NUM] = {0, 1, 1, 2, 3, 4, 5, 6, 5, 5, 5, 9, 7, 10, 8, 10};
   int destination[SIDE_NUM] = {1, 2, 3, 3, 4, 5, 6, 7, 7, 8, 9, 8, 10, 8, 10, 11};
   int weight[SIDE_NUM] = {6, 6, 1, 2, 12, 2, 2, 1, 2, 2, 9, 9, 1, 2, 2, 5};
   ```
   这里面提供的起点、终点、与权重的信息都是以数字形式进行对应的，想要正确对应与节点与数字之间的关系，需要在graph.cpp中添加节点的信息，在本示例里面，如图所示
   ```cpp
   string point_names[POINT_NUM] = { "玉屏索道入口", "玉屏索道出口", "天都峰", "迎客松", "排云溪站", "排云亭", "光明顶", "白鹤铃", "始信峰", "松谷庵站", "云谷索道入口", "云谷索道出口" };
   ```
   下标与地点名称一一对应
   >注意:下标从0开始

   我们再回头看最开始提供信息那里，我们提供的第0条边信息是这样的
   ```cpp
   departure[0] = 0
   destination[1] = 1
   weight[0] = 6
   point_names[0] = "玉屏索道入口"
   point_names[1] = "玉屏索道出口"
   ```
   起点:玉屏索道入口<br>
   终点:玉屏索道出口<br>
   权重:6<br>
   具体方法如下:
   * 第n条边，那么对应的departure、destination、weight的下标均是n
   * 根据departure、destination对应的值在point_names找到相应的名字
2. 构建图
   ```cpp
   Graph huangshan(departure, destination, weight);
   ```
   你只需要将上述东西全部塞入图中(调用构造函数，即可一步完成构建)
3. 输出
   ```cpp
   huangshan.print();
   ```
   通过print()方法，直接可输出全部的路径信息
   ```cpp
   void print(int departure, int destination);
   ```
   同时，根据我们的有参print方法的声明，你也可以给定起点和终点数值，输出这两个点之间的路径
## 效果截图
![Alt text](End.png)
