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

//算法4.1　BF算法
int Index(SString S, SString T, int pos)
{
	//返回模式T在主串S中第pos个字符之后第s一次出现的位置。若不存在，则返回值为0
	//其中，T非空，1≤pos≤StrLength(S)
	int i = pos;
	int j = 1;
	while(i <= S[0]&&j <= T[0])
	{
		if(S[i]==T[j])
		{
			++i;
			++j;
		} //继续比较后继字符
		else
		{
			i=i-j+2;
			j=1;
		} //指针后退重新开始匹配
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
	return 0;
}//Index

int main()
{
	SString S;
	StrAssign(S,"bbaaabbaba") ;
	SString T;
	StrAssign(T,"abb") ;
	cout<<"主串和子串在第"<<Index(S,T,1)<<"个字符处首次匹配\n";
	return 0;
}
