#include<iostream>
using namespace std;
struct graph
{
	char data;
	int in;
};
int *indegree,*outdegree;char s1;char *st;int j1=0;int k1;
bool visit(char c,char a[],int d)
{
	for(int i=0;i<d;i++)
	if(a[i]==c)
	return true;
	return false;
}
void topologicalsort(graph **arr,int size)
{
	for(int i=0;i<size;i++)
	{if(indegree[i]==0)
	{k1=1;	
	if(j1!=0)k1=j1;}
	else{k1=0;break;}
	}
	if(k1==0)
	{	for(int i=0;i<size;i++)
     	{
		if(indegree[i]==0)
		{
			cout<<"select  "<<arr[i][0].data<<"   ";
		}
	}
	cin>>s1;
	st[j1++]=s1;
	for(int i=0;i<size;i++)
	if(arr[0][i].in!=0)
	{
		arr[0][i].in=0;
		cout<<"select   "<<arr[0][i].data<<"  ";
	}
	cin>>s1;	st[j1++]=s1;
	for(int i=0;i<size;i++)
	if(arr[0][i].data==s1)
	indegree[i]--;	
	topologicalsort(arr,size);
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
    indegree=new int(size);
    outdegree=new int(size);
    for(int i=0;i<size;i++)
    {  indegree[i]=0;
    outdegree[i]=0;
    }
  
    for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
    if(arr[i][j].in!=0)
  {indegree[j]++; outdegree[i]++;
  } 
    topologicalsort(arr,size);
    for(int i=0;i<k1;i++)
    cout<<st[i];
    return 0;
}
