#include<iostream>
using namespace std;
const int d4=2;
struct btnode;
void create(btnode *&t,int c,int d);
struct btnode
{
	btnode *parent;
	int key[2*d4+1];
	btnode *child[2*d4+2];
	int count;
};
bool isleaf(btnode *t);
bool isleaf(btnode *t)
{
		for(int i=0;i<t->count+1;i++)
		if(t->child[i]!=NULL)
		return false;
	    return true;
}
int max(int a[],int b);
int max (int a[],int b)
{
	for(int i=0;i<b-1;i++)
	for(int j=i+1;j<b;j++)
	if(a[j]>a[i])
	{
		int y=a[j];a[j]=a[i];a[i]=y;
	}
	return a[0];
}
int  height(btnode *a4);
int height(btnode *a4)
{
	if(!isleaf(a4))
	{
		int *a;a=new int[2*d4+1];
		for(int i=0;i<a4->count+1;i++)
		a[i]=height(a4->child[i]) ;
		return (1+(max(a,a4->count+1)));	
	}
	else
	return (1);
}
btnode *root;
btnode* leaf(btnode *t,int c);
btnode* leaf(btnode *t,int c)
{
	int d=0,r=0;
	for(int i=0;i<t->count+1;i++)
	{
		if(t->child[i]==NULL)
		d++;
		else
		break;
	}
	if(d==t->count+1)
	return (t);
	else
	{
		if(c>t->key[t->count-1])
		return leaf(t->child[t->count],c);
	    for(int i=0;i<t->count;i++)
	    {
	    	if(c<t->key[i])
	    	break;
	    	r++;
	    }
	    return leaf(t->child[r],c);
   }
}
btnode* node();
btnode* node()
{
	btnode *l;
	l=new(btnode);
	for(int i=0;i<2*d4+1;i++)
	{
		l->child[i]=NULL;
		l->key[i]=-1;
	}
	l->child[2*d4+2]=NULL;
	l->parent=NULL;l->count=0;
	return l;
}
int maxi(btnode *l);
int maxi(btnode *l)
{
	if(isleaf(l))
	return(l->key[l->count-1]);
	else
	return maxi(l->child[l->count]);
}
void nodesplit(btnode *&m);
void nodesplit(btnode *&m)
{
	 btnode *p,*n;
	 p=m;
     n=node();
     for(int i=0;i<d4;i++)
     {
     n->key[i]=p->key[d4+1+i];
     n->child[i+1]=p->child[d4+2+i];
     }
     n->child[0]=p->child[d4+1];
     n->count=d4;
     for(int i=0;i<d4+1;i++)
     {
     	if(n->child[i]!=NULL)
		 n->child[i]->parent=n;
     }
    m=p;
    m->count=d4;
    for(int i=0;i<d4+1;i++)
    m->child[d4+1+i]=NULL;
     if(p->parent==NULL)
     {
     	btnode *d1=node();
     	d1->key[0]=p->key[d4];
     	d1->child[0]=m;
     	d1->child[1]=n;
     	n->parent=d1;
     	m->parent=d1;
     	d1->count=1;
     	root=d1;
     }
     else
     {
        n->parent=m->parent;
	    int a1=0;
	    for(int i=0;i<m->parent->count;i++)
	    {
	 	if(m->parent->key[i]>p->key[d4])
	 	break;a1++;
	    }
	    for(int j=m->parent->count;j>a1;j--)
		{
		m->parent->key[j]=m->parent->key[j-1];
		m->parent->child[j+1]=m->parent->child[j];
	    }
	    m->parent->child[a1+1]=n;
		m->parent->key[a1]=p->key[d4];
		(m->parent->count)++;
		if(m->parent->count>2*d4)
		nodesplit(m->parent);	
     }
}
void underflow(btnode *l);
void underflow(btnode *l)
{
	int r1=0;
     	     for(int i=0;i<l->parent->count+1;i++)
     	     {
     		    if(l->parent->child[i]==l)
     		    break;
     		    r1++;
     	     }
     	     cout<<r1<<endl;
     	     if(r1!=0&&l->parent->child[r1-1]->count>d4)
     	     {
     	     	for(int i=0;i<d4-1;i++)
     	     	{
     	        l->key[d4-1-i]=l->key[d4-1-(i+1)];l->child[d4-i]=l->child[d4-1-i];
     	        }
     	        l->child[1]=l->child[0];
     	        l->key[0]=l->parent->key[r1-1];l->child[0]=l->parent->child[r1-1]->child[l->parent->child[r1-1]->count];
     	        l->count++;
     	        l->parent->key[r1-1]=l->parent->child[r1-1]->key[l->parent->child[r1-1]->count-1];
     	        l->parent->child[r1-1]->count--;
     	     }
     	     else if(r1!=l->parent->count&&l->parent->child[r1+1]->count>d4)
     	     {
     	     	l->key[d4-1]=l->parent->key[r1];
     	     	l->count++;
     	     	l->child[d4]=l->parent->child[r1+1]->child[0];
     	     	l->parent->key[r1]=l->parent->child[r1+1]->key[0];
     	     	for(int i=0;i<l->parent->child[r1+1]->count-1;i++)
     	     	{
     	     	l->parent->child[r1+1]->key[i]=	l->parent->child[r1+1]->key[i+1];
     	     	l->parent->child[r1+1]->child[i]=	l->parent->child[r1+1]->child[i+1];
     	        }
     	        l->parent->child[r1+1]->child[l->parent->child[r1+1]->count-1]=	l->parent->child[r1+1]->child[l->parent->child[r1+1]->count];
     	     	l->parent->child[r1+1]->count--;
     	     }
     	     else
     	     {
     	     	if(r1!=l->parent->count)
     	     	{
     	     		l->key[d4-1]=l->parent->key[r1];
     	     		l->count++;
     	     		for(int i=0;i<l->parent->child[r1+1]->count;i++)
     	     		{
     	     			l->key[d4+i]=l->parent->child[r1+1]->key[i];
     	     			l->child[d4+i]=l->parent->child[r1+1]->child[i];
     	     			l->count++;
     	     		}
     	     		l->child[l->count]=l->parent->child[r1+1]->child[l->parent->child[r1+1]->count];
     	     		l->parent->child[r1+1]=NULL;
     	     		for(int i=r1;i<l->parent->count-1;i++)
     	     		{
     	     			l->parent->key[i]=l->parent->key[i+1];
     	     			l->parent->child[i+1]=l->parent->child[i+2];
     	     		}
     	     		l->parent->count--;
     	     		if(l->parent->count<d4&&l->parent!=root)
     	     		underflow(l->parent);
     	     	}
     	     	else
     	     	{
     	     		l->parent->child[r1-1]->key[l->parent->child[r1-1]->count]=l->parent->key[r1-1];
     	     		l->parent->child[r1-1]->count++;
     	     		for(int i=0;i<l->count;i++)
     	     		{
     	     			l->parent->child[r1-1]->key[l->parent->child[r1-1]->count+i]=l->key[i];
     	     			l->parent->child[r1-1]->child[l->parent->child[r1-1]->count]=l->child[i];
     	     			l->parent->child[r1-1]->count++;
     	     		}
     	     		l->parent->child[r1-1]->child[l->parent->child[r1-1]->count]=l->child[d4-1];
     	     		l->parent->count--;
     	     		l->parent->child[r1]=NULL;
     	     		if(l->parent->count<d4&&l->parent!=root)
     	     		underflow(l->parent);
     	     	}
     	     }
}
void create(btnode *&t,int c,int d);
void create(btnode *&t,int c,int d)
{
	static int k=0;
	btnode *l,*m,*n;
	if(k==0)
	{
		t=node();
		t->key[0]=c;
		k++;t->count=1;root=t;
	}
	else
	{
			m=leaf(root,c);int k1=0;
		for(int i=0;i<m->count;i++)
		{
			if(c<m->key[i])
			break;
			k1++;
		}
		for(int j=m->count;j>k1;j--)
		{
		m->key[j]=m->key[j-1];
		m->child[j+1]=m->child[j];
	    }
	    m->child[k1+1]=NULL;
		m->key[k1]=c;
		(m->count)++;
		if(m->count>2*d4)
		nodesplit(m);
	}
}
btnode* search(btnode *t,int g);
btnode* search(btnode *t,int g)
{
	for(int i=0;i<t->count;i++)
	{
		if(g<t->key[i])
		return (search(t->child[i],g));
		else if(g==t->key[i])
		return (t);
		else if(i==t->count-1&&t->key[i]<g)
		return search(t->child[i+1],g);
	}
}
int pwr(int d)
{
	int k=1;
	for(int i=0;i<d;i++)
	{
	 k=k*5;
	}
	return k;
}
bool num(int a)
{
	int k;
	for(k=0;a>0;k++)
	a=a/10;
	if(k==1)
	return true;
	else
	return false;
}
void dlte(btnode *&l,int a);
void dlte(btnode *&l,int a)
{
	if(isleaf(l))
	{
		if(l->count>d4)
		{
		  int b=0;
		  for(int i=0;i<l->count;i++)
		  {
			 if(l->key[i]==a)
			 break;
			 b++;
		  }
		  for(int i=b;i<l->count-1;i++)
		  l->key[i]=l->key[i+1];
		  l->count--;
		  l->key[l->count]=-1;
	    } 
	    else
	    {
	    	int b=0;
		   for(int i=0;i<l->count;i++)
		   {
			 if(l->key[i]==a)
			 break;
			 b++;
		   }
		   for(int i=b;i<l->count-1;i++)
		   l->key[i]=l->key[i+1];
		   l->count--;
		   l->key[l->count]=-1;
		   if(l->parent!=NULL)
		   underflow(l);
        }
    }
	else
	{
		int b=0;
		for(int i=0;i<l->count;i++)
		{
			if(l->key[i]==a)
			break;
			b++;
		}
		int c=maxi(l->child[b]);cout<<c<<endl;
		btnode *p=search(root,c);
	l->key[b]=c;	dlte(p,c);
	}
}static int k3=0;
void level(btnode *t,int a,int m,int g);
void level(btnode *t,int a,int m,int g)
{
 if(t!=NULL)
 {
 if(a==0)
 {
 	int d=g-m;
	d=pwr(d-1);d=d-1;d=2*d;
	for(int i=0;i<2*d4;i++)
	{
		for(int j=0;j<d;j++)
		cout<<" ";
		if(i<t->count)
		{
		if(num(t->key[i]))
		cout<<t->key[i]<<" ";
		else
		cout<<t->key[i];}
		else
		cout<<"  ";	
	}
	for(int j=0;j<d;j++)
    cout<<" ";
	if(d==0)
	cout<<"  ";
 }
 else if(a>0)
 {
 	btnode *m1=NULL;
 	for(int i=0;i<2*d4+1;i++)
 	{
 		if(i<t->count+1)
 		level(t->child[i],a-1,m,g);
 		else
 		level(m1,a-1,m,g);
 	}
 }
 }
 else
 {
 	if(a>0)
 	for(int i=0;i<2*d4+1;i++)
 	level(t,a-1,m,g);
 	else if(a==0)
 	{
 		int d=g-m;
	    d=pwr(d-1);d=d-1;d=3*d;
	    for(int i=0;i<2*d4;i++)
	    {
		for(int j=0;j<d;j++)
		cout<<" ";
		cout<<"  ";
	    }
	    for(int j=0;j<d;j++)
		cout<<" ";
	    if(d==0)
	    cout<<"  ";
 	}
 }
}
void order(btnode *t);
void order(btnode *t)
{
 int a=height(t);
 for(int i=0;i<a;i++)
 {
  level(t,i,i,a);cout<<endl;k3=0;
 }
}   
int main()
{
	btnode *l=NULL;int a;
	int b=0;
	cout<<"enter the starting no\n";
	cin>>a;
	while(a!=-1)
	{
		b=0;
		create(l,a,b);l=root;
		cout<<"enter the next no\n";
		cin>>a;
	}
	cout<<endl;
	order(root);cout<<endl;
	while(1)
	{
	cout<<"enter the no to be deleted\n";
	cin>>a;if(a==0)break;
	if(root->count==0)
	    {
	    	root=root->child[0];root->parent=NULL;
	    }
	      l=search(root,a);
          dlte(l,a);
	      order(root);
	}
	cout<<endl;
	return 0;
}
