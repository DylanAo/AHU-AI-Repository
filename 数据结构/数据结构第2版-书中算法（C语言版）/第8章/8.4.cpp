//�㷨8.4 ð������
#include <iostream>
using namespace std;
#define  MAXSIZE  20          			//˳������󳤶�
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

void BubbleSort(SqList &L)
{
	//��˳���L��ð������
	int m,j,flag;
	ElemType t;
    m=L.length-1; flag=1; 				//flag�������ĳһ�������Ƿ�������
    while((m>0)&&(flag==1))
	{
		flag=0;           				//flag��Ϊ0�������������û�з����������򲻻�ִ����һ������
        for(j=1;j<=m;j++)
			if(L.r[j].key>L.r[j+1].key) 
			{
				flag=1;					//flag��Ϊ1����ʾ�����������˽���
				t=L.r[j];L.r[j]=L.r[j+1];L.r[j+1]=t;	//����ǰ��������¼
			}							//if
		--m;
    }									//while
}										//BubbleSort

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
	BubbleSort(L);
	cout<<"�����Ľ��Ϊ��"<<endl;
	show(L);
}