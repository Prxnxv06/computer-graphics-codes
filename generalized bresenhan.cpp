#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

int main(){

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    int midx=getmaxx()/2;
    int midy=getmaxy()/2;

    line(0,midy,getmaxx(),midy);
    line(midx,0,midx,getmaxy());

    int x1,y1,x2,y2,x,y,deltax,deltay,signx,signy,temp,interchange,e;

    cout<<"Enter the endpoints of the line: ";
    cin>>x1>>y1>>x2>>y2;

    x1=midx+x1;
    y1=midy-y1;
    x2=midx+x2;
    y2=midy-y2;

    x=x1;
    y=y1;

    deltax=abs(x2-x1);
    deltay=abs(y2-y1);

    if((x2-x1)<0) signx=-1;
    else signx=1;

    if((y2-y2)<0) signy=-1;
    else signy=1;

    if(deltay>deltax){

        temp=deltay;
        deltay=deltax;
        deltax=temp;
        interchange=1;
    }else interchange=0;

    e=2*deltay-deltax;

    for(int i=1;i<deltax;i++){

        putpixel(x,y,WHITE);

        while(e>0){

            if(interchange){

                x=x+signx;
            }else{
                y=y+signy;
            }

            e=e-2*deltax;

        }

        if(interchange){
            y=y+signy;
        }else{
            x=x+signx;
        }

        e=e+2*deltay;
    }
    getch();
    closegraph();

    return 0;
}
