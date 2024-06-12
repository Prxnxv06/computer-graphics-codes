#include<iostream>
#include<graphics.h>

using namespace std;

int LEFT=1,RIGHT=2,TOP=8,BOTTOM=4;
int xmin,xmax,ymin,ymax,x1,y1,x2,y2;

int getcode(int x,int y){

    int code=0;

    if(y>ymax) code|=TOP;
    if(y<ymin) code|=BOTTOM;
    if(x<xmin) code|=LEFT;
    if(x>xmax) code|=RIGHT;

    return code;
}

int main(){

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    cout<<"Enter the minimum and maximum coordinate of the window: ";
    cin>>xmin>>ymin>>xmax>>ymax;

    rectangle(xmin,ymin,xmax,ymax);

    cout<<"Enter the endpoints of line: ";
    cin>>x1>>y1>>x2>>y2;

    line(x1,y1,x2,y2);

    int outcode1=getcode(x1,y1);
    int outcode2=getcode(x2,y2);

    int accept=0;

    while(1){

        float m=(float)(y2-y1)/(x2-x1);

        if(outcode1==0 && outcode2==0){
             accept=1;
             cout<<"The line is completely inside the window so no need to clip"<<endl;
             break;

        }else if(( outcode1 & outcode2)!=0){
             accept=0;
             cout<<"The line is completely outside the window";
             break;
        }else{

             int x,y,temp;

             if(outcode1==0) temp=outcode2;
             else temp=outcode1;

             if(temp & TOP){

                y=ymax;
                x=x1+(ymax-y1)/m;

             }else if(temp & LEFT){

                 x=xmin;
                 y=y1+(xmin-x1)*m;

             }else if(temp & RIGHT){

                 x=xmax;
                 y=y1+(xmax-x1)*m;

             }else if(temp & BOTTOM){

                 y=ymin;
                 x=x1+(ymin-y)/m;

             }

             if (temp==outcode1){

                x1=x;
                y1=y;
                outcode1=getcode(x1,y1);
             }else{

                 x2=x;
                 y2=y;
                 outcode2=getcode(x2,y2);
             }

        }

    }

    cout<<"Line Clipping"<<endl;

    if(accept){

        cleardevice();
        rectangle(xmin,ymin,xmax,ymax);
        setcolor(YELLOW);
        line(x1,y1,x2,y2);
    }



    getch();
    closegraph();

    return 0;

}


