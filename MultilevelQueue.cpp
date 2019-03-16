#include<iostream>
using namespace std;
int main()
{
   int p[20],bt[20], su[20], wt[20],tat[20],i, k, n, temp;
   float wtavg, tatavg;
   cout<<"Enter the number of processes: "<<endl;
   cin>>n;
   for(i=0;i<n;i++)
   {
       p[i] = i;
       cout<<"Enter the Burst Time of Process"<<i<<":"<<endl;
      	cin>>bt[i];
       cout<<"System/User Process (0/1) ? : "<<endl;
       cin>>su[i];
   }
   for(i=0;i<n;i++)
   {
       for(k=i+1;k<n;k++)
       {
           if(su[i] > su[k])
           {
               temp=p[i];
               p[i]=p[k];
               p[k]=temp;
               temp=bt[i];
               bt[i]=bt[k];
               bt[k]=temp;
               temp=su[i];
               su[i]=su[k];
               su[k]=temp;
           }   
       }   
   }
   wtavg = wt[0] = 0;
   tatavg = tat[0] = bt[0];
   for(i=1;i<n;i++)
   {
       wt[i] = wt[i-1] + bt[i-1];
       tat[i] = tat[i-1] + bt[i];
       wtavg = wtavg + wt[i];
       tatavg = tatavg + tat[i];
   }
   cout<<"\nPROCESS\t\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUND TIME"<<endl;
   for(i=0;i<n;i++)
   {
      cout<<"\n"<<p[i]<<"\t\t" << su[i]<<"\t\t "<<bt[i]<<" \t\t"<<wt[i]<<" \t\t"<<tat[i]<<endl;
   }   
   cout<<"\nAverage Waiting Time is : "<<(wtavg/n)<<endl;
   cout<<"\nAverage Turnaround Time is : "<<(tatavg/n);
   return(0);
}
