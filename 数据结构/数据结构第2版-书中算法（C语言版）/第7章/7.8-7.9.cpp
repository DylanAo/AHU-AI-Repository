//�㷨7.8��B-���Ĳ���
//�㷨7.9��B-���Ĳ���


#include<iostream>
using namespace std;
#define FALSE 0
#define TRUE 1
#define OK 1
#define m 3						//B-���Ľף�����Ϊ3
typedef struct BTNode{
	int keynum;					//����йؼ��ֵĸ����������Ĵ�С
	BTNode *parent;				//ָ��˫�׽��
	int key[m+1];				//�ؼ���ʸ����0�ŵ�Ԫδ��
	BTNode *ptr[m+1];			//����ָ��ʸ��
}BTNode,*BTree;

//- - - - - B-���Ĳ��ҽ�����Ͷ���- - - - -
struct Result{
  BTNode *pt;     							//ָ���ҵ��Ľ��
  int i;           							//1..m���ڽ���еĹؼ������
  int tag;         							//1�����ҳɹ���0������ʧ��
}; 	                           


int Search(BTree T,int key)
{
	BTree p=T;	
	int endnum;
	if(p)						//����Ϊ��ʱ
	{
		endnum=p->keynum;		//����׽ڵ�����ļ�¼����
	}
	else
	{
		return 0;				//����û�ҵ�
	}
	int i=0;
	if(endnum==0)
	{
		return i;				//�����ڣ�������һ��Ϊ�ո��ڵ�
	}
	else if(key>=p->key[endnum])//�ڵ㲻Ϊ�գ�����ǰֵ������key����
	{
		i=endnum;
		return i;
	}
	else if(key<=p->key[1])		//�ڵ㲻Ϊ�գ�����ǰֵ����С��key��С
	{
		return i;}
	else
	{
		for(i=1;i<endnum;i++)	//�к��ʵ�λ�ã������ڵ�ǰ����������Сֵ֮�䣬���ҵ���
		{
			if(p->key[i]<=key && key<p->key[i+1])
				return i;
		}
	}
}

void Insert(BTree &q,int i,int x,BTree &ap)
{//��x����q����i+1λ����
	int j;
	for(j=m-1;j>i;j--)			
	{
		//������λ��֮���keyȫ������һλ
		q->key[j+1]=q->key[j];
	}
	for(j=m;j>i;j--)
	{
		//��Ӧ��Ҳ�ƶ����ptr��λ��
		q->ptr[j]=q->ptr[j-1];
	}
	q->key[i+1]=x;//����x����λ��
	q->ptr[i+1]=ap;
	q->keynum++;
}

void split(BTree &q,int s,BTree &ap)
{	//��q->key[s+1,..,m], q->ptr[s+1,..,m]�����½��*ap��Ϊ�ҽ��
	//ԭ�����Ϊ�µ������
	//�м�ֵ��������ap[0]->key�У��ȴ��ҵ���ת��InsertBTree����Ѱ�ҵ������ʵĲ���λ�ò���
	int i;
	ap=new BTNode;
	for(i=s+1;i<=m;i++)
	{	//��q->key[s+1,..,m]���浽ap->key[0,..,m-s+1]��
		//��q->ptr[s+1,..,m]���浽ap->ptr[0,..,m-s+1]��
		ap->key[i-s-1]=q->key[i];	
		ap->ptr[i-s-1]=q->ptr[i];
	}
	if(ap->ptr[0])
	{
		//��ap��������ʱ��
		for(i=0;i<=1;i++)
		{
			//��ap�������ĸ��׸�Ϊap�Լ�
			ap->ptr[i]->parent=ap;
		}
	}
	ap->keynum=(m-s)-1;
	ap->parent=q->parent;//��ap�ĸ��׸�Ϊq�ĸ���

	q->keynum=q->keynum-(m-s);//�޸�q�ļ�¼����
}

void NewRoot(BTree &T,BTree q,int x,BTree &ap)//���ɺ���Ϣ��T, x, ap�����µĸ����*T��ԭT��apΪ����ָ��
{
	BTree newT=new BTNode;//�½�һ�������Ϊ�µĸ�
	
	newT->key[1]=x;//д���¸���key[1]
	newT->ptr[0]=T;//��ԭ����������Ϊ�¸���������
	newT->ptr[1]=ap;//ap��Ϊ�¸���������
	newT->keynum=1;
	newT->parent=NULL;//�¸��ĸ���Ϊ��

	ap->parent=newT;//ap�ĸ���Ϊ�¸�
	T->parent=newT;//T�ĸ���Ϊ�¸�

	T=newT;//���ĳ��¸�������
}

//�㷨7.9��B-���Ĳ���
int InsertBTree(BTree &T,int K,BTree q,int i){
  int x=K;
  BTree ap=NULL;
  int finished=FALSE;//x��ʾ�²���Ĺؼ��֣�apΪһ����ָ��
  while(q&&!finished){
    Insert(q,i,x,ap);      		//��x��ap�ֱ���뵽q->key[i+1]��q->ptr[i+1]
    if (q->keynum<m)
		finished=TRUE;   	//�������
    else{                      	//���ѽ��*q
     int s= m/2;
	 split(q,s,ap);
	x=ap->key[0];//	 x=q->key[s];
      //��q->key[s+1..m], q->ptr[s..m]��q->recptr[s+1..m] �����½��*ap
      q=q->parent;
      if(q)
	  {
		  i=Search(q,x);
	  }		//��˫�׽��*q�в���x�Ĳ���λ��
	}						//else
  }							//while
  if(!finished)    			//T�ǿ���������q��ֵΪNULL�����߸�����ѷ���Ϊ���*q��*ap
      NewRoot(T,q,x,ap);		//���ɺ���Ϣ��T, x, ap�����µĸ����*T��ԭT��apΪ����ָ��
  return  OK;
}							//InsertBTree						//InsertBTree

//�㷨7.8��B-���Ĳ���
Result SearchBTree(BTree &T, int key){
	/*��m��B-��T�ϲ��ҹؼ���key�����ؽ��(pt,i,tag)�������ҳɹ���������ֵtag=1��ָ��pt��ָ����е�i���ؼ��ֵ���key����������ֵtag=0������key�Ĺؼ���Ӧ������ָ��pt��ָ����е�i�͵�i+1���ؼ���֮��*/
	BTree p=T;
	BTree q=NULL;
	int found=FALSE;
	int i=0;			//��ʼ����pָ������㣬qָ��p��˫��
while(p&&!found){
    i=Search(p,key);               	
    //��p-��key[1..keynum]�в���i��ʹ�ã�p-��key[i]��=key��p-��key[i+1]
    if(i>0&&p->key[i]==key)
		found=TRUE;		//�ҵ�����ؼ���
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
}              		//���ҳɹ�
else
{
	result.pt=q;
	result.i=i;
	result.tag=0;
	return result;
}              			//���Ҳ��ɹ�������K�Ĳ���λ����Ϣ
}//SearchBTree

void InitialBTree(BTree &T)
{
	//��ʼ��һ���յĸ�
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
	//����SearchBTree()�ҵ�Ҫ�����λ�ã��õ�һ��Result�ṹ��
	//����InsertBTree()��������
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

