  #include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib> 
using namespace std;
int d=0;static int k1=1,k2=0;char *c1,*d2,m[10];
ofstream out1,out2;
ifstream in1,in2;
struct bckt
{
	int d1,count;
	int recrds;
	bckt()
	{
		d1=0;count=0;
		recrds=k1++;
	}
};

void getbin(int *bnry,int rno)
{
	for(int i=0;i<8;i++)
	bnry[i]=0;
	int c=7;
	while(rno>0)
	{
		bnry[c--]=rno%2;
		rno=rno/2;
	}
}
void check(bckt **&drctry,int *bnry,int rno,int key,int limit);
int pwr(int a)
{
	int k=1;
	for(int i=0;i<a;i++)
	k=k*2;
	return k;
}
int getrcrd(int *bnry,int a)
{
	int c=0;
	for(int i=a;i>0;i--)
	{
		c=c+bnry[i-1]*pwr(a-i);
	}
	return c;
}
void dcntact(bckt **&drctry)
{
	int p;
	for(p=0;p<d;p++)
	if(drctry[2*p]->recrds!=drctry[2*p+1]->recrds)
	break;
	if(p==d)
	{
		d--;
		bckt **ndrctry=new bckt*[pwr(d)];
		for(int i=0;i<pwr(d);i++)
		ndrctry[i]=new(bckt);
		for(int i=0;i<pwr(d);i++)
		ndrctry[i]=drctry[2*i];
		bckt **s=drctry;
		drctry=ndrctry;
	}
}
void del(int k,bckt **&drctry,int rno,int *bnry,int key,int limit)
{
	int p[5],p2;
	c1=new char[10];
	itoa(drctry[k]->recrds,c1,10);
	strcat(c1,"ahash.txt");
	in1.open(c1);
	for(int i=0;i<drctry[k]->count;i++)
	in1>>p[i];
	in1.close();
	for(p2=0;p2<drctry[k]->count;p2++)
	if(p[p2]==key)
	break;
	for(int i=p2;i<drctry[k]->count-1;i++)
	p[i]=p[i+1];
	out1.open(c1);
	drctry[k]->count--;
	for(int i=0;i<drctry[k]->count;i++)
	out1<<p[i]<<" ";
	if(k%2==0&&(drctry[k]->count+drctry[k+1]->count)<=5&&d!=0)
	{
	  d2=new char[10];
	  itoa(drctry[k+1]->recrds,d2,10);
	  strcat(d2,"ahash.txt");
	  in1.open(d2);
	  for(int i=0;i<drctry[k+1]->count;i++)
	  {
	  	in1>>p2;out1<<p2<<" ";drctry[k]->count++;
	  }
	  in1.close();out1.close();bckt *s=drctry[k+1];
	  drctry[k+1]=drctry[k];delete s;
	}
	else if(k%2==1&&(drctry[k]->count+drctry[k-1]->count)<=5&&d!=0)
	{
	  out1.close();
	  d2=new char[10];
	  itoa(drctry[k-1]->recrds,d2,10);
	  strcat(d2,"ahash.txt");
	  out1.open(d2,ios::app);
	  c1=new char[10];
	  itoa(drctry[k]->recrds,c1,10);
	  strcat(c1,"ahash.txt");
	  in1.open(c1);
	  for(int i=0;i<drctry[k]->count;i++)
	  {
	  	in1>>p2;out1<<p2<<" ";drctry[k-1]->count++;
	  }
	  in1.close();out1.close();bckt *s=drctry[k];
	  drctry[k]=drctry[k-1];delete s;	
	}
	else
	out1.close();
	dcntact(drctry);
}
void create(int k,bckt **&drctry,int rno,int *bnry,int key,int limit)
{
	if(drctry[k]->count<5)
	{
		c1=new char[10];
		itoa(drctry[k]->recrds,c1,10);
		strcat(c1,"ahash.txt");
		if(drctry[k]->count==0)
		out1.open(c1);
		else
		out1.open(c1,ios::app);
		out1<<key<<" ";
		drctry[k]->count++;out1.close();
	}
	else if(drctry[k]->d1<d) 
	{
	   bckt *p1=new(bckt),*p2=new(bckt);
	   //cout<<p1->recrds<<" "<<p2->recrds<<endl;
	     int *e=new int[8];
	     c1=new char[10];
		itoa(drctry[k]->recrds,c1,10);
		strcat(c1,"ahash.txt");
		in1.open(c1);
		int arr[5];
		for(int i=0;i<5;i++)
		{
			in1>>arr[i];
		}in1.close();
		p1->recrds=drctry[k]->recrds;
		out1.open(c1);
		d2=new char[10];
		itoa(p2->recrds,d2,10);
		strcat(d2,"ahash.txt");out2.open(d2);
	   	   for(int i=0;i<5;i++)
	   	   {
	   	      getbin(e,arr[i]%limit);
	   	      if(e[drctry[k]->d1]==0)
	   	      {
	   	      	p1->count++;out1<<arr[i]<<" ";
	   	      }
	   	      else
	   	      {
	   	      	p2->count++;
	   	      	out2<<arr[i]<<" ";
	   	      }
	   	   }
	   	   out1.close();out2.close();
	   	   p1->d1=drctry[k]->d1+1;p2->d1=drctry[k]->d1+1;bckt *s=drctry[k];
	   	   if(k%2==0)
	   	   {
	   	   drctry[k]=p1;drctry[k+1]=p2;
	       }
	   	   else
	   	   {
	   	   drctry[k-1]=p1;drctry[k]=p2;
	       }
		   delete s;
	   	   check(drctry,bnry,rno,key,limit);
	   }
	   else
	   {
	   	 d++;
	   	 bckt **ndrctry=new bckt*[pwr(d)];
		 for(int i=0;i<pwr(d);i++)
		 ndrctry[i]=new(bckt);
		 for(int i=0;i<pwr(d-1);i++)
		 {
		 	ndrctry[2*i]=drctry[i];
		 	ndrctry[2*i+1]=drctry[i];
		 }
		 drctry=ndrctry;
		 check(drctry,bnry,rno,key,limit);	  
	   }
}
void check(bckt **&drctry,int *bnry,int rno,int key,int limit)
{
	int k=getrcrd(bnry,d);
	create(k,drctry,rno,bnry,key,limit);
}
void take(bckt **&drctry,int *bnry,int rno,int key,int limit)
{
    int k=getrcrd(bnry,d);
    cout<<drctry[k]->recrds<<endl;
	del(k,drctry,rno,bnry,key,limit);	
}
int main()
{
	int a=256,key,rno,*bnry,k;char ch;
	bnry=new int[8];
	cout<<"enter the key\n";
	cin>>key;
	bckt **drctry=new bckt*[pwr(d)];
	for(int i=0;i<pwr(d);i++)
	drctry[i]=new(bckt);
	do
	{
		rno=key%a;
		getbin(bnry,rno);
		check(drctry,bnry,rno,key,a);	
		cout<<"enter the key\n";
		cin>>key;
	}while(key!=-1);
	cout<<"enter the key to be deleted\n";
	cin>>key;
	do
	{
		if(key!=-1){rno=key%a;
		getbin(bnry,rno);
		take(drctry,bnry,rno,key,a);
		cout<<"enter the key to be deleted\n";
		cin>>key;
		}
	}while(key!=-1);
	return 0;
}
