#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define maxn 1000
using namespace std;

int n = 4, m = 4;//n*m迷宫 
int flag = 0; //若有能到终点的路，则flag变为1
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }; //方向数组 ,分别为下，上，右，左 ，输出分别设为0,1,2,3
int vis[maxn][maxn];//DFS标记数组 

int mp[maxn][maxn] = {
    {1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}
};  //输入的迷宫 

char mp2[maxn][maxn]; //待输出的迷宫 

typedef struct Point
{
    int x, y;
}Point;

Point pre[maxn][maxn];//记录每个位置的前驱
Point solution[maxn * maxn];//方案记录数组

int Check(Point u)  //检查点是否有障碍和是否已经遍历过 
{
    if (mp[u.x][u.y] == 0 && vis[u.x][u.y] == 0)//这个点是通路且没有被访问过
        return 1;//通路返回1
    else return 0;//不通返回0
}

void Input() //输入迷宫 
{
    memset(mp, 1, sizeof(mp));  //memset初始化函数。作用是将某一块内存中的内容全部设置为指定的值
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mp[i][j];
}

void Output() //输出迷宫 
{
    printf("迷宫为：\n\n");
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cout << mp[i][j];
        cout << endl;
    }
    cout << endl;
}

int Direction(Point a, Point b)
//节点a->b的方向（方向数组做了解释） int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; 
//方向数组 ,分别为下，上，右，左 ，输出分别设为0,1,2,3
{
    for (int i = 0; i < 4; ++i)
        if (b.x == a.x + dir[i][0] && b.y == a.y + dir[i][1])
            return i;
}

void Output2(int len) //另一种输入方法
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            mp2[i][j] = mp[i][j] + 48;
    for (int i = 1; i < len; ++i)
    {
        int x = solution[i].x, y = solution[i].y, d = Direction(solution[i], solution[i + 1]);
        if (d == 0) mp2[x][y] = 'D';
        if (d == 1) mp2[x][y] = 'U';
        if (d == 2) mp2[x][y] = 'R';
        if (d == 3) mp2[x][y] = 'L';    //DOWN,UP,RIGHT,LEFT
    }
    flag = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            printf("%c ", mp2[i][j]);
        printf("\n");
    }
    printf("\n");
}

void DFS(int k, int inx, int iny, int outx, int outy)
{
    solution[k].x = inx;
    solution[k].y = iny;
    vis[inx][iny] = 1;//标记这个点已经走过了
    if (inx == outx && iny == outy)//判断是否到终点
        Output2(k);
    else
        for (int i = 0; i < 4; ++i)
        {
            int u = inx + dir[i][0], v = iny + dir[i][1];//u，v是下一临近点的坐标位置
            Point temp = { u,v };
            if (!Check(temp))//判断这个点是否通路且未被访问
                continue;
            DFS(k + 1, u, v, outx, outy);//是通路就执行DPS，不是通路就跳出去
        }
    vis[inx][iny] = 0;
}

void Solve2(int a, int b, int c, int d)//调用递归函数求路径
{
    cout << "项目1：递归输出：" << endl;
    flag = 0;
    memset(vis, 0, sizeof(vis));//初始化vis数组为0
    DFS(1, a, b, c, d);
    if (!flag) cout << "无通路,请重新输入" << endl;
}


int main() {
    //	freopen("text1.txt","r",stdin); 

    int a = 1, b = 1, c = 4, d = 4;//定义起点和终点
    //Input();
    Output();//展示迷宫
    Solve2(a, b, c, d);//开始找
    cout << "xxxxxxxxxxxxxxxxxxxxxx" << endl;

    return 0;
}