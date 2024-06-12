#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
int maxx,maxy,ox,oy;
void Rotation(int c1,int ansMat[4][2],int initMat[4][2]){
int c3;
int n=c1+1;
cout<<"1.Anticlockwise \n 2.clockwise"<<endl;
cin>>c3;
float Ang;
cout<<"enter the angle"<<endl;
cin>>Ang;
Ang= Ang*(3.14/180);
if(c3==2) Ang =-(Ang);
for(int i=0;i<n;i++)
{
ansMat[i][0]= cos(Ang) * initMat[i][0] - sin(Ang) * initMat[i][1];
ansMat[i][1]= sin(Ang) * initMat[i][0] + cos(Ang) * initMat[i][1];
}
for(int i=0;i<n;i++)
{
if(i==n-1) line(ox+ansMat[i][0],oy-ansMat[i][1],ox+ansMat[0][0],oy-ansMat[0][1]);
else line(ox+ansMat[i][0],oy-ansMat[i][1],ox+ansMat[i+1][0],oy-ansMat[i+1][1]);
}
}
void Scaling(int c1,int ansMat[4][2],int initMat[4][2]){
int xf,yf;
int n=c1+1;
cout<<"Enter scaling factors"<<endl;
cin>>xf>>yf;
for(int i=0;i<n;i++)
{
ansMat[i][0]= xf * initMat[i][0];
ansMat[i][1]= yf * initMat[i][1];
}
for(int i=0;i<n;i++)
{
if(i==n-1) line(ox+ansMat[i][0],oy-ansMat[i][1],ox+ansMat[0][0],oy-ansMat[0][1]);
else line(ox+ansMat[i][0],oy-ansMat[i][1],ox+ansMat[i+1][0],oy-ansMat[i+1][1]);
}
}
void Reflection(int c1,int ansMat[4][2],int initMat[4][2]){
int c3;
int n=c1+1;
cout<<"reflection along which axis do you want? \n 1.x-axis \n 2.y-axis \n 3.x=y \n 4.x= -y"<<endl;
cin>>c3;
switch(c3)
{
case 1:
for(int i=0;i<n;i++)
{
ansMat[i][1]= (-1) * initMat[i][1];
ansMat[i][0]= initMat[i][1];
}
break;
case 2:
for(int i=0;i<n;i++)
{
ansMat[i][0]= (-1) *initMat[i][0];
ansMat[i][1]= initMat[i][1];
}
break;
case 3:
for(int i=0;i<n;i++)
{
ansMat[i][0]= initMat[i][1];
ansMat[i][1]= initMat[i][0];
}
break;
case 4:
for(int i=0;i<n;i++)
{
ansMat[i][0]= (-1) *initMat[i][1];
ansMat[i][1]= (-1) *initMat[i][0];
}
break;
default:
cout<<"not valid choice";
break;
}
for(int i=0;i<n;i++)
{
if(i==n-1) line(ox+ansMat[i][0],oy-ansMat[i][1],ox+ansMat[0][0],oy-ansMat[0][1]);
else line(ox+ansMat[i][0],oy-ansMat[i][1],ox+ansMat[i+1][0],oy-ansMat[i+1][1]);
}
}
void drawTriangle(int mat[4][2]){
int n=3;
cout<<"enter co ordinates of three points";
for(int i=0;i<n;i++)
{
for(int j=0;j<2;j++)
{
cin>>mat[i][j];
}
}
for(int i=0;i<n;i++)
{
if(i==n-1) line(ox+mat[i][0],oy-mat[i][1],ox+mat[0][0],oy-mat[0][1]);
else line(ox+mat[i][0],oy-mat[i][1],ox+mat[i+1][0],oy-mat[i+1][1]);
}
}
void drawRectangle(int mat[4][2]){
int n=4;
cout<<"enter co ordinates of four points";
for(int i=0;i<n;i++)
{
for(int j=0;j<2;j++)
{
cin>>mat[i][j];
}
}
for(int i=0;i<n;i++)
{
if(i==n-1) line(ox+mat[i][0],oy-mat[i][1],ox+mat[0][0],oy-mat[0][1]);
else line(ox+mat[i][0],oy-mat[i][1],ox+mat[i+1][0],oy-mat[i+1][1]);
}
}
void drawLine(int mat[4][2]){
cout<<"enter co ordinates of two points";
for(int i=0;i<2;i++)
{
for(int j=0;j<2;j++)
{
cin>>mat[i][j];
}
}
int n=2;
for(int i=0;i<n;i++)
{
if(i==n-1) line(ox+mat[i][0],oy-mat[i][1],ox+mat[0][0],oy-mat[0][1]);
else line(ox+mat[i][0],oy-mat[i][1],ox+mat[i+1][0],oy-mat[i+1][1]);
}
}
int main()
{
int gd=DETECT,gm;
initgraph (&gd,&gm,"c:\\tc\\bgi");
setbkcolor(GREEN);
int initMat[4][2];
int ansMat[4][2];
maxx = getmaxx();
maxy = getmaxy();
ox=maxx/2;
oy=maxy/2;
line(0,maxy/2,maxx,maxy/2);
line(maxx/2,0,maxx/2,maxy);
int c1;
cout<<"Slect the object from the below \n 1.Line \n 2.tringle \n 3.rectangle"<<endl;
cin>>c1;
switch(c1)
{
case 1:
drawLine(initMat);
break;
case 2:
drawTriangle(initMat);
break;
case 3:
drawRectangle(initMat);
break;
default:
cout<<"not valid choice";
break;
}
int c2;
cout<<"Slect the transformation from the below \n 1.Rotation \n 2.Scaling \n 3.Reflection"<<endl;
cin>>c2;
switch(c2)
{
case 1:
Rotation(c1, ansMat, initMat);
break;
case 2:
Scaling(c1, ansMat, initMat);
break;
case 3:
Reflection(c1, ansMat, initMat);
break;
default:
cout<<"not valid choice";
break;
}
getch();
return 0;
}
