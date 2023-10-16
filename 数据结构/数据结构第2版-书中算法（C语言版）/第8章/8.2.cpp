//算法8.2 折半插入排序
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
}SqList;											//顺序表

void BInsertSort(SqList &L){
	//对顺序表L做折半插入排序
	int i,j,low,high,m;
	for(i=2;i<=L.length;++i)
	{
		L.r[0]=L.r[i];          					//将待插入的记录暂存到监视哨中
		low=1; high=i-1;        					//置查找区间初值
		while(low<=high)
		{											//在r[low..high]中折半查找插入的位置
			m=(low+high)/2;             			//折半
			if(L.r[0].key<L.r[m].key)  high=m-1;	//插入点在前一子表
			else  low=m+1;					   		//插入点在后一子表
		}//while
		for(j=i-1;j>=high+1;--j)  L.r[j+1]=L.r[j];	//记录后移
		L.r[high+1]=L.r[0];							//将r[0]即原r[i]，插入到正确位置
    }												//for
}													//BInsertSort

void Create_Sq(SqList &L)
{
	int i,n;
	cout<<"请输入数据个数，不超过"<<MAXSIZE<<"个。"<<endl;
	cin>>n;											//输入个数
	cout<<"请输入待排序的数据：\n";
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
	BInsertSort(L);
	cout<<"排序后的结果为："<<endl;
	show(L);
}