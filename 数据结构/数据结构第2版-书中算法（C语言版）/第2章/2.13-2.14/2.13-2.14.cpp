#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType; //ElemType 为可定义的数据类型，此设为int类型

struct Book {
	string id;//ISBN
	string name;//书名
	double price;//定价
};
typedef struct DuLNode {
	Book data; //数据域
	struct DuLNode *prior; //直接前驱
	struct DuLNode *next; //直接后继
} DuLNode, *DuLinkList;

string head_1, head_2, head_3;
int length;

Status InitDuList_L(DuLinkList &L) {
	//构造一个空的双向链表L
	L = new DuLNode; //生成新结点作为头结点，用头指针L指向头结点
	L->next = NULL; //头结点的指针域置空
	L->prior = NULL;
	return OK;
}

DuLNode *GetElemP_DuL(DuLinkList L, int i) {
	//在带头结点的双向链表L中查找第i个元素，返回结点的地址
	int j;
	DuLinkList p;
	p = L->next;
	j = 1; //初始化，p指向第一个结点，j为计数器
	while (j < i && p) { //顺链域向后扫描，直到p指向第i个元素或p为空
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return NULL; //第i个元素不存在
	return p;
} //GetElemP_DuL

Status ListInsert_DuL(DuLinkList &L, int i, Book e) { //算法2.13 双向链表的插入
	//在带头结点的双向链表L中第i个位置之前插入元素e，i的合法值为1<=i<=表长+1
	DuLinkList s, p;
	if (!(p = GetElemP_DuL(L, i))) //在L中确定第i个元素的位置指针p
		return ERROR; //p为NULL时，第i个元素不存在
	if (i == 1) {//在双向链表的第一个元素上插入
		s = new DuLNode; //生成新结点s
		s->data = e; //将结点s数据置为e
		DuLinkList p = L->next;
		L->next = s;
		s->prior = L;
		s->next = p;//将结点*s插入L中
		p->prior = s;
		++length;
	} else if (i == length) {//在双向链表的最后一个元素上插入
		s = new DuLNode; //生成新结点s
		s->data = e; //将结点s数据置为e
		DuLinkList p = L;
		while (p->next)
			p = p->next;//将LinkList p指向双向链表结尾
		p->next = s;
		s->prior = p;//将结点*s插入到p的后面，插入到L中
		s->next = NULL;
		++length;
	} else {
		s = new DuLNode; //生成新结点*s
		s->data = e; //将结点*s数据域置为e
		s->prior = p->prior; //将结点*s插入L中，此步对应图2.20① 
		p->prior->next = s; //对应图2.20②
		s->next = p; //对应图2.20③
		p->prior = s; //对应图2.20④
		++length;
	}
	return OK;
} //ListInsert_DuL

Status ListDelete_DuL(DuLinkList &L, int i) { //算法2.14 双向链表的删除
	//删除带头结点的双向链表L中第i个位置之前插入元素e，i的合法值为1<=i<=表长
	DuLinkList p;
	if (!(p = GetElemP_DuL(L, i))) //在L中确定第i个元素的位置指针p
		return ERROR; //p为NULL时，第i个元素不存在
	if (i == 1)//删除双向链表的第一个元素
		L = L->next;
	else if (i == length) {//删除双向链表的最后一个元素
		p->prior->next = NULL;
		delete p;
		--length;
		return OK;
	} else {
		p->prior->next = p->next; //修改被删结点的前驱结点的后继指针，对应图2.21①
		p->next->prior = p->prior; //修改被删结点的后继结点的前驱指针，对应图2.21②
		delete p; //释放被删结点的空间 
		--length;
		return OK;
	}
}//ListDelete_DuL

void CreateDuList_L(DuLinkList &L) {
	//正位序输入n个元素的值，建立带表头结点的双向链表L，同时建立前驱指针
	DuLinkList r, p;
	L = new DuLNode;
	L->next = NULL; //先建立一个带头结点的空链表
	r = L;//尾指针r指向头结点
	length = 0;
	fstream file;
	file.open("book.txt");
	if (!file) {
		cout << "未找到相关文件，无法打开！" << endl;
		exit(ERROR);
	}
	file >> head_1 >> head_2 >> head_3;
	while (!file.eof()) {
		p = new DuLNode; //生成新结点
		file >> p->data.id >> p->data.name >> p->data.price; //输入元素值
		p->next = NULL;
		r->next = p; //插入到表尾
		r = p; //r指向新的尾结点
		p->prior = L->prior; //插入到表头
		L->prior = p;
		length++;
	}
	file.close();
} //CreateDuList_L

int main() {
	int a, choose;
	Book e;
	DuLinkList L, p;
	cout << "1. 建立\n";
	cout << "2. 输入\n";
	cout << "3. 插入\n";
	cout << "4. 删除\n";
	cout << "5. 输出\n";
	cout << "0. 退出\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "请选择:";
		cin >> choose;
		switch (choose) {
		case 1: //建立一个双向链表
			if (InitDuList_L(L))
				cout << "成功建立双向链表!\n\n";
			break;
		case 2: //使用后插法创建双向链表
			CreateDuList_L(L);
			cout << "输入 book.txt 信息完毕\n\n";
			break;
		case 3: //双向链表的插入
			cout << "请输入两个数分别代表插入的位置和数值（书的信息：编号&书名&价格）:";
			cin >> a;
			cin >> e.id >> e.name >> e.price;
			if (ListInsert_DuL(L, a, e))
				cout << "插入成功.\n\n";
			else
				cout << "插入失败!\n\n";
			break;
		case 4: //双向链表的删除
			cout << "请输入所要删除的书籍的位置:";
			cin >> a;
			if (ListDelete_DuL(L, a))
				cout << "删除成功!\n\n";
			else
				cout << "删除失败!\n\n";
			break;
		case 5: //双向链表的输出
			cout << "当前图书系统信息读出:\n";
			p = L->next;
			while (p) {
				cout << left << setw(15) << p->data.id << "\t" << left << setw(
						50) << p->data.name << "\t" << left << setw(5)
						<< p->data.price << endl;
				p = p->next;
			}
			cout << endl;
			break;
		}
	}
	return 0;
}