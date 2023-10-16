//�㷨6.10���Ͻ�˹�����㷨

#include <iostream>
using namespace std;

#define MaxInt 32767                    					//��ʾ����ֵ������
#define MVNum 100                       					//��󶥵���
typedef char VerTexType;              						//���趥�����������Ϊ�ַ��� 
typedef int ArcType;                  						//����ߵ�Ȩֵ����Ϊ����

int *D=new int[MVNum];	                    				//���ڼ�¼���·�ĳ���
bool *S=new bool[MVNum];          							//��Ƕ����Ƿ����S����
int *Path=new int[MVNum];									//���ڼ�¼���·�����ǰ��

//------------ͼ���ڽӾ���-----------------
typedef struct{ 
	VerTexType vexs[MVNum];            						//����� 
	ArcType arcs[MVNum][MVNum];      						//�ڽӾ��� 
	int vexnum,arcnum;                						//ͼ�ĵ�ǰ�����ͱ��� 
}AMGraph;

int LocateVex(AMGraph G , VerTexType v){
	//ȷ����v��G�е�λ��
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vexs[i] == v)
			return i;
   return -1;
}//LocateVex

void CreateUDN(AMGraph &G){ 
    //�����ڽӾ����ʾ��������������G 
	int i , j , k;
	cout <<"�������ܶ��������ܱ������Կո����:";
    cin >> G.vexnum >> G.arcnum;							//�����ܶ��������ܱ���
	cout << endl;

	cout << "����������:����a" << endl;

    for(i = 0; i < G.vexnum; ++i){   
		cout << "�������" << (i+1) << "���������:";
		cin >> G.vexs[i];                        			//������������Ϣ 
	}
	cout << endl;
    for(i = 0; i < G.vexnum; ++i)                			//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt 
		for(j = 0; j < G.vexnum; ++j)   
			G.arcs[i][j] = MaxInt; 
	cout << "����������Ķ��㼰Ȩֵ����a b 7" << endl;
	for(k = 0; k < G.arcnum;++k){							//�����ڽӾ��� 
		VerTexType v1 , v2;
		ArcType w;
		cout << "�������" << (k + 1) << "���������Ķ��㼰Ȩֵ:";
		cin >> v1 >> v2 >> w;								//����һ���������Ķ��㼰Ȩֵ
		i = LocateVex(G, v1);  j = LocateVex(G, v2);		//ȷ��v1��v2��G�е�λ�ã�������������±� 
		G.arcs[i][j] = w;									//��<v1, v2>��Ȩֵ��Ϊw 
		G.arcs[j][i] = G.arcs[i][j];						//��<v1, v2>�ĶԳƱ�<v2, v1>��ȨֵΪw 
	}//for
}//CreateUDN

void ShortestPath_DIJ(AMGraph G, int v0){ 
    //��Dijkstra�㷨��������G��v0���㵽���ඥ������·�� 
    int v , i , w , min;
	int n = G.vexnum;                    					//nΪG�ж���ĸ��� 

	for(v = 0; v < n; ++v){             					//n���������γ�ʼ�� 
		S[v] = false;                  						//S��ʼΪ�ռ� 
		D[v] = G.arcs[v0][v];           					//��v0�������յ�����·�����ȳ�ʼ��Ϊ���ϵ�Ȩֵ 
		if(D[v] < MaxInt)  Path [v] = v0;  					//���v0��v֮���л�����v��ǰ����Ϊv0 
		else Path [v] = -1;               					//���v0��v֮���޻�����v��ǰ����Ϊ-1 
	}//for 

	S[v0]=true;                    							//��v0����S 
	D[v0]=0;                      							//Դ�㵽Դ��ľ���Ϊ0 

	/*�D��ʼ����������ʼ��ѭ����ÿ�����v0��ĳ������v�����·������v�ӵ�S���D*/ 
	for(i = 1;i < n; ++i){									//������n-1�����㣬���ν��м��� 
        min= MaxInt; 
        for(w = 0; w < n; ++w) 
			if(!S[w] && D[w] < min){						//ѡ��һ����ǰ�����·�����յ�Ϊv 
				v = w; 
				min = D[w];
			}//if         	
		S[v]=true;                   						//��v����S 
		for(w = 0;w < n; ++w)           					//���´�v0����������V?S�����ж�������·������ 
			if(!S[w] && (D[v] + G.arcs[v][w] < D[w])){ 
				D[w] = D[v] + G.arcs[v][w];   				//����D[w] 
				Path [w] = v;              					//����w��ǰ��Ϊv 
			}//if 
    }//for  
}//ShortestPath_DIJ

void DisplayPath(AMGraph G , int begin ,int temp ){
	//��ʾ���·
	if(Path[temp] != -1){
		DisplayPath(G , begin ,Path[temp]);
		cout << G.vexs[Path[temp]] << "-->";
	}
}//DisplayPath

void main()
{
	cout << "************�㷨6.10���Ͻ�˹�����㷨**************" << endl << endl;
	AMGraph G; 
	int i , j ,num_start , num_destination;
	VerTexType start , destination;
	CreateUDN(G);
	cout <<endl;
	cout << "*****������G������ɣ�*****" << endl;
	
	for(i = 0 ; i < G.vexnum ; ++i){
		for(j = 0; j < G.vexnum; ++j){
			if(j != G.vexnum - 1){
				if(G.arcs[i][j] != MaxInt)
					cout << G.arcs[i][j] << "\t";
				else
					cout << "��" << "\t";
			}
			else{
				if(G.arcs[i][j] != MaxInt)
					cout << G.arcs[i][j] <<endl;
				else
					cout << "��" <<endl;
			}
		}
	}//for
	cout << endl;
	cout << "������������ʼ�㡢�յ����ƣ�";
	cin >> start >> destination;
	num_start = LocateVex(G , start);
	num_destination = LocateVex(G , destination);
	ShortestPath_DIJ(G , num_start);
	cout << endl <<"���·��Ϊ��";
	DisplayPath(G , num_start , num_destination);
	cout << G.vexs[num_destination]<<endl;
}//main

