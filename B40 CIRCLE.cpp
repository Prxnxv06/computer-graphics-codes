#include<graphics.h>
#include<iostream>
#include<math.h>
#include<conio.h>
#include<stdlib.h>

void EightWaySymmetricPlot(int xc,int yc,int x,int y)
{
    putpixel(x+xc,y+yc,RED);
    putpixel(x+xc,-y+yc,YELLOW);
    putpixel(-x+xc,-y+yc,GREEN);
    putpixel(-x+xc,y+yc,YELLOW);
    putpixel(y+xc,x+yc,12);
    putpixel(y+xc,-x+yc,14);
    putpixel(-y+xc,-x+yc,15);
    putpixel(-y+xc,x+yc,6);
}

int drawCircle(int xi, int yi,int di,int del,int del1)
{
    int r;
    xi=0;
    yi=r;
    di=2*(1-r);
    int limit=0;

    while(yi>=limit)
    {
        putpixel(xi,yi,9);
        if (di<0)
        {
           del=2*di+2*yi-1;
           if (del<=0)
                mh(xi,yi,di);
           else
                md(xi,yi,di);
        }
        else if(di>0)
        {
            del1=2*di-2*xi-1;
            if (del1<=0)
                md(xi,yi,di);
            else
                mv(xi,yi,di);

        }
        else if(di=0)
        {
            md(xi,yi,di);
        }
    }

}
void mh(int xi,yi,di)
{
    xi=xi+1;
    di=di+2*xi+1;
}

void md(int xi,yi,di)
{
    xi=xi+1;
    yi=yi-1;
    di=di+2*xi-2*yi+2;
}

void mv(int xi,yi,di)
{
    yi=yi-1;
    di=di-2*yi+1;
}

int main()
{
    int gm,c;
    int gd=DETECT;
    initgraph(&gd,&gm,0);
    setcolor(9);
    int xi,yi,di,r;
    cout<<"enter values of radius:"<<endl;
    cin>>r;
    drawCircle(xi,yi,di);

    getch();
    closegraph();
    return 0;
}













