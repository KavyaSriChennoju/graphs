#include<iostream>
#include<fstream>
using namespace std;
int min(int a[],int g)
{
    int x=-1;
    for(int i=0;i<g;i++)
    {
        if(a[i]!=-1)
        {
            x=a[i];
            break;
        }
    }
    for(int i=0;i<g;i++)
    {
        if(a[i]!=-1)
        {
            if(a[i]<x)
                x=a[i];
        }
    }
    if(x==-1)
        return -1;
    else
        return x;
}
void add(ifstream f[],ofstream &fout,int g)
{
    int x,j=0;
    int a[g];
    for(int i=0;i<g;i++)
        f[i]>>a[i];
    x=min(a,g);
    while(x!=-1)
    {
        for(int i=0;i<g;i++)
        {
            if(a[i]==x)
            {
                j=i;
                break;
            }
        }
        fout<<x<<" ";
        f[j]>>a[j];
        j=0;
        x=min(a,g);
    }
}
void sort(int a[],int m)
{
    for(int i=0;i<m-1;i++)
    {
        for(int j=i;j<m;j++)
        {
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
int main()
{
    int g;
    ifstream fin;
    char A[10][8]={"A1.txt","A2.txt","A3.txt","A4.txt","A5.txt","A6.txt","A7.txt","A8.txt","A9.txt","A10.txt"};
    char B[10][8]={"B1.txt","B2.txt","B3.txt","B4.txt","B5.txt","B6.txt","B7.txt","B8.txt","B9.txt","B10.txt"};
    fin.open("mway.txt");
    cout<<"\n enter the number of ways"<<endl;
    cin>>g;
    ofstream fout[g];
    for(int i=0;i<g;i++)
    {
        fout[i].open(A[i]);
    }
    int i=0,x,j=0,y=0,m=0,n=0,a[3],k=0,z=0,t=0,s;
    for(i=0;i<3;i++)
    {
        fin>>x;
        a[k++]=x;
    }
    while(!fin.eof())
    {
        k=j;
        sort(a,3);
        m=j%g;
        if(a[0]>y)
        {
            fout[m]<<a[0]<<" ";
            y=a[0];
            fin>>x;
            a[0]=x;
        }
        else if(a[1]>y)
        {
            fout[m]<<a[1]<<" ";
            y=a[1];
            fin>>x;
            a[1]=x;
        }
        else if(a[2]>y)
        {
            fout[m]<<a[2]<<" ";
            y=a[2];
            fin>>x;
            a[2]=x;
        }
        else
        {
            fout[m]<<-1<<" ";
            y=0;
            j++;
        }
        if(k!=j)
        {
            n++;
            if(m==0)
            {
                z++;
            }
        }
    }
  j++;
    s=m;
    m=j%g;
    if(m==0)
        z++;
    if(a[0]!=-1)
    {
        if(a[0]<y)
        fout[m]<<a[0]<<" ";
        else
        {
            fout[s]<<a[0]<<" ";
            y=a[0];
        }
    }
    if(a[1]!=-1)
    {
        if(a[1]<y)
        fout[m]<<a[1]<<" ";
        else
        {
            fout[s]<<a[1]<<" ";
            y=a[1];
        }
    }
    if(a[2]!=-1)
    {
        if(a[2]<y)
        fout[m]<<a[2]<<" ";
        else
            fout[s]<<a[2]<<" ";
    }
    fout[m]<<-1<<" ";
    fout[s]<<-1<<" ";
    k++;
    j++;
    m=j%g;
    if(m==0)
        z++;
    j++;
    m=j%g;
    if(m==0)
        z++;
    n=n+2;
    m=n%g;
    while(m!=g)
    {
        fout[m++]<<-1<<" ";
    }
    for(int i=0;i<g;i++)
        fout[i].close();
    fin.close();
    ifstream f[g];
    i=0;
    x=0;
    while(z!=0)
    {
        if(i%2==0)
        {
            for(int t=0;t<g;t++)
            {
                f[t].open(A[t]);
                fout[t].open(B[t]);
            }
        }
        else
        {
            for(int t=0;t<g;t++)
            {
                f[t].open(B[t]);
                fout[t].open(A[t]);
            }
        }
        while(x!=z)
        {
            t=x%g;
            add(f,fout[t],g);
            fout[t]<<-1<<" ";
            x++;
        }
        y=t;
        t=x%g;
        while(t!=0)
        {
            fout[t]<<-1<<" ";
            x++;
            t=x%g;
        }
        for(int t=0;t<g;t++)
        {
            fout[t].close();
            f[t].close();
        }
        x=0;
        z=z/2;
        i++;
    }
    if(i%2==0)
        {
            f[0].open(A[y]);
        }
        else
        {
            f[0].open(B[y]);
        }
    f[0]>>y;
    while(y!=-1)
    {
        cout<<y<<" ";
        f[0]>>y;
    }
    f[0].close();
    return 0;
}
