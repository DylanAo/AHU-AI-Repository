//�㷨8.1 ֱ�Ӳ�������
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

void InsertSort(SqList &L)
{
   //��˳���L��ֱ�Ӳ�������
	int i,j;
	for(i=2;i<=L.length;++i)
		if(L.r[i].key<L.r[i-1].key)
		{   										//"<"���轫r[i]���������ӱ�
			L.r[0]=L.r[i];				 			//��������ļ�¼�ݴ浽��������
            L.r[i]=L.r[i-1];	            		//r[i-1]����
            for(j=i-2; L.r[0].key<L.r[j].key;--j)			//�Ӻ���ǰѰ�Ҳ���λ��
				L.r[j+1]=L.r[j];					//��¼������ƣ�ֱ���ҵ�����λ��
            L.r[j+1]=L.r[0];						//��r[0]��ԭr[i]�����뵽��ȷλ��
		}											//if
}													//InsertSort

void Create_Sq(SqList &L)
{
	int i,n;
	cout<<"���������ݸ�����������"<<MAXSIZE<<"����"<<endl;
	cin>>n;											//�������
	cout<<"����������������:\n";
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
	InsertSort(L);
	cout<<"�����Ľ��Ϊ��"<<endl;
	show(L);
}