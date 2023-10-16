//算法7.8　B-树的查找
//算法7.9　B-树的插入


#include<iostream>
using namespace std;
#define FALSE 0
#define TRUE 1
#define OK 1
#define m 3						//B-树的阶，暂设为3
typedef struct BTNode{
	int keynum;					//结点中关键字的个数，即结点的大小
	BTNode *parent;				//指向双亲结点
	int key[m+1];				//关键字矢量，0号单元未用
	BTNode *ptr[m+1];			//子树指针矢量
}BTNode,*BTree;

//- - - - - B-树的查找结果类型定义- - - - -
struct Result{
  BTNode *pt;     							//指向找到的结点
  int i;           							//1..m，在结点中的关键字序号
  int tag;         							//1：查找成功，0：查找失败
}; 	                           


int Search(BTree T,int key)
{
	BTree p=T;	
	int endnum;
	if(p)						//树不为空时
	{
		endnum=p->keynum;		//获得首节点包含的记录个数
	}
	else
	{
		return 0;				//返回没找到
	}
	int i=0;
	if(endnum==0)
	{
		return i;				//树存在，但仅有一个为空根节点
	}
	else if(key>=p->key[endnum])//节点不为空，但当前值比最大的key还大
	{
		i=endnum;
		return i;
	}
	else if(key<=p->key[1])		//节点不为空，但当前值比最小的key还小
	{
		return i;}
	else
	{
		for(i=1;i<endnum;i++)	//有合适的位置，即处于当前结点的最大和最小值之间，或找到了
		{
			if(p->key[i]<=key && key<p->key[i+1])
				return i;
		}
	}
}

void Insert(BTree &q,int i,int x,BTree &ap)
{//将x插入q结点的i+1位置中
	int j;
	for(j=m-1;j>i;j--)			
	{
		//将插入位置之后的key全部后移一位
		q->key[j+1]=q->key[j];
	}
	for(j=m;j>i;j--)
	{
		//相应地也移动其后ptr的位置
		q->ptr[j]=q->ptr[j-1];
	}
	q->key[i+1]=x;//插入x到该位置
	q->ptr[i+1]=ap;
	q->keynum++;
}

void split(BTree &q,int s,BTree &ap)
{	//将q->key[s+1,..,m], q->ptr[s+1,..,m]移入新结点*ap作为右结点
	//原结点作为新的左侧结点
	//中间值被保存在ap[0]->key中，等待找到跳转回InsertBTree（）寻找到到合适的插入位置插入
	int i;
	ap=new BTNode;
	for(i=s+1;i<=m;i++)
	{	//将q->key[s+1,..,m]保存到ap->key[0,..,m-s+1]中
		//将q->ptr[s+1,..,m]保存到ap->ptr[0,..,m-s+1]中
		ap->key[i-s-1]=q->key[i];	
		ap->ptr[i-s-1]=q->ptr[i];
	}
	if(ap->ptr[0])
	{
		//当ap有子树的时候
		for(i=0;i<=1;i++)
		{
			//将ap的子树的父亲改为ap自己
			ap->ptr[i]->parent=ap;
		}
	}
	ap->keynum=(m-s)-1;
	ap->parent=q->parent;//将ap的父亲改为q的父亲

	q->keynum=q->keynum-(m-s);//修改q的记录个数
}

void NewRoot(BTree &T,BTree q,int x,BTree &ap)//生成含信息（T, x, ap）的新的根结点*T，原T和ap为子树指针
{
	BTree newT=new BTNode;//新建一个结点作为新的根
	
	newT->key[1]=x;//写入新根的key[1]
	newT->ptr[0]=T;//将原来的树根作为新根的左子树
	newT->ptr[1]=ap;//ap作为新根的右子树
	newT->keynum=1;
	newT->parent=NULL;//新根的父亲为空

	ap->parent=newT;//ap的父亲为新根
	T->parent=newT;//T的父亲为新根

	T=newT;//树改成新根引导的
}

//算法7.9　B-树的插入
int InsertBTree(BTree &T,int K,BTree q,int i){
  int x=K;
  BTree ap=NULL;
  int finished=FALSE;//x表示新插入的关键字，ap为一个空指针
  while(q&&!finished){
    Insert(q,i,x,ap);      		//将x和ap分别插入到q->key[i+1]和q->ptr[i+1]
    if (q->keynum<m)
		finished=TRUE;   	//插入完成
    else{                      	//分裂结点*q
     int s= m/2;
	 split(q,s,ap);
	x=ap->key[0];//	 x=q->key[s];
      //将q->key[s+1..m], q->ptr[s..m]和q->recptr[s+1..m] 移入新结点*ap
      q=q->parent;
      if(q)
	  {
		  i=Search(q,x);
	  }		//在双亲结点*q中查找x的插入位置
	}						//else
  }							//while
  if(!finished)    			//T是空树（参数q初值为NULL）或者根结点已分裂为结点*q和*ap
      NewRoot(T,q,x,ap);		//生成含信息（T, x, ap）的新的根结点*T，原T和ap为子树指针
  return  OK;
}							//InsertBTree						//InsertBTree

//算法7.8　B-树的查找
Result SearchBTree(BTree &T, int key){
	/*在m阶B-树T上查找关键字key，返回结果(pt,i,tag)。若查找成功，则特征值tag=1，指针pt所指结点中第i个关键字等于key；否则特征值tag=0，等于key的关键字应插入在指针pt所指结点中第i和第i+1个关键字之间*/
	BTree p=T;
	BTree q=NULL;
	int found=FALSE;
	int i=0;			//初始化，p指向待查结点，q指向p的双亲
while(p&&!found){
    i=Search(p,key);               	
    //在p-＞key[1..keynum]中查找i，使得：p-＞key[i]＜=key＜p-＞key[i+1]
    if(i>0&&p->key[i]==key)
		found=TRUE;		//找到待查关键字
    else
	{
		q=p;
		p=p->ptr[i];
	}
  }
	Result result;
if(found)
{
	result.pt=p;
	result.i=i;
	result.tag=1;
	return result;
}              		//查找成功
else
{
	result.pt=q;
	result.i=i;
	result.tag=0;
	return result;
}              			//查找不成功，返回K的插入位置信息
}//SearchBTree

void InitialBTree(BTree &T)
{
	//初始化一个空的根
	T->keynum=0;		
	T->parent=NULL;	
	for(int i=0;i<m+1;i++)
	{
		T->ptr[i]=NULL;
	}
}



void main()
{
	BTree T=new BTNode;
	InitialBTree(T);
	//先用SearchBTree()找到要插入的位置，得到一个Result结构体
	//再用InsertBTree()插入数据
	Result result;
	int a[11]={45,24,53,90,3,12,50,61,70,100};
	for(int i=0;i<10;i++)
	{
		result=SearchBTree(T,a[i]);
		if(result.tag==0)
		{
			InsertBTree(T,a[i],result.pt,result.i);
		}
	}
	cout<<"OK";
}

