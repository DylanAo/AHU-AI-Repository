/***�ַ���ƥ���㷨***/
#include<cstring>
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
#define MAXSTRLEN 255   		//�û�����255���ڶ��������
typedef char SString[MAXSTRLEN+1];		//0�ŵ�Ԫ��Ŵ��ĳ���

Status StrAssign(SString T, char *chars) { //����һ����ֵ����chars�Ĵ�T
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
//�㷨4.3������next����ֵ
void get_next(SString T, int next[])
{ //��ģʽ��T��next����ֵ����������next
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

//�㷨4.2��KMP�㷨
int Index_KMP(SString S, SString T, int pos, int next[])
{ 	// ����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨
	//���У�T�ǿգ�1��pos��StrLength(S)
	int i = pos, j = 1;
	while (i <= S[0] && j <= T[0])
		if (j == 0 || S[i] == T[j]) // �����ȽϺ����
		{
			++i;
			++j;
		}
		else
			j = next[j]; // ģʽ�������ƶ�
	if (j > T[0]) // ƥ��ɹ�
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
	int *p = new int[T[0]+1]; // ����T��next����
	get_next(T,p);
	cout<<"�������Ӵ��ڵ�"<<Index_KMP(S,T,1,p)<<"���ַ����״�ƥ��\n";
	return 0;
}
