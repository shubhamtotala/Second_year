#include<iostream>
#include<cstring>

using namespace std;

class strings
{
  char str[20];
  int len;

  public:

  strings()
  {
	  len=0;
  }

  void read()
  {
    cout<<"\n Enter the string : ";
    //cin.get(str,20);
    cin>>str;
  }

  int  operator ~()//string length
  {
      int i;
      len=0;
      for(i=0;str[i]!='\0';i++)
      {
	      len++;
      }
      return(len);
  }

  void operator +(strings s2);
  void operator ||(strings s2);
  void operator !(void);
  void operator ==(strings s);
  void operator =(strings);



  friend ostream &operator <<(ostream &out,strings &s);

  friend void operator >>(istream &in,strings &s);

};


void strings::operator !(void) //string pallindrome
  {
    int f=0;
    ~*this;//len=~s1 i.e. len=s1.operator~();(s1 is current object )
    for(int i=0;i<len;i++)
    {
      if(str[i]==str[len-i-1])
	      f=1;
      else
       {
    	  f=0;
    	  break;
       }
    }
    if(f==1)
      cout<<"\nIt is a pallindrome!";
    else
    	cout<<"\n Not Pallindrome";
  }


void strings::operator ||(strings s2)
  {
    int i,j=0,f=0,count=0;
    cout<<"\nPositions of occurence: ";

    for(i=0;str[i]!='\0';i++)
    {
       if(str[i]==s2.str[j])
       {
    	   j++;
       }
       else
       {
    	   j=0;
       }
       if(s2.str[j]=='\0')
       {
    	   f=1;
    	   count++;
    	   cout<<"  "<<(i-j+2);
    	   j=0;
       }
    }

    cout<<"\nNo of occurence of substring: "<<count;
  }

void operator >>(istream &in,strings &s)
  {
    int i;
    ~s;
    cout<<"\nReverse string: ";
    for(i=s.len-1;i>=0;i--)
    {
      cout<<s.str[i];
    }
  }





  void strings::operator ==(strings s2)
   {
     int i,f=0;
     for(i=0;str[i]!='\0';i++)
     {
        if(str[i]==s2.str[i])
        {
        	f=1;
        }
       else
       {
 	     f=0;
 	     break;
       }
     }
     if(f==1)
      cout<<"\nStings are equal!";
     else
      cout<<"\nStrings are not equal";
   }



  void strings::operator +(strings s2)
  {
    ~*this;//len=~s1 i.e. len=s1.operator~();(s1 is current object )
    int j=len;
    for(int i=0;s2.str[i]!='\0';i++)
    {
       str[j]=s2.str[i];
       j++;
    }
    str[j]='\0';
    cout.write(str,20);
  }



 void strings::operator =(strings s2)
  {
	  int i;
     //s1.read();
       for(i=0;str[i]!='\0';i++)
       s2.str[i]=str[i];
       s2.str[i]='\0';
    cout<<"\nCopy : ";
    cout.write(s2.str,20);
  }

 ostream & operator <<(ostream &out,strings &s)
  {
     out<<s.str;
     return(out);
  }



int main()
{
int c,l;
 char m;
 strings s1,s2;
 do
 {
 cout<<"\nMENU:\n1.Length of the string\n2.Copy\n3.Reverse\n4.Concatination\n5.Compare two strings\n6.Find Substring\n7.Pallindrome\n8.Show\nChoice= ";
 cin>>c;
 switch(c)
 {
  case 1:
	  s1.read();
	  l=~s1;
	  cout<<"\nLength of the string is: "<<l;
	  break;
  case 2:
	  s1.read();
	  s1=s2;
	 //s1.operator=(s2);
	  break;
  case 3: s1.read();
	  cin>>s1;
	  //operator>>(cin,s1);
	  break;
  case 4:
	  s1.read();
	  s2.read();
	  //s1+s2;
	  s1.operator+(s2);
	  break;
  case 5: s1.read();
	  s2.read();
	  s1==s2;
	  break;
  case 6:
	  s1.read();
	  s2.read();
	  s1||s2;
	  break;
  case 7:
	  s1.read();
	  //!s1;
	  s1.operator!();
	  break;
  case 8:
	  s1.read();
	  cout<<s1;
	  break;
  default:cout<<"Invalid";
	  break;
  }
  cout<<"\nDo you want to continue?-y/n: ";
  cin>>m;
  }while(m=='y');
 return 0;
}
