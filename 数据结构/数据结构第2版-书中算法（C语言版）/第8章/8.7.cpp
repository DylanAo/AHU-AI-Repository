//算法8.7 筛选法调整堆
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

void HeapAdjust(SqList &L,int s,int m)
{ 
   //假设r[s+1..m]已经是堆，将r[s..m]调整为以r[s]为根的大根堆
	ElemType rc;
	int j;
	rc=L.r[s];
    for(j=2*s;j<=m;j*=2)
	{												//沿key较大的孩子结点向下筛选
		if(j<m&&L.r[j].key<L.r[j+1].key) ++j;		//j为key较大的记录的下标
        if(rc.key>=L.r[j].key) break;      			//rc应插入在位置s上
		L.r[s]=L.r[j]; s=j; 
    }
	L.r[s]=rc;                          			//插入
}													//HeapAdjust
								
void Create_Sq(SqList &L)
{
	int i,n;
	cout<<"请输入数据个数，不超过"<<MAXSIZE<<"个。"<<endl;
	cin>>n;											//输入个数
	cout<<"请输入待调整的数据:\n";
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
	HeapAdjust(L,1,L.length);
	cout<<"调整后的结果为："<<endl;
	show(L);
}