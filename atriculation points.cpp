#include<iostream>
using namespace std;
struct graph
{
	char data;
	int in;
};
bool visited(int visit[],int size)
{
	for(int i=0;i<size;i++)
	if(visit[i]==0)
	return false;
	return true;
}
int low(int p,int **edges,int visit[],int size)
{
	int *a=new int[size];int m=0,n;
	a[m++]=visit[p];
	for(int i=0;i<size;i++)
	{
		if(edges[p][i]==1)
		a[m++]=low(i,edges,visit,size);
		if(edges[p][i]==-1)
		a[m++]=visit[i];
	}
	for(int i=0;i<m-1;i++)
	for(int j=i+1;j<m;j++)
	if(a[i]>a[j])
	{
		n=a[i];a[i]=a[j];a[j]=n;
	}
	return a[0];
}
void dft(graph **arr,int visit[],char &cv,int size,char parent[],int **edges)
{
 if(!visited(visit,size))
 {
   static int k=1;char d=cv;
   int p,p1,m=0;
   for(p=0;p<size;p++)
   if(arr[0][p].data==cv)
   break;
   if(visit[p]==0)
   visit[p]=k++;
   for(p1=0;p1<size;p1++)
   if(arr[p][p1].in!=0&&visit[p1]==0)
   {
   	m++;parent[p1]=cv;
	edges[p][p1]=1;
   	cv=arr[p][p1].data;break;
   }
   if(m==0)
   {
   	cv=parent[p];
   }
   else
   {
   	for(int i=0;i<size;i++)
   	if(arr[p1][i].in!=0&&visit[i]!=0&&arr[p1][i].data!=d)
   	edges[p1][i]=-1;
   }
   if(cv!='*')
   dft(arr,visit,cv,size,parent,edges);
   else
   {
   	for(int i=0;i<size;i++)
   	if(visit[i]==0)
   	{
   		cv=arr[0][i].data;break;
   	}
   	if(!visited(visit,size))
   	dft(arr,visit,cv,size,parent,edges);
   }
   if(parent[p]!=arr[0][0].data&&parent[p]!='*')
   {
   	int s=low(p,edges,visit,size);
   	int p2;
   	for(p2=0;p2<size;p2++)
   	if(arr[0][p2].data==parent[p])
   	break;
   	if(s>=visit[p2])
   	cout<<parent[p]<<endl;
   }
 }
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
		arr[p1][p2].in=1;arr[p2][p1].in=1;
		cout<<"want to enter more\n";
		cin>>ch;
	}while(ch=='y');
	char parent[size];char cv=arr[0][0].data;
	for(int i=0;i<size;i++)
	parent[i]='*';
	int visit[size];
	for(int i=0;i<size;i++)
	visit[i]=0;
	int **edges=new int*[size];
	for(int i=0;i<size;i++)
	edges[i]=new int[size];
	for(int i=0;i<size;i++)
	for(int j=0;j<size;j++)
	edges[i][j]=0;
	cout<<"Atriculation points \n";
	dft(arr,visit,cv,size,parent,edges);
	return 0;
}
