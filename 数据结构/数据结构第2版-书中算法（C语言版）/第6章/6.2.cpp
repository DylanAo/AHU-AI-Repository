//算法6.2　采用邻接表表示法创建无向图

#include <iostream>
using namespace std;

#define MVNum 100                        	//最大顶点数 
#define OK 1

typedef char VerTexType;					//顶点信息
typedef int OtherInfo;						//和边相关的信息 

//- - - - -图的邻接表存储表示- - - - - 
typedef struct ArcNode{                		//边结点 
    int adjvex;                          	//该边所指向的顶点的位置 
    struct ArcNode *nextarc;          		//指向下一条边的指针 
    OtherInfo info;                      	//和边相关的信息 
}ArcNode; 

typedef struct VNode{ 
    VerTexType data;                    	//顶点信息 
    ArcNode *firstarc;                		//指向第一条依附该顶点的边的指针 
}VNode, AdjList[MVNum];               		//AdjList表示邻接表类型 

typedef struct{ 
    AdjList vertices;                 		//邻接表 
    int vexnum, arcnum;              		//图的当前顶点数和边数 
}ALGraph;


int LocateVex(ALGraph G , VerTexType v){
	//确定点v在G中的位置
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vertices[i].data == v)
			return i;
   return -1;
}//LocateVex

int CreateUDG(ALGraph &G){ 
	//采用邻接表表示法，创建无向图G
	int i , k;

	cout <<"请输入总顶点数，总边数中间以空格隔开:";
	cin >> G.vexnum >> G.arcnum;				//输入总顶点数，总边数 
    cout << endl;
	
	cout << "输入点的名称，如 a " <<endl;
	for(i = 0; i < G.vexnum; ++i){          	//输入各点，构造表头结点表
		cout << "请输入第" << (i+1) << "个点的名称:";
		cin >> G.vertices[i].data;           	//输入顶点值 
		G.vertices[i].firstarc=NULL;			//初始化表头结点的指针域为NULL 
    }//for
	cout << endl;
    
	cout << "请输入一条边依附的顶点,如 a b" << endl;
	for(k = 0; k < G.arcnum;++k){        		//输入各边，构造邻接表
		VerTexType v1 , v2;
		int i , j;
		cout << "请输入第" << (k + 1) << "条边依附的顶点:";
		cin >> v1 >> v2;                 		//输入一条边依附的两个顶点
		i = LocateVex(G, v1);  j = LocateVex(G, v2);
		//确定v1和v2在G中位置，即顶点在G.vertices中的序号 

		ArcNode *p1=new ArcNode;               	//生成一个新的边结点*p1 
		p1->adjvex=j;                   		//邻接点序号为j 
		p1->nextarc= G.vertices[i].firstarc;  G.vertices[i].firstarc=p1;  
		//将新结点*p1插入顶点vi的边表头部

		ArcNode *p2=new ArcNode;                //生成另一个对称的新的边结点*p2 
		p2->adjvex=i;                   		//邻接点序号为i 
		p2->nextarc= G.vertices[j].firstarc;  G.vertices[j].firstarc=p2;  
		//将新结点*p2插入顶点vj的边表头部 
    }//for 
    return OK; 
}//CreateUDG

int main(){
	cout << "************算法6.2　采用邻接表表示法创建无向图**************" << endl << endl;
	ALGraph G;
	CreateUDG(G);
	int i;

	cout << endl;
	cout << "*****邻接表表示法创建的无向图*****" << endl;
	
	for(i = 0 ; i < G.vexnum ; ++i){
		VNode temp = G.vertices[i];
		ArcNode *p = temp.firstarc;
		if(p == NULL){
			cout << G.vertices[i].data;
			cout << endl;
		}
		else{
			cout << temp.data;
			while(p){
				cout << "->";
				cout << p->adjvex;
				p = p->nextarc;
			}
		}
		cout << endl;
	}
	return 0;
}//main
