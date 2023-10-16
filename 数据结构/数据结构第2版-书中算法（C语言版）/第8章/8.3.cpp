//�㷨8.3 ϣ������
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

void ShellInsert(SqList &L,int dk)
{
	//��˳���L��һ��������dk��ϣ����������
	int i,j;
	for(i=dk+1;i<=L.length;++i)
		if(L.r[i].key<L.r[i-dk].key)
		{										//�轫L.r[i]�������������ӱ�
			L.r[0]=L.r[i];						//�ݴ���L.r[0]
			for(j=i-dk;j>0&& L.r[0].key<L.r[j].key;j-=dk)
				L.r[j+dk]=L.r[j];				//��¼���ƣ�ֱ���ҵ�����λ��
			L.r[j+dk]=L.r[0];					//��r[0]��ԭr[i]�����뵽��ȷλ��
		}										//for
}
												//ShellInsert
void ShellSort(SqList &L,int dt[ ],int t){
   //����������dt[0..t-1]��˳���L��t��ϣ������
	int k;
    for(k=0;k<t;++k)
        ShellInsert(L,dt[k]);			 		//һ������Ϊdt[t]��ϣ����������
}												//ShellSort

void Create_Sq(SqList &L)
{
	int i,n;
	cout<<"���������ݸ�����������"<<MAXSIZE<<"����"<<endl;
	cin>>n;										//�������
	cout<<"���������������ݣ�\n";
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
	
	int i,t;//��������ĳ���
	int *dt=new int[MAXSIZE];//��������
	cout<<"����������������\n";
	cin>>t;
	for(i=0;i<t;i++)
	{
		cout<<"��"<<i+1<<"������:\n";
		cin>>dt[i];
	}
	ShellSort(L,dt,t);
	cout<<"�����Ľ��Ϊ��"<<endl;
	show(L);
}