//�㷨6.4���������������������ͨͼ

#include <iostream>
using namespace std;

#define MVNum 100								//��󶥵���
typedef char VerTexType;						//���趥�����������Ϊ�ַ��� 
typedef int ArcType;                 			//����ߵ�Ȩֵ����Ϊ���� 
	
//-------------ͼ���ڽӾ���-----------------
typedef struct{ 
	VerTexType vexs[MVNum];            			//����� 
	ArcType arcs[MVNum][MVNum];      			//�ڽӾ��� 
	int vexnum,arcnum;                			//ͼ�ĵ�ǰ�����ͱ��� 
}Graph;

bool visited[MVNum];           					//���ʱ�־���飬���ֵΪ"false" 
int FirstAdjVex(Graph G , int v);				//����v�ĵ�һ���ڽӵ�
int NextAdjVex(Graph G , int v , int w);		//����v�����w����һ���ڽӵ�

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
    cin >> G.vexnum >> G.arcnum;								//�����ܶ��������ܱ���
	cout << endl;	
	
	cout << "���������ƣ���a" << endl;
    for(i = 0; i < G.vexnum; ++i){   
		cout << "�������" << (i+1) << "���������:";
		cin >> G.vexs[i];                        				//������������Ϣ 
	}
	cout << endl;
    for(i = 0; i < G.vexnum; ++i)                				//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt 
		for(j = 0; j < G.vexnum; ++j)   
			G.arcs[i][j] = 0;  
	cout << "����������Ķ��㣬��a b" << endl;
	for(k = 0; k < G.arcnum;++k){								//�����ڽӾ��� 
		VerTexType v1 , v2;
		cout << "�������" << (k + 1) << "���������Ķ���:";
		cin >> v1 >> v2;										//����һ���������Ķ��㼰Ȩֵ
		i = LocateVex(G, v1);  j = LocateVex(G, v2);			//ȷ��v1��v2��G�е�λ�ã�������������±� 
		G.arcs[j][i] = G.arcs[i][j] = 1;						//��<v1, v2>�ĶԳƱ�<v2, v1>��ȨֵΪw 
	}//for
}//CreateUDN 

void DFS(Graph G, int v){        								
	//�ӵ�v����������ݹ��������ȱ���ͼG 
	cout << G.vexs[v] << "    ";  visited[v] = true;    		//���ʵ�v�����㣬���÷��ʱ�־������Ӧ����ֵΪtrue 
	int w;
	for(w = FirstAdjVex(G, v);  w >= 0;  w = NextAdjVex(G, v, w))  
		//���μ��v�������ڽӵ�w ��FirstAdjVex(G, v)��ʾv�ĵ�һ���ڽӵ� 
		//NextAdjVex(G, v, w)��ʾv�����w����һ���ڽӵ㣬w��0��ʾ�����ڽӵ� 
		if(!visited[w]) DFS(G, w);    							//��v����δ���ʵ��ڽӶ���w�ݹ����DFS 
}//DFS

void DFSTraverse(Graph G){ 
	//�Է���ͨͼG��������ȱ��� 
	int v;
	for(v = 0; v < G.vexnum; ++v)  visited[v] = false;			//���ʱ�־�����ʼ�� 
	for(v = 0; v < G.vexnum; ++v)                    			//ѭ�������㷨6.3 
        if(!visited[v])  DFS(G, v);                    			//����δ���ʵĶ������DFS 
}//DFSTraverse 

int FirstAdjVex(Graph G , int v){
	//����v�ĵ�һ���ڽӵ�
	int i;
	for(i = 0 ; i < G.vexnum ; ++i){
		if(G.arcs[v][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}//FirstAdjVex

int NextAdjVex(Graph G , int v , int w){
	//����v�����w����һ���ڽӵ�
	int i;
	for(i = w ; i < G.vexnum ; ++i){
		if(G.arcs[v][i] == 1 && visited[i] == false)
			return i;
	}
	return -1;
}//NextAdjVex

int main(){
	cout << "************�㷨6.4���������������������ͨͼ**************" << endl << endl;
	Graph G;
	CreateUDN(G);
	cout << endl;
	cout << "����ͼG������ɣ�" << endl << endl;
	
	cout << "�������������������ͨͼ�����" << endl;
	DFSTraverse(G);

	cout <<endl;
	return 0;
}//main