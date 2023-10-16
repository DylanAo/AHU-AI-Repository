//算法8.11 归并排序
#include <iostream>
using namespace std;
#define  MAXSIZE  20          						//顺序表的最大长度
typedef struct
{
	int key;
	char *otherinfo;
}RedType;

typedef struct
{
	RedType *r;
	int length;
}SqList;
																		
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

//用算法8.10 相邻两个有序子序列的归并
void Merge(RedType R[],RedType T[],int low,int mid,int high)
{ 
   //将有序表R[low..mid]和R[mid+1..high]归并为有序表T[low..high] 
	int i,j,k;
	i=low; j=mid+1;k=low; 
    while(i<=mid&&j<=high)
	{                 	
		//将R中记录由小到大地并入T中 
		if(R[i].key<=R[j].key) T[k++]=R[i++]; 
        else T[k++]=R[j++]; 
	} 
	while(i<=mid)                            		//将剩余的R[low..mid]复制到T中 
		T[k++]=R[i++];                 
	while(j<=high)                           		//将剩余的R[j.high]复制到T中 
		T[k++]=R[j++];                       
}//Merge 

void MSort(RedType R[],RedType T[],int low,int high)
{ 
	//R[low..high]归并排序后放入T[low..high]中 
	int mid;
	RedType *S=new RedType[MAXSIZE];
    if(low==high) T[low]=R[low]; 
    else
	{ 
		mid=(low+high)/2;       					//将当前序列一分为二，求出分裂点mid 
        MSort(R,S,low,mid);							//对子序列R[low..mid] 递归归并排序，结果放入S[low..mid] 
        MSort(R,S,mid+1,high);						//对子序列R[mid+1..high] 递归归并排序，结果放入S[mid+1..high] 
        Merge(S,T,low,mid,high);					//将S[low..mid]和S [mid+1..high]归并到T[low..high]  
    }//else 
}// MSort 
 
void MergeSort(SqList &L)
{ 
	//对顺序表L做归并排序 
    MSort(L.r,L.r,1,L.length); 
}//MergeSort 
void show(SqList L)
{
	int i;
	for(i=1;i<=L.length;i++)
		cout<<L.r[i].key<<endl;
}
void main()
{
	SqList R;
	R.r=new RedType[MAXSIZE+1];
	R.length=0;
	Create_Sq(R);
	MergeSort(R);
	cout<<"排序后的结果为："<<endl;
	show(R);
}