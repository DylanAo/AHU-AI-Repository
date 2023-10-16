//算法6.8　普里姆算法
#include <iostream>
using namespace std;

typedef char VerTexType;
typedef int ArcType;
#define MVNum 100
#define MaxInt 32767                    	//表示极大值，即∞

//辅助数组的定义，用来记录从顶点集U到V-U的权值最小的边
struct{
	VerTexType adjvex;						//最小边在U中的那个顶点
	ArcType lowcost;						//最小边上的权值
}closedge[MVNum];

//- - - - -图的邻接表存储表示- - - - - 						
typedef char VerTexType;              		//假设顶点的数据类型为字符型 
typedef int ArcType;                  		//假设边的权值类型为整型 
typedef struct{ 
	VerTexType vexs[MVNum];            		//顶点表 
	ArcType arcs[MVNum][MVNum];      		//邻接矩阵 
	int vexnum,arcnum;                		//图的当前点数和边数 
}AMGraph;

int LocateVex(AMGraph G , VerTexType v){
	//确定点v在G中的位置
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vexs[i] == v)
			return i;
		return -1;
}//LocateVex

void CreateUDN(AMGraph &G){ 
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
			G.arcs[i][j] = MaxInt;
	cout << "输入边依附的顶点及权值，如a b 5" << endl;
	for(k = 0; k < G.arcnum;++k){							//构造邻接矩阵 
		VerTexType v1 , v2;
		ArcType w;
		cout << "请输入第" << (k + 1) << "条边依附的顶点及权值:";
		cin >> v1 >> v2 >> w;								//输入一条边依附的顶点及权值
		i = LocateVex(G, v1);  j = LocateVex(G, v2);		//确定v1和v2在G中的位置，即顶点数组的下标 
		G.arcs[i][j] = w;									//边<v1, v2>的权值置为w 
		G.arcs[j][i] = G.arcs[i][j];						//置<v1, v2>的对称边<v2, v1>的权值为w 
	}//for
}//CreateUDN 

int Min(AMGraph G){
	//返回权值最小的点
	int i;
	int index = -1;
	int min = MaxInt;
	for(i = 0 ; i < G.vexnum ; ++i){
		if(min > closedge[i].lowcost && closedge[i].lowcost != 0){
			min = closedge[i].lowcost;
			index = i;
		}
	}//for
	return index;
}//Min

void MiniSpanTree_Prim(AMGraph G, VerTexType u){ 
    //无向网G以邻接矩阵形式存储，从顶点u出发构造G的最小生成树T，输出T的各条边  
	int k , j , i;
	VerTexType u0 , v0;
    k =LocateVex(G, u);           										//k为顶点u的下标 
    for(j = 0; j < G.vexnum; ++j){     									//对V-U的每一个顶点vi，初始化closedge[i] 
		if(j != k){  
			closedge[j].adjvex = u;
			closedge[j].lowcost = G.arcs[k][j];							//{adjvex, lowcost}
		}//if
	}//for
	closedge[k].lowcost = 0;        									//初始，U = {u}
	for(i = 1; i < G.vexnum; ++i){     									//选择其余n-1个顶点，生成n-1条边(n= G.vexnum) 
		k = Min(G);  
		//求出T的下一个结点：第k个顶点，closedge[k]中存有当前最小边 
		u0 = closedge[k].adjvex;     									//u0为最小边的一个顶点，u0∈U 
		v0 = G.vexs[k];            										//v0为最小边的另一个顶点，v0∈V-U 
		cout << "边  " <<u0 << "--->" << v0 << endl;           			//输出当前的最小边(u0, v0) 
		closedge[k].lowcost = 0;   		//第k个顶点并入U集 
		for(j = 0; j < G.vexnum; ++j) 
			if(G.arcs[k][j] < closedge[j].lowcost){						//新顶点并入U后重新选择最小边 
				closedge[j].adjvex = G.vexs[k];
				closedge[j].lowcost = G.arcs[k][j];
			}//if 
	}//for 
}//MiniSpanTree_Prim 

int main(){
	cout << "************算法6.8　普里姆算法**************" << endl << endl;
	AMGraph G;
	CreateUDN(G);
	cout << endl;
	cout << "无向图G创建完成！" << endl;
	cout <<endl;

	cout << "******利用普里姆算法构造最小生成树结果：******" << endl;
	MiniSpanTree_Prim(G , 'a');
	cout <<endl;
	return 0;
}//main