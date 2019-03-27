#include<iostream>
using namespace std;
struct graph
{
	char data;
	int in;
};int size,p;char *a2;  int count=0;
bool visit(char c,char * &a2,int &d)
{
	for(int i=0;i<d;i++)
	if(a2[i]==c)
	return true;
	return false;
}
   void dfs(graph **arr,char *&a2,int &count,char c)
    {  if(count<size )
    {  if(!visit(c,a2,count))
		{ a2[count++]=c;	
		   cout<<c<<" ";
		   for( p=0;p<size;p++)
		  if(arr[p][0].data==c) 
		  break;
		  for(int i=0;i<size;i++)
		  if(arr[p][i].in!=0&&!visit(arr[p][i].data,a2,count))
		{ dfs(arr,a2,count,arr[p][i].data);break;}}}}
int main()
{
	int a,b;char c,d,e;
	cout<<"enter the no of vertices\n";
	cin>>a;
 size=a;
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
    
	 a2=new char(size);
    cout<<endl;
	
  dfs(arr,a2,count,arr[0][0].data);
    while(count<size)
      for(int i=0;i<size;i++)
			if(!visit(arr[i][0].data,a2,count))
			{
			 dfs(arr,a2,count,arr[i][0].data);break;
			}
return 0;
}
