#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
struct node2;
union un;
struct trienode;
struct store
{
	char s[15];
	int in;	
};
struct node2
{
	char ch[27];
	trienode *chptr[27];
};
union un
{
	int rno;
	node2 a;
};
struct trienode
{
	int tag;
	un u;
};
int main()
{
	ofstream fout;ifstream fin;store st[100];
	fout.open("file1.txt");
	int n=1,i=0,j=0,k=1;
	char s[20],ch;
	cout<<"enter the words\n";
	do
	{
		cin>>s;
		fout<<s<<'$';
		cout<<"to continue\n";
		cin>>ch;
		n++;
	}while(ch=='y');
	int m=n,k1=0;n=1;
	fout.close();
	while(!fin.eof())
	{
	fin.open("file1.txt");
	for(int i=0;i<n-1;i++)
    {
	while(ch!='$')
	{
		fin.get(ch);
	}
	fin.get(ch);
    }
    if(n==1)
    fin.get(ch);
	if(ch!='$' && k!=1 )
	{  cout<<ch;
	   st[i].s[j++]=ch;
	}
  
    while(ch!='$')
    {
	fin.get(ch);
	if(ch!='$' && k!=1)
	{
	cout<<ch;
	 st[i].s[j++]=ch;
	}
    } st[i].s[j++]='\0';st[i].in=k1;j=0;i++;k1++;
    cout<<"\n";  fin.close();
    n++;
    k=2;
   }
   int cnt=i;
   for(int i=1;i<cnt-1;i++)
   cout<<st[i].in<<"  "<<st[i].s<<"\n";
  
	
	
}
