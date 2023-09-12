//ջ �ǵݹ� �����������

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

using namespace std;
#define maxn 1000
int fp = 0;//���б�ʶ����Ĭ�ϲ�����
int flag = 0;//ͨ·��ʶ����Ĭ����ͨ·
int n = 4, m = 4;//n*m�Թ� 
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }; //�������� ,�ֱ�Ϊ�£��ϣ��ң��� ������ֱ���Ϊ0,1,2,3
int vis[maxn][maxn];//DFS������� 
int mp[maxn][maxn] = {
    {1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}
};  //��ʼ�Թ�
char mp2[maxn][maxn]; //�����Թ� 

typedef struct Point
{
    int x, y;//x�������꣬y�Ǻ�����
}Point;

typedef struct Snode
{
    Point data;
    struct Snode* next;
}Snode, * Linkstack;

void Init_S(Linkstack& S)//��ʼ��
{
    S = (Linkstack)malloc(sizeof(Snode));
    S->next = NULL;
}

void Push(Linkstack& S, Point e) //��ջ 
{
    Linkstack p = (Linkstack)malloc(sizeof(Snode));
    p->next = S->next;
    p->data = e;
    S->next = p;
}

void Pop(Linkstack& S, Linkstack& e) //��ջ 
{
    if (S->next == NULL) printf("ջ�գ�����");
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
}//��ջ��

int Check(Point u)
{
    if (mp[u.x][u.y] == 0 && vis[u.x][u.y] == 0)//����ڵ���ͨ·��û�б����ʹ�
        return 1;//���з���1
    else return 0;//�����з���0
}//�жϽڵ��Ƿ����

int Direction(Point a, Point b)
//�ڵ�a->b�ķ��򣨷����������˽��ͣ� int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}}; 
//�������� ,�ֱ�Ϊ�£��ϣ��ң��� ������ֱ���Ϊ0,1,2,3
{
    for (int i = 0; i < 4; ++i)
        if (b.x == a.x + dir[i][0] && b.y == a.y + dir[i][1])
            return i;
}

void Output() //�����ʼ�Թ� 
{
    printf("��ʼ�Թ�Ϊ��\n\n");
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            printf("%d ", mp[i][j]);
        printf("\n");
    }
}

void Output2(int len, Linkstack& S)//��������Թ�
{
    printf("�����Թ�Ϊ��\n\n");
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            mp2[i][j] = mp[i][j] + 48;//��mp����ת��Ϊ�ַ�

    Linkstack p = (Linkstack)malloc(sizeof(Snode));
    for (int i = 1; i < len; ++i)
    {
        Pop(S, p);
        int x = S->next->data.x, y = S->next->data.y, d = Direction(S->next->data, p->data);
        if (d == 0) mp2[x][y] = 'D';//��
        if (d == 1) mp2[x][y] = 'U';//��
        if (d == 2) mp2[x][y] = 'R';//��
        if (d == 3) mp2[x][y] = 'L';//��
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
    while (S->next != NULL)//��ջ��Ϊ��ʱִ��
    {
        if (S->next->data.x == outp.x && S->next->data.y == outp.y)//�ж�ջ��Ԫ��
        {
            flag = 1;//������յ�,��ͨ·��ʶ����Ϊ1
            break;//��������
        }
        else//��������յ㣬��������
        {
            vis[S->next->data.x][S->next->data.y] = 1;//�ȱ�Ǳ��ڵ�Ϊ�ѷ���
            for (int i = 0; i < 4; ++i)//��ʼ����������ڵ���ٽ��ڵ�
            {
                fp = 1;//���б�ʶ��Ĭ��Ϊ����
                int u = S->next->data.x + dir[i][0], v = S->next->data.y + dir[i][1];//u��v����һ�ٽ��������λ��
                Point temp = { u,v };
                if (Check(temp))//�ж�������Ƿ����
                {
                    Push(S, temp);//���оͰ������ѹ��ջ��
                    break;//��ִ�к�����ˣ����¿�ʼѭ��
                }
                else//��������У�����Ѱ����һ���ٽ��ڵ�
                    fp = 0;//���б�ʶ����Ϊ������
            }
            if (fp == 0)//���ĸ��ٽ��ڵ㶼������
            {
                Linkstack p = (Linkstack)malloc(sizeof(Snode));
                Pop(S, p);//�򱾽ڵ�Ӧ������ջ
                free(p);
            }
        }
    }
}

int main()
{
    Linkstack S;
    Init_S(S);//����һ����ջ

    Point Start = { 1,1 };
    Point End = { 4,4 };//��ʼ��������յ�

    Push(S, Start);//�����ѹ��ջ��
    Output();//չʾ��ʼ�Թ�
    dps(End, S);//��ʼ����
    if (flag == 1)
    {
        int len = StackLength(S);
        Output2(len, S);//�н⣬��չʾ�����Թ�
    }
    else
        printf("���Թ��޽�");

    return 0;
}