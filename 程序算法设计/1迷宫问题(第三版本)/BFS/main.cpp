#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;
const int ROW = 4, COL = 4;// �����Թ���С
int visited[ROW][COL] = { 0 };//���ʶ�ά����洢��Ĭ��Ϊδ����
int mp[ROW][COL] = {
    { 0, 1, 1, 1 },
    { 0, 0, 0, 0 },
    { 0, 1, 0, 1 },
    { 0, 1, 0, 0 },
};//��ʼ�Թ�
struct Node
{
    int x, y;//x�������꣬y�Ǻ�����
};

int maze[ROW][COL] =
{
    { 0, 1, 1, 1 },
    { 0, 0, 0, 0 },
    { 0, 1, 0, 1 },
    { 0, 1, 0, 0 },
};//��ʼ�Թ�

void BFS(Node start, Node end)
{
    queue<Node> q;//���д洢�ڵ�
    Node pre[ROW][COL];//ǰ���ڵ������ά����

    q.push(start);//��������
    visited[start.x][start.y] = 1; //������Ϊ�ѷ���

    Node cur;//��ǰ�ڵ�

    Node adj[4] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };//���ڽڵ�����

    while (!q.empty())
    {
        cur = q.front();
        q.pop();//ȡ����ͷ�ڵ�
        //cout << "��ʱ����ͷ�ڵ�Ϊ(" << cur.x << ", " << cur.y << ")" << endl;//����ɾ��
        if (cur.x == end.x && cur.y == end.y)//�ж��Ƿ񵽴��յ�
        {
            cout << "�����յ�" << endl;

            // ���·��
            stack<Node> s;
            Node p = cur;
            while (!(p.x == start.x && p.y == start.y))
            {
                s.push(p);
                p = pre[p.x][p.y];
            }
            s.push(start);

            cout << "·��Ϊ��" << endl;
            while (!s.empty())
            {
                p = s.top();
                s.pop();
                cout << "(" << p.x << ", " << p.y << ")" << endl;
            }
            return;
        }

        for (int i = 0; i < 4; i++)//�������ڵ�����ڽڵ�
        {
            int nx = cur.x + adj[i].x, ny = cur.y + adj[i].y;//nx��nyΪ�ٽ��ڵ�����

            if (nx < 0 || nx >= ROW || ny < 0 || ny >= COL || visited[nx][ny] == 1 || mp[nx][ny] == 1)//�ж����ڽڵ�
                continue;//����Խ����ѷ��ʻ򲻿��У������������һ���ٽ��ڵ�

            struct Node temp;//��δԽ����δ�����ҿ��У��򱾽ڵ�����ұ���ѷ���
            temp.x = nx;
            temp.y = ny;
            q.push(temp);
            //cout << "��ʱ��(" << temp.x << ", " << temp.y << ")���" << endl;//����ɾ��
            visited[nx][ny] = 1;
            pre[nx][ny] = cur; //��¼ǰ���ڵ�
        }
        //printf("\n");//����ɾ��
    }
    cout << "����ʧ��" << endl;//����Ϊ�գ�����ʧ��
}

int main()
{
    Node start = { 0, 0 };
    Node end = { 3, 3 };//��ʼ��������յ�

    BFS(start, end);//��ʼ����

    return 0;
}