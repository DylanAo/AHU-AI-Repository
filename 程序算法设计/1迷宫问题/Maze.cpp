#include"head.h"

//��ʼ��
Status InitStack(LinkStack S) {
	S = NULL;
	return OK;
}
//��ջ
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
//��ջ
Status Pop(LinkStack& S) {
	if(S == NULL) {
		return ERROR;
	}
	StackNode* p;
	p = S;
	if(S != NULL) S = S->next;
	cout<< "<"<< p->dataX<<","<< p->dataY<< ">"<< endl;
	free(p);//�ͷŽڵ�
	return OK;
}

//����·��
void SetRoadBlock(int arr[][MaxSize]) {
	int x, y;
	cout << "����������·�ϵĵ�������#��ʾֹͣ:" << endl;
	while ((getchar())!='#') {
		cout << "����·������:(x,y)" << endl;
		cin >> x >> y;
		arr[x][y] = 1;
	}
}
//��ӡ�Թ�
void MazePrint(int arr[][MaxSize]){
	int x,y;
	for (x = 0; x < MaxSize; x++) {
		for (y = 0; y < MaxSize; y++)
			cout << arr[x][y] << "\t";
		cout << endl;
	}
}
//���Թ�
Status GetNext(int arr[][MaxSize], LinkStack& S, int x, int y){
	if (arr[x][y] == 2) {
		Push(S, x, y);
		return OK;
	}//�յ�Ϊ3�����Ϊ2�����ǲ��ô��յ�������ߵķ�ʽ����������
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
//���·��ͬʱ��ջ���
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
}*///����������
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
		{1, 1, 1, 1, 1, 1, 1} };//�Թ���ʼ��
	
	cout << "�����Թ������<x,y>:";
	cin >> beginx >> beginy;
	Maze[beginx][beginy] = 2;//�������յ�����Ϊ��ͬ����ֵ
	cout << "�����Թ����յ�<x,y>:";
	cin >> endx >> endy;
	Maze[endx][endy] = 3;//����Թ������յ�����
	SetRoadBlock(Maze);//�����Թ�·�ϣ�1Ϊ�����ߵ��ϰ���0Ϊ�����ߵ�ͨ��
	MazePrint(Maze);//��ӡ�Թ�
	
	LinkStack Path;//����·��ջ
	InitStack(Path);//��ʼ��·��
	GetNext(Maze, Path, endx, endy);//���յ㿪ʼ�������
	//PrintPath(Path);����������
	Pop(Path);
	system("pause");
	return 0;
}