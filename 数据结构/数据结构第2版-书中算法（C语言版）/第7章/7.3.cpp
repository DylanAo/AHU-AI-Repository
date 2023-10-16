//算法7.3　折半查找



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
   // 在有序表ST中折半查找其关键字等于key的数据元素。若找到，则函数值为
   // 该元素在表中的位置，否则为0
   int low=1,high=ST.length;							//置查找区间初值
   int  mid;
   while(low<=high) {
	   mid=(low+high) / 2;
      if (key==ST.R[mid].key)  return mid;      		//找到待查元素
      else if (key<ST.R[mid].key)  high = mid -1;		//继续在前一子表进行查找
      else  low =mid +1;                       			//继续在后一子表进行查找
   }//while
   return 0;										//表中不存在待查元素
}// Search_Bin

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
	result=Search_Bin(ST, testkey1);
	Show_End(result,testkey1);
	result=Search_Bin(ST, testkey2);
	Show_End(result,testkey2);
}