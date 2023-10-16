//�㷨5.4 ���ƶ�����
#include<iostream>
using namespace std;

//�������Ķ�������洢��ʾ
typedef struct BiNode
{				
	char data;						//���������
	struct BiNode *lchild,*rchild;	//���Һ���ָ��
}BiTNode,*BiTree;

//���㷨5.3������������
void CreateBiTree(BiTree &T)
{	
	//�������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
	char ch;
	cin >> ch;
	if(ch=='#')  T=NULL;			//�ݹ������������
	else{							
		T=new BiTNode;
		T->data=ch;					//���ɸ����
		CreateBiTree(T->lchild);	//�ݹ鴴��������
		CreateBiTree(T->rchild);	//�ݹ鴴��������
	}								//else
}									//CreateBiTree

void Copy(BiTree T, BiTree &NewT)
{ 
	if(T==NULL ) 
	{   							//����ǿ������ݹ����
		NewT=NULL; 
		return; 
	} 
	else
	{
		NewT=new BiTNode;
		NewT->data= T->data;					//���Ƹ����
		Copy(T->lchild, NewT->lchild);    		//�ݹ鸴��������
		Copy(T->rchild, NewT->rchild);   		//�ݹ鸴��������
	}											//else
}												//CopyBiTree

//���㷨5.1 ��������ĵݹ��㷨							
void InOrderTraverse(BiTree T)
{  
	//�������������T�ĵݹ��㷨
	if(T){
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}
void main()
{
	BiTree tree,new_tree;
	cout<<"�����뽨�������������У�\n";
	CreateBiTree(tree);
	Copy(tree,new_tree);
	cout<<"���Ƶõ����������������У�\n";
	InOrderTraverse(new_tree);
	cout<<endl;
}
