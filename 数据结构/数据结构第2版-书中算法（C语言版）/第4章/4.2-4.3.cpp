/***字符串匹配算法***/
#include<cstring>
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
#define MAXSTRLEN 255   		//用户可在255以内定义最长串长
typedef char SString[MAXSTRLEN+1];		//0号单元存放串的长度

Status StrAssign(SString T, char *chars) { //生成一个其值等于chars的串T
	int i;
	if (strlen(chars) > MAXSTRLEN)
		return ERROR;
	else {
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return OK;
	}
}
//算法4.3　计算next函数值
void get_next(SString T, int next[])
{ //求模式串T的next函数值并存入数组next
	int i = 1, j = 0;
	next[1] = 0;
	while (i < T[0])
		if (j == 0 || T[i] == T[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
}//get_next

//算法4.2　KMP算法
int Index_KMP(SString S, SString T, int pos, int next[])
{ 	// 利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法
	//其中，T非空，1≤pos≤StrLength(S)
	int i = pos, j = 1;
	while (i <= S[0] && j <= T[0])
		if (j == 0 || S[i] == T[j]) // 继续比较后继字
		{
			++i;
			++j;
		}
		else
			j = next[j]; // 模式串向右移动
	if (j > T[0]) // 匹配成功
		return i - T[0];
	else
		return 0;
}//Index_KMP

int main()
{
	SString S;
	StrAssign(S,"aaabbaba") ;
	SString T;
	StrAssign(T,"abb") ;
	int *p = new int[T[0]+1]; // 生成T的next数组
	get_next(T,p);
	cout<<"主串和子串在第"<<Index_KMP(S,T,1,p)<<"个字符处首次匹配\n";
	return 0;
}
