#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

typedef struct{   
   char ch[600];				//���Ƿǿմ����򰴴�������洢��������chΪNULL   
   int len;				//������   
}HString; 


int Index_BF(HString S,HString T,int pos)
{//����ģʽT������S�е�pos���ַ���ʼ��һ�γ��ֵ�λ�á��������ڣ��򷵻�ֵΪ0 
 //���У�T�ǿգ�1��pos��StrLength(S) 
	int i,j;
   i=pos; j=1;   
   while(i<=S.len&&j<=T.len)
   { 
      if(S.ch[i]==T.ch[j]){++i;++j;}	//�����ȽϺ���ַ� 
      else{i=i-j+2;j=1;}	//ָ��������¿�ʼƥ��
   }   
   if(j>T.len) return i-T.len;   
   else return 0;   
} 

void Virus_detection()
{ 
   int num,m,flag,i,j; char Vir[600];
   HString Virus,Person,temp;
   ifstream inFile("������Ⱦ�����������.txt");
   ofstream outFile("������Ⱦ���������.txt");
   inFile>>num;//��ȡ������������
   while(num--) //���μ��ÿ�Բ���DNA���˵�DNA�Ƿ�ƥ��
   {
      inFile>>Virus.ch+1;//��ȡ����DNA����
      inFile>>Person.ch+1;//��ȡ�˵�DNA����
      strcpy(Vir,Virus.ch);
	  Virus.len=strlen(Virus.ch)-1;
	  Person.len=strlen(Person.ch)-1;
	  flag=0;//������ʶ�Ƿ�ƥ�䣬��ʼΪ0��ƥ���Ϊ��0
	  m=Virus.len;
      for(i=m+1,j=1;j<=m;j++) Virus.ch[i++]=Virus.ch[j];
      //�򲡶�Ϊ��״���ʽ������ĳ�������2��
      //��������ȡ�����г���ΪVirus.len���ַ���
      Virus.ch[2*m+1]='\0';				//��ӽ�������
      for(i=0;i<m;i++)
      {
         for(j=1;j<=m;j++) temp.ch[j]=Virus.ch[i+j];
         //ȡ��ΪVirus.len�Ļ����ַ���
         //��Virus.ch[0]-- Virus.ch[Virus.len-1],
         //Virus.ch[1]-- Virus.ch[0], Virus.ch[2]-- Virus.ch[1]...
         temp.ch[m+1]='\0';		//��ӽ�������
		 temp.len=strlen(temp.ch)-1;
         flag=Index_BF(Person,temp,1);	//ģʽƥ��
         if(flag) break;				//ƥ�伴���˳�ѭ��
      }//for
      if(flag)
         outFile<<Vir+1<<"	"<<Person.ch+1<<"	"<<"YES"<<endl;
      else
         outFile<<Vir+1<<"	"<<Person.ch+1<<"	"<<"NO"<<endl;
   }//while
}

int main()
{
	Virus_detection();
	return 0;
}
	