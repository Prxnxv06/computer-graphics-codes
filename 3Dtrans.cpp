#include<iostream>
#include<graphics.h>
#include<math.h>
#include<stdio.h>

using namespace std;

void translate(int midx,int midy){
    setcolor(YELLOW);
    int tx,ty,tz;
    printf("enter translation factors tx,ty,tz:");
    scanf("%d %d %d",&tx,&ty,&tz);
    bar3d(midx-50+tx,midy-50+ty,midx+50+tx,midy+50+ty,20+tz,1);

}

void scaling(int midx,int midy){
    setcolor(RED);
    float shx,shy,shz;
    printf("enter scaling factors shx,shy,shz:");
    scanf("%d %d %d",&shx,&shy,&shz);
    bar3d((midx-50)*shx,(midy-50)*shy,(midx+50)*shx,(midy+50)*shy,20*shz,1);

}

int main()
{
    int gm,c;
    int gd=DETECT;
    initgraph(&gd,&gm,0);
    cleardevice();


    int midx,midy;
    midx=getmaxx()/2;
    midy=getmaxy()/2;

    bar3d(midx-50,midy-50,midx+50,midy+50,20,1);
    printf("\n\t 3D transformation Scaling\n");
    scaling(midx,midy);

    printf("\n\t 3D transformation translation\n");
    translate(midx,midy);

    getch();
    closegraph();
    return 0;
}
