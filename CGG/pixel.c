//Write a c++ class to display a pixel on the screen
//-----------------------------------------------------

#include<stdio.h>
#include<graphics.h>




class pixel
{
 private: 
    int x;
    int y;
 public:
    void accept();
    void dispaly();
};

void pixel :: accept() 
{
 cout<<"Enter the value of x:";
 cin>>x;
 cout<<"Enter the value of y:";
 cin>>y;
}

void pixel :: display()
{
 putpixel(x,y,4);
}

void main()
{
 pixel P;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,NULL);
 P.accept();
 P.display();
 getch();
 closegraph();
}
