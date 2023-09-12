//栈 非递归 深度优先搜索

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

using namespace std;
#define maxn 1000
int fp = 0;//可行标识符，默认不可行
int flag = 0;//通路标识符，默认无通路
int n = 4, m = 4;//n*m迷宫 
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }; //方向数组 ,分别为下，上，右，左 ，输出分别设为0,1,2,3
int vis[maxn][maxn];//DFS标记数组 
int mp[maxn][maxn] = {
    {1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}
};  //初始迷宫
char mp2[maxn][maxn]; //解析迷宫 

typedef struct Point
{
    int x, y;//x是竖坐标，y是横坐标
}Point;

typedef struct Snode
{
    Point data;
    struct Snode* next;
}Snode, * Linkstack;

void Init_S(Linkstack& S)//初始化
{
    S = (Linkstack)malloc(sizeof(Snode));
    S->next = NULL;
}

void Push(Linkstack& S, Point e) //入栈 
{
    Linkstack p = (Linkstack)malloc(sizeof(Snode));
    p->next = S->next;
    p->data = e;
    S->next = p;
}

void Pop(Linkstack& S, Linkstack& e) //出栈 
{
    if (S->next == NULL) printf("栈空！！！");
    Linkstack p = S->next;
    e->data = p->data;
    S->next = p->next;
    free(p);
}

int StackLength(Linkstack& S)
{
    Linkstack p = (Linkstack)malloc(sizeof(Snode));
    p->next = S->next;
    int len = 0;
    while (p->next != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}//求栈长

int Check(Point u)
{
    if (mp[u.x][u.y] == 0 && vis[u.x][u.y] == 0)//这个节点是通路且没有被访问过
        return 1;//可行返回1
    else return 0;//不可行返回0
}//判断节点是否可行

int Direction(Point a, Point b)
//节点a->b的方向（方向数组做了解释） int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; 
//方向数组 ,分别为下，上，右，左 ，输出分别设为0,1,2,3
{
    for (int i = 0; i < 4; ++i)
        if (b.x == a.x + dir[i][0] && b.y == a.y + dir[i][1])
            return i;
}

void Output() //输出初始迷宫 
{
    printf("初始迷宫为：\n\n");
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            printf("%d ", mp[i][j]);
        printf("\n");
    }
}

void Output2(int len, Linkstack& S)//输出解析迷宫
{
    printf("解析迷宫为：\n\n");
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            mp2[i][j] = mp[i][j] + 48;//由mp数字转化为字符

    Linkstack p = (Linkstack)malloc(sizeof(Snode));
    for (int i = 1; i < len; ++i)
    {
        Pop(S, p);
        int x = S->next->data.x, y = S->next->data.y, d = Direction(S->next->data, p->data);
        if (d == 0) mp2[x][y] = 'D';//下
        if (d == 1) mp2[x][y] = 'U';//上
        if (d == 2) mp2[x][y] = 'R';//右
        if (d == 3) mp2[x][y] = 'L';//左
    }
    free(p);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            printf("%c ", mp2[i][j]);
        printf("\n");
    }
    printf("\n");

}

void dps(Point outp, Linkstack& S)
{
    while (S->next != NULL)//当栈不为空时执行
    {
        if (S->next->data.x == outp.x && S->next->data.y == outp.y)//判断栈顶元素
        {
            flag = 1;//如果是终点,则通路标识符改为1
            break;//搜索结束
        }
        else//如果不是终点，继续查找
        {
            vis[S->next->data.x][S->next->data.y] = 1;//先标记本节点为已访问
            for (int i = 0; i < 4; ++i)//开始逐个搜索本节点的临近节点
            {
                fp = 1;//可行标识符默认为可行
                int u = S->next->data.x + dir[i][0], v = S->next->data.y + dir[i][1];//u，v是下一临近点的坐标位置
                Point temp = { u,v };
                if (Check(temp))//判断这个点是否可行
                {
                    Push(S, temp);//可行就把这个点压入栈中
                    break;//不执行后面的了，重新开始循环
                }
                else//如果不可行，接着寻找下一个临近节点
                    fp = 0;//可行标识符改为不可行
            }
            if (fp == 0)//若四个临近节点都不可行
            {
                Linkstack p = (Linkstack)malloc(sizeof(Snode));
                Pop(S, p);//则本节点应被弹出栈
                free(p);
            }
        }
    }
}

int main()
{
    Linkstack S;
    Init_S(S);//创建一个空栈

    Point Start = { 1,1 };
    Point End = { 4,4 };//初始化起点与终点

    Push(S, Start);//将起点压入栈中
    Output();//展示初始迷宫
    dps(End, S);//开始搜索
    if (flag == 1)
    {
        int len = StackLength(S);
        Output2(len, S);//有解，则展示解析迷宫
    }
    else
        printf("此迷宫无解");

    return 0;
}