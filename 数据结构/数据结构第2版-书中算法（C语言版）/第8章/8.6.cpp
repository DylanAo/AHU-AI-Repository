//�㷨8.6 ��ѡ������
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

void SelectSort(SqList &L) 
{ 
   //��˳���L����ѡ������
	int i,j,k;
	ElemType t;
    for(i=1;i<L.length;++i) 
	{  												//��L.r[i..L.length] ��ѡ��ؼ�����С�ļ�¼
		k=i;                 
        for(j=i+1;j<=L.length;++j)
			if(L.r[j].key<L.r[k].key)  k=j;			//kָ����������йؼ�����С�ļ�¼
		if(k!=i) {t=L.r[i];L.r[i]=L.r[k];L.r[k]=t;} //����r[i]��r[k]        
     }												//for  
}													// SelectSort
								
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
	SelectSort(L);
	cout<<"�����Ľ��Ϊ��"<<endl;
	show(L);
}