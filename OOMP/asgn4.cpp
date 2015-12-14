#include<iostream>
using namespace std;

class complex
{
int real,img;
public:
void getdata();
void showdata();
 complex operator +(complex);
 friend complex operator -(complex ,complex);
 complex operator *(complex);
 friend complex operator /(complex ,complex);
};


void complex::getdata()
{
cout<<"\n Enter Real and Imaginary parts";
cin>>real>>img;

}


void complex::showdata()
{
cout<<"\n"<<real<<"+i"<<img;

}


complex complex::operator +(complex c2)
{

	complex c;
	c.real=real+c2.real;
	c.img=img+c2.img;
    return(c);

}

complex complex::operator *(complex c2)
{

	complex c;
	c.real=real*c2.real;
	c.img=img*c2.img;
    return(c);

}


complex operator -(complex c1,complex c2)
{

	complex c3;
	c3.real=c1.real-c2.real;
	c3.img=c1.img-c2.img;
    return(c3);

}
complex operator /(complex c1,complex c2)
{

	complex c3;
	
    float den;
    den=c2.real*c2.real-c2.img*c2.img;
    c2.img=c2.img*(-1);
    c3.real=c1.real*c2.real-c1.img*c2.img;
    c3.img=c1.real*c2.img+c1.img*c2.real;
    c3.real=c3.real/den;
    c3.img=c3.img/den;
    return c3;

}

int main()

{
	int op;
	complex c1,c2,c3;
	cout<<"\n Enter First Complex Number";
	c1.getdata();
	cout<<"\n Enter Second Complex Number";
	c2.getdata();

	do{
	cout<<"\n you are having following options\n 1.ADD \n 2.SuB \n 3.MUL \n 4.Div";
	cout<<"\n Enter your choice \n ";
	cin>>op;

	switch(op)
	{
	case 1:
		c3=c1+c2;
		//c3=c1.operator +(c2);
		c1.showdata();
		c2.showdata();

		cout<<"\n ADDITION IS= ";
		c3.showdata();
		break;
	case 2:
			c3=c1-c2;
			//c3=operator -(c1,c2);
			c1.showdata();
			c2.showdata();

			cout<<"\n SUBTRACTION IS= ";
			c3.showdata();
			break;


	case 3:
			c3=c1*c2;
			//c3=c1.operator *(c2);
			c1.showdata();
			c2.showdata();

			cout<<"\n MULTIPLICATION IS= ";
			c3.showdata();
			break;
		case 4:
				c3=c1/c2;
				//c3=operator /(c1,c2);
				c1.showdata();
				c2.showdata();

				cout<<"\n DIVision IS= ";
				c3.showdata();
				break;

	}

	}while(op!=5);
	return (0);
}
