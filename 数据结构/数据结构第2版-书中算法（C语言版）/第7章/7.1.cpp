//算法7.1　顺序查找
#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 1;

typedef struct{
	int key;//关键字域
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
		cout<<"初始化错误";
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
    //在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为
    //该元素在表中的位置，否则为0
     for (int i=ST.length; i>=1; --i)  
             if (ST.R[i].key==key) return i;		//从后往前找        
     return 0;
   }// Search_Seq

void Show_End(int result,int testkey)
{
	if(result==0)
		cout<<"未找到"<<testkey<<endl;
	else
		cout<<"找到"<<testkey<<"位置为"<<result<<endl;
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