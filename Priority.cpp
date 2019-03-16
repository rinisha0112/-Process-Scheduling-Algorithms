#define MEMORY_H
#include <iostream>
using namespace std;
#include <stdlib.h>
   int main()
   {
       int pos=0,temp,n,i;
       int *p,*bt,*pt,*wt,*tat;
       cout<<"Enter the number of processes:"<<endl;
       cin>>n;
       
       cout<<"Enter the burst times: "<<endl;
       p=new int[n];
       bt=new int[n];
       pt=new int[n];
       wt=new int[n];
       tat=new int[n];
       for(i=0;i<n;i++)
       {
           p[i]=i+1;
           cin>>bt[i];
       }
       cout<<"Enter priority time:";
       for(i=0;i<n;i++)
       {
           cin>>pt[i];
       }
       for(i=0;i<n;i++)
       {
           pos=i;
           for(int j=i+1;j<n;j++)
           {
               if(pt[j]<pt[pos])
               pos=j;
           }
           temp=pt[pos];
           pt[pos]=pt[i];
           pt[i]=temp;
           temp=p[pos];
           p[pos]=p[i];
           p[i]=temp;
           temp=bt[pos];
           bt[pos]=bt[i];
           bt[i]=temp;
       }
       wt[0]=0;
       for(i=1;i<n;i++)
       {
           wt[i]=0;
           for(int j=0;j<i;j++)
           {
               wt[i]+=bt[j];
           }
       }
     	//cout<<"Process\tBT\tpriority\twaiting time\tTAT";
       for(i=0;i<n;i++)
       {
           tat[i]=bt[i]+wt[i];
           cout<<"Process: "<<p[i]<<"\tBurst Time: "<<bt[i]<<"\tPriority: "<<pt[i]<<"\tWaiting time:"<<wt[i]<<"\tTAT:"<<tat[i]<<endl;
       }
   }

