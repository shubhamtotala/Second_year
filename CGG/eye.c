
#include<stdio.h>
#include<graphics.h>


 
main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, NULL);
 
   setviewport(100,100,200,200);
   circle(100,100,50);
   getch();
   closegraph();
   return 0;
}
