//算法8.4 冒泡排序
#include <iostream>
using namespace std;
#define  MAXSIZE  20          			//顺序表的最大长度
typedef struct
{
	int key;
	char *otherinfo;
}ElemType;
//顺序表的存储结构                         
typedef struct
{
    ElemType *r;	         						//存储空间的基地址
    int  length;            						//顺序表长度
}SqList;											//顺序表类型

void BubbleSort(SqList &L)
{
	//对顺序表L做冒泡排序
	int m,j,flag;
	ElemType t;
    m=L.length-1; flag=1; 				//flag用来标记某一趟排序是否发生交换
    while((m>0)&&(flag==1))
	{
		flag=0;           				//flag置为0，如果本趟排序没有发生交换，则不会执行下一趟排序
        for(j=1;j<=m;j++)
			if(L.r[j].key>L.r[j+1].key) 
			{
				flag=1;					//flag置为1，表示本趟排序发生了交换
				t=L.r[j];L.r[j]=L.r[j+1];L.r[j+1]=t;	//交换前后两个记录
			}							//if
		--m;
    }									//while
}										//BubbleSort

void Create_Sq(SqList &L)
{
	int i,n;
	cout<<"请输入数据个数，不超过"<<MAXSIZE<<"个。"<<endl;
	cin>>n;											//输入个数
	cout<<"请输入待排序的数据:\n";
	while(n>MAXSIZE)
	{
		cout<<"个数超过上限，不能超过"<<MAXSIZE<<"，请重新输入"<<endl;
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
	cout<<"排序后的结果为："<<endl;
	show(L);
}