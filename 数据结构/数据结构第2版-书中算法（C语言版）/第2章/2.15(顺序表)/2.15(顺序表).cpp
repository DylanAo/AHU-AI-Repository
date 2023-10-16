#include<iostream>
#include<fstream>
using namespace std;
#define MAXSIZE 100
#define ERROR 0
typedef struct { //定义顺序表
	int *elem;
	int length;
} List;
int n, m;
char st = 'A';

void InitList(List &L) //创建顺序表
{
	L.elem = new int[MAXSIZE];
	L.length = 0;
}

void ListInput(List &L, int n) //顺序表数据的输入
{
	int i = 0;
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
		file >> L.elem[i];
		i++;
	}
	L.length = i;

}

int ListLength(List L) //求顺序表的长度
{
	return L.length;
}

void GetElem(List L, int i, int &e) //求顺序表的第i个元素，并以e返回
{
	e = L.elem[i - 1];
}

bool LocateElem(List L, int e) //判断List里有没有e这个元素
{
	int i;
	for (i = 0; i < L.length; i++)
		if (e == L.elem[i])
			return true;
	return false;
}

void ListInsert(List &L, int e) //将e插入到List的最后
{
	L.elem[L.length] = e;
	L.length++;
}

void ListOutput(List L) //输出List
{
	int i;
	for (i = 0; i < L.length; i++)
		cout << L.elem[i] << " ";
	cout << endl;
}

void unionList(List &LA, List LB) //算法2.14 线性表的合并（顺序表）
{
	//将所有在线性表LB中但不在LA中的数据元素插入到LA中
	int LA_len, LB_len, i, e;
	LA_len = ListLength(LA);
	LB_len = ListLength(LB); //求线性表的长度
	for (i = 1; i <= LB_len; i++) {
		GetElem(LB, i, e); //取LB中第i个数据元素赋给e
		if (!LocateElem(LA, e)) //LA中不存在和e相同的数据元素，则插入之
			ListInsert(LA, e);
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