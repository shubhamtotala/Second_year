#include<iostream>
#include<graphics.h>
using namespace std;

class dline
{
protected: int x1,y1,x2,y2;
public:
dline()
{
x1=0,y1=0,x2=0,y2=0;
}
void step1()
{
cout<<"\n Enter x1: ";cin>>x1;
cout<<"\n Enter y1: ";cin>>y1;
}
void step2()
{
cout<<"\n Enter x2: ";cin>>x2;
cout<<"\n Enter y2: ";cin>>y2;
}
void drawl()
{
float x,y,dx,dy,len;
int i;
dx=abs(x2-x1);
dy=abs(y2-y1);
if(dx >= dy)
{

len=dx;
}
else
{
len=dy;
}

dx=(x2-x1)/len;
dy=(y2-y1)/len;

x = x1 + 0.5;
y = y1 + 0.5;

i=1;

while(i<=len)
{
putpixel(x,y,15);
x = x + dx;
y = y + dy;
i = i + 1;
}

putpixel(x,y,15);

}
};

class rect: public dline //Rectangle
{
private: int w,l;
public:
void setrect()
{
dline::step1();
cout<<"\n Enter width: ";cin>>w;
cout<<"\n Enter length: ";cin>>l;
}
void drawrect()
{
x2=x1;
y2=y1+w;
dline::drawl(); //left

x2=x1+l;
y2=y1;
dline::drawl(); //top

x1=x1;
y1=y1+w;
x2=x1+l;
y2=y1;
dline::drawl(); //bottom

x1=x1+l;
y1=y1-w;
x2=x1;
y2=y1+w;
dline::drawl(); //right
}
};

class square: public dline //Square
{
private: int l;
public:
void setsquare()
{
dline::step1();
cout<<"\n Enter length: ";cin>>l;
}
void drawsquare()
{
x2=x1;
y2=y1+l;
dline::drawl(); //left

x2=x1+l;
y2=y1;
dline::drawl(); //top

x1=x1;
y1=y1+l;
x2=x1+l;
y2=y1;
dline::drawl(); //bottom

x1=x1+l;
y1=y1-l;
x2=x1;
y2=y1+l;
dline::drawl(); //right
}
};
class triangle: public dline //Triangle
{
private: int x3,y3;
public:
void settri()
{
dline::step1();
dline::step2();
cout<<"\n Enter x3: ";cin>>x3;
cout<<"\n Enter y3: ";cin>>y3;
}
void drawtri()
{
int tempx,tempy;
dline::drawl();

tempx=x2;
x2=y2;
x2=x3;
y2=y3;
dline::drawl();

x1=tempx;
y1=tempy;
dline::drawl();
}
};

int main()
{
int gd=DETECT,gm=VGAMAX;
int i, x, y, r,ch, xmax,ymax,xmid,ymid;
char a;
initgraph(&gd,&gm,NULL);
rect r1;
square s;
triangle t;
do
{
cout<<"\nChoose polygon to draw";
cout<<"\n1.Rectangle..";
cout<<"\n2.Square..";
cout<<"\n3.Triangle..";
cout<<"\n4.EXIT..";
cout<<"\nEnter your choice: ";
cin>>ch;
switch(ch)
{
case 1:
{
r1.setrect();
r1.drawrect();
break;
}
case 2:
{
s.setsquare();
s.drawsquare();
break;
}

case 3:
{
t.settri();
t.drawtri();
delay(3000);
break;
}
case 4:
exit;
break;
}
cout<<"\nDO U Want To Continue y OR n: ";
cin>>a;
}while(a!='n');
delay(50);
getch();
closegraph();
return 0;
}
