//�㷨5.10 ����շ�����
#include<iostream>
using namespace std;
typedef struct
{
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;

void Select(HuffmanTree HT,int len,int &s1,int &s2)
{
	int i,min1=0x3f3f3f3f,min2=0x3f3f3f3f;//�ȸ������ֵ
	for(i=1;i<=len;i++)
	{
		if(HT[i].weight<min1&&HT[i].parent==0)
		{
			min1=HT[i].weight;
			s1=i;
		}	
	}
	int temp=HT[s1].weight;//��ԭֵ���������Ȼ���ȸ������ֵ����ֹs1���ظ�ѡ��
	HT[s1].weight=0x3f3f3f3f;
	for(i=1;i<=len;i++)
	{
		if(HT[i].weight<min2&&HT[i].parent==0)
		{
			min2=HT[i].weight;
			s2=i;
		}
	}
	HT[s1].weight=temp;//�ָ�ԭ����ֵ
}

void CreatHuffmanTree(HuffmanTree &HT,int n)
{
	//����շ�����HT
	int m,s1,s2,i;
	if(n<=1) return;
	m=2*n-1;
	HT=new HTNode[m+1];  		//0�ŵ�Ԫδ�ã�������Ҫ��̬����m+1����Ԫ��HT[m]��ʾ�����   
	for(i=1;i<=m;++i)        	//��1~m�ŵ�Ԫ�е�˫�ס����ӣ��Һ��ӵ��±궼��ʼ��Ϊ0   
	   { HT[i].parent=0;  HT[i].lchild=0;  HT[i].rchild=0; }
	cout<<"������Ҷ�ӽ���Ȩֵ��\n";
	for(i=1;i<=n;++i)        	//����ǰn����Ԫ��Ҷ�ӽ���Ȩֵ  
		cin>>HT[i].weight;  
	/*�D�D�D�D�D�D�D�D�D�D��ʼ���������������濪ʼ�����շ������D�D�D�D�D�D�D�D�D�D*/ 
	for(i=n+1;i<=m;++i) 
	{  	//ͨ��n-1�ε�ѡ��ɾ�����ϲ��������շ�����
		Select(HT,i-1,s1,s2);
		//��HT[k](1��k��i-1)��ѡ��������˫����Ϊ0��Ȩֵ��С�Ľ��,
		// ������������HT�е����s1��s2
		HT[s1].parent=i; 	
		HT[s2].parent=i;   
		//�õ��½��i����ɭ����ɾ��s1��s2����s1��s2��˫������0��Ϊi
		HT[i].lchild=s1;   
		HT[i].rchild=s2 ;							//s1,s2�ֱ���Ϊi�����Һ���
		HT[i].weight=HT[s1].weight+HT[s2].weight; 	//i ��ȨֵΪ���Һ���Ȩֵ֮��
	}												//for
 }													// CreatHuffmanTree

void main()
{
	HuffmanTree HT;
	int n;
	cout<<"������Ҷ�ӽ��ĸ�����\n";
	cin>>n;
	CreatHuffmanTree(HT,n);
	cout<<"��������������ϣ�\n";
}
