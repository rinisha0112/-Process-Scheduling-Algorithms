#define MEMORY_H
#include <iostream>
#include <stdlib.h>
using namespace std;
static int fault=0;
 class Frame
{
	int size;
	
	int *a;
	int *b;
	public:
	Frame(int s)
	{
		size=s;
		a=new int[size];
		b=new int[size];
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
	void set_frame(int i, int x, int index)
	{
		a[i]=x;
		b[i]=index;
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
	/*void search_and_replace(int pos, int n)
	{
		for(int i=0;i<size;i++)
		{
			if(x==a[i])
			{
				a[i]=n;
			}
		}
	}*/
	int get_least_index()
	{
		int min=b[0],pos=0;
		for(int i=0;i<size;i++)
		{
			if(b[i]<min)
			{
				min=b[i];
				pos=i;
			}
		}
		return(pos);
		
	}
};

 class Process
{
	public:
	int proc_id;

		
	Process()
	{
		cout<<"Enter Process id: "<<endl;
		
		cin>>proc_id;
	}
	
	/*void get_proc(Process p, Frame f)
	{
		for(i=0;i<n;i++)
		{
			
			if(f.)
		}
	}*/
};

int main()
{
	int n,s,j=0,x;
	cout<<"Enter No of Process (String Length): "<<endl;
	cin>>n;
	cout<<"Enter Size of Main Frame: "<<endl;
	cin>>s;
	Frame f(s);
	Process p[n];
	for(int i=0;i<n;i++)
	{
		if(i<s)
		{
					if(f.get_frame(j)==-1)
					{
						f.set_frame(j,p[i].proc_id,i);
					
					}
					j++;
		}
		else
		{
				if(f.is_present(p[i].proc_id)==false)
				{
			
				
			
					
					x=f.get_least_index();
					f.set_frame(x,p[i].proc_id,i);
				
					fault++;
					
				}
		}
			
		
	}
	cout<<"No of Page Faults are: "<<fault<<endl;
}
