#include<iostream>
#include<fstream>
using namespace std;
#define ERROR 0

typedef struct LNode //定义单链表
{
	int data;
	struct LNode *next;
} LNode, *LinkList;

int num_a, num_b;
char st = 'A';

void InitList_L(LinkList &L) //创建单链表
{
	L = new LNode;
	L->next = NULL;
}

void input(LinkList &L, int n) //依次往单链表L里输入数据
{
	int i;
	LNode *p, *r;
	r = L;
	char filename[20] = { 0 };
	cout << "请输入非递减单链表" << st << "的数据文件名称（文件名+“.txt”，如List" << st << ".txt）：" << endl;
	++st;
	gets(filename);
	fstream file;
	file.open(filename);
	if (!file) {
		cout << "未找到相关文件，无法打开！" << endl;
		exit(ERROR);
	}
	while (!file.eof()) {
		p = new LNode;
		file >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
		n++;
	}
	file.close();
}

void output(LinkList L) //依次输出单链表里的每个元素
{
	int i = 0;
	LNode *p;
	p = L->next;
	while (p) {
		if (i)
			cout << ",";
		cout << p->data;
		p = p->next;
		i = 1;
	}
}

void MergeList_L(LinkList &LA, LinkList &LB, LinkList &LC) //算法2.17 链式有序表的合并
{
	//已知单链表LA和LB的元素按值非递减排列
	//归并LA和LB得到新的单链表LC，LC的元素也按值非递减排列
	LinkList pa, pb, pc;
	pa = LA->next;
	pb = LB->next; //pa和pb的初值分别指向两个表的第一个结点
	LC = LA; //用LA的头结点作为LC的头结点
	pc = LC; //pc的初值指向LC的头结点
	while (pa && pb) //两个表都非空
	{
		if (pa->data <= pb->data) //依次"摘取"两表中值较小的结点插入到LC表的最后
		{
			pc->next = pa; //将pa所指结点链接到pc所指结点之后
			pc = pa;
			pa = pa->next;
		} else {
			pc->next = pb; //将pb所指结点链接到pc所指结点之后
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb; //插入非空表的剩余段
	delete LB; //释放LB的头结点
} //MergeList_L()

int main() {
	LinkList La, Lb, Lc;

	InitList_L(La); //La表的创建
	input(La, num_a); //依次往单链表La里输入数据

	InitList_L(Lb); //Lb表的创建	
	input(Lb, num_b); //依次往单链表La里输入数据

	InitList_L(Lc);
	MergeList_L(La, Lb, Lc); //将单链表La和Lb进行合并


	cout << "非递减单链表A，B合并后的非递减单链表C为：\n"; //输出合并后的单链表Lc
	output(Lc);
	cout << endl;
	return 0;
}