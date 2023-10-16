//算法6.7　广度优先搜索遍历连通图

#include <iostream>
using namespace std;

#define MVNum 100                       	//最大顶点数
#define MAXQSIZE 100						//最大队列长度
						
typedef char VerTexType;              		//假设顶点的数据类型为字符型
typedef int ArcType;                  		//假设边的权值类型为整型
bool visited[MVNum];           				//访问标志数组，其初值为"false" 

//-----图的邻接矩阵存储表示----- 
typedef struct{ 
	VerTexType vexs[MVNum];            		//顶点表
	ArcType arcs[MVNum][MVNum];      		//邻接矩阵
	int vexnum,arcnum;                		//图的当前点数和边数
}Graph;

//----队列的定义及操作--------
typedef struct{
	ArcType *base;							//初始化的动态分配存储空间
	int front;								//头指针，若队列不空，指向队头元素
	int rear;								//尾指针，若队列不空，指向队尾元素的下一个位置
}sqQueue;

void InitQueue(sqQueue &Q){
	//构造一个空队列Q
	Q.base = new ArcType[MAXQSIZE];
	if(!Q.base)     exit(1);				//存储分配失败
	Q.front = Q.rear = 0;
}//InitQueue

void EnQueue(sqQueue &Q, ArcType e){
	//插入元素e为Q的新的队尾元素
	if((Q.rear + 1) % MAXQSIZE == Q.front)
		return;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
}//EnQueue

bool QueueEmpty(sqQueue Q){
	//判断是否为空队
	if(Q.rear == Q.front)
		return true;
	return false;
}//QueueEmpty

void DeQueue(sqQueue &Q, ArcType &u){
	//队头元素出队并置为u 
	u = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
}//DeQueue   								
//--------------------------------------------------

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
	cout <<"请输入总顶点数，总边数，以空格隔开:";
    cin >> G.vexnum >> G.arcnum;							//输入总顶点数，总边数
	cout << endl;
	cout << "输入点的名称，如a" << endl;
    for(i = 0; i < G.vexnum; ++i){   
		cout << "请输入第" << (i+1) << "个点的名称:";
		cin >> G.vexs[i];                        			//依次输入点的信息 
	}
	cout << endl;
    for(i = 0; i < G.vexnum; ++i)                			//初始化邻接矩阵，边的权值均置为极大值MaxInt 
		for(j = 0; j < G.vexnum; ++j)   
			G.arcs[i][j] = 0; 
	cout << "输入边依附的顶点，如a b" << endl;
	for(k = 0; k < G.arcnum;++k){							//构造邻接矩阵 
		VerTexType v1 , v2;
		cout << "请输入第" << (k + 1) << "条边依附的顶点:";
		cin >> v1 >> v2;									//输入一条边依附的顶点
		i = LocateVex(G, v1);  j = LocateVex(G, v2);		//确定v1和v2在G中的位置，即顶点数组的下标 
		G.arcs[i][j] = 1;									//边<v1, v2>的权值置为w 
		G.arcs[j][i] = G.arcs[i][j];						//置<v1, v2>的对称边<v2, v1>的权值为w 
	}//for 
}//CreateUDN

int FirstAdjVex(Graph G , int v){
	//返回v的第一个邻接点
	int i;
	for(i = 0 ; i < G.vexnum ; ++i){
		if(G.arcs[v][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}//FirstAdjVex

int NextAdjVex(Graph G , int u , int w){
	//返回v相对于w的下一个邻接点
	int i;
	for(i = w ; i < G.vexnum ; ++i){
		if(G.arcs[u][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}//NextAdjVex

void BFS (Graph G, int v){ 
    //按广度优先非递归遍历连通图G 
	sqQueue Q;
	ArcType u;
	ArcType w;

    cout << G.vexs[v] << "  ";    visited[v] = true;     						//访问第v个顶点，并置访问标志数组相应分量值为true 
    InitQueue(Q);              													//辅助队列Q初始化，置空         
    EnQueue(Q, v);            													//v进队 
    while(!QueueEmpty(Q)){   													//队列非空 
		DeQueue(Q, u);       													//队头元素出队并置为u
		for(w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)){
			//依次检查u的所有邻接点w ，FirstAdjVex(G, u)表示u的第一个邻接点 
			//NextAdjVex(G, u, w)表示u相对于w的下一个邻接点，w≥0表示存在邻接点 
			if(!visited[w]){	           										//w为u的尚未访问的邻接顶点 
				cout << G.vexs[w] << "  ";   visited[w] = true;					//访问w，并置访问标志数组相应分量值为true 
				EnQueue(Q, w);													//w进队 
			}//if 
		}//for
    }//while 
}//BFS 

int main(){
	cout << "************算法6.7　广度优先搜索遍历连通图**************" << endl << endl;
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
	BFS(G , i);
	
	cout <<endl;
	return 0;
}//main