#include<iostream>
#include<string>
using namespace std;
struct store
{
	char ch;
	int in;
};
store st[15];
struct btnode
{
	int data;
	char data1;
	btnode *lchild;
	btnode *rchild;
};

void sort(store st[],int n1)
{
	for(int i=0;i<n1-1;i++)
	{
		for(int j=i;j<n1;j++)
		{
			if(st[i].in>st[j].in)
			{
				store t=st[i];
				st[i]=st[j];
				st[j]=t;
			}
		}
	}
}
int height(btnode* a4)
{
	int b,c;
	if(a4==NULL)
		return -1;
	else
	{
		b=height(a4->lchild);
		 c=height(a4->rchild);
		if(b>c)
			return 1+b;
		else
			return 1+c;			
	}
}
void level(btnode* t, int l)
{
 if(t == NULL)
 return;
 if(l==1)
 {
 	 cout<<t->data<<" "<<t->data1<<"   ";
 }
 else if (l > 1)
 {
  level(t->lchild, l-1);
  level(t->rchild,l-1);
  cout<<" ";
 }
}
void print(btnode* t)
{
 int h = height(t)+2;
 int i;
 for(i=1;i<=h;i++)
 {
  level(t, i);
  cout<<endl;
 }
}
void print1(btnode *b)
{if(b!=NULL){
		print1(b->lchild);
	 cout<<b->data<<" "<<b->data1<<"       ";
	print1(b->rchild); 
}	
}
void printhoff(btnode *b,string s)
{if(b!=NULL)
 { 
	printhoff(b->lchild,(s+'0'));
	if(b->data1!='*')cout<<b->data1<<"  "<<s<<"\n";
	printhoff(b->rchild,(s+'1'));	
}	
}
int main()
{char a;btnode *b;
int i;int i1=0;
do{
	cout<<"enter the letter to stop -\n";
	cin>>a;
	if(a!='-'){
	cout<<"enter no of repetitions\n";
	cin>>i;
	st[i1].ch=a;
	st[i1++].in=i;
	}  
}while(a!='-');
int n1=i1;int i5=2;
sort(st,n1);
b=new(btnode);btnode *t1,*t2;t1=new(btnode);t2=new(btnode);
b->data=st[0].in+st[1].in;
b->data1='*';
t1->data=st[1].in;t1->data1=st[1].ch;t2->data=st[0].in;t2->data1=st[0].ch;
t1->lchild=NULL;t1->rchild=NULL;t2->lchild=NULL;t2->rchild=NULL;
b->lchild=t1;b->rchild=t2;

if(n1>2)do
{ if(st[i5].in >= b->data || i5==n1-1)
	{
		btnode *t,*t1;
		t=new(btnode);	t1=new(btnode);	t1->lchild=NULL;t1->rchild=NULL;
		t->data=b->data+st[i5].in;
		t->data1='*';
		t1->data=st[i5].in;t1->data1=st[i5].ch;t->rchild=t1;
		t->lchild=b;
		b=t;	
	}
	else
	{  
	    int i6=i5;i5++;	int i7=i5;
		btnode *t,*t1,*t2,*t3;
		t=new(btnode);	t1=new(btnode);	t2=new(btnode);	t3=new(btnode);
        t->data1='*';
        t2->data=st[i6].in;t2->data1=st[i6].ch;t3->data=st[i7].in;t3->data1=st[i7].ch;
        t2->lchild=NULL;t2->rchild=NULL;t3->lchild=NULL;t3->rchild=NULL;
        t->data=t2->data+t3->data;
        t1->data=b->data+t->data;
        t->lchild=t2;t->rchild=t3;
		t1->data1='*';
		t1->rchild=t;
		t1->lchild=b;
		b=t1;	
	}
	i5++;
}while(i5<n1);string s;
print(b);
printhoff(b,s);	
}
