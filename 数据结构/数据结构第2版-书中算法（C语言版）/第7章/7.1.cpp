//�㷨7.1��˳�����
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
	int j=0;
	for(int i=0;i<MAXSIZE;i++)
	{
		L.R[i].key=j;
		L.length++;
		j++;
	}
	return 1;
}

int Search_Seq(SSTable ST, int key){
    //��˳���ST��˳�������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ
    //��Ԫ���ڱ��е�λ�ã�����Ϊ0
     for (int i=ST.length; i>=1; --i)  
             if (ST.R[i].key==key) return i;		//�Ӻ���ǰ��        
     return 0;
   }// Search_Seq

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
	result=Search_Seq(ST, testkey1);
	Show_End(result,testkey1);
	result=Search_Seq(ST, testkey2);
	Show_End(result,testkey2);
}