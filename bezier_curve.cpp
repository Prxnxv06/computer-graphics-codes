#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

void bezier(int x[4],int y[4]){

    for(double t=0.0;t<=1.0;t+=0.0005){

        double xt=pow((1-t),3)*x[0]+ 3*t*pow((1-t),2)*x[1]+ 3*t*t*(1-t)*x[2] + pow(t,3)*x[3];
        double yt=pow((1-t),3)*y[0]+ 3*t*pow((1-t),2)*y[1]+ 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];

        delay(2);
        putpixel(xt,yt,YELLOW);


    }

    for(int i=0;i<4;i++){

        delay(2);
        putpixel(x[i],y[i],RED);
    }
}

int main(){

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    int x[4],y[4];
    cout<<"Enter the x and y coordinate of 4 control points: ";

    for(int i=0;i<4;i++){
        cin>>x[i]>>y[i];
    }

    bezier(x,y);

    getch();
    closegraph();

    return 0;

}
