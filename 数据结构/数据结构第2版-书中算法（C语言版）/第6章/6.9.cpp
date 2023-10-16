//�㷨6.9����³˹�����㷨

#include <iostream>
using namespace std;

typedef char VerTexType;              		//���趥�����������Ϊ�ַ��� 
typedef int ArcType;   
#define MVNum 100                       	//��󶥵���
#define MaxInt 32767                    	//��ʾ����ֵ������

//----------------ͼ���ڽӾ���---------------------
typedef struct{ 
	VerTexType vexs[MVNum];            		//����� 
	ArcType arcs[MVNum][MVNum];      		//�ڽӾ��� 
	int vexnum,arcnum;                		//ͼ�ĵ�ǰ�����ͱ��� 
}AMGraph;

//��������Edges�Ķ���
struct{
	VerTexType Head;						//�ߵ�ʼ��
	VerTexType Tail;						//�ߵ��յ�
	ArcType lowcost;						//���ϵ�Ȩֵ
}Edge[(MVNum * (MVNum - 1)) / 2];

int Vexset[MVNum];							//��������Vexset�Ķ���

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
    cin >> G.vexnum >> G.arcnum;						//�����ܶ��������ܱ���
	cout << endl;
	
	cout << "���������ƣ���a" << endl;

    for(i = 0; i < G.vexnum; ++i){   
		cout << "�������" << (i+1) << "���������:";
		cin >> G.vexs[i];                        		//������������Ϣ 
	}
	cout << endl;
	for(i = 0; i < G.vexnum; ++i)                		//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt 
		for(j = 0; j < G.vexnum; ++j) 
			G.arcs[i][j] = MaxInt; 
	cout << "����������Ķ��㼰Ȩֵ����a b 6" << endl;
	for(k = 0; k < G.arcnum;++k){						//�����ڽӾ��� 
		VerTexType v1 , v2;
		ArcType w;
		cout << "�������" << (k + 1) << "���������Ķ��㼰Ȩֵ:";
		cin >> v1 >> v2 >> w;                           //����һ���������Ķ��㼰Ȩֵ
		i = LocateVex(G, v1);  j = LocateVex(G, v2);	//ȷ��v1��v2��G�е�λ�ã�������������±� 
		G.arcs[i][j] = w;								//��<v1, v2>��Ȩֵ��Ϊw 
		G.arcs[j][i] = G.arcs[i][j];					//��<v1, v2>�ĶԳƱ�<v2, v1>��ȨֵΪw 
		Edge[k].lowcost = w;
		Edge[k].Head = v1;
		Edge[k].Tail = v2;
	}//for
}//CreateUDN 

//----------ð������-------------------
void Sort(AMGraph G){
	int m = G.arcnum - 2;
	int flag = 1;
	while((m > 0) && flag == 1){
		flag = 0;
		for(int j = 0 ; j <= m ; j++){
			if(Edge[j].lowcost > Edge[j+ 1].lowcost){
				flag = 1;

				VerTexType temp_Head = Edge[j].Head;
				Edge[j].Head = Edge[j+ 1].Head;
				Edge[j + 1].Head = temp_Head;
				

				VerTexType temp_Tail = Edge[j].Tail;
				Edge[j].Tail = Edge[j+ 1].Tail;
				Edge[j + 1].Tail = temp_Tail;
				
				ArcType temp_lowcost = Edge[j].lowcost;
				Edge[j].lowcost = Edge[j+ 1].lowcost;
				Edge[j + 1].lowcost = temp_lowcost;
			}//if
		}//for
		--m;
	}//while
}//Sort

void MiniSpanTree_Kruskal(AMGraph G){ 
    //������G���ڽӾ�����ʽ�洢������G����С������T�����T�ĸ�����     
    int i , j , v1 , v2 , vs1 , vs2;
	Sort(G);                 							//������Edge�е�Ԫ�ذ�Ȩֵ��С�������� 
	for(i = 0; i < G.vexnum; ++i)     					//�������飬��ʾ�������Գ�һ����ͨ���� 
        Vexset[i] = i;
    for(i = 0; i < G.arcnum; ++i){      
		//���β鿴�ź��������Edge�еı��Ƿ���ͬһ��ͨ������     
		v1 =LocateVex(G, Edge[i].Head);     			//v1Ϊ�ߵ�ʼ��Head���±� 
		v2 =LocateVex(G, Edge[i].Tail);     			//v2Ϊ�ߵ��յ�Tail���±� 
		vs1 = Vexset[v1];       						//��ȡ��Edge[i]��ʼ�����ڵ���ͨ����vs1 
		vs2 = Vexset[v2];       						//��ȡ��Edge[i]���յ����ڵ���ͨ����vs2 
		if(vs1 != vs2){         						//�ߵ��������������ͬ����ͨ���� 
			cout << Edge[i].Head << "-->" << Edge[i].Tail << endl;		//����˱� 
			for(j = 0; j < G.vexnum; ++j)      			//�ϲ�vs1��vs2��������������������ͳһ��� 
				if(Vexset[j] == vs2) Vexset[j] = vs1;	//���ϱ��Ϊvs2�Ķ���Ϊvs1 
		}//if 
    }//for 
}//MiniSpanTree_Kruskal

void main(){
	cout << "************�㷨6.9����³˹�����㷨**************" << endl << endl;
	AMGraph G;
	CreateUDN(G);
	
	cout <<endl;
	cout << "*****������G������ɣ�*****" << endl;

	cout <<endl;
	MiniSpanTree_Kruskal(G);
}///main
