#include <iostream>
#include <graphics.h>

using namespace std;

void boundaryFill8(int x, int y, int fill_color, int boundary_color) {
    int current = getpixel(x, y);
    if (current != fill_color && current != boundary_color) {


        putpixel(x, y, fill_color);
        boundaryFill8(x + 1, y, fill_color, boundary_color);
        boundaryFill8(x - 1, y, fill_color, boundary_color);
        boundaryFill8(x, y + 1, fill_color, boundary_color);
        boundaryFill8(x, y - 1, fill_color, boundary_color);
        boundaryFill8(x + 1, y + 1, fill_color, boundary_color); // for 8-connected
        boundaryFill8(x - 1, y + 1, fill_color, boundary_color); // for 8-connected
        boundaryFill8(x + 1, y - 1, fill_color, boundary_color); // for 8-connected
        boundaryFill8(x - 1, y - 1, fill_color, boundary_color); // for 8-connected
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1,y1,x2,y2;
    cout<<"Enter the coordinates ";
    cin>>x1>>y1>>x2>>y2;

    rectangle(x1,y1,x2,y2);


    boundaryFill8((x1+x2)/2, (y1+y2)/2, GREEN,WHITE);

    getch();
    closegraph();
    return 0;
}
