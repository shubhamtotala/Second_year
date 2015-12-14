#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,NULL);
 cout<<"hello";
 circle(100,100,50); 
 getch();
 closegraph();
 return 0;
}  
