#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define ERROR 0

typedef struct LNode {
	int data; //结点的数据域
	struct LNode *next; //结点的指针域
} LNode, *List; //LinkList为指向结构体LNode的指针类型

int n, m;
char st = 'A';

void InitList(List &L) //创建链表
{
	L = new LNode;
	L->next = NULL;
}

void ListInput(List &L, int n) //链表数据的输入
{
	int i;
	List p, r;
	r = L;
	char filename[20] = { 0 };
	cout << "请输入顺序表L" << st << "的数据文件名称（文件名+“.txt”，如List" << st << ".txt）：" << endl;
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

bool LocateElem(List L, int e) //判断List里有没有e这个元素
{
	List p;
	p = L->next;
	while (p != NULL) {
		if (p->data == e)
			return true;
		p = p->next;
	}
	return false;
}

void ListInsert(List &L, int e) //将e插入到List中
{
	List p;
	p = new LNode;
	p->data = e;
	p->next = L->next;
	L->next = p;
}

void ListOutput(List L) //输出List
{
	List p;
	p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void unionList(List &LA, List LB) //算法2.15 线性表的合并（链表）
{
	//将所有在线性表LB中但不在LA中的数据元素插入到LA中
	int e;
	List p;
	p = LB->next;
	while (p != NULL) {
		e = p->data;
		if (!LocateElem(LA, e)) //LA中不存在和e相同的数据元素，则插入之
			ListInsert(LA, e);
		p = p->next;
	}
} //unionList

int main() {
	List LA, LB;

	InitList(LA);
	
	InitList(LB);
	
	ListInput(LA, n);
	ListInput(LB, m);

	unionList(LA, LB);

	cout << "LA和LB合并后的集合为：\n";
	ListOutput(LA);
	return 0;
}