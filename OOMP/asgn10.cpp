
/*
Assignment No.:10
 
Problem Statement:

Implement C++/Java/Python program to create a base class called shape. Use this class to store two double type values that could be used to compute the area of figures. Derive two specific classes called function get_data() to initialize base class data members and another member function display_area() to compute and display the area of figures. Make classes to suit their requirements. Using these three classes, design a program that will accept dimension of a triangle or a rectangle interactively, and display the area.
Remember the two values given as input will be treated as lengths of two sides in the case of rectangles, and as base and height in the case of triangles, and used as follows:
Area of rectangle = x*y
Area of triangle =1/2*x*y
*/

#include<iostream>
using namespace std;

class shape
{
   protected:
      int width, height;
   public:
      shape( )
      {
         width = 0;
         height = 0;
      }

     virtual ~ shape( )
            {
               width = 0;
               height =0;
            }

     virtual  int area()
      {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};

class rectAngle: public shape
{
   public:

      void getdata()
      {
    	  cout<<"\n Enter length and breadth of rectangle";
    	     		   cin>>width;
    	     		   cin>>height;
      }
       int area ()
      {
         cout << "Rectangle class area :" <<endl;
         return (width * height);
      }
};


class triangle: public shape
{
   public:
	 void getdata()
	      {
		 	 cout<<"\n Enter height and base of triangle";
		 	 cin>>width;
		 	 cin>>height;
	      }
      int area ()
      {
         cout << "Triangle class area :" <<endl;
         return (width * height / 2);
      }
};



// Main function for the program
int main( )
{
	int op;
   shape *shape;
   rectAngle rec;
   triangle  tri;
   do{
   cout<<"\n You R having following options\n1:Rectangle\n2:Triangle\n3:Exit";
   cout<<"\n Enter Ur option::";
   cin>>op;
   switch(op)
   {
   	   case 1:
   		   rec.getdata();

      		   	   // store the address of Rectangle
   		   shape = &rec;
   		   	   // call rectangle area.

   		   cout<<" "<<shape->area();
   	   break;
   	   case 2:
   		   tri.getdata();
   		   // store the address of Triangle
   		   shape = &tri;
   		   // call triangle area.
   		   cout<<" "<<shape->area();
   	   break;
   }
   }while(op!=3);
   return 0;
}


/*output:
-----------------------------------------------------------------------------------------------------------------------------------------------------
ubuntu@admin12:~$ cd Desktop
ubuntu@admin12:~/Desktop$ cd OOMP
ubuntu@admin12:~/Desktop/OOMP$ g++ asgn10.cpp
ubuntu@admin12:~/Desktop/OOMP$ ./a.out

 You R having following options
1:Rectangle
2:Triangle
3:Exit
 Enter Ur option::1

 Enter length and breadth of rectangle5
5
Rectangle class area :
 25
 You R having following options
1:Rectangle
2:Triangle
3:Exit
 Enter Ur option::2

 Enter height and base of triangle7
2
Triangle class area :
 7
 You R having following options
1:Rectangle
2:Triangle
3:Exit
 Enter Ur option::3
ubuntu@admin12:~/Desktop/OOMP$ 
*/


