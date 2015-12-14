#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

const float PI=3.14;

void LineWithDDA(int x0,int y0,int x1,int y1)
{
glPointSize(2.0);
glBegin(GL_POINTS);
glColor3f(0.0,0.0,0.0);

int dx,dy,steps,i;
float x,y;
float xinc,yinc;

dy=y1-y0;
dx=x1-x0;
y=y0;
x=x0;
if(abs(dx)>=abs(dy))
{
steps=dx;
}
else
{
steps=dy;
}
xinc=(float)dx/steps;
yinc=(float)dy/steps;
glVertex2d(x,y);
for(i=1;i<steps;i++)
{
x+=xinc;
y+=yinc;
x0=floor(x);
y0=floor(y);
glVertex2d(x,y);
}
glEnd();
}

void init(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0,800,0,600,0,600);
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
LineWithDDA(0,0,800,600);
LineWithDDA(0,600,800,0);
LineWithDDA(0,300,800,300);
LineWithDDA(400,0,400,600);
LineWithDDA(0,150,800,450);
LineWithDDA(0,450,800,150);
LineWithDDA(200,0,600,600);
LineWithDDA(600,0,200,600);
glutSwapBuffers();
}

int main(int argc, char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(800,600);
glutInitWindowPosition(100,100);
glutCreateWindow("DDA Line Drawing!");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}



