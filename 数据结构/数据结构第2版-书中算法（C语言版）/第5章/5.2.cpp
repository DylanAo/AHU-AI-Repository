//算法5.2 中序遍历的非递归算法
#include<iostream>
using namespace std;

//二叉树的二叉链表存储表示
typedef struct BiNode
{				
	char data;						//结点数据域
	struct BiNode *lchild,*rchild;	//左右孩子指针
}BiTNode,*BiTree;

//链栈的定义
typedef struct StackNode
{
	BiTNode data;
	struct StackNode *next;
}StackNode,*LinkStack;

//用算法5.3 先序遍历的顺序建立二叉链表
void CreateBiTree(BiTree &T)
{	
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

void InitStack(LinkStack &S)
{
	//构造一个空栈S，栈顶指针置空
	S=NULL;
}

bool StackEmpty(LinkStack S)
{
	if(!S)
		return true;
	return false;
}

void Push(LinkStack &S,BiTree e)
{
	//在栈顶插入元素*e
	StackNode *p=new StackNode;
	p->data=*e;
	p->next=S;
	S=p;
}

void Pop(LinkStack &S,BiTree e)
{
	if(S!=NULL)//原书上写的是if(S==NULL)return ERROR;
	{	
		*e=S->data;
		StackNode *p=S;
		S=S->next;
		delete p;
	}
} 
  
void InOrderTraverse1(BiTree T)
{ 
  // 中序遍历二叉树T的非递归算法
	LinkStack S; BiTree p;
	BiTree q=new BiTNode;
	InitStack(S); p=T;
	while(p||!StackEmpty(S))
	{
		if(p) 
		{            				
			Push(S,p);				//p非空根指针进栈，遍历左子树
			p=p->lchild;
		}       
		else
		{             				
			Pop(S,q);               //p为空根指针退栈，访问根结点，遍历右子树
			cout<<q->data;
			p=q->rchild; 
		}
	}								// while
}									// InOrderTraverse

void main()
{
	BiTree tree;
	cout<<"请输入建立二叉链表的序列：\n";
	CreateBiTree(tree);
	cout<<"中序遍历的结果为：\n";
	InOrderTraverse1(tree);
	cout<<endl;
}
