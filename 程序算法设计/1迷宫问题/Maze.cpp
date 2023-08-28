#include"head.h"

//初始化
Status InitStack(LinkStack S) {
	S = NULL;
	return OK;
}
//进栈
Status Push(LinkStack& S, ElemType ex,ElemType ey) {
	StackNode* p;
	p = new StackNode;
	if (!p) 
	{
		printf("ERROR\n");
		return ERROR;
	}
	p->dataX = ex;
	p->dataY = ey;
	p->next = S;
	S = p;
	return OK;
}
//出栈
Status Pop(LinkStack& S) {
	if(S == NULL) {
		return ERROR;
	}
	StackNode* p;
	p = S;
	if(S != NULL) S = S->next;
	cout<< "<"<< p->dataX<<","<< p->dataY<< ">"<< endl;
	free(p);//释放节点
	return OK;
}

//设置路障
void SetRoadBlock(int arr[][MaxSize]) {
	int x, y;
	cout << "请输入设置路障的地区，用#表示停止:" << endl;
	while ((getchar())!='#') {
		cout << "输入路障坐标:(x,y)" << endl;
		cin >> x >> y;
		arr[x][y] = 1;
	}
}
//打印迷宫
void MazePrint(int arr[][MaxSize]){
	int x,y;
	for (x = 0; x < MaxSize; x++) {
		for (y = 0; y < MaxSize; y++)
			cout << arr[x][y] << "\t";
		cout << endl;
	}
}
//走迷宫
Status GetNext(int arr[][MaxSize], LinkStack& S, int x, int y){
	if (arr[x][y] == 2) {
		Push(S, x, y);
		return OK;
	}//终点为3，起点为2，我们采用从终点向起点走的方式，优先左上
	if (arr[x][y] == 0|| arr[x][y] == 3) {
		Push(S, x, y);
		arr[x][y] = 1;
	}
	if(arr[x - 1][y] != 1){
		x--;
	}
	else if(arr[x][y - 1] != 1){
		y--;
	}
	else if(arr[x][y + 1] != 1){
		y++;
	}
	else if(arr[x + 1][y] != 1){
		x++;
	}
	else return OK;
	GetNext(arr, S, x, y);
	Pop(S);
}
/*
//输出路径同时将栈清空
Status PrintPath(LinkStack& S){
	while(S != NULL){
		cout << "<" << S->dataX << "," << S->dataY << ">" << endl;
		Pop(S);
	}
	if(S == NULL) return OK;
	else {
		cout << "ERROR" << endl;;
		return ERROR;
	}
}*///初版错误代码
int main()
{
	int beginx, beginy, endx, endy;
	int Maze[MaxSize][MaxSize] = { 
		{1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1} };//迷宫初始化
	
	cout << "设置迷宫的起点<x,y>:";
	cin >> beginx >> beginy;
	Maze[beginx][beginy] = 2;//把起点和终点设置为不同的数值
	cout << "设置迷宫的终点<x,y>:";
	cin >> endx >> endy;
	Maze[endx][endy] = 3;//完成迷宫起点和终点设置
	SetRoadBlock(Maze);//设置迷宫路障，1为不可走的障碍，0为可以走的通道
	MazePrint(Maze);//打印迷宫
	
	LinkStack Path;//建立路径栈
	InitStack(Path);//初始化路径
	GetNext(Maze, Path, endx, endy);//从终点开始深度搜索
	//PrintPath(Path);初版错误代码
	Pop(Path);
	system("pause");
	return 0;
}