#include <stdio.h>
#include <string.h>
char str[100];
int main(){
	get(str);
	void max();
	max();
}
void max(){
	int i,word;
	char c;
	int a[100];
	int i2=0;
	for (i=0;(c=str[i])!='\0';i++)
	 if(c==' ') word=0;
	 else if (word==0){
	 	word=1; //�ж��Ƿ�Ϊ��������
	 	i2=0;   //��¼���ﵥ�ʽ�������λ��
	 	a[i2]=i;
	 	i2++;
	 }
}