//�㷨6.8������ķ�㷨
#include <iostream>
using namespace std;

typedef char VerTexType;
typedef int ArcType;
#define MVNum 100
#define MaxInt 32767                    	//��ʾ����ֵ������

//��������Ķ��壬������¼�Ӷ��㼯U��V-U��Ȩֵ��С�ı�
struct{
	VerTexType adjvex;						//��С����U�е��Ǹ�����
	ArcType lowcost;						//��С���ϵ�Ȩֵ
}closedge[MVNum];

//- - - - -ͼ���ڽӱ�洢��ʾ- - - - - 						
typedef char VerTexType;              		//���趥�����������Ϊ�ַ��� 
typedef int ArcType;                  		//����ߵ�Ȩֵ����Ϊ���� 
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
    for(i = 0; i < G.vexnum; ++i)                			//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt 
		for(j = 0; j < G.vexnum; ++j)   
			G.arcs[i][j] = MaxInt;
	cout << "����������Ķ��㼰Ȩֵ����a b 5" << endl;
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

int Min(AMGraph G){
	//����Ȩֵ��С�ĵ�
	int i;
	int index = -1;
	int min = MaxInt;
	for(i = 0 ; i < G.vexnum ; ++i){
		if(min > closedge[i].lowcost && closedge[i].lowcost != 0){
			min = closedge[i].lowcost;
			index = i;
		}
	}//for
	return index;
}//Min

void MiniSpanTree_Prim(AMGraph G, VerTexType u){ 
    //������G���ڽӾ�����ʽ�洢���Ӷ���u��������G����С������T�����T�ĸ�����  
	int k , j , i;
	VerTexType u0 , v0;
    k =LocateVex(G, u);           										//kΪ����u���±� 
    for(j = 0; j < G.vexnum; ++j){     									//��V-U��ÿһ������vi����ʼ��closedge[i] 
		if(j != k){  
			closedge[j].adjvex = u;
			closedge[j].lowcost = G.arcs[k][j];							//{adjvex, lowcost}
		}//if
	}//for
	closedge[k].lowcost = 0;        									//��ʼ��U = {u}
	for(i = 1; i < G.vexnum; ++i){     									//ѡ������n-1�����㣬����n-1����(n= G.vexnum) 
		k = Min(G);  
		//���T����һ����㣺��k�����㣬closedge[k]�д��е�ǰ��С�� 
		u0 = closedge[k].adjvex;     									//u0Ϊ��С�ߵ�һ�����㣬u0��U 
		v0 = G.vexs[k];            										//v0Ϊ��С�ߵ���һ�����㣬v0��V-U 
		cout << "��  " <<u0 << "--->" << v0 << endl;           			//�����ǰ����С��(u0, v0) 
		closedge[k].lowcost = 0;   		//��k�����㲢��U�� 
		for(j = 0; j < G.vexnum; ++j) 
			if(G.arcs[k][j] < closedge[j].lowcost){						//�¶��㲢��U������ѡ����С�� 
				closedge[j].adjvex = G.vexs[k];
				closedge[j].lowcost = G.arcs[k][j];
			}//if 
	}//for 
}//MiniSpanTree_Prim 

int main(){
	cout << "************�㷨6.8������ķ�㷨**************" << endl << endl;
	AMGraph G;
	CreateUDN(G);
	cout << endl;
	cout << "����ͼG������ɣ�" << endl;
	cout <<endl;

	cout << "******��������ķ�㷨������С�����������******" << endl;
	MiniSpanTree_Prim(G , 'a');
	cout <<endl;
	return 0;
}//main