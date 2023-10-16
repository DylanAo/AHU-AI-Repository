#include<iostream>
#include<string>
#define ERROR -1
#define MAXSIZE 100
using namespace std;

typedef struct BiTNode{                             //�������Ķ�������洢��ʾ
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct{                  // �ַ�ջ����
	char *base;
	char *top;
	int stacksize;
}SqStack;

typedef struct{                   //��ջ����
	BiTree *base;
	BiTree *top;
	int stacksize;
}BiTreeStack;


void  InitStack(SqStack &S){             //�ַ�ջ��ʼ��
	S.base=new char[MAXSIZE];
	if(!S.base) exit(-1);
	S.top=S.base;
	S.stacksize=MAXSIZE;
}


void  InitBiTreeStack(BiTreeStack &S){             //��ջ��ʼ��
	S.base=new BiTree[MAXSIZE];
	if(!S.base) exit(-1);
	S.top=S.base;
	S.stacksize=MAXSIZE;
}


void Push(SqStack &S,char e)             //�ַ�ջ��ջ
{
	if(S.top-S.base==S.stacksize) return ;
	*S.top=e;
	S.top++;

}
void PushBiTree(BiTreeStack &S,BiTree e)             //��ջ��ջ
{
	if(S.top-S.base==S.stacksize) return ;
	*S.top=e;
	S.top++;

}
void Pop(SqStack &S,char &e)           //�ַ�ջ��ջ
{
	if(S.top==S.base) return;
	e=*--S.top;
	 
}

void PopBiTree(BiTreeStack &S,BiTree &e)           //��ջ��ջ
{
	if(S.top==S.base) return;
	e=*--S.top;
	 
}


char GetTop(SqStack &S)                //�ַ�ջ�õ�ջ������
{		
	if(S.top==S.base)	exit(1);
	return *(S.top-1);
}

char Precede(char t1,char t2) 
 { /* ���ݽ̿����3.1���ж������ŵ����ȹ�ϵ */
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
 { /* �ж�c�Ƿ�Ϊ����� */
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
int GetValue(char theta,int a,int b)     //��������ĺ���
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

void CreateExpTree(BiTree &T,BiTree a,BiTree b,char ch){           //�򵥶������Ĵ���
	T=new BiTNode;
	T->data=ch;
	T->lchild=a;
	T->rchild=b;
}


 void InitExpTree(BiTree &T)      //�㷨5.12 ���ʽ���Ĵ���
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

 int EvaluateExTree(BiTree T){ //�㷨5.13 ���ʽ������ֵ
	int lvalue,rvalue;
	lvalue=rvalue=0;
	if(T->lchild==NULL&&T->rchild==NULL)
		return T->data-'0';
	else{
		lvalue=EvaluateExTree(T->lchild);
		rvalue=EvaluateExTree(T->rchild);
		return GetValue(T->data,lvalue,rvalue);    //���㺯��
	}
 }

 void main() 
 {
   cout<<"�������������ʽ,����#����,�м�������Ҫ�Ǹ�λ��."<<endl;
   BiTree T;
   InitExpTree(T);          //�������ʽ��
   cout<<EvaluateExTree(T)<<endl;             //���ֵ
 }
	