#define MEMORY_H
#define INT_MAX
#include <iostream>
#include <stdlib.h>
using namespace std;
static int fault=0;

 class Process
{
	public:
	int proc_id;
	int frequency;
	
		
	Process()
	{
		cout<<"Enter Process id: "<<endl;
		cin>>proc_id;
		frequency=1;
	}
	
	/*void get_proc(Process p, Frame f)
	{
		for(i=0;i<n;i++)
		{
			
			if(f.)
		}
	}*/
};
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
	void set_frame(int i, int x)
	{
		a[i]=x;
		b[i]=INT_MAX;
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
	int get_most_frequency(Process x[],int k, int s)
	{
		int flag=0;
		for(int m=0;m<size;m++)
		{
			flag=0;
			for(int i=k; i<s;i++)
			{
				if(a[m]==x[i].proc_id)
				{
					b[m]=i;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				b[m]=INT_MAX;
			}
		}
		for(int i=0;i<size;i++)
		{
			cout<<"a["<<i<<"] = "<<a[i]<<" index: "<<b[i]<<endl;
		}
		int max=b[0], pos=0;
		for(int i=0;i<size;i++)
		{
			
			if(b[i]>max)
			{
				max=b[i];
				pos=i;
			}
		}
		cout<<"Pos: "<<pos<<endl;
		return(pos);
		//return(pos);
		
	}

};



int main()
{
	int n,s,j=0,x,y;
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
						f.set_frame(j,p[i].proc_id);
					
					}
					j++;
					fault++;
		}
		else
		{
				if(f.is_present(p[i].proc_id)==false)
				{
			
					x=f.get_most_frequency(p,i+1,n);
					f.set_frame(x,p[i].proc_id);
				
					fault++;
					
				}
		}
			
		
	}
	cout<<"No of Page Faults are: "<<fault<<endl;
}

/*void swap(Process &x, Process &y)
{
	int temp=x.proc_id;
	x.proc_id=y.proc_id;
	y.proc_id=temp;
}*/
/*	y=n-1;
	for(int i=0;i<=(n-1)/2;i++)
	{
		swap(p[i],p[y]);
		y--;
	}
	for(int i=0;i<n;i++)
	{
		cout<<"pid: "<<p[i].proc_id<<endl;
	}*/
