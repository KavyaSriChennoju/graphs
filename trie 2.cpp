#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct trienode;
char dif[26];int cnt;
struct node
{
	string s;
	int rno;
	node *next;
};
struct data
{
	char *c;
	trienode **p;
};
union u
{
	int rno;
	data a;
};
struct trienode
{
	int tag;
	u p;
};
data crte()
{
	data t;
	t.c=new char[cnt];
	t.p=new trienode*[cnt+1];
	for(int i=0;i<cnt;i++)
	{
		t.c[i]=dif[i];
		t.p[i]=NULL;
	}
	t.p[cnt]=NULL;
	return t;
}
void create(trienode *&t1,node *l,int p3,node *s,int a2)
{
	if(t1==NULL)
	{
		t1=new(trienode);
		t1->tag=0;
		t1->p.rno=l->rno;
	}
	else
	{
	     int k;
         if(t1->tag==1&&p3<a2)
         {
	      for(k=0;k<cnt;k++) 
		  if(t1->p.a.c[k]==l->s.at(p3)) 
		  break; 
	      create(t1->p.a.p[k],l,p3+1,s,a2);
         }
         else if(t1->tag==1&&p3==a2)
         {
         	t1->p.a.p[cnt]=new(trienode);
	    	t1->p.a.p[cnt]->tag=0;
	    	t1->p.a.p[cnt]->p.rno=l->rno;
         }
         else
         {
         	node *r=s;
         	while(r->rno!=t1->p.rno)
         	r=r->next;
         	trienode *b=new(trienode);
         	b->tag=1;
         	b->p.a=crte();int z;
         	for(z=0;z<cnt;z++)
         	if(l->s.at(p3)==b->p.a.c[z])
         	break;
         	b->p.a.p[z]=new(trienode);
         	b->p.a.p[z]->tag=0;
         	b->p.a.p[z]->p.rno=l->rno;
         	t1=b;
         	int d1=(r->s).length();
         	create(t1,r,p3,s,d1);
         }
	}
}
int height(trienode *t)
{
	if(t==NULL) 
	return 0;
	if(t->tag==0) 
	return 0;
	else
	{
	  int max=0,l;
	  for(int k=0;k<cnt+1;k++) 
	  max=(l=height(t->p.a.p[k])>max)? max=l : max;
	  return ++max;
	}
}
void print(trienode *t,int in)
{
  if(t!=NULL)
  {
	int k;
	if(in==0)
	{
	  cout<<t->tag<<" ";
	  if(t->tag==1) 
	  for(k=0;k<cnt;k++) 
	  cout<<t->p.a.c[k]<<" ";
	  else 
	  cout<<t->p.rno<<" ";
	}
	else
	{
	  if(t->tag==1)
	  for(k=0;k<cnt+1;k++) 
	  print(t->p.a.p[k],in-1);
	}
  }
}
int main()
{
   node *l,*s,*t;string a;int p=1,p3=0,a2;cnt=0;trienode *t1,*t2;
   t1=new(trienode);
   ofstream out;
   out.open("trdata.txt");
   char ch;
   cout<<"enter string\n";
   cin>>a;
   l=new(node);
   l->s=a;
   l->rno=p++;
   l->next=NULL;
   s=l;
   do
   {
   	cout<<"enter string\n";
   	cin>>a;
   	while(l->next!=NULL)
   	l=l->next;
   	t=new(node);
   	t->s=a;t->rno=p++;
   	t->next=NULL;
   	l->next=t;
   	l=s;
   	cout<<"do u want to enter \n";
   	cin>>ch;
   }while(ch=='y');
   l=s;
   dif[cnt]=l->s.at(cnt++);
   while(l!=NULL)
   {
   	a=l->s;int k2=0;
   	a2=a.length();
   	for(int i=0;i<a2;i++)
   	{
   	  for(int j=0;j<cnt;j++)
   	  if(a.at(i)==dif[j])
   	  k2++;
   	  if(k2==0)
   	  dif[cnt++]=a.at(i);
   	  else
   	  k2=0;
    }
   	l=l->next;
   }
   t1->tag=1;
   t1->p.a=crte();
   for(int i=0;i<cnt;i++)
   cout<<t1->p.a.c[i]<<" ";l=s;t=s;
   a=l->s;cout<<endl;
   for(int i=0;i<cnt;i++)
   if(t1->p.a.c[i]==a.at(0))
   {
   	t1->p.a.p[i]=new(trienode);
   	t1->p.a.p[i]->tag=0;
   	t1->p.a.p[i]->p.rno=l->rno;
   	break;
   }
   out<<l->rno<<" "<<l->s<<endl;
   l=l->next;t2=t1;
   while(l!=NULL)
   {
   	out<<l->rno<<" "<<l->s<<endl;
   	a2=(l->s).length();
   	create(t1,l,p3,s,a2);
   	s=t;t1=t2;
   	l=l->next;
   }
   int h=height(t2);
   for(int i=0;i<h+1;i++)
   {
   	print(t2,i);
   	cout<<endl;
   }out.close();
   return 0;
}
