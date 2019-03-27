#include<iostream>
using namespace std;
struct graph
{
	char data;
	int in;
};
class queue
{
	public:
		char a[50];
		int front ,rear,size;
		void enq(char b);
		char dq();
		queue()
		{
			size=0;
			front =-1;
			rear=-1;
		}
		bool isfull();
		bool isemp();
}s;
bool queue::isfull()
{
	if((rear+1)%50==front)
	return true;
	else
	return false;
}
bool queue::isemp()
{
	if(front==-1)
	return true;
	else
	return false;
}
void queue::enq(char b)
{
	if(isfull())
	cout<<"queue is full \n";
	else
	{    size++;
		rear=(rear+1)%50;
		a[rear]=b;
		if(front==-1)
		front++;}
}
char queue::dq()
{
	if(isemp())
	cout<<"q is empty \n";
	else
	{    size--;
		int temp=front;
		if(front!=rear)
		{
			front=(front+1)%50;
		}
	    else
	    {
	    	rear=-1;
	    	front=-1;
	    }
	    return a[temp];
	}
}
bool visit(char c,char a[],int d)
{
	for(int i=0;i<d;i++)
	if(a[i]==c)
	return true;
	return false;
}
void shortlen(graph** arr,graph visit[],graph length[],char via[],char &cv,int &cl,int size)
{
	int p;int k,n1=0;char d;;
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
			s.enq(arr[p][i].data);
			n1++;
			length[i].in=cl+arr[p][i].in;
			via[i]=cv;
		    }
		}
	}
    for(int i1=0;i1<n1;i1++)
    {
    	d=s.dq();
    	cv=d;
   	shortlen(arr,visit,length,via,cv,cl,size);
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
    c=arr[0][0].data;
     graph visit[size],length[size];char via[size];
    for(int i=0;i<size;i++)
    {
    	visit[i].data=arr[i][0].data;
    	visit[i].in=0;
    	length[i].data=arr[i][0].data;
    	length[i].in=1000;
    	via[i]=f;
    }
    int sum=0;
    for(int i=0;i<size;i++)
    if(length[i].data==c)
    length[i].in=0;char cv=c;int cl=0;
     shortlen(arr,visit,length,via,cv,cl,size);cout<<endl;
     for(int i=0;i<size;i++)
     {
     	sum=sum+length[i].in;
     	cout<<length[i].in;
     }
  cout<<"\ncost of minimum spanning tree is\n"<<sum;
}
    
    
    
