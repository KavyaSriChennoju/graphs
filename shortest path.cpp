#include<iostream>
using namespace std;
struct graph
{
	char data;
	int in;
};
struct node
{
	int n1,n2;
};
int setlength(graph visit[],graph length[],int size)
{
	const int s=size;
	node a[s];
	int p,m=-1;
	for(int i=0;i<size;i++)
	{
		a[i].n1=i;
		a[i].n2=length[i].in;
	}
	for(int i=0;i<size-1;i++)
	for(int j=i+1;j<size;j++)
	if(a[i].n2>a[j].n2)
	{
		node t=a[i];
		a[i]=a[j];
		a[j]=a[i];
	}
	for(int i=0;i<size;i++)
	{
		if(visit[a[i].n1].in!=1)
		{
			p=a[i].n1;break;
		}
	}
	cout<<p<<endl;
	if(length[p].in!=1000)
	return p;
	else 
	return m;
}
void shortlength(graph** arr,graph visit[],graph length[],char via[],char &cv,int &cl,int size,char d)
{
	int p;int k;
	for(p=0;p<size;p++)
	if(visit[p].data==cv)
	break;
	visit[p].in=1;
	for(int i=0;i<size;i++)
	{
		if(arr[p][i].in!=0)
		{
			if(cl+arr[p][i].in<length[i].in&&visit[i].in!=1)
			{
			length[i].in=cl+arr[p][i].in;
			via[i]=cv;
		    }
		}
	}
	k=setlength(visit,length,size);
	if(k!=-1)
	{
		cv=length[k].data;
		cl=length[k].in;
		if(cv!=d)
		shortlength(arr,visit,length,via,cv,cl,size,d);
	}
}
void print(char c,char via[],char d,graph visit[],int size)
{
	int p;
	for(p=0;p<size;p++)
	{
		if(visit[p].data==d)
		break;
	}
	if(d!=c)
	print(c,via,via[p],visit,size);
	cout<<d<<" ";
}
int main()
{
	int a,b;char c,d,e;char v='*';
	cout<<"enter the no of vertices\n";
	cin>>a;
	const int size=a;
	graph **arr,visit[size],length[size];char via[size];
	arr=new graph*[size];
	for(int i=0;i<size;i++)
	arr[i]=new graph[size];
	for(int i=0;i<size;i++)
	{
		cout<<"enter the vertex "<<i+1<<endl;
		cin>>c;
		arr[i][0].data=c;
	}
	for(int j=1;j<size;j++)
    arr[0][j].data=arr[j][0].data;
    for(int i=1;i<size;i++)
    for(int j=1;j<size;j++)
    arr[i][j].data=arr[i-1][j].data;
    cout<<endl;
    for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
    arr[i][j].in=0;
    do
    {
    	cout<<"enter the edge vertices\n";
    	cin>>c>>d;
    	cout<<"enter the edge weight\n";
    	cin>>b;
    	int h,k;
    	for(h=0;h<size;h++)
    	if(arr[h][0].data==c)
    	break;
    	for(k=0;k<size;k++)
    	if(arr[k][0].data==d)
    	break;
    	arr[h][k].in=b;
    	cout<<"do u want to continue\n";
    	cin>>e;
    }while(e=='y');
    for(int i=0;i<size;i++)
    {
    for(int j=0;j<size;j++)
    cout<<arr[i][j].in<<" ";
    cout<<endl;
    }
    cout<<endl;
    do
	{
    cout<<"enter the vertices to be shortpathed\n";
    cin>>c>>d;
    for(int i=0;i<size;i++)
    {
    	visit[i].data=arr[i][0].data;
    	visit[i].in=0;
    	length[i].data=arr[i][0].data;
    	length[i].in=1000;
    	via[i]=v;
    }
    for(int i=0;i<size;i++)
    if(length[i].data==c)
    length[i].in=0;char cv=c;int cl=0;
    shortlength(arr,visit,length,via,cv,cl,size,d);
	cout<<endl;
    print(c,via,d,visit,size);cout<<endl;
    cout<<"the pathlength is:\n";
    for(int i=0;i<size;i++)
    if(length[i].data==d)
    cout<<length[i].in;
    cout<<"\nto continue\n";
    cin>>e;
  }while(e=='y');
    return 0;
}
