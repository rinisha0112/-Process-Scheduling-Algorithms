#include <iostream>
#define SIZE 5
using namespace std;
int main()
{
	int arrival[SIZE];
	int burst[SIZE];
	int i,j;
	float wt_fcfs;
	float fcfs(int arr[], int brr[], int n);
	cout<<"Enter Arrival time for: "<<endl;
	for(i=0;i<SIZE;i++)
	{
		cout<<"P"<<i+1<<": ";
		cin>>arrival[i];
	}
	cout<<endl<<"Enter Burst Time for: "<<endl;
	for(i=0;i<SIZE;i++)
	{
		cout<<"P"<<i+1<<": ";
		cin>>burst[i];
	}
	wt_fcfs=fcfs(arrival,burst,SIZE);
	cout<<"Avrage waitng tme s : "<<wt_fcfs<<endl;
	
	

}
float fcfs(int arr[], int brr[], int n)
{
	int wait[n],sumb=0,sumw=0;
	int i;
	float ret;
	if(arr[0]==0)
	{
		wait[0]=0;
	}
	else
	{
		wait[0]=arr[0];
	}
	sumb=brr[0];
	sumw=wait[0];
	for(i=1;i<n;i++)
	{
		wait[i]=sumb-arr[i];
		sumb=sumb+brr[i];
		sumw=sumw+wait[i];
	}
	ret=(float)sumw/n;
	return(ret);

}
