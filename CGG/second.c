#include<stdio.h>
#include<graphics.h>

int main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,NULL);
 rectangle(0,0,500,200);
 getch();
 closegraph();
 return 0;
}
