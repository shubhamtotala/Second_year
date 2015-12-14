#include<graphics.h>
//#include<iostream.h>
//using namespace std;
int main() {
   int gdriver = DETECT, gmode=VGAMAX;
   int x1 = 200, y1 = 200;
   int x2 = 300, y2 = 300;

   initgraph(&gdriver, &gmode,NULL);
rectangle(20,20,600,450);
rectangle(220,30,420,120);//processor
outtextxy(280,40,"PROCESSOR");

rectangle(230,60,410,120);
outtextxy(260,90,"CPU");
rectangle(320,60,410,120);
outtextxy(350,90,"ALU");

rectangle(220,180,420,250);//memory
outtextxy(290,210,"MEMORY");

rectangle(50,180,180,250);//i/p devices
outtextxy(70,210,"I/O DEVICES");

rectangle(65,270,210,320);    //keyboard
rectangle(70,275,75,280);

rectangle(80,275,85,280);
rectangle(90,275,95,280);
rectangle(100,275,105,280);
rectangle(110,275,115,280);
rectangle(120,275,125,280);
rectangle(130,275,135,280);
rectangle(140,275,145,280);
rectangle(150,275,155,280);
rectangle(160,275,165,280);
rectangle(170,275,175,280);
rectangle(180,275,185,280);

rectangle(70,285,75,290);
rectangle(80,285,85,290);
rectangle(90,285,95,290);
rectangle(100,285,105,290);
rectangle(110,285,115,290);
rectangle(120,285,125,290);
rectangle(130,285,135,290);
rectangle(140,285,145,290);
rectangle(150,285,155,290);
rectangle(160,285,165,290);
rectangle(170,285,175,290);
rectangle(180,285,185,290);


rectangle(70,295,75,300);
rectangle(80,295,85,300);
rectangle(90,295,95,300);
rectangle(100,295,105,300);
rectangle(110,295,115,300);
rectangle(120,295,125,300);
rectangle(130,295,135,300);
rectangle(140,295,145,300);
rectangle(150,295,155,300);
rectangle(160,295,165,300);
rectangle(170,295,175,300);
rectangle(180,295,185,300);


rectangle(70,305,75,310);
rectangle(80,305,85,310);
rectangle(90,305,95,310);

rectangle(100,305,135,310);  //space bar

rectangle(140,305,145,310);
rectangle(150,305,155,310);
rectangle(160,305,165,310);
rectangle(170,305,175,310);
rectangle(180,305,185,310);

ellipse(40,300,0,360,10,20);   //mouse
arc(68,280,180,110,33);
arc(177,280,271,360,34);

rectangle(450,180,580,250); //o/p devices
outtextxy(480,210,"O/P DEVICES");

rectangle(430,280,590,370); //monitor
rectangle(440,290,580,360);

outtextxy(495,360,"DELL");
line(470,370,490,380);
line(490,380,470,390);

line(555,370,535,380);
line(535,380,555,390);

line(490,380,535,380);
line(470,390,555,390);

line(510,250,510,280);


rectangle(220,320,420,390); //st devices
outtextxy(260,340,"STORAGE DEVICES");

line(320,120,320,180);      //direction lines
line(320,250,320,320);
line(180,210,220,210);
line(420,210,450,210);


line(320,120,310,130);
line(320,120,330,130);
line(320,180,310,170);
line(320,180,330,170);


line(220,210,210,200);
line(220,210,210,220);

line(320,250,310,260);
line(320,250,330,260);
line(320,320,310,310);
line(320,320,330,310);


line(450,210,440,200);
line(450,210,440,220);

line(510,280,500,270);
line(510,280,520,270);


delay(10000);
   closegraph();
getch();
return 0;
}


