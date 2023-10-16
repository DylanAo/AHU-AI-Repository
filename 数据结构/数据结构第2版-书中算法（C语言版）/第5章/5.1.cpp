//�㷨5.1 ��������ĵݹ��㷨
#include<iostream>
using namespace std;
typedef struct BiNode{				//����������
	char data;
	struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

//���㷨5.3 ���������˳������������
void CreateBiTree(BiTree &T){	
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

void InOrderTraverse(BiTree T){  
	//�������������T�ĵݹ��㷨
	if(T){
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}

void main(){
	BiTree tree;
	cout<<"�����뽨��������������У�\n";
	CreateBiTree(tree);
	cout<<"��������Ľ��Ϊ��\n";
	InOrderTraverse(tree);
	cout<<endl;
}
