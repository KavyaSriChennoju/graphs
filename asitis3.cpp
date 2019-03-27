#include<iostream>
using namespace std;
struct bst
{
	char data;
	bst *lchild;
	bst *rchild;
};
void create(bst *&m,char a)
{
	char ch;
	if(m->lchild==NULL)
	{
		cout<<"enter left child of "<<a<<" \n";
		cin>>ch;
		if(ch!='.')
		{
			bst *t;
			t=new(bst);
			t->data=ch;
			t->lchild=NULL;
			t->rchild=NULL;m->lchild=t;
			create(m->lchild,ch);
		}
	}
	if(m->rchild==NULL)
	{
		cout<<"enter right child of "<<a<<"\n";
		cin>>ch;
		if(ch!='.')
		{
			bst *t;
			t=new(bst);
			t->data=ch;
			t->lchild=NULL;
			t->rchild=NULL;m->rchild=t;
			create(m->rchild,ch);
		}
	}
}
int pwr(int d)
{
	int k=1;
	for(int i=0;i<d;i++)
	k=k*2;
	return k;
}
int height(bst *l)
{
	if(l==NULL)
	return 0;
	else
	{
		int a=height(l->lchild),b=height(l->rchild);
		if(a>b)
		return(a+1);
		else
		return(b+1);
	}
}static int n=0;
void print(bst *l,int k,int m,int a)
{
	if(l!=NULL)
	{
	if(k==0)
	{
		int d=a-m;
		d=pwr(d-1);
	//	d=d+n;n=d-n;
	//	if(n!=0)
	//	d=d-1;
		for(int i=0;i<d;i++)
		cout<<" ";
		cout<<l->data;
	}
	else
	{
		print(l->lchild,k-1,m,a);
		print(l->rchild,k-1,m,a);
	}
    }
    else if(l==NULL)
    {
    	if(k>0)
    	{
    		print(l,k-1,m,a);print(l,k-1,m,a);
    	}
    	else if(k==0)
    	{
    		int d=a-m;
		    d=pwr(d-1);
		   // d=d+n;n=d-n;
		   // if(n!=0)
		   // d=d-1;
		    for(int i=0;i<d+1;i++)
		    cout<<" ";
    	}
    }
}
int main()
{
	char c;int d;
	bst *l,*s,*t;
	l=new(bst);
	l->lchild=NULL;
	l->rchild=NULL;
	cout<<"enter the root \n";
	cin>>c;
	l->data=c;s=l;t=l;
	create(l,c);
	d=height(l);
	cout<<d<<endl;
	for(int i=0;i<d;i++)
	{
		int m=i;
	print(l,i,m,d);cout<<endl;n=0;
    }
	return 0;
		
}
