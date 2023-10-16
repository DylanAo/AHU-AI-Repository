#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType; //ElemType 为可定义的数据类型，此设为int类型

#define MAXSIZE 100			//顺序表可能达到的最大长度
struct Book {
	string id;//ISBN
	string name;//书名
	double price;//定价
};
typedef struct {
	Book *elem; //存储空间的基地址
	int length; //当前长度
} SqList;

Status InitList_Sq(SqList &L) { //算法2.1 顺序表的初始化
	//构造一个空的顺序表L
	L.elem = new Book[MAXSIZE]; //为顺序表分配一个大小为MAXSIZE的数组空间
	if (!L.elem)
		exit(OVERFLOW); //存储分配失败退出
	L.length = 0; //空表长度为0
	return OK;
}

Status GetElem(SqList L, int i, Book &e) {//算法2.2　顺序表的取值
	if (i < 1 || i > L.length)
		return ERROR; //判断i值是否合理，若不合理，返回ERROR
	e = L.elem[i - 1]; //elem[i-1]单元存储第i个数据元素
	return OK;
}

int LocateElem_Sq(SqList L, double e) { //算法2.3 顺序表的查找
	//顺序表的查找
	for (int i = 0; i < L.length; i++)
		if (L.elem[i].price == e)
			return i + 1;//查找成功，返回序号i+1
	return 0;//查找失败，返回0
}

Status ListInsert_Sq(SqList &L, int i, Book e) { //算法2.4 顺序表的插入
	//在顺序表L中第i个位置之前插入新的元素e
	//i值的合法范围是1<=i<=L.length+1
	if ((i < 1) || (i > L.length + 1))
		return ERROR; //i值不合法
	if (L.length == MAXSIZE)
		return ERROR; //当前存储空间已满
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j]; //插入位置及之后的元素后移
	L.elem[i - 1] = e; //将新元素e放入第i个位置
	++L.length; //表长增1
	return OK;
}

Status ListDelete_Sq(SqList &L, int i) { //算法2.5 顺序表的删除
	//在顺序表L中删除第i个元素，并用e返回其值
	//i值的合法范围是1<=i<=L.length
	if ((i < 1) || (i > L.length))
		return ERROR; //i值不合法
	for (int j = i; j <= L.length; j++)
		L.elem[j - 1] = L.elem[j]; //被删除元素之后的元素前移
	--L.length; //表长减1
	return OK;
}

int main() {
	SqList L;
	int i = 0, temp, a, c, choose;
	double price;
	Book e;
	string head_1, head_2, head_3;
	cout << "1. 建立\n";
	cout << "2. 输入\n";
	cout << "3. 取值\n";
	cout << "4. 查找\n";
	cout << "5. 插入\n";
	cout << "6. 删除\n";
	cout << "7. 输出\n";
	cout << "0. 退出\n\n";

	choose = -1;
	while (choose != 0) {
		cout << "请选择:";
		cin >> choose;
		switch (choose) {
		case 1://创建顺序表
			if (InitList_Sq(L))
				cout << "成功建立顺序表\n\n";
			else
				cout << "顺序表建立失败\n\n";
			break;
		case 2: {//顺序表信息输入
			i = 0;
			L.elem = new Book[MAXSIZE];
			if (!L.elem)
				exit(OVERFLOW);
			L.length = 0;
			fstream file;
			file.open("book.txt");
			if (!file) {
				cout << "错误！未找到文件！" << endl;
				exit(ERROR);
			}
			file >> head_1 >> head_2 >> head_3;
			while (!file.eof()) {
				file >> L.elem[i].id >> L.elem[i].name >> L.elem[i].price;
				i++;
			}
			cout << "输入 book.txt 信息完毕\n\n";
			L.length = i;
			file.close();
		}
			break;
		case 3://顺序表的取值
			cout << "请输入一个位置用来取值：\n";
			cin >> i;
			temp = GetElem(L, i, e);
			if (temp != 0) {
				cout << "查找成功\n";
				cout << "第" << i << "本图书的信息是：\n";
				cout << left << setw(15) << e.id << "\t" << left << setw(50)
						<< e.name << "\t" << left << setw(5) << e.price << endl
						<< endl;
			} else
				cout << "查找失败！位置超出范围\n\n";
			break;
		case 4: //顺序表的查找
			cout << "请输入所要查找价格:";
			cin >> price;
			temp = LocateElem_Sq(L, price);
			if (temp != 0) {
				cout << "查找成功\n";
				cout << "该价格对应的书名为：" << L.elem[temp - 1].name << endl << endl;
			} else
				cout << "查找失败！没有这个价格对应的书籍\n\n";
			break;
		case 5: //顺序表的插入
			cout << "请输入插入的位置和书本信息，包括：编号 书名 价格（用空格隔开）:";
			cin >> a;
			cin >> e.id >> e.name >> e.price; //输入a和b，a代表插入的位置，b代表插入的数值（书本信息）
			if (ListInsert_Sq(L, a, e))
				cout << "插入成功.\n\n";
			else
				cout << "插入失败.\n\n";
			break;
		case 6: //顺序表的删除
			cout << "请输入所要删除的书籍的位置:";
			cin >> c;
			if (ListDelete_Sq(L, c))
				cout << "删除成功.\n\n";
			else
				cout << "删除失败.\n\n";
			break;
		case 7: //顺序表的输出
			cout << "当前图书系统信息（顺序表）读出:\n";
			for (i = 0; i < L.length; i++)
				cout << left << setw(15) << L.elem[i].id << "\t" << left
						<< setw(50) << L.elem[i].name << "\t" << left
						<< setw(5) << L.elem[i].price << endl;
			cout << endl;
			break;
		}
	}
	return 0;
}