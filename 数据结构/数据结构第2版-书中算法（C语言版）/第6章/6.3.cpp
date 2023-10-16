//算法6.3　深度优先搜索遍历连通图的递归算法

#include <iostream>
using namespace std;

#define MVNum 100									//最大顶点数
typedef char VerTexType;							//假设顶点的数据类型为字符型 
typedef int ArcType;                 				//假设边的权值类型为整型 

typedef struct{ 
	VerTexType vexs[MVNum];            				//顶点表 
	ArcType arcs[MVNum][MVNum];      				//邻接矩阵 
	int vexnum,arcnum;                				//图的当前点数和边数 
}Graph;
 
bool visited[MVNum];           					//访问标志数组，其初值为"false" 
int FirstAdjVex(Graph G , int v);				//返回v的第一个邻接点
int NextAdjVex(Graph G , int v , int w);		//返回v相对于w的下一个邻接点

int LocateVex(Graph G , VerTexType v){
	//确定点v在G中的位置
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vexs[i] == v)
			return i;
		return -1;
}//LocateVex

void CreateUDN(Graph &G){ 
    //采用邻接矩阵表示法，创建无向网G 
	int i , j , k;
	cout <<"请输入总顶点数，总边数 , 以空格隔开:";
    cin >> G.vexnum >> G.arcnum;						 //输入总顶点数，总边数
	cout << endl;

	cout << "输入点的名称，如 a：" << endl;

    for(i = 0; i < G.vexnum; ++i){   
		cout << "请输入第" << (i+1) << "个点的名称:";
		cin >> G.vexs[i];                        		 //依次输入点的信息 
	}
	cout << endl;

    for(i = 0; i < G.vexnum; ++i)                		 //初始化邻接矩阵，边的权值均置为极大值MaxInt 
		for(j = 0; j < G.vexnum; ++j)   
			G.arcs[i][j] = 0;  
	cout << "输入边依附的顶点，如：a b" << endl;
	for(k = 0; k < G.arcnum;++k){						 //构造邻接矩阵 
		VerTexType v1 , v2;
		cout << "请输入第" << (k + 1) << "条边依附的顶点:";
		cin >> v1 >> v2;								 //输入一条边依附的顶点及权值
		i = LocateVex(G, v1);  j = LocateVex(G, v2);	 //确定v1和v2在G中的位置，即顶点数组的下标 
		G.arcs[j][i] = G.arcs[i][j] = 1;                 //置<v1, v2>的对称边<v2, v1>的权值为w 
	}//for
}//CreateUDN 

void DFS(Graph G, int v){        			//从第v个顶点出发递归地深度优先遍历图G 
	cout << G.vexs[v] << "    ";  visited[v] = true;   	//访问第v个顶点，并置访问标志数组相应分量值为true 
	int w;
	for(w = FirstAdjVex(G, v);  w >= 0;  w = NextAdjVex(G, v, w))  
		//依次检查v的所有邻接点w ，FirstAdjVex(G, v)表示v的第一个邻接点 
		//NextAdjVex(G, v, w)表示v相对于w的下一个邻接点，w≥0表示存在邻接点 
		if(!visited[w]) DFS(G, w);    					//对v的尚未访问的邻接顶点w递归调用DFS 
}//DFS

int FirstAdjVex(Graph G , int v){
	int i;
	for(i = 0 ; i < G.vexnum ; ++i){
		if(G.arcs[v][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}//FirstAdjVex

int NextAdjVex(Graph G , int v , int w){
	int i;
	for(i = w ; i < G.vexnum ; ++i){
		if(G.arcs[v][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}//NextAdjVex

int main(){
	cout << "************算法6.3　深度优先搜索遍历连通图的递归算法**************" << endl << endl;
	Graph G;
	CreateUDN(G);
	cout << endl;
	cout << "无向连通图G创建完成！" << endl << endl;
	
	cout << "请输入遍历连通图的起始点：";
	VerTexType c;
	cin >> c;

	int i;
	for(i = 0 ; i < G.vexnum ; ++i){
		if(c == G.vexs[i])
			break;
	}
	cout << endl;
	while(i >= G.vexnum){
		cout << "该点不存在，请重新输入！" << endl;
		cout << "请输入遍历连通图的起始点：";
		cin >> c;
		for(i = 0 ; i < G.vexnum ; ++i){
			if(c == G.vexs[i])
				break;
		}
	}
	cout << "深度优先搜索遍历连通图结果：" << endl;
	DFS(G , i);

	cout <<endl;
	return 0;
}//main