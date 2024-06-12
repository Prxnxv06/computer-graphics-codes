#include<iostream>
#include<graphics.h>
#include<dos.h>

using namespace std;


void drawcircle(int xc,int yc,int x,int y){

    putpixel(xc+x,yc+y,YELLOW);
    putpixel(xc-x,yc+y,YELLOW);
    putpixel(xc+x,yc-y,YELLOW);
    putpixel(xc-x,yc-y,YELLOW);
    putpixel(xc+y,yc+x,YELLOW);
    putpixel(xc-y,yc+x,YELLOW);
    putpixel(xc+y,yc-x,YELLOW);
    putpixel(xc-y,yc-x,YELLOW);

}


int main(){

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    int midx=getmaxx()/2;
    int midy=getmaxy()/2;

    line(0,midy,getmaxx(),midy);
    line(midx,0,midx,getmaxy());

    int xc,yc,x,y,r,d;

    cout<<"Enter the coordiates of center of circle:";
    cin>>xc>>yc;

    xc=midx+xc;
    yc=midy-yc;

    cout<<"Enter the radius:";
    cin>>r;

    x=0;
    y=r;
    d=3-2*r;

    drawcircle(xc,yc,x,y);

    while(x<=y){

        delay(100);

        if(d<0){
            x++;
            d=d+4*x+5;
        }else{
            x++;
            y--;
            d=d+4*(x-y)+10;
        }

        drawcircle(xc,yc,x,y);
    }

    getch();
    closegraph();

    return 0;
}
