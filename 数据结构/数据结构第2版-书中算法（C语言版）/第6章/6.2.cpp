//�㷨6.2�������ڽӱ��ʾ����������ͼ

#include <iostream>
using namespace std;

#define MVNum 100                        	//��󶥵��� 
#define OK 1

typedef char VerTexType;					//������Ϣ
typedef int OtherInfo;						//�ͱ���ص���Ϣ 

//- - - - -ͼ���ڽӱ�洢��ʾ- - - - - 
typedef struct ArcNode{                		//�߽�� 
    int adjvex;                          	//�ñ���ָ��Ķ����λ�� 
    struct ArcNode *nextarc;          		//ָ����һ���ߵ�ָ�� 
    OtherInfo info;                      	//�ͱ���ص���Ϣ 
}ArcNode; 

typedef struct VNode{ 
    VerTexType data;                    	//������Ϣ 
    ArcNode *firstarc;                		//ָ���һ�������ö���ıߵ�ָ�� 
}VNode, AdjList[MVNum];               		//AdjList��ʾ�ڽӱ����� 

typedef struct{ 
    AdjList vertices;                 		//�ڽӱ� 
    int vexnum, arcnum;              		//ͼ�ĵ�ǰ�������ͱ��� 
}ALGraph;


int LocateVex(ALGraph G , VerTexType v){
	//ȷ����v��G�е�λ��
	for(int i = 0; i < G.vexnum; ++i)
		if(G.vertices[i].data == v)
			return i;
   return -1;
}//LocateVex

int CreateUDG(ALGraph &G){ 
	//�����ڽӱ��ʾ������������ͼG
	int i , k;

	cout <<"�������ܶ��������ܱ����м��Կո����:";
	cin >> G.vexnum >> G.arcnum;				//�����ܶ��������ܱ��� 
    cout << endl;
	
	cout << "���������ƣ��� a " <<endl;
	for(i = 0; i < G.vexnum; ++i){          	//������㣬�����ͷ����
		cout << "�������" << (i+1) << "���������:";
		cin >> G.vertices[i].data;           	//���붥��ֵ 
		G.vertices[i].firstarc=NULL;			//��ʼ����ͷ����ָ����ΪNULL 
    }//for
	cout << endl;
    
	cout << "������һ���������Ķ���,�� a b" << endl;
	for(k = 0; k < G.arcnum;++k){        		//������ߣ������ڽӱ�
		VerTexType v1 , v2;
		int i , j;
		cout << "�������" << (k + 1) << "���������Ķ���:";
		cin >> v1 >> v2;                 		//����һ������������������
		i = LocateVex(G, v1);  j = LocateVex(G, v2);
		//ȷ��v1��v2��G��λ�ã���������G.vertices�е���� 

		ArcNode *p1=new ArcNode;               	//����һ���µı߽��*p1 
		p1->adjvex=j;                   		//�ڽӵ����Ϊj 
		p1->nextarc= G.vertices[i].firstarc;  G.vertices[i].firstarc=p1;  
		//���½��*p1���붥��vi�ı߱�ͷ��

		ArcNode *p2=new ArcNode;                //������һ���ԳƵ��µı߽��*p2 
		p2->adjvex=i;                   		//�ڽӵ����Ϊi 
		p2->nextarc= G.vertices[j].firstarc;  G.vertices[j].firstarc=p2;  
		//���½��*p2���붥��vj�ı߱�ͷ�� 
    }//for 
    return OK; 
}//CreateUDG

int main(){
	cout << "************�㷨6.2�������ڽӱ��ʾ����������ͼ**************" << endl << endl;
	ALGraph G;
	CreateUDG(G);
	int i;

	cout << endl;
	cout << "*****�ڽӱ��ʾ������������ͼ*****" << endl;
	
	for(i = 0 ; i < G.vexnum ; ++i){
		VNode temp = G.vertices[i];
		ArcNode *p = temp.firstarc;
		if(p == NULL){
			cout << G.vertices[i].data;
			cout << endl;
		}
		else{
			cout << temp.data;
			while(p){
				cout << "->";
				cout << p->adjvex;
				p = p->nextarc;
			}
		}
		cout << endl;
	}
	return 0;
}//main
