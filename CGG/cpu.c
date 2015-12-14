#include<stdio.h>
#include<graphics.h>
//using namespace std;
int main()
{
int x,y;
int gd=DETECT,gm=VGAMAX;
initgraph(&gd,&gm,NULL);
setcolor(LIGHTRED);
rectangle(2,15,610,450);
outtextxy(200,430,"Fig 1.1 :  CPU Architecture");
//internal memory

setcolor(RED);
sector(297,35,0,360,100,15);//colour of internal memory

ellipse (297,35,0,360,100,15);
outtextxy(240,30,"Internal Memory");
line(300,50,300,75);
line(295,70,300,75); //internal memory arrow
line(305,70,300,75); //internal memory arrow

//external memory

setcolor(GREEN);
sector(297,385,0,360,100,15);//colour of external memory

ellipse(297,385,0,360,100,15);
outtextxy(240,380,"External Memory");
line(300,370,300,350);
line(300,370,295,365); //external memory arrow
line(300,370,305,365); //external memory arrow


//input devices

setcolor(CYAN);
sector(65,220,0,360,50,50);//colour of input devices

circle(65,220,50);
outtextxy(20,215,"Input Devices");
line(115,225,150,225);
//mouse

setcolor(BLUE);
sector(65,300,0,360,50,15);//colour of mouse

ellipse(65,300,0,360,50,15);
outtextxy(46,295,"Mouse");
line(65,270,65,285);
line(70,277,65,270);//mouse arrow
line(60,277,65,270);//mouse arrow
//keyboard

setcolor(BLUE);
sector(65,142,0,360,50,15);//colour of keyboard

ellipse(65,142,0,360,50,15);
outtextxy(35,138,"Keyboard");
line(65,158,65,170);
line(70,163,65,170);//keyboard arrow
line(60,163,65,170);//keyboard arrow




//output devices

setcolor(CYAN);
sector(540,220,0,360,55,55);//colour of output devices

circle(540,220,55);
outtextxy(490,215,"Output Devices");
line(450,225,484,225);
//display

setcolor(LIGHTBLUE);
sector(540,310,0,360,50,15);//colour of display

ellipse(540,310,0,360,50,15);
outtextxy(515,305,"Display");
line(540,275,540,295);
line(535,280,540,275);//display arrow
line(545,280,540,275);//display arrow
//printer

setcolor(LIGHTBLUE);
sector(540,130,0,360,50,15);//colour of printer


ellipse(540,130,0,360,50,15);
outtextxy(515,125,"Printer");
line(540,145,540,165);
line(535,160,540,165);//printer arrow
line(545,160,540,165);//printer arrow



//arrow
line(145,220,150,225); //input arrow
line(145,230,150,225);

line(475,220,484,225); //output arrow
line(475,230,484,225);


//cpu
rectangle(150,75,450,350);
outtextxy(220,100,"Central Processing Unit");
//cu
rectangle(180,150,280,200);
outtextxy(190,160,"Control Unit");
//alu
rectangle(300,150,430,200);
outtextxy(310,160,"Arithematic & ");
outtextxy(310,175,"Logic Unit ");
//memory
rectangle(180,220,430,300);
outtextxy(275,225,"M e m o r y ");
line(180,250,430,250);
line(300,250,300,300);
outtextxy(210,270,"Registers ");
outtextxy(350,270,"Cache ");


delay(10000);
closegraph();
return 0;
}



