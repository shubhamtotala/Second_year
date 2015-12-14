//Aim: Booth's Algorithm

#include<iostream>
#include<graphics.h>
using namespace std;

int addbinary(int a1[], int a2[], int result[])
{
    int i, c = 0;
    for(i = 3; i >=0 ; i--)
    {
result[i] = ((a1[i] ^ a2[i]) ^ c); //a xor b xor c
c = ((a1[i] & a2[i]) | (a1[i] &c)) | (a2[i] & c); //ab+bc+ca
    }
     return c;
}

void bininv(int a[],int b[])
{
for(int i=0;i<4;i++)
{
b[i]=!a[i];
}


}

void main()
{
int a[4]={0,0,0,0},q[5]={0,0,0,0,0},b[4]={0,0,0,0},bc[4]={0,0,0,0};
int res[4],twoc[4]={0,0,0,1};
clrscr();
cout<<"\nEnter the multiplicand:";
for(int i=0;i<4;i++)
{
b[i]=getche();
b[i]-=48;
}

cout<<"\nEnter the multiplier:";
for(i=0;i<4;i++)
{
q[i]=getche();
q[i]-=48;
}
//2's Complement of b;
bininv(b,bc);
addbinary(bc,twoc,res);
for(i=0;i<4;i++)
{
bc[i]=res[i];
}


int cnt=4;
while(cnt!=0)
{ if(q[3]>q[4])
{
addbinary(a,bc,res) ;
for(i=3;i>=0;i--)
{
a[i]=res[i];
}
}
else if(q[3]<q[4])
{
addbinary(a,b,res) ;
for(i=3;i>=0;i--)
{
a[i]=res[i];
}

}
for(i=4;i>=1;i--)
{
q[i]=q[i-1];
}
q[0]=a[3];
for(i=3;i>=1;i--)
{
a[i]=a[i-1];
}
a[0]=a[1];
cnt--;

}

cout<<"\nMultiplication is:";
for(i=0;i<4;i++)
cout<<a[i]<<" ";
for(i=0;i<4;i++)
{
cout<<q[i]<<" ";
}
getch();
}

/*OUTPUT.......................................................................................

Enter the multiplicand:0101
Enter the multiplier:0100
Multiplication is:00010100
*/

