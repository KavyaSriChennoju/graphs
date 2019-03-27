#include<iostream>
using namespace std;
struct graph
{
	char data;
	int in;
};
int *indegree,*outdegree;char s1;char st[20];int j1=0;int k1=0,k2,visit[10];int w=0,x=0;
void topologicalsort(graph **arr,int size,char s1)
{
     for(int i=0;i<size;i++)
     {	if((arr[0][i].data==s1)&&(outdegree[i]==0))
     	{k1=1;	break;} }
	if(k1==0 )
	{	for(int i2=0;i2<size;i2++)
	{if(indegree[i2]==0 &&visit[i2]!=1 )
	{cout<<"select   "<<arr[i2][0].data<<" ";w=1;}}
	if(w==1)
	{cout<<"\n";cin>>s1;st[j1++]=s1;w=0;}
	for(int i=0;i<size;i++)
	if(arr[i][0].data==s1)
	k2=i;
	visit[k2]=1;
	for(int i1=0;i1<size;i1++)
	{if(arr[k2][i1].in!=0)
	{ cout<<"select   "<<arr[k2][i1].data<<" ";x=1;	
	}}
	if(x==1)
	{cout<<"\n";cin>>s1;
	st[j1++]=s1;
	x=0;}
	for(int i=0;i<size;i++)
	if(arr[i][0].data==s1)
	{
		arr[k2][i].in=0;
		k2=i;
	}
	visit[k2]=1;	
	for(int i=0;i<size;i++)
	if(arr[0][i].data==s1)
	indegree[i]--;	
	topologicalsort(arr,size,s1);
	}
}
int main()
{
	int a,b;char c,d,e;
	cout<<"enter the no of vertices\n";
	cin>>a;
	const int size=a;
	graph **arr;
	arr=new graph *[size];
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
         b=1;
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
    indegree=new int(size);
    outdegree=new int(size);
    for(int i=0;i<size;i++)
    {  indegree[i]=0;
    outdegree[i]=0;
    }
    for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
    if(arr[i][j].in!=0)
  {indegree[j]++; outdegree[i]++;}  
   for(int i=0;i<size;i++)
    if(indegree[i]==0)
    { s1=arr[i][0].data;break;
    }
    topologicalsort(arr,size,s1);
    cout<<"topologica sort is\n";
    for(int i=0;i<j1;i++)
    cout<<st[i]<<"  ";
    return 0;
}
