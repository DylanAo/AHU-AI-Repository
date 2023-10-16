//�㷨8.2 �۰��������
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
}SqList;											//˳���

void BInsertSort(SqList &L){
	//��˳���L���۰��������
	int i,j,low,high,m;
	for(i=2;i<=L.length;++i)
	{
		L.r[0]=L.r[i];          					//��������ļ�¼�ݴ浽��������
		low=1; high=i-1;        					//�ò��������ֵ
		while(low<=high)
		{											//��r[low..high]���۰���Ҳ����λ��
			m=(low+high)/2;             			//�۰�
			if(L.r[0].key<L.r[m].key)  high=m-1;	//�������ǰһ�ӱ�
			else  low=m+1;					   		//������ں�һ�ӱ�
		}//while
		for(j=i-1;j>=high+1;--j)  L.r[j+1]=L.r[j];	//��¼����
		L.r[high+1]=L.r[0];							//��r[0]��ԭr[i]�����뵽��ȷλ��
    }												//for
}													//BInsertSort

void Create_Sq(SqList &L)
{
	int i,n;
	cout<<"���������ݸ�����������"<<MAXSIZE<<"����"<<endl;
	cin>>n;											//�������
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
	BInsertSort(L);
	cout<<"�����Ľ��Ϊ��"<<endl;
	show(L);
}