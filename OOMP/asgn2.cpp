#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
class book
{
	char author[20],title[20],publisher[20];

public:
	float price;
		int stock;
	book(char auth[20],char tit[20],char publ[20],float pr,int stk)
{
		strcpy(this->author,auth);
		strcpy(this->title,tit);
		strcpy(this->publisher,publ);
		this->price=pr;
		this->stock=stk;
}
	void display();
	int search(char author[20],char title[20]);
};
void book::display()
{
	cout<<"\n Book name is         : "<<setw(5)<<title;
	cout<<"\n Author of book is    : "<<setw(5)<<author;
	cout<<"\n Publisher of book is : "<<setw(5)<<publisher;
	cout<<"\n Price of book is     : "<<setw(5)<<price;
	cout<<"\n Book Stock is        : "<<setw(5)<<stock;

}
int book::search(char author[20],char title[20])
{
	if(strcmp(this->author,author)==0 && strcmp(this->title,title)==0)
		return 1;
	return 0;
}
int main()
{
	book *b[10];
	char author[20],title[20],publisher[20],count,amt;
		float price;
		int stock,ch,i,no;
		do
		{
			cout<<"\n\n-------Book Store Program-----";
			cout<<"\n\n You have following options ";
			cout<<"\n 1. Entry\n 2. display \n 3. Order \n 4. Exit";
			cout<<"\n\n\n Enter your choice : ";
			cin>>ch;
			switch(ch)
			{
			case 1:
				cout<<"\n how many entries you want to make....? ";
				cin>>no;
				for(i=0;i<no;i++)
				{
					cout<<"Enter Book title : ";
					cin>>title;
					cout<<"Enter Author title : ";
					cin>>author;
					cout<<"Enter Publisher : ";
					cin>>publisher;
					cout<<"Enter Book price : ";
					cin>>price;
					cout<<"Enter Book Stock : ";
					cin>>stock;
					b[i]=new book(author,title,publisher,price,stock);
				}
				break;
			case 2:
				for(i=0;i<no;i++)
				{
					cout<<"----------------------------------------";
					b[i]->display();
					cout<<"\n----------------------------------------";
				}
				break;
			case 3:
				int ans,flag=0,count,amt;
				char cho;
				cout<<"Enter Book title : ";
				cin>>title;
				cout<<"Enter author name : ";
				cin>>author;
				for(i=0;i<no;i++)
				{
							ans=b[i]->search(author,title);
							if(ans==1)
							{
							b[i]->display();
							flag=1;
							cout<<"\n\n How many copies you want to buy...? : ";
							cin>>count;

							if(count==0)
							{
								cout<<"\n SORRY....Book out of stock.....";
							}

							if(count>(b[i]->stock))
							{
								cout<<"\n\n Only" <<b[i]->stock<<"  copies are remaining, do you want to buy?[y/n]";
								cin>>cho;
								if(cho=='y'||cho=='Y')
								{
									amt=(b[i]->stock)*(b[i]->price);
									cout<<"\n\n You have to pay "<<amt<<"Rupees :";
									(b[i]->stock)=0;
								}
								else
								{
									cout<<"\n Thank You For Visit...";
								}
							}
							else
							{
							amt=count*(b[i]->price);
							(b[i]->stock)=(b[i]->stock)-count;
							cout<<"\n\n You have to pay "<<amt<< "Rupees :";
							}
							break;
							}
				}
				if(flag==0)
				{
				cout<<"\n Sorry , Book not available...";
				}
				break;
			}
			}while (ch!=4);
			return 0;
}




