/*
Assignment No.:8
PROGRAM NAME:Write a C++/Java program for the following:
Create a class named Television that has data members to hold the model number and
the screen size in inches, and the price. Member functions include overloaded
insertion and extraction operators. If more than four digits are entered for the model,
if the screen size is smaller than 12 or greater than 70 inches, or if the price is
negative or over $5000 then throw an exception. Write a main() function that
instantiates a television object, allows user to enter data and displays the data
members .If an exception is caught ,replace all the data member values with zero values.
*/

#include<iostream>
#include<cstring>
using namespace std;
class television
{
	int price,e;
	float size;
	char model[20];

	public:
	friend istream &operator >>(istream &din,television &t)
	{
		cout<<"\n\n Enter model number of TV::";
		cin>>t.model;
		cout<<"\n\n Enter size of TV(Inches)::";
		cin>>t.size;
		cout<<"\n\n Enter Price of TV::";
		cin>>t.price;
		return(din);
	}


	friend ostream &operator <<(ostream &dout,television &t)
	{
		try
		{
			if(strlen(t.model)>4)
			throw(1);
			if(t.size<12 && t.size<=70)
			throw(2);
			if(t.price>5000)
			throw(3);
			else
			{
				cout<<"\n Model number of TV::"<<t.model;
				cout<<"\nSize of TV"<<t.size;
				cout<<"\n Price of TV"<<t.price;
			}
		}
			catch(int e)
			{
				switch(e)
				{
					case 1:
						cout<<"\n Exception Caught";
						cout<<"\n Model no should be less than 4 digits long!!!";
					break;
					case 2:
						cout<<"\n Exception Caught";
						cout<<"\nSize should be greater than 12 & less than 70 inches!!!";
					break;
					case 3:
						cout<<"\n Exception Caught";
						cout<<"\n Price should be less than or equal to Rs5000!!!";
					break;
				}
			}
			return(dout);

	}
};



int main()
{
	int ch;
	television t1;
	cout<<"\n\t============Exception Handling===============\n";
	do
	{
		cout<<"\n\n\t 1.Insert data\n\t2. Display Data \n\t 3.Exit\n";
		cout<<"Enter your choice";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cin>>t1;
			break;

			case 2:
				cout<<t1;
			break;
			case 3:
			break;
		default:
			cout<<"Enter correct choice";
		}
	}while(ch!=3);

}

/*
output:
-------------------------------------------------------
ubuntu@admin12:~/Desktop/OOMP$ g++ asgn8.cpp
ubuntu@admin12:~/Desktop/OOMP$ ./a.out

	============Exception Handling===============


	 1.Insert data
	 2. Display Data 
	 3.Exit
Enter your choice1


 Enter model number of TV::E250


 Enter size of TV(Inches)::32


 Enter Price of TV::4000


	 1.Insert data
	 2. Display Data 
	 3.Exit
Enter your choice2

 Model number of TV::E250
 Size of TV32
 Price of TV4000

	 1.Insert data
	 2. Display Data 
	 3.Exit
Enter your choice3
ubuntu@admin12:~/Desktop/OOMP
--------------------------------------------------------*/

