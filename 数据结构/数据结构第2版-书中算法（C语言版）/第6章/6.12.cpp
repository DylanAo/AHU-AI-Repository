//�㷨6.12����������

#include <iostream>
using namespace std;

#define MVNum 100                       	//��󶥵���
#define OK 1	
#define ERROR 0 

typedef char VerTexType;

//- - - - -ͼ���ڽӱ�洢��ʾ- - - - - 
typedef struct ArcNode{                		//�߽�� 
    int adjvex;                          	//�ñ���ָ��Ķ����λ�� 
    struct ArcNode *nextarc;          		//ָ����һ���ߵ�ָ�� 
}ArcNode; 

typedef struct VNode{ 
    VerTexType data;                    	//������Ϣ 
    ArcNode *firstarc;                		//ָ���һ�������ö���ıߵ�ָ�� 
}VNode, AdjList[MVNum];               		//AdjList��ʾ�ڽӱ����� 

typedef struct{ 
    AdjList vertices;                 		//�ڽӱ� 
	AdjList converse_vertices;				//���ڽӱ�
    int vexnum, arcnum;              		//ͼ�ĵ�ǰ�������ͱ��� 
}ALGraph;
//- - - - - - - - - - - - - - - -

//- - - - -˳��ջ�Ķ���- - - - -
typedef struct{
	int *base;
	int *top;
	int stacksize;
}spStack;
//- - - - - - - - - - - - - - - -

int indegree[MVNum];						//����indegree��Ÿ���������
spStack S;

//------------ջ����ز���----------------------
void InitStack(spStack &S){
	//��ʼ��ջ
	S.base = new int[MVNum];
	if(!S.base)
		exit(1);
	S.top = S.base;
	S.stacksize = MVNum;
}//InitStack

void Push(spStack &S , int i){
	//��ջ
	if(S.top - S.base == S.stacksize)
		return;
	*S.top++ = i;
}//Push

void Pop(spStack &S , int &i){
	//��ջ
	if(S.top == S.base)
		return;
	i = *--S.top;
}//Pop

bool StackEmpty(spStack S){
	//�ж�ջ�Ƿ�Ϊ��
	if(S.top == S.base)
		return true;
	return false;
}//StackEmpty
//-------------------------------------------------

int LocateVex(ALGraph G , VerTexType v){
	//ȷ����v��G�е�λ��
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vertices[i].data == v)
			return i;
		return -1;
}//LocateVex

int CreateUDG(ALGraph &G){ 
	//��������ͼG���ڽӱ����ڽӱ�
	int i , k;
	
	cout <<"�������ܶ��������ܱ������Կո����:";
	cin >> G.vexnum >> G.arcnum;				//�����ܶ��������ܱ��� 
    cout << endl;
	
	cout << "���������ƣ���a" << endl;
	
	for(i = 0; i < G.vexnum; ++i){          	//������㣬�����ͷ����
		cout << "�������" << (i+1) << "���������:";
		cin >> G.vertices[i].data;           	//���붥��ֵ
		G.converse_vertices[i].data = G.vertices[i].data;
		//��ʼ����ͷ����ָ����ΪNULL 
		G.vertices[i].firstarc=NULL;			
		G.converse_vertices[i].firstarc=NULL;
    }//for
	cout << endl;
	cout << "����������Ķ��㣬��a b" << endl;
	for(k = 0; k < G.arcnum;++k){        		//������ߣ������ڽӱ�
		VerTexType v1 , v2;
		int i , j;
		cout << "�������" << (k + 1) << "���������Ķ���:";
		cin >> v1 >> v2;                		//����һ������������������
		i = LocateVex(G, v1);  j = LocateVex(G, v2);
		//ȷ��v1��v2��G��λ�ã���������G.vertices�е���� 

		ArcNode *p1=new ArcNode;               	//����һ���µı߽��*p1 
		p1->adjvex=j;                   		//�ڽӵ����Ϊj
		p1->nextarc = G.vertices[i].firstarc;  G.vertices[i].firstarc=p1;
		//���½��*p1���붥��vi�ı߱�ͷ��

		ArcNode *p2=new ArcNode;               	//����һ���µı߽��*p1 
		p2->adjvex=i;                   		//���ڽӵ����Ϊi
		p2->nextarc = G.converse_vertices[j].firstarc;  G.converse_vertices[j].firstarc=p2;
		//���½��*p1���붥��vi�ı߱�ͷ��
    }//for 
    return OK; 
}//CreateUDG

void FindInDegree(ALGraph G){
	//������������ȴ�������indegree�� 
	int i , count;

	for(i = 0 ; i < G.vexnum ; i++){
		count = 0;
		ArcNode *p = G.converse_vertices[i].firstarc;
		if(p){
			while(p){
				p = p->nextarc;
				count++;
			}
		}
		indegree[i] = count;
	}
}//FindInDegree

int TopologicalSort(ALGraph G , int topo[]){ 
    //����ͼG�����ڽӱ�洢�ṹ 
    //��G�޻�·��������G��һ����������topo[]������OK������ERROR 
	int i , m;
    FindInDegree(G);              				//������������ȴ�������indegree�� 
    InitStack(S);                          		//ջS��ʼ��Ϊ�� 
    for(i = 0; i < G.vexnum; ++i)
		if(!indegree[i]) Push(S, i);     		//���Ϊ0�߽�ջ 
	m = 0;                               		//����������������ʼΪ0 
	while(!StackEmpty(S)){                		//ջS�ǿ� 
		Pop(S, i);                          	//��ջ������vi��ջ
		topo[m]=i;                         		//��vi������������������topo�� 
		++m;                             		//������������ 
		ArcNode *p = G.vertices[i].firstarc;    //pָ��vi�ĵ�һ���ڽӵ� 
		while(p){
			int k = p->adjvex;					//vkΪvi���ڽӵ�   
			--indegree[k];                   	//vi��ÿ���ڽӵ����ȼ�1 
			if(indegree[k] ==0)  Push(S, k);	//����ȼ�Ϊ0������ջ 
			p = p->nextarc;                		//pָ�򶥵�vi��һ���ڽӽ�� 
		}//while 
	}//while
	
	if(m < G.vexnum)  return ERROR;    			//������ͼ�л�· 
	else return OK;
}//TopologicalSort 

int main(){
	cout << "************�㷨6.12����������**************" << endl << endl;
	ALGraph G;
	CreateUDG(G);
	int *topo = new int [G.vexnum];
	
	cout << endl;
	cout << "����ͼ���ڽӱ����ڽӱ������!" << endl << endl;

	if(TopologicalSort(G , topo)){
		cout << "������ͼ��������������Ϊ��";
		for(int j = 0 ; j < G.vexnum; j++){
			if(j != G.vexnum - 1)
				cout << G.vertices[topo[j]].data << " , ";
			else
				cout << G.vertices[topo[j]].data << endl << endl;
		}//for
	}
	else
		cout << "���д��ڻ����޷�������������" <<endl << endl;
	return OK;
}//main
