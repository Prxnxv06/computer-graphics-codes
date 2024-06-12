#include<graphics.h>
#include<math.h>
#include<stdio.h>
int main()
{
int x[4],y[4],i;
float t,px,py;
int gm;
int gd=DETECT;
initgraph(&gd,&gm,0);
printf("\n Bezier Curve \n ");

   for(i=0;i<4;i++)
   {
       printf("Enter the x and y coordinate\n ");
       scanf("%d%d",&x[i],&y[i]);
       putpixel(x[i],y[i],7);
   }

for(t=0.0;t<=1.0;t=t+0.001)
{
px = pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*(1-t)*x[2] + pow(t,3)*x[3];
py =  pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
putpixel(px,py,YELLOW);
delay(10);
}
getch();
closegraph();
}
