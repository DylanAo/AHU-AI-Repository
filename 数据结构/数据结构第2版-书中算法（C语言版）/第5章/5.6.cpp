//�㷨5.6 ͳ�ƶ������н��ĸ���
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

int NodeCount(BiTree T)
{
     if(T==NULL) return 0;  			// ����ǿ������������Ϊ0���ݹ����
     else return NodeCount(T->lchild)+ NodeCount(T->rchild) +1;
     //���������Ϊ�������Ľ�����+�������Ľ�����+1
} 

void main()
{
	BiTree tree;
	cout<<"�����뽨��������������У�\n";
	CreateBiTree(tree);
	cout<<"������Ϊ��"<<NodeCount(tree)<<endl;

}
