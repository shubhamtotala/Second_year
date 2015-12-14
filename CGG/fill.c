

#include <graphics.h>

 
int main(void)
{
   int gd=DETECT,gm,points[]={320,150,440,340,230,340,320,150};
 
   initgraph(&gd, &gm, NULL);
   
   setfillstyle(4,4);
   bar(100,200,300,300);
 
   getch();
   closegraph();
   return 0;
}
