#include<iostream>
using namespace std;
struct graph
{
	char data;
	int in;
};
class stack
{
 public:
	int top;
	char pop();
	void push(char a);
	bool isemp();
	char b[100];
	stack()
	{
		top=-1;
	}
};
char stack::pop()
{
	if(top>-1)
	return b[top--];
}
void stack::push(char a)
{
	if(top<99)
	b[++top]=a;
}
bool stack::isemp()
{
	if(top==-1)
	return true;
	else
	return false;
}
bool visit(char c,char a[],int d)
{
	for(int i=0;i<d;i++)
	if(a[i]==c)
	return true;
	return false;
}
char check(graph **arr,int size,graph *visit)
{
	int p,p1,p2=0,k=0;char ch='*';
	for(p=0;p<size;p++)
	{
		for(p1=0;p1<size;p1++)
		{
			if(arr[p][p1].in!=0)
			{
				if(p2==0)
				p2=arr[p][p1].in;
				else
				{
	              if(p2!=arr[p][p1].in)
					{
					  k=1;break;	   
					}
				}
			}
		}
		p2=0;
		if(k!=1&&visit[p].in==0)
		{
			ch=arr[0][p].data;visit[p].in=1;break;
		}
		else
		k=0;
	}
	return ch;
}
bool vsit(char c,char a[],int d)
{
	for(int i=0;i<d;i++)
	if(a[i]==c)
	return true;
	return false;
}
int main()
{
	int a,p1,p2;char ch,b,c;
	cout<<"enter the no of vertices\n";
	cin>>a;
	const int size=a;
	graph **arr=new graph*[size];
	for(int i=0;i<size;i++)
	arr[i]=new graph[size];
	for(int i=0;i<size;i++)
	for(int j=0;j<size;j++)
	arr[i][j].in=0;
	for(int i=0;i<size;i++)
	{
		cout<<"enter the vertex "<<i+1<<endl;
		cin>>arr[0][i].data;
	}
	for(int i=1;i<size;i++)
	for(int j=0;j<size;j++)
	arr[i][j].data=arr[i-1][j].data;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		cout<<arr[i][j].data<<" ";
		cout<<endl;
	}
	do
	{
		cout<<"enter the edge vertices\n";
		cin>>b>>c;
		for(p1=0;p1<size;p1++)
		if(arr[0][p1].data==b)
		break;
		for(p2=0;p2<size;p2++)
		if(arr[0][p2].data==c)
		break;
		arr[p1][p2].in=1;arr[p2][p1].in=-1;
		cout<<"want to enter more\n";
		cin>>ch;
	}while(ch=='y');
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		cout<<arr[i][j].in<<" ";
		cout<<endl;
	}
	graph *visit=new graph[size];
	for(int i=0;i<size;i++)
	{
		visit[i].data=arr[0][i].data;
		visit[i].in=0;
	}char d=check(arr,size,visit);
	while(d!='*')
	{
		cout<<d<<endl;int i;
		for(i=0;i<size;i++)
		if(visit[i].data==d)
		{
			visit[i].in=1;break;
		}
		for(int j=0;j<size;j++)
		{
			arr[i][j].in=0;arr[j][i].in=0;
		}
		d=check(arr,size,visit);
	}stack s;
    for(int i=0;i<size;i++)
    if(visit[i].in==0)
    {
    	s.push(visit[i].data);break;
    }char a2[size];int count=0;
    while(!s.isemp())
    {
    	c=s.pop();
		   int p;
		   for(p=0;p<size;p++)
		   if(arr[0][p].data==c)
		   break;
		   if(!vsit(c,a2,count))
		{a2[count++]=c;visit[p].in=1;	
		   cout<<c<<" ";}
		   for(int i=0;i<size;i++)
		   if(arr[p][i].in!=0&&arr[p][i].in!=-1)
		   {
		   	arr[p][i].in=0;arr[i][p].in=0;
		   	s.push(c);
		    s.push(arr[p][i].data);break;
	       }
	   	if(s.isemp())
		{
			cout<<endl;
			for(int i=0;i<size;i++)
			if(visit[i].in==0)
			{
				s.push(visit[i].data);break;
			}
		}	
    }
	return 0;
}
