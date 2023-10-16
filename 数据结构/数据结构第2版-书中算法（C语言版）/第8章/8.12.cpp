//算法8.12 基数排序
#include <iostream.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAXNUM_KEY 8                	//关键字项数的最大值 
#define RADIX 10                        //关键字基数，此时是十进制整数的基数 
#define MAX_SPACE 10000 
typedef char KeysType;					//定义关键字类型为字符型
typedef int InfoType;					//定义其它数据项的类型
typedef struct
{ 
	KeysType keys[MAXNUM_KEY];          //关键字 
	InfoType otheritems;               	//其他数据项 
	int next; 
}SLCell;						    	//静态链表的结点类型 
typedef struct
{ 
	SLCell r[MAX_SPACE];		        //静态链表的可利用空间，r[0]为头结点 
	int keynum;				         	//记录的当前关键字个数 
	int recnum;					     	//静态链表的当前长度 
}SLList;							    //静态链表类型 
typedef int ArrType[RADIX];	          	//指针数组类型

void InitList(SLList *L)
{ 
	//初始化静态链表L（把数组D中的数据存于L中）
	char c[MAXNUM_KEY],c1[MAXNUM_KEY];
    int i,j,n,max;						//max为关键字的最大值 
    max=-10000;
    cout<<"请输入数据个数，不超过"<<MAX_SPACE<<"个。\n";
    cin>>n;
    while(n>MAX_SPACE)
    {
		cout<<"您输入的个数超过上限，请重新输入，不超过"<<MAX_SPACE<<"个。\n";
	    cin>>n;
    }
    int *D=new int[n];
	cout<<"请输入"<<n<<"个排排序的数据：\n";
    for(i=0;i<n;i++)
    {
	    cin>>D[i];
	    if(max<D[i])
			max=D[i];
    }
    (*L).keynum=(int)(ceil(log10(max)));
    (*L).recnum=n;
    for(i=1;i<=n;i++)
    {
        itoa(D[i-1],c,10);					//将10进制整型转化为字符型,存入c 
		for(j=strlen(c);j<(*L).keynum;j++)  //若c的长度<max的位数,在c前补'0' 
		{
		   strcpy(c1,"0");
		   strcat(c1,c);
		   strcpy(c,c1);
		}
		for(j=0;j<(*L).keynum;j++)
			(*L).r[i].keys[j]=c[(*L).keynum-1-j];
    }
}

int ord(char c)
{	
	//返回k的映射(个位整数)
	return c-'0';
}
void Distribute(SLCell *r,int i,ArrType &f,ArrType &e)
{ 
	//静态链表L的r域中记录已按（keys[0], …, keys[i-1]）有序 
	//本算法按第i个关键字keys[i]建立RADIX个子表，使同一子表中记录的keys[i]相同。 
	//f[0..RADIX-1]和e[0..RADIX-1]分别指向各子表中第一个和最后一个记录
	int j,p;
	for(j=0;j<RADIX;++j)  f[j]=0;        	//各子表初始化为空表 
	for(p=r[0].next;p;p=r[p].next)
	{ 
		j=ord(r[p].keys[i]);                //ord将记录中第i个关键字映射到[0..RADIX-1] 
		if(!f[j])  f[j]=p; 
		else  r[e[j]].next=p; 
		e[j]=p;                          	//将p所指的结点插入第j个子表中 
	}//for 
}//Distribute 

int succ(int i)
{ 
	//求后继函数
    return ++i;
}
void Collect (SLCell *r,int i,ArrType &f,ArrType &e)
{ 
	//本算法按keys[i]自小至大地将f[0..RADIX-1]所指各子表依次链接成一个链表 
    //e[0..RADIX-1]为各子表的尾指针
	int j,t;
    for(j=0;!f[j];j=succ(j));  			//找第一个非空子表，succ为求后继函数 
    r[0].next=f[j];t=e[j];   			//r[0].next指向第一个非空子表中第一个结点 
    while(j<RADIX-1)
	{ 
		for(j=succ(j);j<RADIX-1&&!f[j];j=succ(j)) ;       	//找下一个非空子表 
		if(f[j])  {r[t].next=f[j];t=e[j];}		        	//链接两个非空子表 
	}//while 
	r[t].next=0;                		//t指向最后一个非空子表中的最后一个结点 
}//Collect 

void RadixSort(SLList &L)
{ 
	//L是采用静态链表表示的顺序表 
    //对L做基数排序，使得L成为按关键字自小到大的有序静态链表，L.r[0]为头结点
	int i;
	ArrType f,e;
    for(i=0;i<L.recnum;++i)  L.r[i].next=i+1; 
    L.r[L.recnum].next = 0;             	//将L改造为静态链表 
	for(i=0;i<L.keynum;++i) 
	{       	
		//按最低位优先依次对各关键字进行分配和收集 
		Distribute(L.r,i,f,e);		     	//第i趟分配 
		Collect(L.r,i,f,e);					//第i趟收集 
	}//for 
} // RadixSort
 
void print(SLList L)
{  
	//按数组序号输出静态链表
    int i,j;
    for(i=1;i<=L.recnum;i++)
    {
		for(j=L.keynum-1;j>=0;j--)
			cout<<L.r[i].keys[j];
	    cout<<endl;
    }
}
void Sort(SLList L,int adr[]) 
{ 
	//求得adr[1..L.length]，adr[i]为静态链表L的第i个最小记录的序号
    int i=1,p=L.r[0].next;
    while(p)
    {
		adr[i++]=p;
		p=L.r[p].next;
	}
}
void Rearrange(SLList *L,int adr[])
{ 
	//adr给出静态链表L的有序次序，即L.r[adr[i]]是第i小的记录。
    //本算法按adr重排L.r，使其有序。算法10.18(L的类型有变) 
	int i,j,k;
    if(adr[i]!=i)
    {
		j=i;
		(*L).r[0]=(*L).r[i]; //暂存记录(*L).r[i]
		while(adr[j]!=i)
		{ 
			//调整(*L).r[adr[j]]的记录到位直到adr[j]=i为止
			k=adr[j];
			(*L).r[j]=(*L).r[k];
			adr[j]=j;
			j=k; //记录按序到位 
		}
		(*L).r[j]=(*L).r[0];
		adr[j]=j;
    }
}

void main()
{
	SLList l;
	int *adr;
	InitList(&l);
	RadixSort(l);
	adr=new int[l.recnum];
	Sort(l,adr);
	Rearrange(&l,adr);
	cout<<"排序后(重排记录):\n";
	print(l);
} 
