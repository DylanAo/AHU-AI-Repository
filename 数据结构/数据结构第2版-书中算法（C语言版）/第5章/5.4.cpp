//算法5.4 复制二叉树
#include<iostream>
using namespace std;

//二叉树的二叉链表存储表示
typedef struct BiNode
{				
	char data;						//结点数据域
	struct BiNode *lchild,*rchild;	//左右孩子指针
}BiTNode,*BiTree;

//用算法5.3建立二叉链表
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

void Copy(BiTree T, BiTree &NewT)
{ 
	if(T==NULL ) 
	{   							//如果是空树，递归结束
		NewT=NULL; 
		return; 
	} 
	else
	{
		NewT=new BiTNode;
		NewT->data= T->data;					//复制根结点
		Copy(T->lchild, NewT->lchild);    		//递归复制左子树
		Copy(T->rchild, NewT->rchild);   		//递归复制右子树
	}											//else
}												//CopyBiTree

//用算法5.1 中序遍历的递归算法							
void InOrderTraverse(BiTree T)
{  
	//中序遍历二叉树T的递归算法
	if(T){
		InOrderTraverse(T->lchild);
		cout << T->data;
		InOrderTraverse(T->rchild);
	}
}
void main()
{
	BiTree tree,new_tree;
	cout<<"请输入建立二叉树的序列：\n";
	CreateBiTree(tree);
	Copy(tree,new_tree);
	cout<<"复制得到的新树的中序序列：\n";
	InOrderTraverse(new_tree);
	cout<<endl;
}
