
#define MEMORY_H
#include <iostream>
#include <stdlib.h>
using namespace std;
static int fault=0;
 class Process
{
	public:
	int proc_id;
	
	Process()
	{
		cout<<"Enter Process id: "<<endl;
		cin>>proc_id;
	}
};
 class Frame
{
	int size;
	
	int *a;
	public:
	Frame(int s)
	{
		size=s;
		a=new int[size];
		for(int i=0;i<s;i++)
		{
			a[i]=-1;
		}
		
	}
	int get_frame(int x)
	{
		if(x<size)
		{
			return(a[x]);
		}
		else
		{
			cout<<"Array acessed is out of Bound!"<<endl;
			return(-1);
		}
	
	}
	void set_frame(int i, int x)
	{
		a[i]=x;
	}
	
	bool is_present(int x)
	{
		bool ret=false;
		for (int i=0;i<size;i++)
		{
			if(x==a[i])
			{
				ret=true;
				break;
			
			}
		}
		return(ret);
	}
};

int main()
{
	int n,s,j=0;
	cout<<"Enter No of Process (String Length): "<<endl;
	cin>>n;
	cout<<"Enter Size of Main Frame: "<<endl;
	cin>>s;
	Frame f(s);
	Process p[n];
	for(int i=0;i<n;i++)
	{
		if(j!=s)
		{
			if(f.is_present(p[i].proc_id)==false)
			{
					if(f.get_frame(j)==-1)
				{
					f.set_frame(j,p[i].proc_id);
					
				}
				else// if(f.get_frame(j)!=p[i].proc_id)
				{
					f.set_frame(j,p[i].proc_id);
				}
				fault++;
				j++;
			}
	}
			else
			{
				j=0;
				/*	if(f.get_frame(j)==-1)
					{
						f.set_frame(j,p[i].proc_id);
						
					}
				else// if(f.get_frame(j)!=p[i].proc_id)
				{
					f.set_frame(j,p[i].proc_id);
				}
				fault++;
				j++;*/
					if(f.is_present(p[i].proc_id)==false)
			{
					if(f.get_frame(j)==-1)
				{
					f.set_frame(j,p[i].proc_id);
					
				}
				else// if(f.get_frame(j)!=p[i].proc_id)
				{
					f.set_frame(j,p[i].proc_id);
				}
				fault++;
				j++;
			}
			
		
			}
		
			
		
	}
	cout<<"No of Page Faults are: "<<fault<<endl;
	
}

