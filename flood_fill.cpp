#include<iostream>
#include<graphics.h>

using namespace std;

void floodfill(int x,int y,int fill_color,int default_color){

   if(getpixel(x,y)== default_color){


      putpixel(x,y,fill_color);

      floodfill(x+1,y,fill_color,default_color);
      floodfill(x-1,y,fill_color,default_color);
      floodfill(x,y+1,fill_color,default_color);
      floodfill(x,y-1,fill_color,default_color);

   }

}

int main(){

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    rectangle(120,120,220,220);
    floodfill(150,160,10,0);

    getch();
    closegraph();

    return 0;

}
