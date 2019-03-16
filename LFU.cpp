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
	int *fetch_frequency;
	int *set_frequency;
	public:
	Frame(int s)
	{
		size=s;
		a=new int[size];
		b=new int[size];
		fetch_frequency=new int[size];
	
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
		int n;
		//cout<<"1";
		n=a[i];
		set_frequency[n]--;
		//cout<<"2";
		if(set_frequency[n]==0)
		{
			set_frequency[n]=-1;
		}
		a[i]=x;
		b[i]=index;
		set_frequency[x]++;
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
	int set_freq(Process x[], int s)
	{
		int max=x[0].proc_id;
		for(int i=0;i<s;i++)
		{
			if(x[i].proc_id>max)
			{
				max=x[i].proc_id;
			}
		}
		set_frequency=new int[max+1];
		for(int i=0;i<(max+1);i++)
		{
			set_frequency[i]=0;
		}
	}
	
	int fetch_min_frequency()
	{
		int x[size],min,flag=1,pos,min_b,ret,prev,n,y;
		for(int i=0;i<size;i++)
		{
			n=a[i];
			x[i]=set_frequency[n];
			
		}
		pos=prev=0;
		min=x[0];
		for(int i=0;i<size;i++)
		{
			
			if(x[i]<=min)
			{
			
				prev=pos;
				min=x[i];
				pos=i;
				
			}
		}
		if(pos!=prev&&x[pos]==x[prev])
		{
			cout<<"HERE!!"<<endl;
			min_b=b[0];
			ret=0;
			for(int i=0;i<size;i++)
			{
				
				y=b[i];
				if(y<min_b&&set_frequency[y]!=-1&&set_frequency[y]==x[pos])
				{
					min_b=b[i];
					ret=i;
				}
			}
		}
		else
		{
			ret=pos;
		}
		//cout<<"0";
		//cout<<ret;
		return(ret);
		
	}
	void print()
	{
		for(int i=0;i<size;i++)
		{
			cout<<a[i]<<endl;
		}
	}
	void increment_frequency(int x)
	{
		set_frequency[x]++;
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
	y=f.set_freq(p,n);
	
	for(int i=0;i<n;i++)
	{
		if(i<s)
		{
					if(f.get_frame(j)==-1)
					{
						f.set_frame(j,p[i].proc_id,i);
					
					}
					j++;
					fault++;
					
		}
		else
		{
				if(f.is_present(p[i].proc_id)==false)
				{
			
				
					
					
					//x=f.get_least_index();
					f.set_frame(f.fetch_min_frequency(),p[i].proc_id,i);
					fault++;
					
				}
				else
				{
					f.increment_frequency(p[i].proc_id);
				}
			
		}
		f.print();
		cout<<endl;
			
		
	}
	cout<<"No of Page Faults are: "<<fault<<endl;
}
