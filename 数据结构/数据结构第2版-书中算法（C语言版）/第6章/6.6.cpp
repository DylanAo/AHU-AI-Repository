//算法6.6　采用邻接表表示图的深度优先搜索遍历

#include <iostream>
using namespace std;

#define MVNum 100							//最大顶点数
typedef char VerTexType;					//假设顶点的数据类型为字符型 

//-------------图的邻接表---------------------
typedef struct ArcNode{                		//边结点 
    int adjvex;                          	//该边所指向的顶点的位置 
    struct ArcNode *nextarc;          		//指向下一条边的指针 
}ArcNode; 

typedef struct VNode{ 
    VerTexType data;                    	//顶点信息
    ArcNode *firstarc;                		//指向第一条依附该顶点的边的指针 
}VNode, AdjList[MVNum];               		//AdjList表示邻接表类型 

typedef struct{
    AdjList vertices;                 		//邻接表 
    int vexnum, arcnum;              		//图的当前顶点数和边数 
}ALGraph;

bool visited[MVNum];           				//访问标志数组，其初值为"false" 

int LocateVex(ALGraph G , VerTexType v){
	//确定点v在G中的位置
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vertices[i].data == v)
			return i;
		return -1;
}//LocateVex

void CreateUDG(ALGraph &G){ 
	//采用邻接表表示法，创建无向图G
	int i , k;
	
	cout <<"请输入总顶点数，总边数，以空格隔开:";
	cin >> G.vexnum >> G.arcnum;				//输入总顶点数，总边数 
    cout << endl;
	
	cout << "输入点的名称，如a" << endl;

	for(i = 0; i < G.vexnum; ++i){          	//输入各点，构造表头结点表
		cout << "请输入第" << (i+1) << "个点的名称:";
		cin >> G.vertices[i].data;           	//输入顶点值 
		G.vertices[i].firstarc=NULL;			//初始化表头结点的指针域为NULL 
    }//for
	cout << endl;
    
	cout << "输入边依附的顶点，如a b" << endl;

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
}//CreateUDG

void DFS(ALGraph G, int v){        				//图G为邻接表类型 
	cout << G.vertices[v].data << "   ";  
	visited[v] = true;    						//访问第v个顶点，并置访问标志数组相应分量值为true 
	ArcNode *p = G.vertices[v].firstarc;		//p指向v的边链表的第一个边结点 
	while(p != NULL){              				//边结点非空 
		int w = p->adjvex;               		//表示w是v的邻接点 
		if(!visited[w])  DFS(G, w);   			//如果w未访问，则递归调用DFS 
		p = p->nextarc;                			//p指向下一个边结点 
	} 
}//DFS

int main(){
	cout << "************算法6.6　采用邻接表表示图的深度优先搜索遍历**************" << endl << endl;
	ALGraph G;
	CreateUDG(G);
	cout << endl;
	cout << "无向连通图G创建完成！" << endl << endl;

	cout << "请输入遍历连通图的起始点：";
	VerTexType c;
	cin >> c;
	
	int i;
	for(i = 0 ; i < G.vexnum ; ++i){
		if(c == G.vertices[i].data)
			break;
	}
	cout << endl;
	while(i >= G.vexnum){
		cout << "该点不存在，请重新输入！" << endl;
		cout << "请输入遍历连通图的起始点：";
		cin >> c;
		for(i = 0 ; i < G.vexnum ; ++i){
			if(c == G.vertices[i].data)
				break;
		}
	}

	cout << "深度优先搜索遍历图结果：" << endl;
	DFS(G , i);
	
	cout <<endl;
	return 0;
}//main