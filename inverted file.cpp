#include<iostream>
#include<fstream>
using namespace std;
struct student
{
    int rno;
	char name[10];	
};
struct course
{
	int cno;
	char cname[6];
};
ifstream & operator >>(ifstream &fin,student &s )
{
	fin>>s.rno;
	fin>>s.name;
}
ifstream & operator >>(ifstream &fin,course &c )
{
	fin>>c.cno;
	fin>>c.cname;
}
ofstream & operator <<(ofstream &fout,student &s )
{
	fout<<s.rno<<"  ";
	fout<<s.name<<"  ";
}
ofstream & operator <<(ofstream &fout,course &c)
{
	fout<<c.cno<<"  ";
	fout<<c.cname<<"  ";
}
int main()
{
	ofstream fout,fout1,fout2,fout3;
	ifstream fin,fin1,fin2,fin3;
	static int r=0,k2=0,k1=0;
	fout.open("reg.txt");fout1.open("student.txt");fout2.open("course.txt");
	fout.close();fout1.close();fout2.close();
	fout.open("reg.txt",ios::app);fout1.open("student.txt",ios::app);fout2.open("course.txt",ios::app);
	fin1.open("student.txt");fin2.open("course.txt");
	student s1,s2;
	course c1,c2;
	cout<<"enter the rollno\n";
	cin>>s1.rno;
	cout<<"enter name\n";
	cin>>s1.name;
	cout<<"enter the course no\n";
	cin>>c1.cno;
	cout<<"enter course name\n";
	cin>>c1.cname;
	fout1<<s1;
	fout2<<c1;
	fout<<r<<"  "<<s1.rno<<"  "<<c1.cno<<"  ";
	r++;
	while(s1.rno!=-1)
	{
	cout<<"enter the rollno\n";
	cin>>s1.rno;
	if(s1.rno!=-1)
	{
	fin1>>s2;
	while(!fin1.eof())
	{
		if(s1.rno==s2.rno)
		{
	    k1=1;
	    }
	    fin1>>s2;
	}
	if(k1!=1)
	{
	cout<<"enter name\n";
	cin>>s1.name;
	fout1<<s1;
	k1=0;
	}
	cout<<"enter the course no\n";
	cin>>c1.cno;
	fin2>>c2;
	while(!fin2.eof())
	{
		if(c1.cno==c2.cno)
		{
	    k2=1;
	    }
	    fin2>>c2;
	}
	if(k2!=1)
	{
	cout<<"enter course name\n";
	cin>>c1.cname;
	fout2<<c1;
	k2=0;
	}

}
	
	
	
	
	
		
		
		
	}
fin1.close();fin2.close();fout.close();fout1.close();fout2.close();
	
}
