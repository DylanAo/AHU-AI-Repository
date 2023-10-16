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

//�㷨4.1��BF�㷨
int Index(SString S, SString T, int pos)
{
	//����ģʽT������S�е�pos���ַ�֮���sһ�γ��ֵ�λ�á��������ڣ��򷵻�ֵΪ0
	//���У�T�ǿգ�1��pos��StrLength(S)
	int i = pos;
	int j = 1;
	while(i <= S[0]&&j <= T[0])
	{
		if(S[i]==T[j])
		{
			++i;
			++j;
		} //�����ȽϺ���ַ�
		else
		{
			i=i-j+2;
			j=1;
		} //ָ��������¿�ʼƥ��
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
	cout<<"�������Ӵ��ڵ�"<<Index(S,T,1)<<"���ַ����״�ƥ��\n";
	return 0;
}
