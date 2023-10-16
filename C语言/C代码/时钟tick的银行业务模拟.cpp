//问题描述：
//假设某银行有四个窗口对外接待客户，从早晨银行开门起不断有客户进入银行。
//由于每个窗口在某个时刻只能接待一个客户，因此在客户人数众多时需在每个窗口前顺次排队
//对于刚进入银行的客户，如果某个窗口的业务员正空闲，则可上前办理业务，反之，若四个窗口均有客户所占，他便会排在人数最少的队伍后面。
//现在需要编制程序以模拟银行的这种业务活动并计算一天中客户在银行逗留的平均时间。

//1. 队列
	//4个服务窗口队列(1)
//2. 随机数
	//自定义随机范围
	//模拟客户到达时间和业务办理时长
//3. 时间
	//编程需要相对时间（上班时间为时间起点）
	//实际符合习惯是绝对时间
//4. 自定义银行上班时长
	//上午8:30上班，下午5:00下班
	//周日休息
	//中午不休息
	//中午休息
	//无值班服务窗口
	//有1个值班服务窗口
//5. 客户结构体（Customer）
	//到达时间: 相对时间或绝对时间
	//服务需要时长
//6. 服务窗口结构体（Window）
	//剩余服务时长
	//累计总等待时长
	//排队队列
//7. 银行结构体（Bank）
	//上下班时间
	//是否午休（1/0）
	//值班窗口数
	//服务窗口队列数组
	//待进入客户队列
	//累计服务人数

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
using namespace std;
#define NumOfWindows 4
#define Maxsize 500

typedef struct windows
{
    int CusRemainTime; // 当前办理业务的客户的剩余服务时长(在时间流逝时-1)
    int AllRemainTime; // 总剩余所需服务时长(加入客户时+N)(在时间流逝时-1)
    int total_wait_time; // 统计该服务窗口所有顾客的等待时长(在时间流逝时+m)

	int CustomerNumber;//记录当前该窗口是第几位顾客(完成一个客户时+1)
	int CustomerAllNumber;//记录该窗口开门之后进入的顾客总数量(加入客户时+1)
	int Customer[Maxsize];//创建一个队列用于记录第n个顾客所需的服务时长(加入客户时改变)
}windows;//服务窗口结构体

typedef struct bank
{
	int bank_work_time;//银行剩余工作时间(在时间流逝时-1)
    windows windows[NumOfWindows]; // 4个服务窗口
}bank;//定义银行结构体

typedef struct bank_wuxiu
{
	int bank_work_time;//银行剩余工作时间
    windows windows; // 1个服务窗口
}bank_wuxiu;//定义午休时的银行结构体（假设午休时单独另开一队）
//函数部分

int WindowsTimeCompute(bank thebank)//找出等待时间最短的窗口
{
	int a=thebank.windows[0].AllRemainTime;
	for(int b=0;b<4;b++)
	{
		if (thebank.windows[b].AllRemainTime < a)
			a=thebank.windows[b].AllRemainTime;
	}
	return a;
}
void CharuWindows(windows &windows)//将生成的顾客插入窗口
{
	int r2=(rand() % (30-10+1))+ 10;//在范围为[10,30]内生成一个随机数作为顾客的服务时间
	cout<<"生成了一个顾客，该顾客的服务时间(分钟)为："<<r2<<endl;
	
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

void timeout(windows &windows,int &a,int &b,int &c)//a为营业时间，b是顾客数量，c是顾客总等待时间
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
//时间流逝的函数应在每一段时间内记录是否有顾客进入，及顾客等待时间

//2.生成顾客时，检查是否在下班前能够完成该顾客的业务，若能则进入银行
//3.更新队列银行内各个队列的状态（更新队列中时间，若有顾客完成队列需更新状态，删除顾客）


//银行开门函数
void OpenBank(int &a,int &b,int &c)//银行开门函数应在每一段开门营业时(a为营业时间)记录是否有顾客进入(b是顾客数量)，及顾客等待时间(c是顾客总等待时间)
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
	//初始化银行和银行四个队列的数值，以防出现错误
	for(int m=0;m<a;m++)
	{
		int lesswindow=WindowsTimeCompute(thebank);//比较查找总等待时间最短的队列
		int r1=(rand() % (100-0+1))+1;//产生一个随机数:0-100，当随机数<10时生成一个顾客
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
	//初始化银行和银行四个队列的数值，以防出现错误
	for(int m=0;m<a;m++)
	{
		int r1=(rand() % (100-0+1))+1;//产生一个随机数:0-100，当随机数<10时生成一个顾客
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
//银行开门函数应在每一段开门营业时(a为营业时间)记录是否有顾客进入(b是顾客数量)，及顾客等待时间(c是顾客总等待时间)


int TimeCompute(int a,int b,int c,int d)
{            
    if(((a<0||a>=24)||(c<0||c>=24))||((b<0||b>=60)||(d<0||d>=60)))//判断输入小时数和分钟数是否合法
    {
        cout<<"输入的小时数应该在0-24之间"<<endl;
        cout<<"输入的分钟数应该在0-60之间"<<endl;
    }

    if(a<c)
    {	
		if (b>d)//输入的开门分钟数大于关门分钟数,则时长为d-a-1个小时外加60-(b-e)分钟
        return 60*(c-a-1)+(60-(d-b));
        else if (b<=d)//输入的第一个分钟数小于等于第二个
		return 60*(c-a)+(b-d);
    }
	else if (a=c) return (d-b);//小时数一致时求时间差
}
//计算两端时间的时间差(min)

int main()
{
	int OpenTime_Hours;
	int OpenTime_mins;
	int CloseTime_Hours;
	int ClosTime_mins;//输入银行上下班时间
	cout<<"请输入开门时间"<<endl;
    cout<<"开门的时(24小时制下的):"<<endl;
    cin>>OpenTime_Hours;
    cout<<"开门的分:"<<endl;
    cin>>OpenTime_mins;
    cout<<"关门的时(24小时制下的):"<<endl;
    cin>>CloseTime_Hours;
    cout<<"关门的分:"<<endl;
    cin>>ClosTime_mins;
	
	int wuxiu;
	cout<<"是否有午休，若有输入1，否则输入0："<<endl;
	cin>>wuxiu;//是否有午休

	int Customer_wait_time=0;
	int Customer_num=0;

	if (wuxiu==1) 
	{
		int wuxiuTime_begin_Hours;
		int wuxiuTime_gebin_mins;
		int wuxiuTime_end_Hours;
		int wuxiuTime_end_mins;
		int wuxiuTime_continue_mins;
		cout<<"请输入午休开始时间"<<endl;
		cout<<"午休开始的时(24小时制下的):"<<endl;
		cin>>wuxiuTime_begin_Hours;
		cout<<"午休开始的分:"<<endl;
		cin>>wuxiuTime_gebin_mins;
		cout<<"午休结束的时(24小时制下的):"<<endl;
		cin>>wuxiuTime_end_Hours;
		cout<<"午休结束的分:"<<endl;
		cin>>wuxiuTime_end_mins;
		wuxiuTime_continue_mins=TimeCompute(wuxiuTime_begin_Hours,wuxiuTime_gebin_mins,wuxiuTime_end_Hours,wuxiuTime_end_mins);

		int zhiban;
		cout<<"是否有值班窗口，若有输入1，否则输入0："<<endl;
		cin>>zhiban;//是否有值班

		if (zhiban == 0)//无值班窗口
			{
				int worktime_1_relatively=TimeCompute(OpenTime_Hours,OpenTime_mins,wuxiuTime_begin_Hours,wuxiuTime_gebin_mins);//午休前银行开门时长
				int worktime_2_relatively=TimeCompute(wuxiuTime_end_Hours,wuxiuTime_end_mins,CloseTime_Hours,ClosTime_mins);//午休后银行开门时长

				for(int n=0;n<7;n++)
				{								
					int Customer_num_1=0;
					int Customer_num_2=0;				
					int Customer_wait_time_1=0;
					int Customer_wait_time_2=0;

					OpenBank(worktime_1_relatively,Customer_num_1,Customer_wait_time_1);//午休前银行开门
					OpenBank(worktime_2_relatively,Customer_num_2,Customer_wait_time_2);//午休后银行开门

					Customer_wait_time+=(Customer_wait_time_1+Customer_wait_time_2);
					Customer_num+=(Customer_num_1+Customer_num_2);
				}
			}
		else//有值班窗口
			{

				int worktime_1_relatively=TimeCompute(OpenTime_Hours,OpenTime_mins,wuxiuTime_begin_Hours,wuxiuTime_gebin_mins);//午休前银行开门时长
				int worktime_2_relatively=TimeCompute(wuxiuTime_end_Hours,wuxiuTime_end_mins,CloseTime_Hours,ClosTime_mins);//午休后银行开门时长
				for(int n=0;n<7;n++)
				{	
					int Customer_wait_time_1=0;
					int Customer_num_1=0;
					int Customer_wait_time_2=0;
					int Customer_num_2=0;
					int Customer_wait_time_zhiban=0;
					int Customer_num_zhiban=0;

					OpenBank(worktime_1_relatively,Customer_num_1,Customer_wait_time_1);//午休前银行开门
					OpenBank_Wuxiu(wuxiuTime_continue_mins,Customer_num_zhiban,Customer_wait_time_zhiban);//午休时值班窗口运作
					OpenBank(worktime_2_relatively,Customer_num_2,Customer_wait_time_2);//午休后银行开门

					Customer_wait_time+=(Customer_wait_time_1+Customer_wait_time_2+Customer_wait_time_zhiban);
					Customer_num+=(Customer_num_1+Customer_num_2+Customer_num_zhiban);
						
				}
			}
	}//有午休，输入午休开始时间和总时长(分钟)，计算并输出银行一周中的平均客户逗留时间
	else
	{
		// 无午休
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
	cout<<"一周平均顾客逗留时间为:"<<aver_time<<"（分钟）"<<endl;
	system("pause"); 
}
