#include <graphics.h>

void edgeFill8(int x, int y, int fill_color,int boundary_color)
{
	if(getpixel(x, y) != boundary_color &&
	getpixel(x, y) != fill_color)
	{
		putpixel(x, y, fill_color);
		delay(20);
		edgeFill8(x + 1, y, fill_color, boundary_color);
		edgeFill8(x, y + 1, fill_color, boundary_color);
		edgeFill8(x - 1, y, fill_color, boundary_color);
		edgeFill8(x, y - 1, fill_color, boundary_color);
        edgeFill8(x - 1, y - 1, fill_color, boundary_color);
		edgeFill8(x - 1, y + 1, fill_color, boundary_color);
		edgeFill8(x + 1, y - 1, fill_color, boundary_color);
		edgeFill8(x + 1, y + 1, fill_color, boundary_color);
}
}

int main()
{

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");

	rectangle(100,100,50,50);
	edgeFill8(55, 55, 10, 15);

	delay(1000);

	getch();
	closegraph();

	return 0;
}
