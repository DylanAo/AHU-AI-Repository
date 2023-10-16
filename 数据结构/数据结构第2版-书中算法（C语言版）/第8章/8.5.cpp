//�㷨8.5 ��������
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


int Partition(SqList &L,int low,int high)
{ 
	//��˳���L�е��ӱ�r[low..high]����һ�����򣬷�������λ��
	int pivotkey;
	L.r[0]=L.r[low];                    	//���ӱ�ĵ�һ����¼�������¼
	pivotkey=L.r[low].key;		   			//�����¼�ؼ��ֱ�����pivotkey��
	while(low<high)
	{										//�ӱ�����˽�������м�ɨ��
		while(low<high&&L.r[high].key>=pivotkey) --high;
		L.r[low]=L.r[high];					//���������¼С�ļ�¼�Ƶ��Ͷ�
		while(low<high&&L.r[low].key<=pivotkey) ++low;
		L.r[high]=L.r[low];					//���������¼��ļ�¼�Ƶ��߶�
	}//while
	L.r[low]=L.r[0];						//�����¼��λ
	return  low;							//��������λ��
}//Partition

void QSort(SqList &L,int low,int high)
{	//����ǰ�ó�ֵ��low=1; high=L.length;
    //��˳���L�е�������L.r[low..high]����������
	int pivotloc;
    if(low<high)
	{										//���ȴ���1
       pivotloc=Partition(L,low,high); 		//��L.r[low..high]һ��Ϊ����pivotloc������λ��
       QSort(L,low,pivotloc-1);				//�����ӱ�ݹ�����
       QSort(L,pivotloc+1,high);        	//�����ӱ�ݹ�����
	}
}											//QSort

void QuickSort(SqList &L)
{
   //��˳���L����������
   QSort(L,1,L.length);
}											//QuickSort
								
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
	QuickSort(L);
	cout<<"�����Ľ��Ϊ��"<<endl;
	show(L);
}