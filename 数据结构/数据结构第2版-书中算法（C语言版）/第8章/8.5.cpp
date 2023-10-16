//算法8.5 快速排序
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


int Partition(SqList &L,int low,int high)
{ 
	//对顺序表L中的子表r[low..high]进行一趟排序，返回枢轴位置
	int pivotkey;
	L.r[0]=L.r[low];                    	//用子表的第一个记录做枢轴记录
	pivotkey=L.r[low].key;		   			//枢轴记录关键字保存在pivotkey中
	while(low<high)
	{										//从表的两端交替地向中间扫描
		while(low<high&&L.r[high].key>=pivotkey) --high;
		L.r[low]=L.r[high];					//将比枢轴记录小的记录移到低端
		while(low<high&&L.r[low].key<=pivotkey) ++low;
		L.r[high]=L.r[low];					//将比枢轴记录大的记录移到高端
	}//while
	L.r[low]=L.r[0];						//枢轴记录到位
	return  low;							//返回枢轴位置
}//Partition

void QSort(SqList &L,int low,int high)
{	//调用前置初值：low=1; high=L.length;
    //对顺序表L中的子序列L.r[low..high]做快速排序
	int pivotloc;
    if(low<high)
	{										//长度大于1
       pivotloc=Partition(L,low,high); 		//将L.r[low..high]一分为二，pivotloc是枢轴位置
       QSort(L,low,pivotloc-1);				//对左子表递归排序
       QSort(L,pivotloc+1,high);        	//对右子表递归排序
	}
}											//QSort

void QuickSort(SqList &L)
{
   //对顺序表L做快速排序
   QSort(L,1,L.length);
}											//QuickSort
								
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
	QuickSort(L);
	cout<<"排序后的结果为："<<endl;
	show(L);
}