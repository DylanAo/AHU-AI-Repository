//�㷨8.11 �鲢����
#include <iostream>
using namespace std;
#define  MAXSIZE  20          						//˳������󳤶�
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
	cout<<"���������ݸ�����������"<<MAXSIZE<<"����"<<endl;
	cin>>n;											//�������
	cout<<"����������������:\n";
	while(n>MAXSIZE)
	{
		cout<<"�����������ޣ����ܳ���"<<MAXSIZE<<"������������"<<endl;
		cin>>n;
	}
	for(i=1;i<=n;i++)
	{
		cin>>L.r[i].key;
		L.length++;
	}
}

//���㷨8.10 �����������������еĹ鲢
void Merge(RedType R[],RedType T[],int low,int mid,int high)
{ 
   //�������R[low..mid]��R[mid+1..high]�鲢Ϊ�����T[low..high] 
	int i,j,k;
	i=low; j=mid+1;k=low; 
    while(i<=mid&&j<=high)
	{                 	
		//��R�м�¼��С����ز���T�� 
		if(R[i].key<=R[j].key) T[k++]=R[i++]; 
        else T[k++]=R[j++]; 
	} 
	while(i<=mid)                            		//��ʣ���R[low..mid]���Ƶ�T�� 
		T[k++]=R[i++];                 
	while(j<=high)                           		//��ʣ���R[j.high]���Ƶ�T�� 
		T[k++]=R[j++];                       
}//Merge 

void MSort(RedType R[],RedType T[],int low,int high)
{ 
	//R[low..high]�鲢��������T[low..high]�� 
	int mid;
	RedType *S=new RedType[MAXSIZE];
    if(low==high) T[low]=R[low]; 
    else
	{ 
		mid=(low+high)/2;       					//����ǰ����һ��Ϊ����������ѵ�mid 
        MSort(R,S,low,mid);							//��������R[low..mid] �ݹ�鲢���򣬽������S[low..mid] 
        MSort(R,S,mid+1,high);						//��������R[mid+1..high] �ݹ�鲢���򣬽������S[mid+1..high] 
        Merge(S,T,low,mid,high);					//��S[low..mid]��S [mid+1..high]�鲢��T[low..high]  
    }//else 
}// MSort 
 
void MergeSort(SqList &L)
{ 
	//��˳���L���鲢���� 
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
	cout<<"�����Ľ��Ϊ��"<<endl;
	show(R);
}