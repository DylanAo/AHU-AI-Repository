//����������
//����ĳ�������ĸ����ڶ���Ӵ��ͻ������糿���п����𲻶��пͻ��������С�
//����ÿ��������ĳ��ʱ��ֻ�ܽӴ�һ���ͻ�������ڿͻ������ڶ�ʱ����ÿ������ǰ˳���Ŷ�
//���ڸս������еĿͻ������ĳ�����ڵ�ҵ��Ա�����У������ǰ����ҵ�񣬷�֮�����ĸ����ھ��пͻ���ռ������������������ٵĶ�����档
//������Ҫ���Ƴ�����ģ�����е�����ҵ��������һ���пͻ������ж�����ƽ��ʱ�䡣

//1. ����
	//4�����񴰿ڶ���(1)
//2. �����
	//�Զ��������Χ
	//ģ��ͻ�����ʱ���ҵ�����ʱ��
//3. ʱ��
	//�����Ҫ���ʱ�䣨�ϰ�ʱ��Ϊʱ����㣩
	//ʵ�ʷ���ϰ���Ǿ���ʱ��
//4. �Զ��������ϰ�ʱ��
	//����8:30�ϰ࣬����5:00�°�
	//������Ϣ
	//���粻��Ϣ
	//������Ϣ
	//��ֵ����񴰿�
	//��1��ֵ����񴰿�
//5. �ͻ��ṹ�壨Customer��
	//����ʱ��: ���ʱ������ʱ��
	//������Ҫʱ��
//6. ���񴰿ڽṹ�壨Window��
	//ʣ�����ʱ��
	//�ۼ��ܵȴ�ʱ��
	//�ŶӶ���
//7. ���нṹ�壨Bank��
	//���°�ʱ��
	//�Ƿ����ݣ�1/0��
	//ֵ�ര����
	//���񴰿ڶ�������
	//������ͻ�����
	//�ۼƷ�������

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
using namespace std;
#define NumOfWindows 4
#define Maxsize 500

typedef struct windows
{
    int CusRemainTime; // ��ǰ����ҵ��Ŀͻ���ʣ�����ʱ��(��ʱ������ʱ-1)
    int AllRemainTime; // ��ʣ���������ʱ��(����ͻ�ʱ+N)(��ʱ������ʱ-1)
    int total_wait_time; // ͳ�Ƹ÷��񴰿����й˿͵ĵȴ�ʱ��(��ʱ������ʱ+m)

	int CustomerNumber;//��¼��ǰ�ô����ǵڼ�λ�˿�(���һ���ͻ�ʱ+1)
	int CustomerAllNumber;//��¼�ô��ڿ���֮�����Ĺ˿�������(����ͻ�ʱ+1)
	int Customer[Maxsize];//����һ���������ڼ�¼��n���˿�����ķ���ʱ��(����ͻ�ʱ�ı�)
}windows;//���񴰿ڽṹ��

typedef struct bank
{
	int bank_work_time;//����ʣ�๤��ʱ��(��ʱ������ʱ-1)
    windows windows[NumOfWindows]; // 4�����񴰿�
}bank;//�������нṹ��

typedef struct bank_wuxiu
{
	int bank_work_time;//����ʣ�๤��ʱ��
    windows windows; // 1�����񴰿�
}bank_wuxiu;//��������ʱ�����нṹ�壨��������ʱ������һ�ӣ�
//��������

int WindowsTimeCompute(bank thebank)//�ҳ��ȴ�ʱ����̵Ĵ���
{
	int a=thebank.windows[0].AllRemainTime;
	for(int b=0;b<4;b++)
	{
		if (thebank.windows[b].AllRemainTime < a)
			a=thebank.windows[b].AllRemainTime;
	}
	return a;
}
void CharuWindows(windows &windows)//�����ɵĹ˿Ͳ��봰��
{
	int r2=(rand() % (30-10+1))+ 10;//�ڷ�ΧΪ[10,30]������һ���������Ϊ�˿͵ķ���ʱ��
	cout<<"������һ���˿ͣ��ù˿͵ķ���ʱ��(����)Ϊ��"<<r2<<endl;
	
	int a=0;
	for(;a<Maxsize;a++) 
	{
		if (windows.Customer[a] == 0) 
			{
				windows.Customer[a]=r2;
				windows.AllRemainTime+=r2;
				windows.CustomerAllNumber++;
				break;
			}
	}
}

void timeout(windows &windows,int &a,int &b,int &c)//aΪӪҵʱ�䣬b�ǹ˿�������c�ǹ˿��ܵȴ�ʱ��
{
	if (windows.CusRemainTime != 0 )
	{
		windows.AllRemainTime--;
		windows.CusRemainTime--;
		windows.total_wait_time+=windows.CustomerAllNumber-windows.CustomerNumber+1;
	}
	else
	{
		if (windows.Customer[1+(windows.CustomerNumber)]!=0)  
		{
			windows.CustomerNumber++;
			windows.CusRemainTime=windows.Customer[windows.CustomerNumber];
			windows.AllRemainTime--;
			windows.CusRemainTime--;
			windows.total_wait_time+=windows.CustomerAllNumber-windows.CustomerNumber+1;
		}
		if (windows.Customer[1+(windows.CustomerNumber)]==0)
		{
		}
	}
}
//ʱ�����ŵĺ���Ӧ��ÿһ��ʱ���ڼ�¼�Ƿ��й˿ͽ��룬���˿͵ȴ�ʱ��

//2.���ɹ˿�ʱ������Ƿ����°�ǰ�ܹ���ɸù˿͵�ҵ���������������
//3.���¶��������ڸ������е�״̬�����¶�����ʱ�䣬���й˿���ɶ��������״̬��ɾ���˿ͣ�


//���п��ź���
void OpenBank(int &a,int &b,int &c)//���п��ź���Ӧ��ÿһ�ο���Ӫҵʱ(aΪӪҵʱ��)��¼�Ƿ��й˿ͽ���(b�ǹ˿�����)�����˿͵ȴ�ʱ��(c�ǹ˿��ܵȴ�ʱ��)
{
	bank thebank;
	thebank.bank_work_time=a;
	for(int n=0;n<4;n++)
	{
		for(int m=0;m<Maxsize;m++)
			thebank.windows[n].Customer[m]=0;
		thebank.windows[n].CusRemainTime=0;
		thebank.windows[n].AllRemainTime=0;
		thebank.windows[n].total_wait_time=0;
		thebank.windows[n].CustomerNumber=-1;
		thebank.windows[n].CustomerAllNumber=0;
	}
	//��ʼ�����к������ĸ����е���ֵ���Է����ִ���
	for(int m=0;m<a;m++)
	{
		int lesswindow=WindowsTimeCompute(thebank);//�Ƚϲ����ܵȴ�ʱ����̵Ķ���
		int r1=(rand() % (100-0+1))+1;//����һ�������:0-100���������<10ʱ����һ���˿�
		if (r1<10)  
		{
			CharuWindows(thebank.windows[lesswindow]);
		}
		for (int aaa=0;aaa<4;aaa++) timeout(thebank.windows[aaa],a,b,c);

		thebank.bank_work_time--;
	}
	for(int n=0;n<4;n++)
	{
		b=b+thebank.windows[n].CustomerAllNumber;
		c=c+thebank.windows[n].total_wait_time;
	}
}

void OpenBank_Wuxiu(int &a,int &b,int &c)
{
	bank_wuxiu thebank;
	thebank.bank_work_time=a;
	for(int m=0;m<Maxsize;m++)
		thebank.windows.Customer[m]=0;
	thebank.windows.CusRemainTime=0;
	thebank.windows.AllRemainTime=0;
	thebank.windows.total_wait_time=0;
	thebank.windows.CustomerNumber=-1;
	thebank.windows.CustomerAllNumber=0;
	//��ʼ�����к������ĸ����е���ֵ���Է����ִ���
	for(int m=0;m<a;m++)
	{
		int r1=(rand() % (100-0+1))+1;//����һ�������:0-100���������<10ʱ����һ���˿�
		if (r1<10)  
		{
			CharuWindows(thebank.windows);
		}
		timeout(thebank.windows,a,b,c);

		thebank.bank_work_time--;
	}

		b=b+thebank.windows.CustomerAllNumber;
		c=c+thebank.windows.total_wait_time;

}
//���п��ź���Ӧ��ÿһ�ο���Ӫҵʱ(aΪӪҵʱ��)��¼�Ƿ��й˿ͽ���(b�ǹ˿�����)�����˿͵ȴ�ʱ��(c�ǹ˿��ܵȴ�ʱ��)


int TimeCompute(int a,int b,int c,int d)
{            
    if(((a<0||a>=24)||(c<0||c>=24))||((b<0||b>=60)||(d<0||d>=60)))//�ж�����Сʱ���ͷ������Ƿ�Ϸ�
    {
        cout<<"�����Сʱ��Ӧ����0-24֮��"<<endl;
        cout<<"����ķ�����Ӧ����0-60֮��"<<endl;
    }

    if(a<c)
    {	
		if (b>d)//����Ŀ��ŷ��������ڹ��ŷ�����,��ʱ��Ϊd-a-1��Сʱ���60-(b-e)����
        return 60*(c-a-1)+(60-(d-b));
        else if (b<=d)//����ĵ�һ��������С�ڵ��ڵڶ���
		return 60*(c-a)+(b-d);
    }
	else if (a=c) return (d-b);//Сʱ��һ��ʱ��ʱ���
}
//��������ʱ���ʱ���(min)

int main()
{
	int OpenTime_Hours;
	int OpenTime_mins;
	int CloseTime_Hours;
	int ClosTime_mins;//�����������°�ʱ��
	cout<<"�����뿪��ʱ��"<<endl;
    cout<<"���ŵ�ʱ(24Сʱ���µ�):"<<endl;
    cin>>OpenTime_Hours;
    cout<<"���ŵķ�:"<<endl;
    cin>>OpenTime_mins;
    cout<<"���ŵ�ʱ(24Сʱ���µ�):"<<endl;
    cin>>CloseTime_Hours;
    cout<<"���ŵķ�:"<<endl;
    cin>>ClosTime_mins;
	
	int wuxiu;
	cout<<"�Ƿ������ݣ���������1����������0��"<<endl;
	cin>>wuxiu;//�Ƿ�������

	int Customer_wait_time=0;
	int Customer_num=0;

	if (wuxiu==1) 
	{
		int wuxiuTime_begin_Hours;
		int wuxiuTime_gebin_mins;
		int wuxiuTime_end_Hours;
		int wuxiuTime_end_mins;
		int wuxiuTime_continue_mins;
		cout<<"���������ݿ�ʼʱ��"<<endl;
		cout<<"���ݿ�ʼ��ʱ(24Сʱ���µ�):"<<endl;
		cin>>wuxiuTime_begin_Hours;
		cout<<"���ݿ�ʼ�ķ�:"<<endl;
		cin>>wuxiuTime_gebin_mins;
		cout<<"���ݽ�����ʱ(24Сʱ���µ�):"<<endl;
		cin>>wuxiuTime_end_Hours;
		cout<<"���ݽ����ķ�:"<<endl;
		cin>>wuxiuTime_end_mins;
		wuxiuTime_continue_mins=TimeCompute(wuxiuTime_begin_Hours,wuxiuTime_gebin_mins,wuxiuTime_end_Hours,wuxiuTime_end_mins);

		int zhiban;
		cout<<"�Ƿ���ֵ�ര�ڣ���������1����������0��"<<endl;
		cin>>zhiban;//�Ƿ���ֵ��

		if (zhiban == 0)//��ֵ�ര��
			{
				int worktime_1_relatively=TimeCompute(OpenTime_Hours,OpenTime_mins,wuxiuTime_begin_Hours,wuxiuTime_gebin_mins);//����ǰ���п���ʱ��
				int worktime_2_relatively=TimeCompute(wuxiuTime_end_Hours,wuxiuTime_end_mins,CloseTime_Hours,ClosTime_mins);//���ݺ����п���ʱ��

				for(int n=0;n<7;n++)
				{								
					int Customer_num_1=0;
					int Customer_num_2=0;				
					int Customer_wait_time_1=0;
					int Customer_wait_time_2=0;

					OpenBank(worktime_1_relatively,Customer_num_1,Customer_wait_time_1);//����ǰ���п���
					OpenBank(worktime_2_relatively,Customer_num_2,Customer_wait_time_2);//���ݺ����п���

					Customer_wait_time+=(Customer_wait_time_1+Customer_wait_time_2);
					Customer_num+=(Customer_num_1+Customer_num_2);
				}
			}
		else//��ֵ�ര��
			{

				int worktime_1_relatively=TimeCompute(OpenTime_Hours,OpenTime_mins,wuxiuTime_begin_Hours,wuxiuTime_gebin_mins);//����ǰ���п���ʱ��
				int worktime_2_relatively=TimeCompute(wuxiuTime_end_Hours,wuxiuTime_end_mins,CloseTime_Hours,ClosTime_mins);//���ݺ����п���ʱ��
				for(int n=0;n<7;n++)
				{	
					int Customer_wait_time_1=0;
					int Customer_num_1=0;
					int Customer_wait_time_2=0;
					int Customer_num_2=0;
					int Customer_wait_time_zhiban=0;
					int Customer_num_zhiban=0;

					OpenBank(worktime_1_relatively,Customer_num_1,Customer_wait_time_1);//����ǰ���п���
					OpenBank_Wuxiu(wuxiuTime_continue_mins,Customer_num_zhiban,Customer_wait_time_zhiban);//����ʱֵ�ര������
					OpenBank(worktime_2_relatively,Customer_num_2,Customer_wait_time_2);//���ݺ����п���

					Customer_wait_time+=(Customer_wait_time_1+Customer_wait_time_2+Customer_wait_time_zhiban);
					Customer_num+=(Customer_num_1+Customer_num_2+Customer_num_zhiban);
						
				}
			}
	}//�����ݣ��������ݿ�ʼʱ�����ʱ��(����)�����㲢�������һ���е�ƽ���ͻ�����ʱ��
	else
	{
		// ������
		int worktime_relatively=TimeCompute(OpenTime_Hours,OpenTime_mins,CloseTime_Hours,ClosTime_mins);
		for(int n=0;n<7;n++)
		{
			int Customer_wait_time_3=0;
			int Customer_num_3=0;

			OpenBank(worktime_relatively,Customer_num_3,Customer_wait_time_3);

			Customer_wait_time+=Customer_wait_time_3;
			Customer_num+=Customer_num_3;
		}
	}
	int aver_time=Customer_wait_time/Customer_num;
	cout<<"һ��ƽ���˿Ͷ���ʱ��Ϊ:"<<aver_time<<"�����ӣ�"<<endl;
	system("pause"); 
}
