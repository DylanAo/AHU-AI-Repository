//算法5.9 遍历中序线索二叉树
#include<iostream>
using namespace std;

//二叉树的二叉线索类型存储表示
typedef struct BiThrNode
{				
	char data;							//结点数据域
	struct BiThrNode *lchild,*rchild;	//左右孩子指针
	int LTag,RTag;
}BiThrNode,*BiThrTree;

//全局变量pre
BiThrNode *pre=new BiThrNode;

//用算法5.3建立二叉链表
void CreateBiTree(BiThrTree &T)
{	
	//按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
	char ch;
	cin >> ch;
	if(ch=='#')  T=NULL;			//递归结束，建空树
	else
	{							
		T=new BiThrNode;
		T->data=ch;					//生成根结点
		CreateBiTree(T->lchild);	//递归创建左子树
		CreateBiTree(T->rchild);	//递归创建右子树
	}								//else
}									//CreateBiTree

//用算法5.7以结点P为根的子树中序线索化
void InThreading(BiThrTree p)
{
	//pre是全局变量，初始化时其右孩子指针为空，便于在树的最左点开始建线索
	if(p)
	{
		InThreading(p->lchild);             			//左子树递归线索化
		if(!p->lchild)
		{                   							//p的左孩子为空
			p->LTag=1;                                 	//给p加上左线索
			p->lchild=pre; 								//p的左孩子指针指向pre（前驱）
		} 
		else
			p->LTag=0;
		if(!pre->rchild)
		{												//pre的右孩子为空
			pre->RTag=1;                   				//给pre加上右线索
			pre->rchild=p;                     			//pre的右孩子指针指向p（后继）
		}
		else
			pre->RTag=0;
		pre=p;                       					//保持pre指向p的前驱
		InThreading(p->rchild);               			//右子树递归线索化
    }
}//InThreading

//用算法5.8带头结点的中序线索化
void InOrderThreading (BiThrTree &Thrt,BiThrTree T)
{
	//中序遍历二叉树T，并将其中序线索化，Thrt指向头结点
	Thrt=new BiThrNode;          		//建头结点
	Thrt->LTag=0;                 		//头结点有左孩子，若树非空，则其左孩子为树根
	Thrt->RTag=1;               		//头结点的右孩子指针为右线索
	Thrt->rchild=Thrt;            		//初始化时右指针指向自己
	if(!T)  Thrt->lchild=Thrt;      	//若树为空，则左指针也指向自己
	else
	{
	  Thrt->lchild=T;  pre=Thrt; 	 	//头结点的左孩子指向根，pre初值指向头结点
	  InThreading(T);              		//调用算法5.7，对以T为根的二叉树进行中序线索化
	  pre->rchild=Thrt;          	  	//算法5.7结束后，pre为最右结点，pre的右线索指向头结点
	  pre->RTag=1;  	             
	  Thrt->rchild=pre;             	//头结点的右线索指向pre
	}
} 										//InOrderThreading

void InOrderTraverse_Thr(BiThrTree T)
{ 
    //T指向头结点，头结点的左链lchild指向根结点，可参见线索化算法5.8。
    //中序遍历二叉线索树T的非递归算法，对每个数据元素直接输出
	BiThrTree p;
	p=T->lchild;                             		//p指向根结点
    while(p!=T)										//空树或遍历结束时，p==T
	{                            					
		while(p->LTag==0)							//沿左孩子向下
			p=p->lchild;							//访问其左子树为空的结点
		cout<<p->data;                      		
		while(p->RTag==1&&p->rchild!=T)
		{
			p=p->rchild;							//沿右线索访问后继结点
			cout<<p->data;     						 
		}
		p=p->rchild;
    }
}													//InOrderTraverse_Thr

void main()
{
	pre->RTag=1;
	pre->rchild=NULL;
	BiThrTree tree,Thrt;
	cout<<"请输入建立二叉链表的序列：\n";
	CreateBiTree(tree);
	InOrderThreading(Thrt,tree);
	cout<<"中序遍历线索二叉树的结果为：\n";
	InOrderTraverse_Thr(Thrt);
	cout<<endl;
}
