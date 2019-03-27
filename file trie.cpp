#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
struct leafnode
{
       int rec;
       int ln;
};
union un
{
      struct trinode *ptr;
      struct leafnode*p;
};
struct trinode
{
       char al[26];
       un u[27];
       int tag[27];
       int nlf;
};int size,i;
trinode* add(trinode *T,string c,int j,int r)
{if(j<size)
  {
         if(T==NULL)
           {cout<<"f1"<<endl;
                    T=new(trinode);
                    for(int i=0;i<26;i++)
                    T->al[i]=i+97;
                    T->nlf=1;  
                        for(int i=0;i<26;i++)
                        {if(c[j]==97+i)
                            {cout<<"check"<<i<<endl;
                                      if(j+1==size)
                                       {
                                                   cout<<"f2"<<endl;
                                                   T->tag[i]=0;
                                                   T->u[i].p=new(leafnode);
                                                   T->u[i].p->rec=r;
                                                   T->u[i].p->ln=0;
                                                   for(int k=0;k<27;k++)
                                                     {    if(k!=i)
                                                         {
                                                              T->u[k].ptr=new(trinode);
                                                              T->u[k].ptr=NULL;
                                                              T->tag[k]=1;
                                                         }
                                                   }
                                      }
                                     else
                                      {
                                         for(int k=0;k<27;k++)
                                         {
                                                T->u[k].ptr=new(trinode);
                                                T->u[k].ptr=NULL;
                                                T->tag[k]=1;
                                         }
                                          T->u[i].ptr=add(T->u[i].ptr,c,j+1,r);
                                      }
                            }
                       }
           }       
           else
           {cout<<"f3"<<endl;
                   for(i=0;i<26;i++)
                     if(c[j]==i+97)
                     {cout<<i<<endl;
                                   if(T->tag[i]==0)
                                   {   cout<<"going"<<endl<<"inside"<<i;int l=T->u[i].p->rec;
                                       T->u[i].ptr=NULL;
                                       T->tag[26]=0;
                                       T->u[26].p=new(leafnode);
                                       T->u[26].p->rec=l;
                                       T->u[26].p->ln=0;
                                       T->tag[i]=1;
                                       T->u[i].ptr=add(T->u[i].ptr,c,j+1,r);
                                   }
                                   else if(j+1==size)
                                   {cout<<"entering";
                                        T->tag[26]=0;
                                         T->u[26].p=new(leafnode);
                                         T->u[26].p->rec=r;
                                         T->u[26].p->ln=0;
                                   }
                                   else
                                   {cout<<"T->u["<<i<<"].ptr"<<endl;
                                   T->u[i].ptr=add(T->u[i].ptr,c,j+1,r);}
                     }
           }
     return T;      
  } 
}
int ch=0,cou=0;
void search(trinode *T,string c)
{
    for(i=0;i<size;i++)
    {for(int n=0;n<26;n++)
      {if(c[i]==n+97)
           {
              if(T->u[n].ptr!=NULL)
               {
                                   T=T->u[n].ptr;
                                   cou++;
                                   break;
               }
               else
               {  cout<<"not found";
                  ch=1;
                   break;
               }
            }
      }
      if(ch==1)
      {ch=0;
      break;}
    }
}
            
    
int main()
{trinode *T,*S;int p,s=0;
string c;
T=NULL;
do
{   
    cout<<"\nEnter a word(only small case letters).";
    cin>>c;
    size=c.length();
    T=add(T,c,0,s);
    s++;
    cout<<"Enter 1 to continue input";
    cin>>p;
}while(p==1);
S=T;
    do{
    cout<<"\nEnter a word to search";
    cin>>c;
    size=c.length();
    search(T,c);
    if(cou==size)
    cout<<"found";
    cout<<"\nTo continue search press 1";
    cin>>p;
    cou=0;T=S;
}
    while(p==1);
getch();
}


