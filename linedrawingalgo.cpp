Line Drawing Algorithm
#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
int maxx,maxy,ox,oy;
int main()
{
int gd=DETECT,gm;
initgraph (&gd,&gm,"c:\\tc\\bgi");
setbkcolor(GREEN);
maxx = getmaxx();
maxy = getmaxy();
ox=maxx/2;
oy=maxy/2;
line(0,maxy/2,maxx,maxy/2);
line(maxx/2,0,maxx/2,maxy);
int x1,x2,y1,y2;
cout<<"Bresenham's line drawing algorithm"<<endl;
cout<<"Enter x1 y1 x2 y2"<<endl;
cin>>x1>>y1>>x2>>y2;
int x=x1;
int y=y1;
int dx=abs(x2-x1);
int dy=abs(y2-y1);
int s1= (x2-x1)<0 ? -1:1;
int s2= (y2-y1)<0 ? -1:1;
int interchange = dy>dx ? 1:0;
int e=2*dy-dx;
for(int i=1;i<=dx;i++)
{
putpixel(x+ox,oy-y,WHITE);
while(e>0)
{
if(interchange==1)x+=s1;
else y+=s2;
e-=2*dx;
}
if(interchange==1)y+=s2;
else x+=s1;
e=e+2*dy;
}
getch();
return 0;
}
