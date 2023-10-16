//�㷨5.8 ��ͷ��������������
#include<iostream>
using namespace std;

//�������Ķ����������ʹ洢��ʾ
typedef struct BiThrNode
{				
	char data;						//���������
	struct BiThrNode *lchild,*rchild;	//���Һ���ָ��
	int LTag,RTag;
}BiThrNode,*BiThrTree;

//ȫ�ֱ���pre
BiThrNode *pre=new BiThrNode;

//���㷨5.3������������
void CreateBiTree(BiThrTree &T)
{	
	//�������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
	char ch;
	cin >> ch;
	if(ch=='#')  T=NULL;			//�ݹ������������
	else
	{							
		T=new BiThrNode;
		T->data=ch;					//���ɸ����
		CreateBiTree(T->lchild);	//�ݹ鴴��������
		CreateBiTree(T->rchild);	//�ݹ鴴��������
	}								//else
}									//CreateBiTree

//���㷨5.7 �Խ��PΪ������������������
void InThreading(BiThrTree p)
{
	//pre��ȫ�ֱ�������ʼ��ʱ���Һ���ָ��Ϊ�գ���������������㿪ʼ������
	if(p)
	{
		InThreading(p->lchild);             			//�������ݹ�������
		if(!p->lchild)
		{                   							//p������Ϊ��
			p->LTag=1;                                 	//��p����������
			p->lchild=pre; 								//p������ָ��ָ��pre��ǰ����
		} 
		else
			p->LTag=0;
		if(!pre->rchild)
		{												//pre���Һ���Ϊ��
			pre->RTag=1;                   				//��pre����������
			pre->rchild=p;                     			//pre���Һ���ָ��ָ��p����̣�
		}
		else
			pre->RTag=0;
		pre=p;                       					//����preָ��p��ǰ��
		InThreading(p->rchild);               			//�������ݹ�������
    }
}//InThreading

void InOrderThreading (BiThrTree &Thrt,BiThrTree T)
{
	//�������������T��������������������Thrtָ��ͷ���
	Thrt=new BiThrNode;          		//��ͷ���
	Thrt->LTag=0;                 		//ͷ��������ӣ������ǿգ���������Ϊ����
	Thrt->RTag=1;               		//ͷ�����Һ���ָ��Ϊ������
	Thrt->rchild=Thrt;            		//��ʼ��ʱ��ָ��ָ���Լ�
	if(!T)  Thrt->lchild=Thrt;      	//����Ϊ�գ�����ָ��Ҳָ���Լ�
	else
	{
	  Thrt->lchild=T;  pre=Thrt; 	 	//ͷ��������ָ�����pre��ֵָ��ͷ���
	  InThreading(T);              		//�����㷨5.7������TΪ���Ķ�������������������
	  pre->rchild=Thrt;          	  	//�㷨5.7������preΪ���ҽ�㣬pre��������ָ��ͷ���
	  pre->RTag=1;  	             
	  Thrt->rchild=pre;             	//ͷ����������ָ��pre
	}
} 										//InOrderThreading

void main()
{
	pre->RTag=1;
	pre->rchild=NULL;
	BiThrTree tree,Thrt;
	cout<<"�����뽨��������������У�\n";
	CreateBiTree(tree);
	InOrderThreading(Thrt,tree);
	cout<<"���������!\n";
}
