#include<iostream>
#include<fstream>
using namespace std;
void sort(int arr[],int a)
{
  for(int i=0;i<a-1;i++)
  for(int j=i+1;j<a;j++)
  if(arr[i]>arr[j])
  {
	int t=arr[i];arr[i]=arr[j];arr[j]=t;
  }
}
int main()
{
  ofstream out("data.txt"),out3("data1.txt"),out4("data2.txt");
  cout<<"enter the numbers to be sorted\n";
  int d,k,a,b,cnt=0;
  cin>>d;
  do
  {
	cnt++;
	out<<d<<" ";
	cin>>d;
  }while(d!=-1);
  out.close();
  cout<<"enter the array size\n";
  cin>>k;
  const int size=k;
  int arr[size],count=1,min,count1=1;
  ifstream in1("data.txt"),in2;
  int count2=0;in1>>d;
  while(!in1.eof())
  {
	arr[count2++]=d;
	if(count2==size)
	{
	  if(count%2==1)
	  {
		for(int i=0;i<count2-1;i++)
		for(int j=i+1;j<count2;j++)
		if(arr[i]>arr[j])
		{
		  int t=arr[i];arr[i]=arr[j];arr[j]=t;
		}
		for(int i=0;i<count2;i++)
		out3<<" "<<arr[i];
		out3<<" "<<"-1"<<endl;
	  }
	  else
	  {
		for(int i=0;i<count2-1;i++)
		for(int j=i+1;j<count2;j++)
		if(arr[i]>arr[j])
		{
		  int t=arr[i];arr[i]=arr[j];arr[j]=t;
		}
		for(int i=0;i<count2;i++)
		out4<<" "<<arr[i];
		out4<<" "<<"-1"<<endl;
	  }
	  count++;count2=0;
	}
	in1>>d;
  }
 if(count%2==1)
  {
	sort(arr,count2);
	for(int i=0;i<count2;i++)
	{
	  out3<<" "<<arr[i];cout<<arr[i]<<" ";
	}
	cout<<arr[count2-1]<<endl;
	out3<<" "<<"-1"<<endl;
  }
  else
  {
	sort(arr,count2);
	for(int i=0;i<count2-1;i++)
	{
	   out4<<" "<<arr[i];cout<<arr[i]<<" ";
	}
	cout<<arr[count2-1]<<endl;
	out4<<" "<<"-1"<<endl;
  }
  out3.close();
  out4.close();
  in1.close();
  while(count2<cnt)
  {
	count=1;
	count2=0;
	if(count1++%2==1)
	{
	  in1.open("data1.txt");
	  in2.open("data2.txt");
	  out3.open("data3.txt");
	  out4.open("data4.txt");
	}
	else
	{
	  in1.open("data3.txt");
	  in2.open("data4.txt");
	  out3.open("data1.txt");
	  out4.open("data2.txt");
	}
    in1>>a;
	in2>>b;
    while(!in1.eof()||!in2.eof())
	{
	  if(a>b)
      {
	    if(count%2==1)
		{
		  if(b!=-1&&!in2.eof())
		  {
			out3<<b<<" ";
			count2++;
			in2>>b;
	       }
		  else
		  {
			while(a!=-1&&!in1.eof())
			{
			  out3<<a<< " ";
    		  count2++;
		      in1>>a;
			}
			if(count2!=cnt)
			out3<<"-1"<<endl;
    		in1>>a;in2>>b;
	    	count++;
		  }
		}
    	else if(count2!=cnt)
	    {
	      if(b!=-1)
		  out4<<b<<" ";
		  if(b!=-1&&!in2.eof())
    	  in2>>b;
	      else
		  {
			while(a!=-1&&!in1.eof())
			{
			  out4<<a<< " ";
	    	  in1>>a;
		    }
		    if(count2!=cnt)
			out4<<"-1"<<endl;
			in1>>a;in2>>b;
    		count++;
	      }
		}
	  }
      else
	  {
	    if(count%2==1)
		{
		  if(a!=-1)
		  {
			out3<<a<<" ";
			count2++;
		  }
	      if(a!=-1&&!in1.eof())
		  in1>>a;
		  else
		  {
    		while(b!=-1&&!in2.eof())
	    	{
	    	  count2++;
		      out3<<b<< " ";
			  in2>>b;
    		}
			if(count2!=cnt)    
		    out3<<"-1"<<endl;
			in1>>a;in2>>b;
			count++;
    	  }    
	    }
		else if(count2!=cnt)
		{
		  if(a!=-1)
		  out4<<a<<" ";
	      if(a!=-1&&!in1.eof())
		  in1>>a;
		  else
		  {
    		while(b!=-1&&!in2.eof())
	    	{
		      out4<<b<< " ";
			  in2>>b;
    		}    
    		if(count2!=cnt)
	    	out4<<"-1"<<endl;
			in1>>a;in2>>b;
			count++;
    	  }
	    }
	  }
	}
	out3.close();
	out4.close();
    in1.close();
	in2.close();
  }
  return 0;
}
