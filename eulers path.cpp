#include<iostream>
using namespace std;
struct graph
{
	char data;
	int in;
};
graph a[10];int n1=0,n2=0;char c1,d1;
bool iseuler(graph **arr,int size)
{
	if(size%2==0)
	{
	 for(int i=0;i<size;i++)
	 {
	 	int n=0;
	 for(int j=0;j<size;j++)
	 {
	 	if(arr[i][j].in==0)
	 	n++;
	 }
	 a[i].data=arr[i][0].data;
	 a[i].in=n;
	 }
	 for(int i=0;i<size;i++)
	 {
	 	if(a[i].in%2==0)
	 	n1++;
	 	else
		 {n2++;
		 if(n2==1)
		 c1=a[i].data;
		 if(n2==2)
		 d1=a[i].data;
		 } 
	 }
	 if(n2==0 )
	  {cout<<"select any vertex\n";
	 return true;}
	 if(n2==2)
	{ cout<<"select vertex from  "<<c1 <<"  or  "<<d1<<"\n";
	 	return true;}
	 else return false;
	 }
	else
	{
			 for(int i=0;i<size;i++)
	 {
	 	int n=0;
	 for(int j=0;j<size;j++)
	 {
	 	if(arr[i][j].in==0)
	 	n++;
	 }
	 a[i].data=arr[i][0].data;
	 a[i].in=n;
	 }
	 for(int i=0;i<size;i++)
	 {
	 	if(a[i].in%2==0)
	 {
		n1++;
	 	 if(n1==1)
		 c1=a[i].data;
		 if(n1==2)
		 d1=a[i].data;}
	 	else n2++;
	 }
	 if(n1==2 )
	 {cout<<"select vertex from  "<<c1 <<"  or  "<<d1<<"\n";
	 	return true;
	}
	 else if(n1==0)
	 {
	  cout<<"select any vertex\n";
	 return true;	
	 }
	 else return false;
	}
}
int main()
{
	int a1,b;char c,d,e;
	cout<<"enter the no of vertices\n";
	cin>>a1;
	const int size=a1;
	graph **arr;
	arr=new graph*[size];
	for(int i=0;i<size;i++)
	arr[i]=new graph[size];
	int degree[size];
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
    		arr[k][h].in=b;
    	cout<<"do u want to continue\n";
    	cin>>e;
    }while(e=='y');
    
    for(int i=0;i<size;i++)
    {
    for(int j=0;j<size;j++)
    cout<<arr[i][j].in<<" ";
    cout<<endl;
    }
    if(!iseuler(arr,size))
    cout<<"euler's path not possible\n";
    else
    { for(int i=0;i<size;i++)
    	{
    		degree[i]=size-a[i].in;
    	}
    	cin>>c;
    	char cv=c;
    	
    }}
