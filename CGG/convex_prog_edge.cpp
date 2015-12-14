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

class poly: public dline //poly
{
private: int a[10][2],p;
public:
void setpts(int i)
{
int j;
for(j=0;j<i;j++)
{
cout<<"\n Enter x-coordinate: "<<j<<":";cin>>a[j][0];
cout<<"\n Enter y-coordinate: "<<j<<":";cin>>a[j][1];
}
}
void drawpoly(int i)
{
int j;
x1=a[0][0];
y1=a[0][1];
x2=a[1][0];
y2=a[1][1];
dline::drawl();
for(j=0;j<i-1;j++)
{
x1=a[j][0];
y1=a[j][1];
x2=a[j+1][0];
y2=a[j+1][1];
dline::drawl();
}

x1=a[j][0];
y1=a[j][1];
x2=a[0][0];
y2=a[0][1];
dline::drawl();
}
};

int main()
{
int n ,gd=DETECT,gm=VGAMAX;
initgraph(&gd,&gm,NULL);
poly shape;
cout<<"\nEnter number of sides: "; cin>>n;
shape.setpts(n);
shape.drawpoly(n);
delay(50);
getch();
closegraph();
return 0;
}


/* output:
 Enter x-coordinate: 0:100

 Enter y-coordinate: 0:100

 Enter x-coordinate: 1:100

 Enter y-coordinate: 1:200

 Enter x-coordinate: 2:200

 Enter y-coordinate: 2:200
*/

