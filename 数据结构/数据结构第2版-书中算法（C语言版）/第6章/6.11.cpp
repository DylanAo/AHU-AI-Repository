//�㷨6.11�����������㷨

#include <iostream>
using namespace std;

#define MaxInt 32767                    	//��ʾ����ֵ������
#define MVNum 100                       	//��󶥵���

typedef char VerTexType;              		//���趥�����������Ϊ�ַ��� 
typedef int ArcType;                  		//����ߵ�Ȩֵ����Ϊ���� 

int Path[MVNum][MVNum];						//���·���϶���vj��ǰһ��������
int D[MVNum][MVNum];						//��¼����vi��vj֮������·������

//------------ͼ���ڽӾ���---------------
typedef struct{ 
	VerTexType vexs[MVNum];            		//����� 
	ArcType arcs[MVNum][MVNum];      		//�ڽӾ��� 
	int vexnum,arcnum;                		//ͼ�ĵ�ǰ�����ͱ��� 
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

	cout << "���������ƣ���a" << endl;

    for(i = 0; i < G.vexnum; ++i){   
		cout << "�������" << (i+1) << "���������:";
		cin >> G.vexs[i];                        			//������������Ϣ 
	}
	cout << endl;
    for(i = 0; i < G.vexnum; ++i){                			//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt 
		for(j = 0; j < G.vexnum; ++j){  
			if(j != i)
				G.arcs[i][j] = MaxInt;  
			else
				G.arcs[i][j] = 0;
		}//for
	}//for

	cout << "����������Ķ��㼰Ȩֵ����a b 3" << endl;
	for(k = 0; k < G.arcnum;++k){						//�����ڽӾ��� 
		VerTexType v1 , v2;
		ArcType w;
		cout << "�������" << (k + 1) << "���������Ķ��㼰Ȩֵ:";
		cin >> v1 >> v2 >> w;                           //����һ���������Ķ��㼰Ȩֵ
		i = LocateVex(G, v1);  j = LocateVex(G, v2);	//ȷ��v1��v2��G�е�λ�ã�������������±� 
		G.arcs[i][j] = w;								//��<v1, v2>��Ȩֵ��Ϊw 
	}//for
}//CreateUDN 

void ShortestPath_Floyed(AMGraph G){ 
    //��Floyd�㷨��������G�и��Զ���i��j֮������·�� 
	int i , j , k ;
    for (i = 0; i < G.vexnum; ++i)          		//���Խ��֮���ʼ��֪·�������� 
        for(j = 0; j < G.vexnum; ++j){ 
            D[i][j] = G.arcs[i][j]; 
            if(D[i][j] < MaxInt && i != j)  Path[i][j]=i;  	//���i��j֮���л�����j��ǰ����Ϊi 
            else Path [i][j] = -1;              		//���i��j֮���޻�����j��ǰ����Ϊ-1 
		}//for
		for(k = 0; k < G.vexnum; ++k) 
			for(i = 0; i < G.vexnum; ++i) 
				for(j = 0; j < G.vexnum; ++j)
					if(D[i][k] + D[k][j] < D[i][j]){   		//��i��k��j��һ��·������ 
						D[i][j] = D[i][k]+D[k][j];    		//����D[i][j] 
						Path[i][j] = Path[k][j];       			//����j��ǰ��Ϊk 
					}//if 
}//ShortestPath_Floyed

void DisplayPath(AMGraph G , int begin ,int temp ){
	//��ʾ���·��
	if(Path[begin][temp] != -1){
		DisplayPath(G , begin ,Path[begin][temp]);
		cout << G.vexs[Path[begin][temp]] << "-->";
	}
}//DisplayPath

void main(){
	cout << "************�㷨6.11�����������㷨**************" << endl << endl;
	AMGraph G;
	char start , destination;
	int num_start , num_destination;

	CreateUDN(G);
	
	cout <<endl;
	cout << "������G������ɣ�" << endl;
	ShortestPath_Floyed(G);

	cout << "����������·����������յ�����ƣ�";
	cin >> start >> destination;
	num_start = LocateVex(G , start);
	num_destination = LocateVex(G , destination);

	DisplayPath(G , num_start , num_destination);
	cout << G.vexs[num_destination] << endl;
	cout << "���·���ĳ���Ϊ��" << D[num_start][num_destination] << endl;
	cout <<endl;
}//main
