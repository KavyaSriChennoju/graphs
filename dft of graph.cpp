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
int main()
{
	int a,b;char c,d,e;
	cout<<"enter the no of vertices\n";
	cin>>a;
	const int size=a;
	graph arr[size][size];
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
    }char a2[size];
    cout<<endl;stack s;
    s.push(arr[0][0].data);int count=0;
    while(!s.isemp()||count<size)
    {
    	c=s.pop();
        if(!visit(c,a2,count))
		{
		   a2[count++]=c;	
		   cout<<c<<" ";
		   int p;
		   for(p=0;p<size;p++)
		   if(arr[p][0].data==c) 
		   break;
		   for(int i=0;i<size;i++)
		   if(arr[p][i].in!=0&&!visit(arr[p][i].data,a2,count))
		   {
		   	s.push(c);
		    s.push(arr[p][i].data);break;
	       }
		}
	   	if(s.isemp())
		{
			cout<<endl;
			for(int i=0;i<size;i++)
			if(!visit(arr[i][0].data,a2,count))
			{
				s.push(arr[i][0].data);break;
			}
		}	
    }
    return 0;
}
