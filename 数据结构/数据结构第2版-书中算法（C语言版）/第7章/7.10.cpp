#include<iostream>
using namespace std;

//�㷨7.10����ϣ��Ĳ���
//- - - - -���ŵ�ַ����ϣ��Ĵ洢��ʾ- - - - -
#define m 16                        			//��ϣ��ı�
#define NULLKEY 0                 			//��ԪΪ�յı��

struct HashTable{
   int  key;		         	 			//�ؼ�����
// InfoType  otherinfo;					//����������
};

//	�㷨7.10Ϊ��ϣ����ҵ��㷨����������̽�ⷨ�����ͻ��
//	���㷨ʵ�֡�

int H(int key)
{
	int result;
	result=key%13;
	return result;
} 

int SearchHash(HashTable HT[],int key){
  //�ڹ�ϣ��HT�в��ҹؼ���Ϊkey��Ԫ�أ������ҳɹ������ع�ϣ��ĵ�Ԫ��ţ����򷵻�-1 
  int H0=H(key);     	                   			//���ݹ�ϣ����H��key�������ϣ��ַ
  int Hi;
  if (HT[H0].key==NULLKEY) return -1;		//����ԪH0Ϊ�գ�������Ԫ�ز�����
  else if (HT[H0].key==key) return H0;		//����ԪH0��Ԫ�صĹؼ���Ϊkey������ҳɹ�
  else{             
     for(int i=1;i<m;++i){                
		 Hi=(H0+i)%m;     		//��������̽�ⷨ������һ����ϣ��ַHi
        if (HT[Hi].key==NULLKEY) return -1;	//����ԪHiΪ�գ�������Ԫ�ز�����
        else if (HT[Hi].key==key) return Hi; 	//����ԪHi��Ԫ�صĹؼ���Ϊkey������ҳɹ�
     }//for
     return -1;
  }//else
}//SearchHash

void main()
{	
	int result;
	int a[16]={-1,14,1,68,27,55,19,20,84,79,23,11,10,-1.-1.-1};
	HashTable HT[m];
	for(int i=0;i<16;i++)
	{
		HT[i].key=a[i];
	}
	result=SearchHash(HT,55);
	if(result!=-1)
	{
		cout<<"�ڵ�"<<result<<"λ���ҵ�"<<endl;
	}
	else
	{
		cout<<"δ�ҵ�"<<endl;
	}
}