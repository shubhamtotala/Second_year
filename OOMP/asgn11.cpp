/*
Assignment No.:11

Problem Statement:

Design a C++ base class consisting of the data members such as name of the student, roll number and subject. The derived class consists of the data members subject code, internal assessment and university examination marks. Construct a virtual base class for the item name of the student and roll number. The program should have the facilities.

i) 	Build a master table 		ii) 	List a table
iii) 	Insert a new entry		iv) 	Delete old entry
v) 	Edit an entry 			    vi) 	Search for a record


*/

#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<cstdlib>
#define MAX 20

using namespace std;

class base
{
  public:
	char name[MAX];
	char roll[10];
	char sub[MAX];
  public:
	base()
  	  {
		strcpy(roll,"00");
		strcpy(name,"NAME");
		strcpy(sub,"SUBJECT");
  	  }

	virtual ~base()
	{
		strcpy(roll,"00");
		strcpy(name,"NAME");
		strcpy(sub,"SUBJECT");
	}

	virtual void getdata();
	virtual void showdata();
};

	void base::getdata()
	{
		cout<<"\n STUDENT INFO\n";
		cout<<"\nROLL:";
		cin>>roll;
		cout<<"\n NAME:";
		cin>>name;
		cout<<"\n SUBJECT";
		cin>>sub;
	}

	void base::showdata()
	{
		cout<<"\n\t"<<roll;
		cout<<"\t"<<name;
		cout<<"\t"<<sub;
	}

class derived:public base
{
	public:
		int subcode;
		int imarks;
		float umarks;
		derived()
		{
			subcode=0;
			imarks=0;
			umarks=0;
		}
		~derived()
		{
			subcode=0;
			imarks=0;
			umarks=0;
		}
		void getdata();
		void showdata();
};






	void derived::getdata()
	{
		base::getdata();
		cout<<"\n SUBJECT CODE:";
		cin>>subcode;
		cout<<"\n INTERNAL MARKS:";
		cin>>imarks;
		cout<<"\n UNIVERSITY MARKS";
		cin>>umarks;
		cout<<"\n";
	}

	void derived::showdata()
	{
		base::showdata();
		cout<<"\t"<<subcode;


		cout<<"\t"<<imarks;

		cout<<"\t"<<umarks;

	}

int n;//global


	void create(int n)
	{
		int i=0;
		ofstream fout;
		derived d[MAX];
		if(n!=0)    //If students are zero then doesnot create file
		{
			fout.open("myfile.txt",ios::out|ios::trunc); //truc to clear contents
			for(i=0;i<n;i++)
			{
				d[i].getdata();
				fout.write((char*)&d[i],sizeof(d[i]));
			}
			fout.close();
		}
	}

	int size()
	{
		ifstream fin;
		fin.open("myfile.txt",ios::in);
		fin.seekg(0,ios::end);     //points to end of file
		int endpos=fin.tellg();   //return total size of file
		return endpos/sizeof(derived);    //total size of file divided by total no of objects present

	}

	void display()
	{
		ifstream fin;
		int i=0;
		derived d[MAX];
		fin.open("myfile.txt",ios::in);
		if(!fin)
			cout<<"\n\t ERROR:UNABLE TO OPEN FILE";
		else
		{
			if(size()==0)   //if file is empty
				cout<<"\n DATABASE EMPTY";
			else
			{
				cout<<"\n\t ROLL\tNAME\tSUB\tSUBCODE\tINTMARKS\tUNVMARKS";
				while(fin.read((char*)&d[i],sizeof(d[i])))
				{
					d[i].showdata();
					i++;
				}
			}
		}
		fin.close();
	}



	void insert()
	{
		derived tmp;
		ofstream fout;
		cout<<"\n INSERT NEW RECORD\n";
		fout.open("myfile.txt",ios::app);
		tmp.getdata();
		fout.write((char*)&tmp,sizeof(tmp));
		n++;
		fout.close();
	}





	void delete_rec(int *n,char r[10])
	{
		fstream file1,file2;
		derived s[MAX];
		int flag=0;
		file1.open("myfile.txt",ios::in|ios::out);
		file2.open("tmp.txt",ios::out|ios::trunc);

		for(int i=0;file1.read((char*)&s[i],sizeof(s[i]));i++)
		{
			if(strcmp(s[i].roll,r)!=0)
			{
				file2.write((char*)&s[i],sizeof(s[i]));
			}
			else
				flag=1;
		}
		(*n)--;
		file1.close();
		file2.close();
		file1.open("myfile.txt",ios::out|ios::trunc);
		file2.open("tmp.txt",ios::in);

//all records are restored to main file

		for(int i=0;file2.read((char *)&s[i],sizeof(s[i]));i++)
		{
			file1.write((char*)&s[i],sizeof(s[i]));
		}

		file1.close();
		file2.close();


		file2.open("tmp.txt",ios::trunc);
		file2.close();
		if(flag==0)

			cout<<"RECORD NOT FOUND";
	}





	void search(char r[])
	{
		int flag=0;
		ifstream fin;
		derived d;
		fin.open("myfile.txt",ios::in);

		if(!fin)
		cout<<"\n\t ERROR:MAY BE FILE EMPTY";
		else
			if (size()==0)
				cout<<"\n\t DATABASE EMPTY";
			else
			{
				while(fin.read((char*)&d,sizeof(d)))
				{
					if(strcmp(d.roll,r)==0)
					{
						flag=1;
						cout<<"\n\t RECORD FOUND\t";
						d.showdata();
						break;
					}
				}
			}

		fin.close();
		if(flag==0)
			cout<<"\n\t RECORD NOT FOUND";
	}



	void edit(char r[])
	{
		int flag=0;
		derived d;
		fstream file;
		int ch;
		int count;
		file.open("myfile.txt",ios::in|ios::out|ios::ate);
		if(!file)
			cout<<"\n\t ERROR:UNABLE TO OPEN FILE";
		else
		{  file.seekg(0,ios::beg);
			count=0;
			while(file.read((char*)&d,sizeof(d)))
			{
				count++;
				if(strcmp(d.roll,r)==0)
				{
					flag=1;
					break;
				}
			}
			file.seekg((count-1)*sizeof(derived));
			file.read((char*)&d,sizeof(d));
			if(flag==1)
			{
				cout<<"\n RECORD FOUND\n\n";
				d.showdata();
				do{
					cout<<"\n\n\t EDIT MENU\n\t";
					cout<<"\n\t 1.ROLL NO";
					cout<<"\n\t 2.NAME";
					cout<<"\n\t 3.SUBJE CT";
					cout<<"\n\t 4.INTERNAL MARKS";
					cout<<"\n\t 5.UNIV MARKS";
					cout<<"\n\t 6. EXIT";
					cout<<"\n\n\t WHAT TO MODIFY:";
					cin>>ch;
					switch(ch)
					{
						case 1:
							cout<<"\n\t Enter new roll no";
							cin>>d.roll;
						break;
						case 2:
							cout<<"\n\t Enter new name";
							cin>>d.name;
						break;
						case 3:
							cout<<"\n\t Enter new subject";
							cin>>d.sub;
							cout<<"Enter new subject code";
							cin>>d.subcode;
						break;
						case 4:
							cout<<"\n\t enter new internal marks";
							cin>>d.imarks;
						break;
						case 5:
							cout<<"\n\t Enter new university marks";
							cin>>d.umarks;
						break;
						case 6:
						break;
				}
			}while(ch!=6);

			file.seekp((count-1)*sizeof(derived));
			file.write((char*)&d,sizeof(d));
			}
		}
		file.close();
		if(flag==0)
			cout<<"\n\t RECORD NOT FOUND";
	}



	int main()
	{
		int ch;
		char roll[10];
		do
		{
			cout<<"\n\t MENU\n---------------------------";
			cout<<"\n\t 1.CREATE RECORD";
			cout<<"\n\t 2.SHOW RECORD";
			cout<<"\n\t 3.INSERT NEW";
			cout<<"\n\t 4.DELETE OLD";
			cout<<"\n\t 5.EDIT RECORD";
			cout<<"\n\t 6.SEARCH RECORD";
			cout<<"\n\t CLOSE";
			cout<<"\n Enter choice";
			cin>>ch;
			switch(ch)
			{
				case 1:
					cout<<"\n How many subject:";
					cin>>n;
					create(n);
				break;
				case 2:
					display();
				break;
				case 3:
					insert();
					display();
				break;
				case 4:
					cout<<"\n Enter roll no to delete record";
					cin>>roll;
					delete_rec(&n,roll);
					display();
				break;
				case 5:
					cout<<"\nEnter roll no to search and edit record";
					cin>>roll;
					edit(roll);
				break;
				case 6:
					cout<<"\n Enter roll no to search record";
					cin>>roll;
					search(roll);
				break;
				case 7:
					//exit(0);
				break;
			}
		}while(ch!=7);

	}

/*
output:
------------------------------------------------------------------------------------------------------------------------
ubuntu@admin12:~$ cd Desktop
ubuntu@admin12:~/Desktop$ cd OOMP
ubuntu@admin12:~/Desktop/OOMP$ g++ asgn11.cpp
asgn11.cpp:401:1: error: unterminated comment
 /*
 ^
ubuntu@admin12:~/Desktop/OOMP$ g++ asgn11.cpp
ubuntu@admin12:~/Desktop/OOMP$ ./a.out

	 MENU
---------------------------
	 1.CREATE RECORD
	 2.SHOW RECORD
	 3.INSERT NEW
	 4.DELETE OLD
	 5.EDIT RECORD
	 6.SEARCH RECORD
	 CLOSE
 Enter choice1

 How many subject:3

 STUDENT INFO

ROLL:1

 NAME:Ram

 SUBJECT:oop

 SUBJECT CODE:1

 INTERNAL MARKS:43

 UNIVERSITY MARKS:95


 STUDENT INFO

ROLL:2

 NAME:Niki

 SUBJECT:cgg

 SUBJECT CODE:2

 INTERNAL MARKS:40

 UNIVERSITY MARKS:85


 STUDENT INFO

ROLL:3

 NAME:Radha

 SUBJECT:co

 SUBJECT CODE:3

 INTERNAL MARKS:41

 UNIVERSITY MARKS:94


	 MENU
---------------------------
	 1.CREATE RECORD
	 2.SHOW RECORD
	 3.INSERT NEW
	 4.DELETE OLD
	 5.EDIT RECORD
	 6.SEARCH RECORD
	 CLOSE
 Enter choice:2

	ROLL	NAME	SUB	SUBCODE	INTMARKS	UNVMARKS
	1	    Ram	    oop	  1	 		43		95
	2	    Niki	cgg	  2	        40		85
	3		Radha	co	  3			41		94
	 MENU
---------------------------
	 1.CREATE RECORD
	 2.SHOW RECORD
	 3.INSERT NEW
	 4.DELETE OLD
	 5.EDIT RECORD
	 6.SEARCH RECORD
	 CLOSE
 Enter choice:3

 INSERT NEW RECORD

 STUDENT INFO

ROLL:4

 NAME:komal

 SUBJECT:M3

 SUBJECT CODE:4

 INTERNAL MARKS:35

 UNIVERSITY MARKS:95


	 ROLL	NAME	SUB	SUBCODE	INTMARKS	UNVMARKS
	1		Ram		oop	1		43			95
	2		Niki	cgg	2		40			85
	3		Radha	co	3		41			94
	4		komal	M3	4		35			95
	 MENU
---------------------------
	 1.CREATE RECORD
	 2.SHOW RECORD
	 3.INSERT NEW
	 4.DELETE OLD
	 5.EDIT RECORD
	 6.SEARCH RECORD
	 CLOSE
 Enter choice:4

 Enter roll no to delete record:2

	 ROLL	NAME	SUB	SUBCODE	INTMARKS	UNVMARKS
	1	Ram			oop	1		43			95
	3	Radha		co	3		41			94
	4	komal		M3	4		35			95
	 MENU
---------------------------
	 1.CREATE RECORD
	 2.SHOW RECORD
	 3.INSERT NEW
	 4.DELETE OLD
	 5.EDIT RECORD
	 6.SEARCH RECORD
	 CLOSE
 Enter choice:5

Enter roll no to search and edit record:1

 RECORD FOUND


	1	Ram	oop	1	43	95

	 EDIT MENU
	
	 1.ROLL NO
	 2.NAME
	 3.SUBJE CT
	 4.INTERNAL MARKS
	 5.UNIV MARKS
	 6. EXIT

	 WHAT TO MODIFY:4

	 enter new internal marks:45


	 EDIT MENU
	
	 1.ROLL NO
	 2.NAME
	 3.SUBJE CT
	 4.INTERNAL MARKS
	 5.UNIV MARKS
	 6. EXIT

	 WHAT TO MODIFY:6

	 MENU
---------------------------
	 1.CREATE RECORD
	 2.SHOW RECORD
	 3.INSERT NEW
	 4.DELETE OLD
	 5.EDIT RECORD
	 6.SEARCH RECORD
	 CLOSE
 Enter choice6

 Enter roll no to search record:3

	 RECORD FOUND	
	3	Radha	co	3	41	94
	 MENU
---------------------------
	 1.CREATE RECORD
	 2.SHOW RECORD
	 3.INSERT NEW
	 4.DELETE OLD
	 5.EDIT RECORD
	 6.SEARCH RECORD
	 CLOSE
 Enter choice

*/




