#include<iostream>
using namespace std;

class Weather_Report
{
	public:
	int low_temp,high_temp,amt_rain,amt_snow;
	char day_of_month[11];
	Weather_Report()
	{
	day_of_month[11]={99};
	high_temp=999;
	low_temp=999;
	amt_rain=0;
	amt_snow=0;
	}

	void Enter_Data();
	void Display_Report();

};

void Weather_Report::Enter_Data()
{
	cout<<"Enter the day of month:-";
	cin>>day_of_month;

	cout<<"Enter high temp:-";
	cin>>high_temp;

	cout<<"Enter low temp:-";
	cin>>low_temp;

	cout<<"Enter the amount of rain:-";
	cin>>amt_rain;

	cout<<"Enter the amount of snow:-";
	cin>>amt_snow;
}

void Weather_Report::Display_Report()
{
	cout<<"\n\t"<<day_of_month<<"\t"<<high_temp<<"\t\t"<<low_temp<<"\t\t"<<amt_rain<<"\t\t"<<amt_snow;
}

int main()
{
	Weather_Report w[30];
	int n,i,ch;

	do
	{
		cout<<"\n\n***MENU***\n";
		cout<<"\n1:Enter the data.\n2:Display data\n3:Exit.\n";
		cout<<"\nEnter the choice:-";
		cin>>ch;

	switch(ch)
	{

	case 1:
		cout<<"Enter the no of days:-";
		cin>>n;
		for(i=0;i<n;i++)
			w[i].Enter_Data();
	break;

	case 2:
		cout<<"\n*******************Weather Report*********************\n";
		cout<<"\n\tfor" "  "<<n<<"  ""days.\n";
		cout<<"\n day_of_month\t high_temp\tlow_temp\tamt_rain\tamt_snow";
		for(i=0;i<n;i++)
			w[i].Display_Report();
	break;

	case 3:
	break;
	}

	}while(ch!=3);
return 0;
}


