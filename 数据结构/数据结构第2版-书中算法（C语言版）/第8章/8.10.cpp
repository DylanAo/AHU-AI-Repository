//�㷨8.10 �����������������еĹ鲢
#include <iostream>
using namespace std;
#define  MAXSIZE  20          						//˳������󳤶�
typedef struct
{
	int key;
	char *otherinfo;
}RedType;
																		
void Create_Sq(RedType *R)
{
	int i,n;
	cout<<"���������ݸ�����������"<<MAXSIZE<<"����"<<endl;
	cin>>n;											//�������
	cout<<"��������ϲ�������:\n";
	while(n>MAXSIZE)
	{
		cout<<"�����������ޣ����ܳ���"<<MAXSIZE<<"������������"<<endl;
		cin>>n;
	}
	for(i=0;i<n;i++)
		cin>>R[i].key;
}

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
	cout<<"�������һ�����������е���㡢�յ��±�͵ڶ������������е��յ��±꣺\n";
	cin>>low>>mid>>high;
	Merge(R,T,low,mid,high);
	cout<<"�ϲ���Ľ��Ϊ��"<<endl;
	show(T,low,high);
}