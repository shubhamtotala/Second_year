/*A book shop maintains the inventory of books that are being sold at the shop. The list includes details such as author, title, price, publisher and stock position. Whenever a
customer wants a book, the sales person inputs the title and author and the system searches the list and displays whether it is available or not. If it is not, an appropriate
message is displayed. If it is, then the system displays the book details and requests for the number of copies required. If the requested copies book details and requests
for the number of copies required. If the requested copies are available, the total cost of the requested copies is displayed; otherwise the message Required copies not in
stockù is displayed*/

#include<iostream>
#include<cstring>
using namespace std;

class book
{
      public:
      char title[100],author[100],publ[100];
      float price;
      int stock;

      void accept();
      void display();
      void search();
      void purchase();
      book()
      {
    	  strcpy(title,"EMPTY");
    	  strcpy(author,"EMPTY");
    	  strcpy(publ,"EMPTY");
    	  price=0;
    	  stock=0;

      }
};
void book::accept()
{
	cout<<"Enter the title of book:-";
	cin>>title;

	cout<<"Enter the author of book:-";
	cin>>author;

	cout<<"Enter the name of publisher:-";
	cin>>publ;

	cout<<"Enter the price of book:-";
	cin>>price;

	cout<<"Enter the stock of books:-";
	cin>>stock;
}

void book::display()
{
	cout<<"\n\t"<<title<<"\t"<<author<<"\t\t"<<publ<<"\t\t"<<price<<"\t\t"<<stock;
}

void book::search()
{
	char t1[10];
	cout<<"Enter book name which you have...";
	cin>>t1;
	 if(strcmp(t1,title)==0)
	 {
       cout<<"Book is available";
       cout<<"you purchase this book y/n";

	 }

}
int main()
{
	int ch,i,n;
	book b[5];

	cout<<"How many book record you have enter.....";
    cin>>n;
	do
	{


	cout<<"\nYOUR CHOICE IS AS FOLLOWS..";
	cout<<"\n1.Enter data..\n2.Display data..";
	cout<<"\nEnter your choice:";
	cin>>ch;

	switch(ch)
	{
	case 1:
		    for(i=0;i<n;i++)
		    {
		    	 b[i].accept();
		    }
    break;
	case 2:
		    for(i=0;i<n;i++)
		    {
		    	 b[i].display();
		    }
    break;
	}
}while(ch!=3);
return 0;
}

/*OUTPUT
How many book record you have enter.....2

YOUR CHOICE IS AS FOLLOWS..
1.Enter data..
2.Display data..
Enter your choice:1
Enter the title of book:-abc
Enter the author of book:-qwerty
Enter the name of publisher:-df
Enter the price of book:-100
Enter the stock of books:-10
Enter the title of book:-xyz
Enter the author of book:-abc
Enter the name of publisher:-ytrewq
Enter the price of book:-200
Enter the stock of books:-20

YOUR CHOICE IS AS FOLLOWS..
1.Enter data..
2.Display data..
Enter your choice:2

	abc	qwerty		df		100		10
	xyz	abc		ytrewq		200		20
YOUR CHOICE IS AS FOLLOWS..
1.Enter data..
2.Display data..
Enter your choice:3
*/
