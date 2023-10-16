//�㷨6.13���ؼ�·���㷨

#include <iostream>
using namespace std;

#define MVNum 100                       	//��󶥵���
#define BDNum MVNum * (MVNum - 1)			//������
#define OK 1	
#define ERROR 0 

typedef char VerTexType;

//- - - - -ͼ���ڽӱ�洢��ʾ- - - - - 
typedef struct ArcNode{                		//�߽�� 
    int adjvex;                          	//�ñ���ָ��Ķ����λ��
	int weight;								//Ȩֵ
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
int ve[BDNum];								//�¼�vi�����緢��ʱ��
int vl[BDNum];								//�¼�vi����ٷ���ʱ��
int topo[MVNum];							//��¼�������еĶ������
spStack S;

//----------------ջ�Ĳ���--------------------
void InitStack(spStack &S){
	//ջ�ĳ�ʼ��
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
//---------------------------------------

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
	
	for(i = 0; i < G.vexnum; ++i){          		//������㣬�����ͷ����
		cout << "�������" << (i+1) << "���������:";
		cin >> G.vertices[i].data;           		//���붥��ֵ
		G.converse_vertices[i].data = G.vertices[i].data;
		//��ʼ����ͷ����ָ����ΪNULL 
		G.vertices[i].firstarc=NULL;			
		G.converse_vertices[i].firstarc=NULL;
    }//for
	cout << endl;

	cout << "����������Ķ��㼰��Ȩֵ����a b 3" << endl;

	for(k = 0; k < G.arcnum;++k){        			//������ߣ������ڽӱ�
		VerTexType v1 , v2;
		int i , j , w;
		cout << "�������" << (k + 1) << "���������Ķ��㼰��Ȩֵ:";
		cin >> v1 >> v2 >> w;                		//����һ������������������
		i = LocateVex(G, v1);  j = LocateVex(G, v2);
		//ȷ��v1��v2��G��λ�ã���������G.vertices�е���� 

		ArcNode *p1=new ArcNode;               		//����һ���µı߽��*p1 
		p1->adjvex=j;                   			//�ڽӵ����Ϊj
		p1->nextarc = G.vertices[i].firstarc;  G.vertices[i].firstarc=p1;
		p1->weight = w;
		//���½��*p1���붥��vi�ı߱�ͷ��

		ArcNode *p2=new ArcNode;               		//����һ���µı߽��*p1 
		p2->adjvex=i;                   			//���ڽӵ����Ϊi
		p2->nextarc = G.converse_vertices[j].firstarc;  G.converse_vertices[j].firstarc=p2;
		p2->weight = w;
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
		}//if
		indegree[i] = count;
	}//for
}//FindInDegree

int TopologicalOrder(ALGraph G , int topo[]){ 
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
}//TopologicalOrder

int CriticalPath(ALGraph G){ 
    //GΪ�ڽӱ�洢�������������G�ĸ���ؼ��
	int n , i , k , j , e , l;
    if (!TopologicalOrder(G, topo))  return ERROR; 
    //�������������㷨��ʹ�������б�����topo�У�������ʧ�ܣ���������򻷣�����ERROR 
    n = G.vexnum;                  				//nΪ������� 
    for(i = 0; i < n; i++)               		//��ÿ���¼������緢��ʱ���ó�ֵ0 
		ve[i] = 0; 


    /*�D�D�D�D�D�D�D�D�D�D�����˴�����ÿ���¼������緢��ʱ�䣭�D�D�D�D���D�D�D�D�D*/ 
    for(i = 0;i < n; i++){                 
		k = topo[i];                   			//ȡ�����������еĶ������k             
		ArcNode *p = G.vertices[k].firstarc;    //pָ��k�ĵ�һ���ڽӶ���  
		while(p != NULL){            			//���θ���k�������ڽӶ�������緢��ʱ��   
			j = p->adjvex;               		//jΪ�ڽӶ�������                   
			if(ve[j] < ve[k] + p->weight)    	//���¶���j�����緢��ʱ��ve[j] 
				ve[j] = ve[k] + p->weight;     
			p = p->nextarc;              		//pָ��k����һ���ڽӶ���  
		} //while 
    } //for 

    for(i=0;i<n;i++)                 			//��ÿ���¼�����ٷ���ʱ���ó�ֵve[n-1] 
		vl[i]=ve[n-1];
	
    /*�D�D�D�D�D�D�D�D�D�D�������˴�����ÿ���¼�����ٷ���ʱ�䣭�D�D�D�D���D�D�D�D�D*/ 
    for(i = n - 1;i >= 0; i--){               
		k = topo[i];                   			//ȡ�����������еĶ������k             
		ArcNode *p = G.vertices[k].firstarc;    //pָ��k�ĵ�һ���ڽӶ���  
		while(p != NULL){            			//����k���ڽӵ㣬����k����ٷ���ʱ��   
			j = p->adjvex;              		//jΪ�ڽӶ�������                   
			if(vl[k] > vl[j] - p->weight)    	//���¶���k����ٷ���ʱ��vl[k] 
				vl[k] = vl[j] - p->weight;       
			p = p->nextarc;              		//pָ��k����һ���ڽӶ���  
		}//while 
    }//for 

    /*�D�D�D�D�D�D�D�D�D�D�D�D�ж�ÿһ��Ƿ�Ϊ�ؼ�����D�D�D�D�D�D���D�D�D�D�D*/
	cout << endl;
	cout << "�ؼ��·��Ϊ:";
    for(i = 0;i < n; i++){                		//ÿ��ѭ�����viΪ���ʼ������л 
        ArcNode *p = G.vertices[i].firstarc;    //pָ��i�ĵ�һ���ڽӶ���  
        while(p != NULL) {    
			j = p->adjvex;             			//jΪi���ڽӶ�������    
			e = ve[i];                 			//����<vi, vj>�����翪ʼʱ�� 
			l = vl[j] - p->weight;      		//����<vi, vj>����ٿ�ʼʱ�� 
			if(e == l)               			//��Ϊ�ؼ���������<vi, vj> 
				cout << G.vertices[i].data << "-->" << G.vertices[j].data << " ";
			p = p->nextarc;              		//pָ��i����һ���ڽӶ���  
		} //while 
	} //for  
	return OK;
}//CriticalPath

int main(){
	cout << "************�㷨6.13���ؼ�·���㷨**************" << endl << endl;
	ALGraph G;
	CreateUDG(G);
	int *topo = new int [G.vexnum];
	
	cout << endl;
	cout << "����ͼ�������!" << endl << endl;
	
	if(!CriticalPath(G))
		cout << "���д��ڻ����޷�������������" <<endl << endl;
	cout << endl;
	return OK;
}//main

