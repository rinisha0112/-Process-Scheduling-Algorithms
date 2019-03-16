#define MEMORY_H
#include <iostream>
using namespace std;

   void findWaitingTime(int processes[], int n,int bt[], int wt[], int quantum)
   {
   		int *rem_bt;
       rem_bt= new int[n];
       for (int i = 0 ; i < n ; i++)
       {
           rem_bt[i] =  bt[i];
       }   
       int t = 0;
       while(true)
       {
           bool done = true;
           for (int i = 0 ; i < n; i++)
           {
               if (rem_bt[i] > 0)
               {
                   done = false;     
                   if (rem_bt[i] > quantum)
                   {
                       t += quantum;
                       rem_bt[i] -= quantum;
                   }
                   else
                   {
                       t = t + rem_bt[i];
                       wt[i] = t - bt[i];
                       rem_bt[i] = 0;
                   }
               }
           }
           if (done == true)
           {
                break;
           }             
       }
   }     
    void findTurnAroundTime(int processes[], int n,int bt[], int wt[], int tat[])
   {
       for (int i = 0; i < n ; i++)
       {
           tat[i] = bt[i] + wt[i];
       }   
   } 
  void findavgTime(int processes[], int n, int bt[],int quantum)
   {
   		int *wt,*tat;
       wt = new int[n];
	    tat= new int[n];
       int total_wt = 0, total_tat = 0;   
       findWaitingTime(processes, n, bt, wt, quantum);
       findTurnAroundTime(processes,n,bt,wt,tat);
       cout<<"Processes " <<" Burst time " <<" Waiting time " << " Turn around time"<<endl;;
       for (int i=0; i<n; i++)
       {
           total_wt = total_wt + wt[i];
           total_tat = total_tat + tat[i];
          cout<<" " << (i+1) <<"\t\t" <<bt[i] <<"\t " <<wt[i] <<"\t\t "<<tat[i]<<endl;
       }
       cout<<"Average waiting time = "<<((float)total_wt / (float)n)<<endl;
       cout<<"Average turn around time = "<<((float)total_tat / (float)n)<<endl;
   } 
  int main()
   {
       int n,*processes,*burst_time,quantum;
       void findWaitingTime(int processes[], int n,int bt[], int wt[], int quantum);
       void findTurnAroundTime(int processes[], int n,int bt[], int wt[], int tat[]);
       void findavgTime(int processes[], int n, int bt[],int quantum);
      cout<<"enter the no of process"<<endl;
       cin>>n;
    	processes=new int[n];
      cout<<"enter the processes"<<endl;
       for(int i=0;i<n;i++)
       {
           cin>>processes[i];
       }
       burst_time= new int[n];
       cout<<"enter the burst times"<<endl;
       for(int i=0;i<n;i++)
       {
          cin>>burst_time[i];
       }   
      	cout<<"enter the time quantum"<<endl;
       cin>>quantum;
       findavgTime(processes, n, burst_time, quantum);
   }

