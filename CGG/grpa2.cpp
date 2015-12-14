#include<iostream>
#include<graphics.h>
#include<cstdlib>
using namespace std;

class pixel
{
  private:
       int xc,yc,cl;
  public:

  pixel()
      {
        xc=yc=0;
        cl=15;
      }
void setcor(int x,int y)
     {
     xc=x;
     yc=y;
     }
void setcolor(int p)
     {
         cl=p;
     }
void draw()
     {
     putpixel(xc,yc,cl);
     }
};

int main()
      {
         
    int x1,y1,x2,y2,cl1,ch,ch1,xmax,ymax,xmid,ymid;
    char a;
    int gd=DETECT,gm=VGAMAX;
    initgraph(&gd,&gm,NULL);
    xmax=getmaxx();  ymax=getmaxy();
    xmid=xmax/2;  ymid=ymax/2;
   
    line(0,ymid,xmax,ymid);  //X-Axis
    line(xmid,0,xmid,ymax);  //Y-Axis
   
    pixel p1;
    do
    {
       //cleardevice();
           cout<<"\n1.PIXEL BY HARDCOADED VALUE";
       cout<<"\n2.ACCEPTING CO-ORDINATES";
       cout<<"\n3.Exit";
           cout<<"\nEnter your choice:- ";
        cin>>ch;
      switch(ch)
         {
           case 1:
                p1.setcor(xmid+50,ymid-50);
            p1.setcolor(15);
                p1.draw();
         break;
       case 2:
    {
        cout<<"Enter X And Y coordinate:- ";
        cin>>x1>>y1;
        cout<<"\nEnter Color For Pixel:- ";
        cin>>cl1;
        cout<<"\nEnter the quadrant Number(1/2/3/4) to draw the pixel:- ";
             cin>>ch1;
       
      if(ch1==1)
            {
         cout<<"\nFirst Quadrant is Selected !!!\n";
        x2=xmid+x1;
        y2=ymid-y1;
        p1.setcor(x2,y2);
        p1.setcolor(cl1);
        p1.draw();
            }
      else
        if(ch1==2)
        {
         cout<<"\nSecond Quadrant is Selected !!!\n";
        x2=xmid-x1;
        y2=ymid-y1;
        p1.setcor(x2,y2);
        p1.setcolor(cl1);
        p1.draw();
        }
         else
        if(ch1==3)
        {        
        cout<<"\nThird Quadrant is Selected !!!\n";
        x2=xmid-x1;
        y2=ymid+y1;
        p1.setcor(x2,y2);
        p1.setcolor(cl1);
        p1.draw();
        }   
    else
        if(ch1==4)
        {
         cout<<"\nFourth Quadrant is Selected !!!\n";
        x2=xmid+x1;
        y2=ymid+y1;
        p1.setcor(x2,y2);
        p1.setcolor(cl1);
            p1.draw();
        }
        break;
    }   
    case 3:
        exit(0);
       
      }
   
    cout<<"\nDO U Want To Continue y OR n:- ";
    cin>>a;
    }   

    while(a!='n');
    exit(0);
    getch();
    closegraph();
    return 0;
      }
