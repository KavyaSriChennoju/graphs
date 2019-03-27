#include <iostream>
#include <fstream>
using namespace std;
 void sort(int d[],int i)
{
	for(int j=0;j<i-1;j++)
	{
		for(int k=j+1;k<i;k++)
		{
			if(d[j]>d[k])
			{
				int t=d[k];
				d[k]=d[j];
				d[j]=t;
			}
		}
	}
}
int main()
{
	ifstream in,in1,in2,in3,in4;
    ofstream out,out1,out2,out3,out4;
	in.open("3wppdata.txt");
	int d[3],a1,a2,a3,a4=0, k1,k2,k3,k4;
	out1.open("3wpp1.txt");
	out2.open("3wpp2.txt");
	out3.open("3wpp3.txt");
	in>> k1>>k2>>k3;
	d[0]= k1;d[1]=k2;d[2]=k3;
	sort(d,3);a1=0,a2=0,a3=0;
	while(!in.eof())
	{
		if(a1==0||(a4==4&&a2<7))
		{
			out1<<d[0]<<" "<<d[1]<<" "<<d[2]<<" "<<"-1"<<" ";
			a1++;a2++;
		}
		else if(a1==1||(a4==4&&a3<6))
		{
			out2<<d[0]<<" "<<d[1]<<" "<<d[2]<<" "<<"-1"<<" ";
			a1++;a3++;
		}
		else if(a4<4)
		{
			out3<<d[0]<<" "<<d[1]<<" "<<d[2]<<" "<<"-1"<<" ";
			a1=0;a4++;
		}
		in>> k1>>k2>>k3;
		d[0]= k1;d[1]=k2;d[2]=k3;sort(d,3);
	}
	out1.close();
	out2.close();
	out3.close();
	out4.open("3wpp4.txt");
	in1.open("3wpp1.txt");
	in2.open("3wpp2.txt");
	in3.open("3wpp3.txt");
	in3>>k3;
	while(!in3.eof())
	{
		in2>>k2;in1>> k1;
		d[0]= k1;d[1]=k2;d[2]=k3;sort(d,3);
		out4<<d[0]<<" ";
		do
		{
			if(d[0]== k1&&!in1.eof()&& k1!=-1)
			{
				in1>> k1;
				if( k1!=-1)
				{
					d[0]= k1;
					sort(d,3);
					out4<<d[0]<<" ";
				}
				else
					d[0]=k2;
			}
			else if( k1==-1)
				d[0]=k2;
			if(d[0]==k2&&!in2.eof()&&k2!=-1)
			{
				in2>>k2;	
				if(k2!=-1)
				{
					d[0]=k2;
					sort(d,3);
					out4<<d[0]<<" ";
				}
				else
					d[0]=k3;
			}
			else if(k2==-1)
				d[0]=k3;
			if(d[0]==k3&&!in3.eof()&&k3!=-1)
			{
				in3>>k3;
				if(k3!=-1)
				{
					d[0]=k3;
					sort(d,3);
					out4<<d[0]<<" ";
				}
				else
					d[0]= k1;
			}
			else if(k3==-1)
				d[0]= k1;
		}while( k1!=-1||k2!=-1||k3!=-1);
		out4<<d[1]<<" "<<d[2]<<" "<<"-1"<<" ";
		in3>>k3;
	}
	in3.close();
	out4.close();
	out3.open("3wpp3.txt");
	in4.open("3wpp4.txt");
	in2>>k2;
	while(!in2.eof())
	{
		in4>>k4;in1>> k1;
		d[0]= k1;d[1]=k4;d[2]=k2;sort(d,3);
		out3<<d[0]<<" ";
		do
		{
			if(d[0]== k1&&!in1.eof()&& k1!=-1)
			{
				in1>> k1;
				if( k1!=-1)
				{
					d[0]= k1;
					sort(d,3);
					out3<<d[0]<<" ";
				}
				else
					d[0]=k4;
			}
			else if( k1==-1)
				d[0]=k4;
			if(d[0]==k4&&!in4.eof()&&k4!=-1)
			{
				in4>>k4;
				if(k4!=-1)
				{
					d[0]=k4;
					sort(d,3);
					out3<<d[0]<<" ";
				}
				else
					d[0]=k2;
			}
			else if(k4==-1)
				d[0]=k2;
			if(d[0]==k2&&!in2.eof()&&k2!=-1)
			{
				in2>>k2;
				if(k2!=-1)
				{
					d[0]=k2;
					sort(d,3);
					out3<<d[0]<<" ";
				}
				else
					d[0]= k1;
			}
			else if(k2==-1)
				d[0]= k1;
		}while( k1!=-1||k4!=-1||k2!=-1);
		out3<<d[1]<<" "<<d[2]<<" "<<"-1"<<" ";
		in2>>k2;
	}
	in2.close();
	out2.open("3wpp2.txt");
	out3.close();
    in3.open("3wpp3.txt");
	in1>> k1;
	while(!in1.eof())
	{
		in4>>k4;in3>>k3;
		d[0]= k1;d[1]=k4;d[2]=k3;sort(d,3);
		out2<<d[0]<<" ";
		do
		{
			if(d[0]== k1&&!in1.eof()&& k1!=-1)
			{
				in1>> k1;
				if( k1!=-1)
				{
					d[0]= k1;
					sort(d,3);
					out2<<d[0]<<" ";
				}
				else
					d[0]=k4;
			}
			else if( k1==-1)
				d[0]=k4;
			if(d[0]==k4&&!in4.eof()&&k4!=-1)
			{
				in4>>k4;
				if(k4!=-1)
				{
					d[0]=k4;
					sort(d,3);
					out2<<d[0]<<" ";
				}
				else
					d[0]=k3;
			}
			else if(k4==-1)
				d[0]=k3;
			if(d[0]==k3&&!in3.eof()&&k3!=-1)
			{
				in3>>k3;
				if(k3!=-1)
				{
					d[0]=k3;
					sort(d,3);
					out2<<d[0]<<" ";
				}
				else
					d[0]= k1;
			}
			else if(k3==-1)
				d[0]= k1;
		}while( k1!=-1||k4!=-1||k3!=-1);
		out2<<d[1]<<" "<<d[2]<<" "<<"-1"<<" ";
		in1>> k1;
	}
	in1.close();
	out1.open("3wpp1.txt");
	out2.close();
	in2.open("3wpp2.txt");
	in4>>k4;in3>>k3;in2>>k2;
		d[0]=k2;d[1]=k4;d[2]=k3;sort(d,3);
		out1<<d[0]<<" ";
		do
		{
			if(d[0]==k2&&!in2.eof()&&k2!=-1)
			{
				in2>>k2;
				if(k2!=-1)
				{
					d[0]=k2;
					sort(d,3);
					out1<<d[0]<<" ";
				}
				else
					d[0]=k4;
			}
			else if(k2==-1)
				d[0]=k4;
			if(d[0]==k4&&!in4.eof()&&k4!=-1)
			{
				in4>>k4;
				if(k4!=-1)
				{
					d[0]=k4;
					sort(d,3);
					out1<<d[0]<<" ";
				}
				else
					d[0]=k3;
			}
			else if(k4==-1)
				d[0]=k3;
			if(d[0]==k3&&!in3.eof()&&k3!=-1)
			{
				in3>>k3;
				if(k3!=-1)
				{
					d[0]=k3;
					sort(d,3);
					out1<<d[0]<<" ";
				}
				else
					d[0]=k2;
			}
			else if(k3==-1)
				d[0]=k2;
		}while(k2!=-1||k4!=-1||k3!=-1);
		out1<<d[1]<<" "<<d[2]<<" "<<"-1"<<" ";
	return 0;
}
