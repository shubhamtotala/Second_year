//Write a c++ class to display a pixel on the screen
//-----------------------------------------------------

#include<graphics.h>
#include<iostream>
using namespace std;


class pixel
{
    int x;
    int y;
 public:
    void accept();
    void display();
};

void pixel::accept()
{
 cout<<"Enter the value of x:";
 cin>>x;
 cout<<"Enter the value of y:";
 cin>>y;
}

void pixel::display()
{
 putpixel(x,y,4);
}

int main()
{
 pixel p;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,NULL);
 p.accept();
 p.display();
 getch();
 closegraph();
 return 0;

}
