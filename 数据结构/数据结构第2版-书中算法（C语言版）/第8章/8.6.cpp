//算法8.6 简单选择排序
#include <iostream>
using namespace std;
#define  MAXSIZE  20          						//顺序表的最大长度
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

void SelectSort(SqList &L) 
{ 
   //对顺序表L做简单选择排序
	int i,j,k;
	ElemType t;
    for(i=1;i<L.length;++i) 
	{  												//在L.r[i..L.length] 中选择关键字最小的记录
		k=i;                 
        for(j=i+1;j<=L.length;++j)
			if(L.r[j].key<L.r[k].key)  k=j;			//k指向此趟排序中关键字最小的记录
		if(k!=i) {t=L.r[i];L.r[i]=L.r[k];L.r[k]=t;} //交换r[i]与r[k]        
     }												//for  
}													// SelectSort
								
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
	SelectSort(L);
	cout<<"排序后的结果为："<<endl;
	show(L);
}