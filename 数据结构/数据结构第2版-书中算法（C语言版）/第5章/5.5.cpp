//�㷨5.5 ��������������
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

int Depth(BiTree T)
{ 
	int m,n;
	if(T == NULL ) return 0;        //����ǿ��������Ϊ0���ݹ����
	else 
	{							
		m=Depth(T->lchild);			//�ݹ��������������ȼ�Ϊm
		n=Depth(T->rchild);			//�ݹ��������������ȼ�Ϊn
		if(m>n) return(m+1);		//�����������Ϊm ��n�Ľϴ��߼�1
		else return (n+1);
	}
}

void main()
{
	BiTree tree;
	cout<<"�����뽨��������������У�\n";
	CreateBiTree(tree);
	cout<<"�������Ϊ��"<<Depth(tree)<<endl;

}
