#include<iostream>
using namespace std;
struct graph
{
	int data;
	int in;
};
struct edge
{
	int u,v,wt;
};
int find(int a,int *s)
{
	if(s[a]==0||s[a]<0)
	return a;
	else
	return (find(s[a],s));
}
void ubyh(int a,int b,int *s)
{
	if(s[a]==0)
	{
		s[a]=b;
		s[b]--;
	}
	else if(s[a]<0&&s[b]==0)
	{
		s[b]=a;
		s[a]--;
	}
	else if(s[a]<=s[b])
	{
		s[b]=a;
		s[a]--;
	}
	else if(s[b]<s[a])
	{
		s[a]=b;s[b]--;
	}
}
void heapify(edge *heap,int a)
{
	edge p;
   for(int i=0;i<a-1;i++)
   for(int j=i+1;j<a;j++)
   {
   	if(heap[i].wt>heap[j].wt)
   	{
   		 p.u=heap[i].u;p.v=heap[i].v;p.wt=heap[i].wt;
		   heap[i].u=heap[j].u;heap[i].v=heap[j].v;heap[i].wt=heap[j].wt;
		   heap[j].u=p.u;heap[j].v=p.v;heap[j].wt=p.wt;
   	}
   }
}
void delheap(edge *heap,int c)
{
	for(int i=0;i<c;i++)
	{
		heap[i].u=heap[i+1].u;
		heap[i].v=heap[i+1].v;
		heap[i].wt=heap[i+1].wt;
	}
}
int main()
{
	int a,b,c,d,l,p=0;char e;edge *m;
	cout<<"enter the no of vertices\n";
	cin>>a;
	 int size=a;
	graph **arr;
	arr=new graph*[a];
	for(int i=0;i<a;i++)
	arr[i]=new graph[a];
	for(int i=0;i<size;i++)
	{
		arr[i][0].data=i;
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
    cout<<"enter the no of edges\n";
    cin>>l;
    m=new edge[l];
    do
    {
    	cout<<"enter the edge vertices\n";
    	cin>>c>>d;
    	cout<<"enter the edge weight\n";
    	cin>>b;
    	m[p].u=c;m[p].v=d;m[p++].wt=b;
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
    int *s;c=a;int g,h;
    s=new int[a];
    for(int i=0;i<a;i++)
    s[i]=0;
    edge *heap=m;
	edge r;
    heapify(heap,a);
    int ac=0;
    while(ac<a)
    {
    	r.u=heap[0].u;r.v=heap[0].v;r.wt=heap[0].wt;
    	delheap(heap,c-1);
    	c--;
    	cout<<r.u<<r.v;
    	g=find(r.u,s);h=find(r.v,s);
    	if(g!=h)
    	{
    		ac++;ubyh(r.u,r.v,s);
    	}
    }
    return 0;
}
