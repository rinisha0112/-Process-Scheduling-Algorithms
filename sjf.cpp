#include <iostream>
using namespace std;
//static int count=0;
//8int main()

class Process 
{
//	char name[3];
	public:
	int proc_no;
	int arrv_time;
	int burst_time;
	int order;
	int waiting_time;
	int tat;
	int completion_time;
	
	public:
	Process();
	Process(int b);
	Process(const Process& obj);
	~Process();
	//void print(Process &p);
	
		
};

Process::Process()
{
	//cout<<"Enter Process id: "<<endl; 
	//count++; 
	cout<<"Enter Process no: ";
	cin>>proc_no;     
	//0cin>>arrv_time;
	arrv_time=0;
	cout<<"Enter Burst Time: ";
	cin>>burst_time;
	cout<<endl;
	waiting_time=0;
	tat=0;
	completion_time=0;
	order=proc_no;
	
}
Process::Process(int b)
{
	arrv_time=0;
	burst_time=b;
	waiting_time=0;
	tat=0;
	completion_time=0;
	order=0;
	
}
/*Process::Process(int a, int b)
{
	arrv_time=0;
	burst_time=b;
	waiting_time=0;
	tat=0;
	completion_time=0;
	order=0;
}*/
Process::~Process()
{
	cout<<"Process Completed!"<<endl;
}
Process::Process(const Process& obj)
{
	arrv_time=obj.arrv_time;
	burst_time=obj.burst_time;
	waiting_time=obj.waiting_time;
	tat=obj.tat;
	completion_time=obj.completion_time;
	order=obj.order;
}
void print(Process &p)
{
	/*cout<<"		Process ID"<<"		Arrival Time"<<"		Burst Time"<<"		Waiting Time"<<"		TAT"<<"		Completion Time	"<<endl;
	cout<<"		"<<p.proc_no<<""<<"		"<<p.arrv_time<<""<<"		"<<p.burst_time<<""<<"		"<<p.waiting_time<<""<<"		"<<p.tat<<""<<"		"<<p.completion_time<<endl;*/
	
	
	
	
	
	
	cout<<"Process P"<<p.proc_no<<endl;
	cout<<"arrv_time: "<<p.arrv_time<<endl;
	cout<<"burst_time: "<<p.burst_time<<endl;
	cout<<"waiting_time: "<<p.waiting_time<<endl;
	cout<<"tat: "<<p.tat<<endl;
	cout<<"Completion time: "<<p.completion_time<<endl;
	cout<<"order: "<<p.order<<endl;
	cout<<endl;
}



void Sort_SJF(Process obj[], int size)
{
	int i,j,flag=0,min,pos;
	Process temp(0);
	for(i=0;i<size-1;i++)
	{
		min=obj[i].burst_time;
		pos=i;
		flag=0;
		for(j=i+1;j<size;j++)
		{
			if((obj[j].burst_time)<min)
			{
				min=obj[j].burst_time;
				pos=j;
				flag=1;
			}
			else if(obj[j].burst_time==min)
			{
				if(obj[j].order<obj[pos].order)
				{
					min=obj[j].burst_time;
					pos=j;
					flag=1;
				}
			}
		}
		if(flag==1)
		{
			temp=obj[pos];
			obj[pos]=obj[i];
			obj[i]=temp;
			cout<<"Swapped!"<<endl;
		}
		
	}
}

void completion_time(Process obj[], int size)
{
	int sum;
	for(int i=0;i<size;i++)
	{
		sum=sum+obj[i].burst_time;
		obj[i].completion_time=sum;
	}
}

void waiting_time(Process obj[], int size)
{
	for(int i=0;i<size;i++)
	{
		obj[i].waiting_time=obj[i].completion_time-obj[i].burst_time-obj[i].arrv_time;
	}
}



void tat(Process obj[], int size)
{
	for(int i=0;i<size;i++)
	{
		obj[i].tat=obj[i].completion_time-obj[i].waiting_time;
	}
}

void average(Process obj[], int size)
{
	int sum_w=0,sum_tat=0,sum_completion=0;
	float avg_w,avg_tat,avg_completion;
	for(int i=0;i<size;i++)
	{
		sum_w=sum_w+obj[i].waiting_time;
		sum_tat=sum_tat+obj[i].tat;
		sum_completion=sum_completion+obj[i].completion_time;
		
	}
	avg_w=(float)sum_w/size;
		avg_tat=(float)sum_tat/size;
		avg_completion=(float)sum_completion/size;
		cout<<"Average Waiting Time is: "<<avg_w<<endl<<endl;
		cout<<"Average TA Time is: "<<avg_tat<<endl<<endl;
		cout<<"Average Completion Time is: "<<avg_completion<<endl<<endl;
		
}


	



int main()
{
	int n,i;
	cin>>n;
	Process p[n];
//	Schedule(p,n);
	for(i=0;i<n;i++)
	{
		print(p[i]);
	}
	//Process copy_p(0);
/*	for(i=0;i<n;i++)
	{
		copy_p[i]=Process(p[i]);
	}*/
	Sort_SJF(p,n);
	
	
	completion_time(p,n);
	
	waiting_time(p,n);
	
	tat(p,n);
	
	
		for(i=0;i<n;i++)
	{
		print(p[i]);
	}
	
	average(p,n);
	

	
}
	

