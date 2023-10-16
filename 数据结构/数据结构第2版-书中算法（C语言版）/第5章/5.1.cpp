//算法5.1 中序遍历的递归算法
#include<iostream>
using namespace std;
typedef struct BiNode{				//二叉链表定义
	char data;
	struct BiNode *lchild,*rchild;
}BiTNode,*BiTree;

//用算法5.3 先序遍历的顺序建立二叉链表
void CreateBiTree(BiTree &T){	
	//按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
	char ch;
	cin >> ch;
	if(ch=='#')  T=NULL;			//递归结束，建空树
	else{							
		T=new BiTNode;
		T->data=ch;					//生成根结点
		CreateBiTree(T->lchild);	//递归创建左子树
		CreateBiTree(T->rchild);	//递归创建右子树
	}								//else
}									//CreateBiTree

void InOrderTraverse(BiTree T){  
	//中序遍历二叉树T的递归算法
	if(T){
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}

void main(){
	BiTree tree;
	cout<<"请输入建立二叉链表的序列：\n";
	CreateBiTree(tree);
	cout<<"中序遍历的结果为：\n";
	InOrderTraverse(tree);
	cout<<endl;
}
