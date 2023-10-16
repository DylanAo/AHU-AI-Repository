#include<iostream>
#include<string>
#define ERROR -1
#define MAXSIZE 100
using namespace std;

typedef struct BiTNode{                             //二叉树的二叉链表存储表示
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct{                  // 字符栈定义
	char *base;
	char *top;
	int stacksize;
}SqStack;

typedef struct{                   //树栈定义
	BiTree *base;
	BiTree *top;
	int stacksize;
}BiTreeStack;


void  InitStack(SqStack &S){             //字符栈初始化
	S.base=new char[MAXSIZE];
	if(!S.base) exit(-1);
	S.top=S.base;
	S.stacksize=MAXSIZE;
}


void  InitBiTreeStack(BiTreeStack &S){             //树栈初始化
	S.base=new BiTree[MAXSIZE];
	if(!S.base) exit(-1);
	S.top=S.base;
	S.stacksize=MAXSIZE;
}


void Push(SqStack &S,char e)             //字符栈入栈
{
	if(S.top-S.base==S.stacksize) return ;
	*S.top=e;
	S.top++;

}
void PushBiTree(BiTreeStack &S,BiTree e)             //树栈入栈
{
	if(S.top-S.base==S.stacksize) return ;
	*S.top=e;
	S.top++;

}
void Pop(SqStack &S,char &e)           //字符栈出栈
{
	if(S.top==S.base) return;
	e=*--S.top;
	 
}

void PopBiTree(BiTreeStack &S,BiTree &e)           //树栈出栈
{
	if(S.top==S.base) return;
	e=*--S.top;
	 
}


char GetTop(SqStack &S)                //字符栈得到栈顶函数
{		
	if(S.top==S.base)	exit(1);
	return *(S.top-1);
}

char Precede(char t1,char t2) 
 { /* 根据教科书表3.1，判断两符号的优先关系 */
   char f;
    switch(t2)
   {
     case '+':if(t1=='('||t1=='#')
                f='<';
              else
                f='>';
              break;
     case '-':if(t1=='('||t1=='#')
                f='<';
              else
                f='>';
              break;
     case '*':if(t1=='*'||t1=='/'||t1==')')
                f='>';
              else
                f='<';
              break;
	case '/':if(t1=='*'||t1=='/'||t1==')')
                f='>';
              else
                f='<';
              break;
	case '(':if(t1!=')')
                f='<';
              break;
	case')':if(t1=='(')
				f='=';
				else
					f='>';
				break;
	case'#':if(t1=='#')
				f='=';
		else
			f='>';
   }

   return f;
 }
int In(char c) 
 { /* 判断c是否为运算符 */
   switch(c)
   {
   case '+':
   case'-':
   case'*':
	case '/':
   case'#':
   case '(':
   case')':return 1;break;
   default:return 0;
   }
 }
int GetValue(char theta,int a,int b)     //进行运算的函数
 {
	int c;
	switch(theta)
	{
	case '+':c=a+b;break;
	case'-':c=a-b;break;
	case'*':c=a*b;break;
	case'/':c=a/b;break;
	default:
		break;
	}
	return c;
 }

void CreateExpTree(BiTree &T,BiTree a,BiTree b,char ch){           //简单二叉树的创建
	T=new BiTNode;
	T->data=ch;
	T->lchild=a;
	T->rchild=b;
}


 void InitExpTree(BiTree &T)      //算法5.12 表达式树的创建
 {	
	SqStack OPTR;
	BiTreeStack EXPT;
	char ch,theta,x;
	BiTree a,b;
	InitStack(OPTR);Push(OPTR,'#');
	InitBiTreeStack(EXPT);cin>>ch;
	while(ch!='#'||GetTop(OPTR)!='#'){
		if(!In(ch)){CreateExpTree(T,NULL,NULL,ch);PushBiTree(EXPT,T);cin>>ch;}//*q
		else
			switch(Precede(GetTop(OPTR),ch)){
			case'<':
				Push(OPTR,ch);cin>>ch;
				break;
			case'>':
				Pop(OPTR,theta);
				PopBiTree(EXPT,b);PopBiTree(EXPT,a);
				CreateExpTree(T,a,b,theta);    //*
				PushBiTree(EXPT,T);
				break;
			case'=':
				Pop(OPTR,x);cin>>ch;
				break;
		}
	}
 }

 int EvaluateExTree(BiTree T){ //算法5.13 表达式树的求值
	int lvalue,rvalue;
	lvalue=rvalue=0;
	if(T->lchild==NULL&&T->rchild==NULL)
		return T->data-'0';
	else{
		lvalue=EvaluateExTree(T->lchild);
		rvalue=EvaluateExTree(T->rchild);
		return GetValue(T->data,lvalue,rvalue);    //运算函数
	}
 }

 void main() 
 {
   cout<<"请输入算术表达式,并以#结束,中间计算过程要是个位数."<<endl;
   BiTree T;
   InitExpTree(T);          //创建表达式树
   cout<<EvaluateExTree(T)<<endl;             //输出值
 }
	