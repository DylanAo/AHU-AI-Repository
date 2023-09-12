#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define maxn 1000
using namespace std;

int n = 4, m = 4;//n*m�Թ� 
int flag = 0; //�����ܵ��յ��·����flag��Ϊ1
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }; //�������� ,�ֱ�Ϊ�£��ϣ��ң��� ������ֱ���Ϊ0,1,2,3
int vis[maxn][maxn];//DFS������� 

int mp[maxn][maxn] = {
    {1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}
};  //������Թ� 

char mp2[maxn][maxn]; //��������Թ� 

typedef struct Point
{
    int x, y;
}Point;

Point pre[maxn][maxn];//��¼ÿ��λ�õ�ǰ��
Point solution[maxn * maxn];//������¼����

int Check(Point u)  //�����Ƿ����ϰ����Ƿ��Ѿ������� 
{
    if (mp[u.x][u.y] == 0 && vis[u.x][u.y] == 0)//�������ͨ·��û�б����ʹ�
        return 1;//ͨ·����1
    else return 0;//��ͨ����0
}

void Input() //�����Թ� 
{
    memset(mp, 1, sizeof(mp));  //memset��ʼ�������������ǽ�ĳһ���ڴ��е�����ȫ������Ϊָ����ֵ
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mp[i][j];
}

void Output() //����Թ� 
{
    printf("�Թ�Ϊ��\n\n");
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            cout << mp[i][j];
        cout << endl;
    }
    cout << endl;
}

int Direction(Point a, Point b)
//�ڵ�a->b�ķ��򣨷����������˽��ͣ� int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; 
//�������� ,�ֱ�Ϊ�£��ϣ��ң��� ������ֱ���Ϊ0,1,2,3
{
    for (int i = 0; i < 4; ++i)
        if (b.x == a.x + dir[i][0] && b.y == a.y + dir[i][1])
            return i;
}

void Output2(int len) //��һ�����뷽��
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
    vis[inx][iny] = 1;//���������Ѿ��߹���
    if (inx == outx && iny == outy)//�ж��Ƿ��յ�
        Output2(k);
    else
        for (int i = 0; i < 4; ++i)
        {
            int u = inx + dir[i][0], v = iny + dir[i][1];//u��v����һ�ٽ��������λ��
            Point temp = { u,v };
            if (!Check(temp))//�ж�������Ƿ�ͨ·��δ������
                continue;
            DFS(k + 1, u, v, outx, outy);//��ͨ·��ִ��DPS������ͨ·������ȥ
        }
    vis[inx][iny] = 0;
}

void Solve2(int a, int b, int c, int d)//���õݹ麯����·��
{
    cout << "��Ŀ1���ݹ������" << endl;
    flag = 0;
    memset(vis, 0, sizeof(vis));//��ʼ��vis����Ϊ0
    DFS(1, a, b, c, d);
    if (!flag) cout << "��ͨ·,����������" << endl;
}


int main() {
    //	freopen("text1.txt","r",stdin); 

    int a = 1, b = 1, c = 4, d = 4;//���������յ�
    //Input();
    Output();//չʾ�Թ�
    Solve2(a, b, c, d);//��ʼ��
    cout << "xxxxxxxxxxxxxxxxxxxxxx" << endl;

    return 0;
}