#include<iostream>
#include<cstring>
#include<iomanip>
#define SIZE 10

using namespace std;

class student
 {
      protected:
	  char name[20],subject[10];
	  int sub_code;
      public:
	  int rollno;
	  void getdata()
	   {
		   cout<<"\nEnter the name of student";
		   cin>>name;
		   cout<<"\nEnter the Roll no:";
		   cin>>rollno;
		   cout<<"\nEnter the subject name";
		   cin>>subject;
		   cout<<"\nEnter the subject code";
		   cin>>sub_code;
	   }



 };


 class internal_marks : virtual public student
 {
    protected:

	int intmark;
    public:
	void accept()
	{
		 cout<<"\n Enter internal assissement marks";
		 cin>>intmark;
	}
 };



 class uni_marks :virtual  public  student
 {
 protected:
	int unimark;
 public:
	void accept()
		{
			 cout<<"\n Enter Univercity marks";
			 cin>>unimark;
		}
};



class result : public internal_marks, public uni_marks
{
	char res[10];
 public:
	void accept_data();
	void display_data();
	int search_data(int);


};

void result::accept_data()
{
	student::getdata();
	internal_marks::accept();
	uni_marks::accept();
}

void result::display_data()
{
	if(intmark<10 || unimark<40)
		strcpy(res,"FAIL");
	else
		strcpy(res,"PASS");
	cout<<"\n"<<setw(7)<<rollno<<setw(15)<<name<<setw(15)<<subject<<setw(14)<<sub_code<<setw(14)<<intmark;
	cout<<setw(14)<<unimark<<setw(9)<<res;
}

int result::search_data(int rollno)
{


					if(this->rollno==rollno)
					{
						return 1;
					}


				return 0;
}

int main()
{
	int i,ch,nos,rn,flag=0;

	result r[SIZE];
	do{

		cout<<"\n U R Having following options:\n1.Create Table\n2. Display Table\n3.Search Student\n4.Update";
		cout<<"\n5.Delete Student\n6.Insert Record\n7.Exit \n Enter UR option:";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\n enter how many numbers of students marks u want to enter";
			cin>>nos;

			for(i=0;i<nos;i++)
			{

				r[i].accept_data();
			}

		break;
		case 2:
			cout<<"\n"<<setw(7)<<"ROLLNO"<<setw(15)<<"NAME"<<setw(15)<<"SUBJECT"<<setw(14)<<"SUBJECT_CODE"<<setw(14);
			cout<<"INTRENAL_MARK"<<setw(14)<<"UNIVERCITY_MARK"<<setw(9)<<"RESULT";

			for(i=0;i<nos;i++)
			{

				r[i].display_data();
			}

		break;

		case 3:

			cout<<"\n Enter Roll Number whose marks u want to Search ";
			cin>>rn;

			for(i=0;i<nos;i++)
			{
				flag=r[i].search_data(rn);
				if(flag==1)
				{
					cout<<"\n"<<setw(7)<<"ROLLNO"<<setw(15)<<"NAME"<<setw(15)<<"SUBJECT"<<setw(14)<<"SUBJECT_CODE"<<setw(14);
					cout<<"INTRENAL_MARK"<<setw(14)<<"UNIVERCITY_MARK"<<setw(9)<<"RESULT";
					r[i].display_data();
					break;
				}

			}

			if(flag==0)
			{
					cout<<"\n Record for Roll Number "<<rn<<" NOT Found";
			}
		break;

		case 4:
						cout<<"\n Enter Roll Number whose marks u want to Edit ";
						cin>>rn;

						for(i=0;i<nos;i++)
						{
							flag=r[i].search_data(rn);
							if(flag==1)
							{

								cout<<"\n Update Record:";
								r[i].accept_data();
								break;
							}

						}

						if(flag==0)
						{
								cout<<"\n Record for Roll Number "<<rn<<" NOT Found";
						}


		break;

		case 5:
									cout<<"\n Enter Roll Number whose marks u want to Delete ";
									cin>>rn;

									for(i=0;i<nos;i++)
									{
										flag=r[i].search_data(rn);
										if(flag==1)
										{
											int loc;
											loc=i;
											while(loc<nos)
											{
											r[loc]=r[loc+1];
											loc++;
											}
											nos--;
											break;
										}

									}

									if(flag==0)
									{
											cout<<"\n Record for Roll Number "<<rn<<" NOT Found";
									}



		break;

		case 6:
												result obj,temp;
												cout<<"\n Enter Record to Insert ";
												obj.accept_data();

												for(i=0;i<nos;i++)
												{
													if(r[i].rollno<obj.rollno)
														continue;
													else
													{
														flag=r[i].search_data(obj.rollno);

														if(flag==1)
														{
															cout<<"\n Record Allready Present";
															break;
														}


														int loc;
														loc=nos;

														if(nos < SIZE-1)//to check whether while inserting New record, object array size does not exceed its limit
														{
															while(loc>=i)
															{
																r[loc+1]=r[loc];
																loc--;
															}
															r[i]=obj;
															nos++;
														}
														else
														{
															cout<<"\n No Space to insert new record ";
														}

														break;
													}
												}










		break;

	}
	}while(ch!=7);

	return 0;
}


