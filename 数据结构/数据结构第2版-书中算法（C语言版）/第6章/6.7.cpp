//�㷨6.7�������������������ͨͼ

#include <iostream>
using namespace std;

#define MVNum 100                       	//��󶥵���
#define MAXQSIZE 100						//�����г���
						
typedef char VerTexType;              		//���趥�����������Ϊ�ַ���
typedef int ArcType;                  		//����ߵ�Ȩֵ����Ϊ����
bool visited[MVNum];           				//���ʱ�־���飬���ֵΪ"false" 

//-----ͼ���ڽӾ���洢��ʾ----- 
typedef struct{ 
	VerTexType vexs[MVNum];            		//�����
	ArcType arcs[MVNum][MVNum];      		//�ڽӾ���
	int vexnum,arcnum;                		//ͼ�ĵ�ǰ�����ͱ���
}Graph;

//----���еĶ��弰����--------
typedef struct{
	ArcType *base;							//��ʼ���Ķ�̬����洢�ռ�
	int front;								//ͷָ�룬�����в��գ�ָ���ͷԪ��
	int rear;								//βָ�룬�����в��գ�ָ���βԪ�ص���һ��λ��
}sqQueue;

void InitQueue(sqQueue &Q){
	//����һ���ն���Q
	Q.base = new ArcType[MAXQSIZE];
	if(!Q.base)     exit(1);				//�洢����ʧ��
	Q.front = Q.rear = 0;
}//InitQueue

void EnQueue(sqQueue &Q, ArcType e){
	//����Ԫ��eΪQ���µĶ�βԪ��
	if((Q.rear + 1) % MAXQSIZE == Q.front)
		return;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
}//EnQueue

bool QueueEmpty(sqQueue Q){
	//�ж��Ƿ�Ϊ�ն�
	if(Q.rear == Q.front)
		return true;
	return false;
}//QueueEmpty

void DeQueue(sqQueue &Q, ArcType &u){
	//��ͷԪ�س��Ӳ���Ϊu 
	u = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
}//DeQueue   								
//--------------------------------------------------

int LocateVex(Graph G , VerTexType v){
	//ȷ����v��G�е�λ��
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vexs[i] == v)
			return i;
		return -1;
}//LocateVex

void CreateUDN(Graph &G){ 
    //�����ڽӾ����ʾ��������������G 
	int i , j , k;
	cout <<"�������ܶ��������ܱ������Կո����:";
    cin >> G.vexnum >> G.arcnum;							//�����ܶ��������ܱ���
	cout << endl;
	cout << "���������ƣ���a" << endl;
    for(i = 0; i < G.vexnum; ++i){   
		cout << "�������" << (i+1) << "���������:";
		cin >> G.vexs[i];                        			//������������Ϣ 
	}
	cout << endl;
    for(i = 0; i < G.vexnum; ++i)                			//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt 
		for(j = 0; j < G.vexnum; ++j)   
			G.arcs[i][j] = 0; 
	cout << "����������Ķ��㣬��a b" << endl;
	for(k = 0; k < G.arcnum;++k){							//�����ڽӾ��� 
		VerTexType v1 , v2;
		cout << "�������" << (k + 1) << "���������Ķ���:";
		cin >> v1 >> v2;									//����һ���������Ķ���
		i = LocateVex(G, v1);  j = LocateVex(G, v2);		//ȷ��v1��v2��G�е�λ�ã�������������±� 
		G.arcs[i][j] = 1;									//��<v1, v2>��Ȩֵ��Ϊw 
		G.arcs[j][i] = G.arcs[i][j];						//��<v1, v2>�ĶԳƱ�<v2, v1>��ȨֵΪw 
	}//for 
}//CreateUDN

int FirstAdjVex(Graph G , int v){
	//����v�ĵ�һ���ڽӵ�
	int i;
	for(i = 0 ; i < G.vexnum ; ++i){
		if(G.arcs[v][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}//FirstAdjVex

int NextAdjVex(Graph G , int u , int w){
	//����v�����w����һ���ڽӵ�
	int i;
	for(i = w ; i < G.vexnum ; ++i){
		if(G.arcs[u][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}//NextAdjVex

void BFS (Graph G, int v){ 
    //��������ȷǵݹ������ͨͼG 
	sqQueue Q;
	ArcType u;
	ArcType w;

    cout << G.vexs[v] << "  ";    visited[v] = true;     						//���ʵ�v�����㣬���÷��ʱ�־������Ӧ����ֵΪtrue 
    InitQueue(Q);              													//��������Q��ʼ�����ÿ�         
    EnQueue(Q, v);            													//v���� 
    while(!QueueEmpty(Q)){   													//���зǿ� 
		DeQueue(Q, u);       													//��ͷԪ�س��Ӳ���Ϊu
		for(w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)){
			//���μ��u�������ڽӵ�w ��FirstAdjVex(G, u)��ʾu�ĵ�һ���ڽӵ� 
			//NextAdjVex(G, u, w)��ʾu�����w����һ���ڽӵ㣬w��0��ʾ�����ڽӵ� 
			if(!visited[w]){	           										//wΪu����δ���ʵ��ڽӶ��� 
				cout << G.vexs[w] << "  ";   visited[w] = true;					//����w�����÷��ʱ�־������Ӧ����ֵΪtrue 
				EnQueue(Q, w);													//w���� 
			}//if 
		}//for
    }//while 
}//BFS 

int main(){
	cout << "************�㷨6.7�������������������ͨͼ**************" << endl << endl;
	Graph G;
	CreateUDN(G);
	cout << endl;
	cout << "������ͨͼG������ɣ�" << endl << endl;
	
	cout << "�����������ͨͼ����ʼ�㣺";
	VerTexType c;
	cin >> c;
	
	int i;
	for(i = 0 ; i < G.vexnum ; ++i){
		if(c == G.vexs[i])
			break;
	}
	cout << endl;
	while(i >= G.vexnum){
		cout << "�õ㲻���ڣ����������룡" << endl;
		cout << "�����������ͨͼ����ʼ�㣺";
		cin >> c;
		for(i = 0 ; i < G.vexnum ; ++i){
			if(c == G.vexs[i])
				break;
		}
	}
	cout << "�����������������ͨͼ�����" << endl;
	BFS(G , i);
	
	cout <<endl;
	return 0;
}//main