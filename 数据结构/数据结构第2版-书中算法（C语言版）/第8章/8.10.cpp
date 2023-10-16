//算法8.10 相邻两个有序子序列的归并
#include <iostream>
using namespace std;
#define  MAXSIZE  20          						//顺序表的最大长度
typedef struct
{
	int key;
	char *otherinfo;
}RedType;
																		
void Create_Sq(RedType *R)
{
	int i,n;
	cout<<"请输入数据个数，不超过"<<MAXSIZE<<"个。"<<endl;
	cin>>n;											//输入个数
	cout<<"请输入待合并的数据:\n";
	while(n>MAXSIZE)
	{
		cout<<"个数超过上限，不能超过"<<MAXSIZE<<"，请重新输入"<<endl;
		cin>>n;
	}
	for(i=0;i<n;i++)
		cin>>R[i].key;
}

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
void show(RedType *T,int low,int high)
{
	int i;
	for(i=low;i<=high;i++)
		cout<<T[i].key<<endl;
}
void main()
{
	RedType *R=new RedType[MAXSIZE];
	RedType *T=new RedType[MAXSIZE];
	Create_Sq(R);
	int low,mid,high;
	cout<<"请输入第一个有序子序列的起点、终点下标和第二个有序子序列的终点下标：\n";
	cin>>low>>mid>>high;
	Merge(R,T,low,mid,high);
	cout<<"合并后的结果为："<<endl;
	show(T,low,high);
}