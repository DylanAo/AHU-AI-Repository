//�㷨8.8 ������
#include <iostream>
using namespace std;
#define  MAXSIZE  20          						//˳������󳤶�
typedef struct
{
	int key;
	char *otherinfo;
}ElemType;
//˳���Ĵ洢�ṹ                         
typedef struct
{
    ElemType *r;	         						//�洢�ռ�Ļ���ַ
    int  length;            						//˳�����
}SqList;											//˳�������

//���㷨8.7 ɸѡ��������
void HeapAdjust(SqList &L,int s,int m)
{ 
   //����r[s+1..m]�Ѿ��Ƕѣ���r[s..m]����Ϊ��r[s]Ϊ���Ĵ����
	ElemType rc;
	int j;
	rc=L.r[s];
    for(j=2*s;j<=m;j*=2)
	{												//��key�ϴ�ĺ��ӽ������ɸѡ
		if(j<m&&L.r[j].key<L.r[j+1].key) ++j;		//jΪkey�ϴ�ļ�¼���±�
        if(rc.key>=L.r[j].key) break;      			//rcӦ������λ��s��
		L.r[s]=L.r[j]; s=j; 
    }
	L.r[s]=rc;                          			//����
}													//HeapAdjust
								
void Create_Sq(SqList &L)
{
	int i,n;
	cout<<"���������ݸ�����������"<<MAXSIZE<<"����"<<endl;
	cin>>n;											//�������
	cout<<"����������:\n";
	while(n>MAXSIZE)
	{
		cout<<"�����������ޣ����ܳ���"<<MAXSIZE<<"������������"<<endl;
		cin>>n;
	}
	for(i=1;i<=n;i++)
	{
		cin>>L.r[i].key;
		L.length++;
	}
}

void CreatHeap(SqList &L)
{
	//����������L.r[1..n]���ɴ����
	int i,n;
	n=L.length;
	for(i=n/2;i>0;--i)       					//��������HeapAdjust 
		HeapAdjust(L,i,n);
}												//CreatHeap
void show(SqList L)
{
	int i;
	for(i=1;i<=L.length;i++)
		cout<<L.r[i].key<<endl;
}

void main()
{
	SqList L;
	L.r=new ElemType[MAXSIZE+1];
	L.length=0;
	Create_Sq(L);
	CreatHeap(L);
	cout<<"�����ɶѵ�����Ϊ��"<<endl;
	show(L);
}