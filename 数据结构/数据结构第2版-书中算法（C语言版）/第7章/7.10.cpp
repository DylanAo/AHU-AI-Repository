#include<iostream>
using namespace std;

//算法7.10　哈希表的查找
//- - - - -开放地址法哈希表的存储表示- - - - -
#define m 16                        			//哈希表的表长
#define NULLKEY 0                 			//单元为空的标记

struct HashTable{
   int  key;		         	 			//关键字项
// InfoType  otherinfo;					//其他数据项
};

//	算法7.10为哈希表查找的算法，采用线性探测法处理冲突。
//	【算法实现】

int H(int key)
{
	int result;
	result=key%13;
	return result;
} 

int SearchHash(HashTable HT[],int key){
  //在哈希表HT中查找关键字为key的元素，若查找成功，返回哈希表的单元标号，否则返回-1 
  int H0=H(key);     	                   			//根据哈希函数H（key）计算哈希地址
  int Hi;
  if (HT[H0].key==NULLKEY) return -1;		//若单元H0为空，则所查元素不存在
  else if (HT[H0].key==key) return H0;		//若单元H0中元素的关键字为key，则查找成功
  else{             
     for(int i=1;i<m;++i){                
		 Hi=(H0+i)%m;     		//按照线性探测法计算下一个哈希地址Hi
        if (HT[Hi].key==NULLKEY) return -1;	//若单元Hi为空，则所查元素不存在
        else if (HT[Hi].key==key) return Hi; 	//若单元Hi中元素的关键字为key，则查找成功
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
		cout<<"在第"<<result<<"位置找到"<<endl;
	}
	else
	{
		cout<<"未找到"<<endl;
	}
}