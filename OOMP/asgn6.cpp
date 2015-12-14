#include<iostream>
#include<iomanip>
using namespace std;

template <class t>
class mat     //defining class mat
{
	int i,j;
	t m[10][10];
	public:
	void getdata(int,int);
	void putdata(int,int);
	void sub(mat&,mat&,int,int);
	void add(mat&,mat&,int,int);
	void mul(mat&,mat&,int,int);
	void trans(mat&,int,int);
};





//defining getdata function
template <class t>
void mat <t> :: getdata(int r,int c)
{
	//accepting data from user
	int i=0,j=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cout<<"\nEnter value a["<<i<<"] ["<<j<<"]";
			cin>>m[i][j];
		}
	}
}





//defining add function
template <class t>
void mat <t> :: add(mat<t> &a1,mat<t> &a2,int r,int c)
{
	int i=0,j=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			//adding two values
			m[i][j]=a1.m[i][j]+a2.m[i][j];
		}
	}
}




//defining subtract function
template <class t>
void mat <t> :: sub(mat<t> &a1,mat<t>&a2,int r,int c)
{
	int i=0,j=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			//adding two values
			m[i][j]=a1.m[i][j]-a2.m[i][j];
		}
	}
}





//defining multiplication function
template <class t>
void mat <t> :: mul(mat<t> &a1,mat<t> &a2,int r,int c)
{
	int i=0,j=0,k=0;//declaring local variables
	//initializing matrix all values to zero
	for(i=0;i<r;i++)
	for(j=0;j<c;j++)
	m[i][j]=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			for(k=0;k<r;k++)
			m[i][j]=m[i][j]+(a1.m[i][k]*a2.m[k][j]);
		}
	}
}





//defining transpose function
template <class t>
void mat <t> :: trans(mat<t> &a1,int r,int c)
{
	int i=0,j=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			//adding two values
			m[i][j]=a1.m[j][i];
		}
	}
}





//defining putdata function
template <class t>
void mat <t> :: putdata(int r,int c)
{
	int i=0,j=0;
	for(i=0;i<r;i++)
	{
		cout<<"\n";
		for(j=0;j<c;j++)
		{
			cout<<"\t";
			cout<<m[i][j];
		}
	}
}






int main()
{
	int ch,m,n,x,y ;  //declaring local variables
	mat<float> p,q,s;

	cout<<"\n Enter rows & columns of 1st matrix";
	cin>>m>>n;  //accepting rows and columns for 1st matrix;

	cout<<"\n Enter 1st  matrix\n";
	p.getdata(m,n); //calling getdata function

	cout<<"\n Enter rows and columns of 2nd matrix";
	cin>>x>>y ; //accepting rows and columns of second matrix;

	cout<<"\n Enter 2nd matrix\n";
	q.getdata(x,y);  //calling getdata function

		do
		{

		//displaying menu
		cout<<"\n Menu \n 1.addition \n 2.substraction \n 3.Multiplication \n 4.Transpose \n 5.Exit";
		cout<<"\n Enter Your Choice::";
		cin>>ch;  //accepting choice from user

		switch(ch)
		{
				case 1:
					if(m==x && n==y)  //if rows and cols are same
					{
						cout<<"\n addition is";
						s.add(p,q,m,n);
						s.putdata(m,n);
					}
					else
					{
						cout<<"\n addition is not possible";
					}
				break;
			case 2:
				 if(m==x && n==y)
				{
					cout<<"\n sunstraction is";
					s.sub(p,q,m,n);
					s.putdata(m,n);
				}
				else
				{
					cout<<"\n substraction is not possible";
				}
			break;
			case 3:
				if (n==x)  //if cols of first matrix is equal to rows of second matrix
			{
				cout<<"\n Multiplication is";
				s.mul(p,q,m,n);
				s.putdata(m,n);
			}
			else
			{
				cout<<"\n multiplication is not possible";
			}
		break;
			case 4:
				cout<<"\n Transpose is:\n";
				s.trans(p,m,n);
				s.putdata(m,n);
		break;
			case 5:
				cout<<"\n Exiting..\n";
		break;
		}//end of switch
	}while(ch!=5);//end of while
	return 0;
}//end of main




