#include<stdio.h>
#include<graphics.h>

int main()

{
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
putpixel(200,300,WHITE);
getch();
closegraph();
return 0;
}
