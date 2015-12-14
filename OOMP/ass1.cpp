/*Program Name:Create a class named weather report that holds a daily weather report with data members day_of_month ,hightemp ,lowtemp ,amount_rain and amount_snow. The constructor initializes the fields with default values: 99 for day_of_month, 999 for hightemp,-999 for low emp and 0 for amount_rain and amount_snow. Include a function that prompts the user and sets values for each field so that you can override the default values. Write a C++/Java/Python program that creates a monthly report.*/

#include<cstring>
#include<iostream>
using namespace std;

class Weather_Report
{
	public:
	int low_temp,high_temp,amt_rain,amt_snow;
	char day_of_month[11];
	Weather_Report()
	{
	day_of_month[11]=99;
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
        float avg_ht=0,avg_lt=0,avg_rain=0,avg_snow=0;
        float ah,al,as,ar;
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
                {
		    w[i].Display_Report();
		                       avg_ht=avg_ht+w[i].high_temp;
		                       avg_lt=avg_lt+w[i].low_temp;
		                       avg_rain=avg_rain+w[i].amt_rain;
		                       avg_snow=avg_snow+w[i].amt_snow;
		                    }

		                       ah=avg_ht/n;
		                       al=avg_lt/n;
		                       ar=avg_rain/n;
		                       as=avg_snow/n;
		                       cout<<"\nAverage"<<"\t\t"<<ah<<"\t\t"<<al<<"\t\t"<<ar<<"\t\t"<<as;


        break;

	case 3:
    break;
}

	}while(ch!=3);
return 0;
}

/*OUTPUT
***MENU***

1:Enter the data.
2:Display data
3:Exit.

Enter the choice:-1
Enter the no of days:-2
Enter the day of month:-10
Enter high temp:-20
Enter low temp:-10
Enter the amount of rain:-20
Enter the amount of snow:-1
Enter the day of month:-3
Enter high temp:-20
Enter low temp:-3
Enter the amount of rain:-0
Enter the amount of snow:-20


***MENU***

1:Enter the data.
2:Display data
3:Exit.

Enter the choice:-2

*******************Weather Report*********************

	for  2  days.

 day_of_month	 high_temp	low_temp	amt_rain	amt_snow
	10	20		10		20		1
	3	20		3		0		20
Average		20		6.5		10		10.5

***MENU***

1:Enter the data.
2:Display data
3:Exit.

Enter the choice:-3
*/





