#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<time.h>
#include<queue>
#include<stack>
#include<iterator>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<map>
//#define ONLINE_JUDGE
#define eps 1e-8
#define INF 0x7fffffff
#define FOR(i,a) for((i)=0;i<(a);(i)++)
#define MEM(a) (memset((a),0,sizeof(a)))
#define sfs(a) scanf("%s",a)
#define sf(a) scanf("%d",&a)
#define sfI(a) scanf("%I64d",&a)
#define pf(a) printf("%d\n",a)
#define pfI(a) printf("%I64d\n",a)
#define pfs(a) printf("%s\n",a)
#define sfd(a,b) scanf("%d%d",&a,&b)
#define sft(a,b,c)scanf("%d%d%d",&a,&b,&c)
#define for1(i,a,b) for(int i=(a);i<b;i++)
#define for2(i,a,b) for(int i=(a);i<=b;i++)
#define for3(i,a,b)for(int i=(b);i>=a;i--)
#define MEM1(a) memset(a,0,sizeof(a))
#define MEM2(a) memset(a,-1,sizeof(a))
const double PI=acos(-1.0);
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
using namespace std;
#define ll __int64
int n,m;
#define Mod 10
#define N 10010
#define M 1000010
struct Edge{		//�洢�ߵĽṹ��
	int to;
	int next;
};
struct Node{		//�洢��Ľṹ��
	int id;
	int step;
};
struct sqQueue{		//���еĽṹ��
	Node *base;
	int front;
	int rear;
};
Edge edge[N];		//
int head[N];
int vis[N];
int cnt;
sqQueue Q;
void Init(){
	memset(head,-1,sizeof head);
	cnt=0;
}
void addEdge(int u,int v){	//��ӱ�
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}
void InitQueue(sqQueue &Q){	//��ʼ������
	Q.base = new Node[M];
	if(!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return;
}
int QueueLength(sqQueue Q){		//����еĳ���
	return(Q.rear-Q.front+M)%M;
}
int EnQueue(sqQueue &Q,Node e){	//���
	if((Q.rear+1)%M == Q.front)
		return 0;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear+1)%M;
	return 1;
}
int DeQueue(sqQueue &Q){		//����
	if(Q.front == Q.rear)
		return 0;
	Q.front = (Q.front+1)%M;
	return 1;
}
Node getHead(sqQueue Q){	//�õ�����ͷ����Ԫ��
	return Q.base[Q.front];
}
void bfs(){				//��bfs���������ʼ����벻����7�ĵ�ĸ���ռ�����İٷֱ�
	memset(vis,0,sizeof vis);
	InitQueue(Q);
	Node cur,next;
	cur.id = 0;
	cur.step = 0;
	EnQueue(Q,cur);
	vis[0] = 1;
	int num = 0;
	while(QueueLength(Q)){
		cur = getHead(Q);
		DeQueue(Q);
		if(cur.step>7){
			break;
		}
		num++;
		int s = cur.id;
		for(int p = head[s];p!=-1;p=edge[p].next){
			int v = edge[p].to;
			if(!vis[v]){
				next.id = v;
				next.step = cur.step + 1;
				vis[v] = 1;
				EnQueue(Q,next);
			}
		}
	}
	printf("%.4f\n",num*1.0/n);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("out.txt","w",stdout);
#endif
    while(sfd(n,m)!=EOF){		//nΪ�����������mΪ�ߵ�����,��ı�Ŵ�0-n-1
    	Init();			//��ʼ��
    	int u,v;
    	for(int i=0;i<m;i++){
    		scanf("%d%d",&u,&v);		//�����������ڵĵ�
    		addEdge(u,v);
    		addEdge(v,u);		//�����
    	}
    	bfs();
    }
return 0;
}
