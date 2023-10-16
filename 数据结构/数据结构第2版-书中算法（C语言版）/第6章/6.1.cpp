//�㷨6.1�������ڽӾ����ʾ������������

#include <iostream>
using namespace std;

#define MaxInt 32767                    	//��ʾ����ֵ������
#define MVNum 100                       	//��󶥵���
#define OK 1	
 						
typedef char VerTexType;              		//���趥�����������Ϊ�ַ��� 
typedef int ArcType;                  		//����ߵ�Ȩֵ����Ϊ���� 

//- - - - -ͼ���ڽӾ���洢��ʾ- - - - -
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

int CreateUDN(AMGraph &G){ 
    //�����ڽӾ����ʾ��������������G 
	int i , j , k;
	cout <<"�������ܶ��������ܱ������Կո������";
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
	cout << "����������Ķ��㼰Ȩֵ���� a b 5" << endl;
	for(k = 0; k < G.arcnum;++k){							//�����ڽӾ��� 
		VerTexType v1 , v2;
		ArcType w;
		cout << "�������" << (k + 1) << "���������Ķ��㼰Ȩֵ:";
		cin >> v1 >> v2 >> w;								//����һ���������Ķ��㼰Ȩֵ
		i = LocateVex(G, v1);  j = LocateVex(G, v2);		//ȷ��v1��v2��G�е�λ�ã�������������±� 
		G.arcs[i][j] = w;									//��<v1, v2>��Ȩֵ��Ϊw 
		G.arcs[j][i] = G.arcs[i][j];						//��<v1, v2>�ĶԳƱ�<v2, v1>��ȨֵΪw 
	}//for	
	return OK; 
}//CreateUDN 

int main(){
	cout << "************�㷨6.1�������ڽӾ����ʾ������������**************" << endl << endl;
	AMGraph G;     int i , j;
	CreateUDN(G);
	
	cout <<endl;
	cout << "*****�ڽӾ����ʾ��������������*****" << endl;
	
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
	cout <<endl;
	return 0;
}//main