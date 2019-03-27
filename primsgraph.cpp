#include<iostream>
using namespace std;
struct graph
{
	char data;
	int in;
};
struct node
{
	int c1,c2;
};
int set(graph vsit[],graph lenth[],int size)
{
	const int s=size;node a[s];int p,m=-1;
	for(int i=0;i<size;i++)
	{
		a[i].c1=i;a[i].c2=lenth[i].in;
	}
	for(int i=0;i<size-1;i++)
	for(int j=i+1;j<size;j++)
	if(a[i].c2>a[j].c2)
	{
		node t=a[i];
		a[i]=a[j];
		a[j]=a[i];
	}
	for(int i=0;i<size;i++)
	{
		if(vsit[a[i].c1].in!=1)
		{
			p=a[i].c1;break;
		}
	}
	return p;
}
void shortlen(graph** arr,graph vsit[],graph lenth[],char via[],char &cv,int &cl,int size)
{
	int p;int k;static int m=0;
	for(p=0;p<size;p++)
	if(vsit[p].data==cv)
	break;
	m++;
	vsit[p].in=1;
	for(int i=0;i<size;i++)
	{
		if(arr[p][i].in!=0&&vsit[i].in!=1)
		{
			lenth[i].in=arr[p][i].in;
			via[i]=cv;
		}
	}
	k=set(vsit,lenth,size);
	if(k!=-1)
	{
		cv=lenth[k].data;
		cl=lenth[k].in;
		if(m<size-1)
		shortlen(arr,vsit,lenth,via,cv,cl,size);
	}
}
int main()
{
	int a,b;char c,d,e;char f='*';
	cout<<"enter the no of vertices\n";
	cin>>a;
	const int size=a;
	graph **arr;
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
    for(int i=0;i<size;i++)
    {
    for(int j=0;j<size;j++)
    cout<<arr[i][j].data<<" ";
    cout<<endl;
    }
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
    	arr[h][k].in=b;arr[k][h].in=b;
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
    graph vsit[size],lenth[size];char via[size];
    for(int i=0;i<size;i++)
    {
    	vsit[i].data=arr[i][0].data;
    	vsit[i].in=0;
    	lenth[i].data=arr[i][0].data;
    	lenth[i].in=1000;
    	via[i]=f;
    }
    char cv=arr[0][0].data;int cl=0;
     for(int i=0;i<size;i++)
     if(lenth[i].data==cv)
    lenth[i].in=0;
    shortlen(arr,vsit,lenth,via,cv,cl,size);cout<<endl;
    cout<<"the circuit is:\n";
    for(int i=1;i<size;i++)
    {
    	cout<<via[i]<<"->"<<vsit[i].data<<endl;
    }
    return 0;
}
