//�㷨6.5�������ڽӾ����ʾͼ�����������������

#include <iostream>
using namespace std;

#define MVNum 100							//��󶥵���
typedef char VerTexType;					//���趥�����������Ϊ�ַ��� 
typedef int ArcType;                 		//����ߵ�Ȩֵ����Ϊ���� 

//------------ͼ���ڽӾ���------------------
typedef struct{ 
	VerTexType vexs[MVNum];            		//����� 
	ArcType arcs[MVNum][MVNum];      		//�ڽӾ��� 
	int vexnum,arcnum;                		//ͼ�ĵ�ǰ�����ͱ��� 
}Graph;

bool visited[MVNum];           				//���ʱ�־���飬���ֵΪ"false" 
int FirstAdjVex(Graph G , int v);			//����v�ĵ�һ���ڽӵ�
int NextAdjVex(Graph G , int v , int w);	//����v�����w����һ���ڽӵ�

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
	
	cout << "���������ƣ���a" <<endl;

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
		cin >> v1 >> v2;									//����һ���������Ķ��㼰Ȩֵ
		i = LocateVex(G, v1);  j = LocateVex(G, v2);		//ȷ��v1��v2��G�е�λ�ã�������������±� 
		G.arcs[j][i] = G.arcs[i][j] = 1;					//��<v1, v2>�ĶԳƱ�<v2, v1>��ȨֵΪw 
	}//for
}//CreateUDN 

void DFS(Graph G, int v){        		
	//ͼGΪ�ڽӾ������� 
	int w;
	cout << G.vexs[v] << "    ";  visited[v] = true;  		//���ʵ�v�����㣬���÷��ʱ�־������Ӧ����ֵΪtrue 
	for(w = 0; w < G.vexnum; w++)  							//���μ���ڽӾ���v���ڵ���  
		if((G.arcs[v][w] != 0)&& (!visited[w]))  DFS(G, w); //G.arcs[v][w]!=0��ʾw��v���ڽӵ㣬���wδ���ʣ���ݹ����DFS 
}//DFS

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
	cout << "************�㷨6.5�������ڽӾ����ʾͼ�����������������**************" << endl << endl;
	Graph G;
	CreateUDN(G);
	cout << endl;
	cout << "����ͼG������ɣ�" << endl << endl;
	
	cout << "�������������ͼG����ʼ�㣺";
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
	cout << "�������������������ͼG�����" << endl;
	DFS(G , i);

	cout <<endl;
	return 0;
}//main