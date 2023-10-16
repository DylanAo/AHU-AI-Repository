//算法7.4　二叉排序树的递归查找
//算法7.5　二叉排序树的插入
//算法7.6　二叉排序树的创建
//算法 7.7　二叉排序树的删除
#include<iostream>
using namespace std;
#define ENDFLAG '#'
//char a[10]={'5','6','7','2','1','9','8','10','3','4','#'};//全局变量
typedef struct ElemType{	
	char key;
}ElemType;

typedef struct BSTNode{
	ElemType data;	//结点数据域
	BSTNode *lchild,*rchild;	//左右孩子指针
}BSTNode,*BSTree;


//算法7.4　二叉排序树的递归查找
BSTree SearchBST(BSTree T,char key) {
  //在根指针T所指二叉排序树中递归地查找某关键字等于key的数据元素
  //若查找成功，则返回指向该数据元素结点的指针，否则返回空指针
  if((!T)|| key==T->data.key) return T;       	            	//查找结束
  else if (key<T->data.key)  return SearchBST(T->lchild,key);	//在左子树中继续查找
  else return SearchBST(T->rchild,key);    		   			//在右子树中继续查找
} // SearchBST



//算法7.5　二叉排序树的插入
void InsertBST(BSTree &T,ElemType e ) {
  //当二叉排序树T中不存在关键字等于e.key的数据元素时，则插入该元素
  if(!T) {                				//找到插入位置，递归结束
		 BSTree S = new BSTNode;            		//生成新结点*S
         S->data = e;                  		//新结点*S的数据域置为e   
         S->lchild = S->rchild = NULL;	//新结点*S作为叶子结点
         T =S;            				//把新结点*S链接到已找到的插入位置
  }
  else if (e.key< T->data.key) 
      InsertBST(T->lchild, e );			//将*S插入左子树
  else if (e.key> T->data.key) 
      InsertBST(T->rchild, e);			//将*S插入右子树
}// InsertBST



//算法7.6　二叉排序树的创建
void CreateBST(BSTree &T ) {
  //依次读入一个关键字为key的结点，将此结点插入二叉排序树T中
  T=NULL;
  ElemType e;
  cin>>e.key;        //???
  while(e.key!=ENDFLAG){   	//ENDFLAG为自定义常量，作为输入结束标志
    InsertBST(T, e);          	//将此结点插入二叉排序树T中
    cin>>e.key;			//???
  }//while            
}//CreatBST

void DeleteBST(BSTree &T,char key) {
  //从二叉排序树T中删除关键字等于key的结点
  BSTree p=T;BSTree f=NULL;                     			//初始化
  BSTree q;
  BSTree s;
  /*------------下面的while循环从根开始查找关键字等于key的结点*p-------------*/
  while(p){                  
   if (p->data.key == key) break;  	      	//找到关键字等于key的结点*p，结束循环
   f=p;                                			//*f为*p的双亲结点
   if (p->data.key> key)  p=p->lchild;     	//在*p的左子树中继续查找
   else p=p->rchild;  	                  		//在*p的右子树中继续查找
  }//while
if(!p) return;                         		//找不到被删结点则返回
/*―考虑三种情况实现p所指子树内部的处理：*p左右子树均不空、无右子树、无左子树―*/
if ((p->lchild)&& (p->rchild)) {     		//被删结点*p左右子树均不空
     q = p;
	 s = p->lchild;
     while (s->rchild)                			//在*p的左子树中继续查找其前驱结点，即最右下结点
       {q = s; s = s->rchild;}	         		//向右到尽头
     p->data = s->data;               			//s指向被删结点的“前驱”
     if(q!=p){
		 q->rchild = s->lchild;     	//重接*q的右子树
	 }
     else q->lchild = s->lchild;        		//重接*q的左子树
     delete s;
  }//if
else{
	if(!p->rchild) {               		//被删结点*p无右子树，只需重接其左子树
		  q = p; p = p->lchild; 
	  }//else if
	else if(!p->lchild) {               		//被删结点*p无左子树，只需重接其右子树
		 q = p; p = p->rchild;
	  }//else if
	/*――――――――――将p所指的子树挂接到其双亲结点*f相应的位置――――――――*/
	  if(!f) T=p;                       			//被删结点为根结点
	  else if (q==f->lchild) f->lchild = p;   	//挂接到*f的左子树位置
	  else f->rchild = p;                 		//挂接到*f的右子树位置
	  delete q;
	}
}//DeleteBST

//算法 7.7　二叉排序树的删除

//中序遍历
void InOrderTraverse(BSTree &T)
{
	if(T)
	{
	InOrderTraverse(T->lchild);
	cout<<T->data.key;
	InOrderTraverse(T->rchild);
	}
}

void main()
{
	BSTree T;
	cout<<"请输入若干字符，用回车区分，以#结束输入"<<endl;
	CreateBST(T);
	cout<<"当前有序二叉树中序遍历结果为"<<endl;
	InOrderTraverse(T);
	char key;//待查找或待删除内容
	cout<<"请输入待查找字符"<<endl;
	cin>>key;
	BSTree result=SearchBST(T,key);
	if(result)
	{cout<<"找到字符"<<key<<endl;}
	else
	{cout<<"未找到"<<key<<endl;}
	cout<<"请输入待删除的字符"<<endl;
	cin>>key;
	DeleteBST(T,key);
	cout<<"当前有序二叉树中序遍历结果为"<<endl;
	InOrderTraverse(T);
}

