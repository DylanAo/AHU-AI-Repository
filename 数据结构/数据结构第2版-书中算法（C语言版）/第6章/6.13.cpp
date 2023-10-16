//算法6.13　关键路径算法

#include <iostream>
using namespace std;

#define MVNum 100                       	//最大顶点数
#define BDNum MVNum * (MVNum - 1)			//最大边数
#define OK 1	
#define ERROR 0 

typedef char VerTexType;

//- - - - -图的邻接表存储表示- - - - - 
typedef struct ArcNode{                		//边结点 
    int adjvex;                          	//该边所指向的顶点的位置
	int weight;								//权值
    struct ArcNode *nextarc;          		//指向下一条边的指针 
}ArcNode; 

typedef struct VNode{ 
    VerTexType data;                    	//顶点信息
    ArcNode *firstarc;                		//指向第一条依附该顶点的边的指针 
}VNode, AdjList[MVNum];               		//AdjList表示邻接表类型 

typedef struct{ 
    AdjList vertices;                 		//邻接表 
	AdjList converse_vertices;				//逆邻接表
    int vexnum, arcnum;              		//图的当前顶点数和边数 
}ALGraph;
//- - - - - - - - - - - - - - - -

//- - - - -顺序栈的定义- - - - -
typedef struct{
	int *base;
	int *top;
	int stacksize;
}spStack;
//- - - - - - - - - - - - - - - -

int indegree[MVNum];						//数组indegree存放个顶点的入度
int ve[BDNum];								//事件vi的最早发生时间
int vl[BDNum];								//事件vi的最迟发生时间
int topo[MVNum];							//记录拓扑序列的顶点序号
spStack S;

//----------------栈的操作--------------------
void InitStack(spStack &S){
	//栈的初始化
	S.base = new int[MVNum];
	if(!S.base)
		exit(1);
	S.top = S.base;
	S.stacksize = MVNum;
}//InitStack

void Push(spStack &S , int i){
	//入栈
	if(S.top - S.base == S.stacksize)
		return;
	*S.top++ = i;
}//Push

void Pop(spStack &S , int &i){
	//出栈
	if(S.top == S.base)
		return;
	i = *--S.top;
}//Pop

bool StackEmpty(spStack S){
	//判断栈是否为空
	if(S.top == S.base)
		return true;
	return false;
}//StackEmpty
//---------------------------------------

int LocateVex(ALGraph G , VerTexType v){
	//确定点v在G中的位置
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vertices[i].data == v)
			return i;
		return -1;
}//LocateVex

int CreateUDG(ALGraph &G){ 
	//创建有向图G的邻接表、逆邻接表
	int i , k;
	
	cout <<"请输入总顶点数，总边数，以空格隔开:";
	cin >> G.vexnum >> G.arcnum;				//输入总顶点数，总边数 
    cout << endl;

	cout << "输入点的名称，如a" << endl;
	
	for(i = 0; i < G.vexnum; ++i){          		//输入各点，构造表头结点表
		cout << "请输入第" << (i+1) << "个点的名称:";
		cin >> G.vertices[i].data;           		//输入顶点值
		G.converse_vertices[i].data = G.vertices[i].data;
		//初始化表头结点的指针域为NULL 
		G.vertices[i].firstarc=NULL;			
		G.converse_vertices[i].firstarc=NULL;
    }//for
	cout << endl;

	cout << "输入边依附的顶点及其权值，如a b 3" << endl;

	for(k = 0; k < G.arcnum;++k){        			//输入各边，构造邻接表
		VerTexType v1 , v2;
		int i , j , w;
		cout << "请输入第" << (k + 1) << "条边依附的顶点及其权值:";
		cin >> v1 >> v2 >> w;                		//输入一条边依附的两个顶点
		i = LocateVex(G, v1);  j = LocateVex(G, v2);
		//确定v1和v2在G中位置，即顶点在G.vertices中的序号 

		ArcNode *p1=new ArcNode;               		//生成一个新的边结点*p1 
		p1->adjvex=j;                   			//邻接点序号为j
		p1->nextarc = G.vertices[i].firstarc;  G.vertices[i].firstarc=p1;
		p1->weight = w;
		//将新结点*p1插入顶点vi的边表头部

		ArcNode *p2=new ArcNode;               		//生成一个新的边结点*p1 
		p2->adjvex=i;                   			//逆邻接点序号为i
		p2->nextarc = G.converse_vertices[j].firstarc;  G.converse_vertices[j].firstarc=p2;
		p2->weight = w;
		//将新结点*p1插入顶点vi的边表头部
    }//for 
    return OK; 
}//CreateUDG

void FindInDegree(ALGraph G){
	//求出各顶点的入度存入数组indegree中 
	int i , count;

	for(i = 0 ; i < G.vexnum ; i++){
		count = 0;
		ArcNode *p = G.converse_vertices[i].firstarc;
		if(p){
			while(p){
				p = p->nextarc;
				count++;
			}
		}//if
		indegree[i] = count;
	}//for
}//FindInDegree

int TopologicalOrder(ALGraph G , int topo[]){ 
    //有向图G采用邻接表存储结构 
    //若G无回路，则生成G的一个拓扑序列topo[]并返回OK，否则ERROR 
	int i , m;
    FindInDegree(G);              				//求出各顶点的入度存入数组indegree中 
    InitStack(S);                          		//栈S初始化为空 
    for(i = 0; i < G.vexnum; ++i)
		if(!indegree[i]) Push(S, i);     		//入度为0者进栈 
	m = 0;                               		//对输出顶点计数，初始为0 
	while(!StackEmpty(S)){                		//栈S非空 
		Pop(S, i);                          	//将栈顶顶点vi出栈
		topo[m]=i;                         		//将vi保存在拓扑序列数组topo中 
		++m;                             		//对输出顶点计数 
		ArcNode *p = G.vertices[i].firstarc;    //p指向vi的第一个邻接点 
		while(p){
			int k = p->adjvex;					//vk为vi的邻接点   
			--indegree[k];                   	//vi的每个邻接点的入度减1 
			if(indegree[k] ==0)  Push(S, k);	//若入度减为0，则入栈 
			p = p->nextarc;                		//p指向顶点vi下一个邻接结点 
		}//while 
	}//while
	
	if(m < G.vexnum)  return ERROR;    			//该有向图有回路 
	else return OK;
}//TopologicalOrder

int CriticalPath(ALGraph G){ 
    //G为邻接表存储的有向网，输出G的各项关键活动
	int n , i , k , j , e , l;
    if (!TopologicalOrder(G, topo))  return ERROR; 
    //调用拓扑排序算法，使拓扑序列保存在topo中，若调用失败，则存在有向环，返回ERROR 
    n = G.vexnum;                  				//n为顶点个数 
    for(i = 0; i < n; i++)               		//给每个事件的最早发生时间置初值0 
		ve[i] = 0; 


    /*――――――――――按拓扑次序求每个事件的最早发生时间－――――－―――――*/ 
    for(i = 0;i < n; i++){                 
		k = topo[i];                   			//取得拓扑序列中的顶点序号k             
		ArcNode *p = G.vertices[k].firstarc;    //p指向k的第一个邻接顶点  
		while(p != NULL){            			//依次更新k的所有邻接顶点的最早发生时间   
			j = p->adjvex;               		//j为邻接顶点的序号                   
			if(ve[j] < ve[k] + p->weight)    	//更新顶点j的最早发生时间ve[j] 
				ve[j] = ve[k] + p->weight;     
			p = p->nextarc;              		//p指向k的下一个邻接顶点  
		} //while 
    } //for 

    for(i=0;i<n;i++)                 			//给每个事件的最迟发生时间置初值ve[n-1] 
		vl[i]=ve[n-1];
	
    /*――――――――――按逆拓扑次序求每个事件的最迟发生时间－――――－―――――*/ 
    for(i = n - 1;i >= 0; i--){               
		k = topo[i];                   			//取得拓扑序列中的顶点序号k             
		ArcNode *p = G.vertices[k].firstarc;    //p指向k的第一个邻接顶点  
		while(p != NULL){            			//根据k的邻接点，更新k的最迟发生时间   
			j = p->adjvex;              		//j为邻接顶点的序号                   
			if(vl[k] > vl[j] - p->weight)    	//更新顶点k的最迟发生时间vl[k] 
				vl[k] = vl[j] - p->weight;       
			p = p->nextarc;              		//p指向k的下一个邻接顶点  
		}//while 
    }//for 

    /*――――――――――――判断每一活动是否为关键活动－――――――－―――――*/
	cout << endl;
	cout << "关键活动路径为:";
    for(i = 0;i < n; i++){                		//每次循环针对vi为活动开始点的所有活动 
        ArcNode *p = G.vertices[i].firstarc;    //p指向i的第一个邻接顶点  
        while(p != NULL) {    
			j = p->adjvex;             			//j为i的邻接顶点的序号    
			e = ve[i];                 			//计算活动<vi, vj>的最早开始时间 
			l = vl[j] - p->weight;      		//计算活动<vi, vj>的最迟开始时间 
			if(e == l)               			//若为关键活动，则输出<vi, vj> 
				cout << G.vertices[i].data << "-->" << G.vertices[j].data << " ";
			p = p->nextarc;              		//p指向i的下一个邻接顶点  
		} //while 
	} //for  
	return OK;
}//CriticalPath

int main(){
	cout << "************算法6.13　关键路径算法**************" << endl << endl;
	ALGraph G;
	CreateUDG(G);
	int *topo = new int [G.vexnum];
	
	cout << endl;
	cout << "有向图创建完成!" << endl << endl;
	
	if(!CriticalPath(G))
		cout << "网中存在环，无法进行拓扑排序！" <<endl << endl;
	cout << endl;
	return OK;
}//main

