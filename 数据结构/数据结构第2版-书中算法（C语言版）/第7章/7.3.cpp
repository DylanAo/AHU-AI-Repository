//�㷨7.3���۰����



#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1;

typedef struct{
	int key;//�ؼ�����
}ElemType;

typedef struct{
	ElemType *R;
	int length;
}SSTable;

int InitList_SSTable(SSTable &L)
{
	L.R=new ElemType[MAXSIZE];
	if (!L.R)
	{
		cout<<"��ʼ������";
		return 0;
	}
	L.length=0;
	return OK;
}

int Insert_SSTable(SSTable &L) 
{
	int j=1;
	for(int i=1;i<MAXSIZE;i++)
	{
		L.R[i].key=j;
		L.length++;
		j++;
	}
	return 1;
}

int Search_Bin(SSTable ST,int key) {
   // �������ST���۰������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ
   // ��Ԫ���ڱ��е�λ�ã�����Ϊ0
   int low=1,high=ST.length;							//�ò��������ֵ
   int  mid;
   while(low<=high) {
	   mid=(low+high) / 2;
      if (key==ST.R[mid].key)  return mid;      		//�ҵ�����Ԫ��
      else if (key<ST.R[mid].key)  high = mid -1;		//������ǰһ�ӱ���в���
      else  low =mid +1;                       			//�����ں�һ�ӱ���в���
   }//while
   return 0;										//���в����ڴ���Ԫ��
}// Search_Bin

void Show_End(int result,int testkey)
{
	if(result==0)
		cout<<"δ�ҵ�"<<testkey<<endl;
	else
		cout<<"�ҵ�"<<testkey<<"λ��Ϊ"<<result<<endl;
	return;
}

void main()
{
	SSTable ST;
	InitList_SSTable(ST);
	Insert_SSTable(ST);
	int testkey1=7,testkey2=200;
	int result;
	result=Search_Bin(ST, testkey1);
	Show_End(result,testkey1);
	result=Search_Bin(ST, testkey2);
	Show_End(result,testkey2);
}