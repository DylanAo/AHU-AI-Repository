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
	 	word=1; //判断是否为整个单词
	 	i2=0;   //记录这里单词结束所在位置
	 	a[i2]=i;
	 	i2++;
	 }
}