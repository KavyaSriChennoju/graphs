#include<iostream>
using namespace std;
struct graph
{
	char data;
	int in;
};
struct node
{
	char ch;
	node *next;
};
node *t=NULL,*s=NULL;int e1=0;node *ptr;
void addend(node *&l,char k)
		{
			while(l->next!=NULL)
			{
				l=l->next;
			}
			l->next=new(node);
	l->next->ch=k;
	l->next->next=NULL;}
	int h=0,n5;	
void splice(char b[],int count) 
{
	if(t==NULL)
	{
		t=new(node);
		t->ch=b[0];
		t->next=NULL;
		s=t;
	    n5=1;	
	}
	if(n5==1)
	{
		for(int i=1;i<=count;i++)
		{
		addend(t,b[i]);
		t=s;}
		n5=0;
		ptr=t->next;
	}
	else
	{
		if(count==1)
		{
		while(t->ch!=b[0])
		t=t->next;
		ptr=t->next;
		}
		else
		{
	    node *t1[h],*s1[h];
	    t1[h]=new(node);
		t1[h]->ch=b[1];
		t1[h]->next=NULL;
		s1[h]=t1[h];	
		for(int i=2;i<count;i++)
		{
		addend(t1[h],b[i]);
		t1[h]=s1[h];}
		while(t->ch!=b[0])
		t=t->next;
		while(t1[h]->next!=NULL)
		t1[h]=t1[h]->next;
		t1[h]->next=t->next;
		t1[h]=s1[h];
		t->next=t1[h];
		ptr=t->next;
	     t=s;
	     h++;}
	}
}
int n6=0,p1;
void dft(char &cv,graph **arr,char a2[],int &count,int degree[],int size)
{
	a2[count++]=cv;                                                                                  
	int p;
	for( p=0;p<size;p++)
	{
	if(n6==0)
	{if(arr[p][0].data==cv)
	{p1=p;
	n6=1;
	break;
	}}
	else
	if(arr[p][0].data==cv)
	break;
	}
	if(degree[p]!=0)
	{
		for(int i=0;i<size;i++)                                                            
		if(arr[p][i].in!=0)
		{
			if(i!=0)cv=arr[p][i].data;
			else cv='a';
			arr[p][i].in=0;arr[i][p].in=0;degree[i]--;degree[p]--;
			break;
		}
		if(degree[p1]!=0)
		dft(cv,arr,a2,count,degree,size);
		else
		{
		a2[count++]=cv;
		}
	}n6=0;
}
void eulerpath(graph **arr,int degree[],int size,char &cv)
{
    int count=0;char a2[100];int d2=0;int dg=0;
	dft(cv,arr,a2,count,degree,size);
	splice(a2,count);
    cv=ptr->ch;
    for(int i=0;i<size;i++)
    {
    	if(degree[i]==0)
    	dg++;
    }
    if(dg!=size)
    eulerpath(arr,degree,size,cv);
}
int main()
{
	int a,b;char c,d,e;char f='*';
	cout<<"enter the no of vertices\n";
	cin>>a;
	const int size=a;
	graph **arr;graph **arr2;
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
    	arr[h][k].in=b;arr[k][h].in=b;
    	cout<<"do u want to continue\n";
    	cin>>e;
    }while(e=='y');
    for(int i=0;i<size;i++)
    {
    for(int j=0;j<size;j++)
    cout<<arr[i][j].in<<" ";
    cout<<endl;
    }char ch5,c5,d5;
    cout<<endl;int s1=0;
    int degree[size];
    for(int i=0;i<size;i++)
    degree[i]=0;
    for(int i=0;i<size;i++)
    for(int j=0;j<size;j++)
    if(arr[i][j].in!=0)
    degree[i]++;arr2=arr;
    for(int i=0;i<size;i++)
    if(degree[i]%2!=0)
    s1++;char cv;
    if(s1==0||s1==2) cout<<"eulers path possible\n";
    else  cout<<"eulers path not possible\n";
    if(s1==0)
    {	cout<<"enter any vertex\n";}
    if(s1==2)
    {int n5=1;
     for(int i=0;i<size;i++)
     { if(degree[i]%2!=0)
       { if(n5==1)
     	{c5=arr[i][0].data;
         n5=0;
       }else d5=arr[i][0].data;
	   }}
    cout<<"select vertex from  "<<c5<<" or "<<d5<<"\n";	
    }
    	cin>>ch5;	cv=ch5;
   	eulerpath(arr2,degree,size,cv);
  cout<<"\n EULER'S PATH IS:\n";
   while(t->next!=NULL)
   { cout<<t->ch<<"  ";t=t->next; }
    return 0;
}
