/*
 * asgn3.cpp
 *
 *  Created on: 04-Feb-2014
 *      Author: ubuntu
 */
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class db
{
	char nm[20],dob[11],bg[4];
  	float wt,ht;
 	int ins;
  	long no;

  	public:
  	static int stdno;    //static member variable
  	static void count();//static member function


  	db()//DEFAULT CONSTRUCTOR
  	{
	 	    strcpy(nm,"Name");
    		strcpy(dob,"DOB");
    		strcpy(bg,"BG");
    		wt=ins=ht=no=0;
    		++stdno;//use of Static variable
  	}

  	db (db *ob)//COPY CONSTRUCTOR
  	{
    		strcpy(nm,ob->nm);
    		strcpy(dob,ob->dob);
    		strcpy(bg,ob->bg);
    		wt=ob->wt;
    		ht=ob->ht;
    		ins=ob->ins;
    		no=ob->no;
    		++stdno;
  	}
  	void fin();
  	void getdata();
  	void show();
  	friend void display(db d);//Friend function

  	~db()//DESTRUCTOR
  	{
    		cout<<"\n\n"<<this->nm<<"(Object) is destroyed!";
  	}
};

inline void db:: fin()//INLINE FUNCTION
	{
		cout<<"\nInline Function!";
	}

void db::getdata()
  	{
    		cout<<"\n\nEnter: name, dob, blood grp, weight, height, insurance policy no,contact no-\n";
    		cin>>nm>>dob>>bg>>wt>>ht>>ins>>no;
  	}

 void db::count()
{
    		cout<<"\n No. of objects created: "<<stdno;
 }


void display(db d)
{
	cout<<"\n"<<setw(10)<<d.nm<<setw(15)<<d.dob<<setw(8)<<d.bg<<setw(5)<<d.wt<<setw(5)<<d.ht<<setw(10)<<d.ins<<setw(15)<<d.no;
}


void db::show()
{
	cout<<"\n"<<setw(10)<<nm<<setw(15)<<dob<<setw(8)<<bg<<setw(5)<<wt<<setw(5)<<ht<<setw(10)<<ins<<setw(15)<<no;
}

int db::stdno;

int main()
{

   	int n,i;
   	db d1,*ptr[5];
   	//cout<<"\n U R having following options\n1. Default Constructor\n2. Friend Function\n3. Copy Constructor";
   	//cout<<"\n4. \n";


   	cout<<"\nDefault values:";
   	//display(d1);
   	d1.show();

   	d1.getdata();
   	//display(d1);
   	d1.show();
   	d1.fin();



   	db d2(&d1);
   	//db d2=d1;



   	cout<<"\n\nUse of copy constructor :\n";
   	display(d2);
   	//d2.show();



   	cout<<"\nHow many objects u want to create?:";
   	cin>>n;
   	for(i=0;i<n;i++)
   	{
   		ptr[i]=new db();
    		ptr[i]->getdata();
   	}


   	cout<<"\n"<<setw(10)<<"Name"<<setw(15)<<"Date of Birth"<<setw(8);
	cout<<"Blood grp"<<setw(5)<<"Weight"<<setw(5)<<"Height"<<setw(10)<<"Ins	no"<<setw(15)<<"Contact no.";

   for(i=0;i<n;i++)
   {
    //display(*ptr[i]);
       ptr[i]->show();
   }


   db::count();//calling Static member function

   for(i=0;i<n;i++)
   {
     delete(ptr[i]);
   }

   //cout<<"\nObjects deleted!" ;

return 0;
}




