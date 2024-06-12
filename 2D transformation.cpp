#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

int main(){
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "");

    int midx = getmaxx() / 2;
    int midy = getmaxy() / 2;

    line(midx, 0, midx, getmaxy());
    line(0, midy, getmaxx(), midy);

    int x1, x2, x3, y1, y2, y3, nx1, nx2, nx3, ny1, ny2, ny3;
    int tx, ty, sx, sy, mx, my, r, choice, tocontinue = 1;

    cout << "Enter the coordinate of triangle" << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    line(midx + x1, midy - y1, midx + x2, midy - y2);
    line(midx + x2, midy - y2, midx + x3, midy - y3);
    line(midx + x3, midy - y3, midx + x1, midy - y1);

    while (tocontinue) {
        cout << "Menu\n" << "1> Translation \n" << "2> Scaling\n" << "3> Rotation\n" << "4> Reflection\n" << "5> Shearing" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Translation" << endl;
                cout << "Enter the value of tx and ty: ";
                cin >> tx >> ty;
                setcolor(YELLOW);

                nx1 = x1 + tx;
                ny1 = y1 + ty;
                nx2 = x2 + tx;
                ny2 = y2 + ty;
                nx3 = x3 + tx;
                ny3 = y3 + ty;

                line(midx + nx1, midy - ny1, midx + nx2, midy - ny2);
                line(midx + nx2, midy - ny2, midx + nx3, midy - ny3);
                line(midx + nx3, midy - ny3, midx + nx1, midy - ny1);

                break;
            }

            case 2: {
                cout << "Scaling" << endl;
                cout << "Enter the scaling factor: ";
                cin >> sx >> sy;

                setcolor(RED);

                mx = (x1 + x2 + x3) / 3;
                my = (y1 + y2 + y3) / 3;

                nx1 = mx + (x1 - mx) * sx;
                nx2 = mx + (x2 - mx) * sx;
                nx3 = mx + (x3 - mx) * sx;
                ny1 = my + (y1 - my) * sy;
                ny2 = my + (y2 - my) * sy;
                ny3 = my + (y3 - my) * sy;

                line(midx + nx1, midy - ny1, midx + nx2, midy - ny2);
                line(midx + nx2, midy - ny2, midx + nx3, midy - ny3);
                line(midx + nx3, midy - ny3, midx + nx1, midy - ny1);

                break;
            }

            case 3: {
                cout << "Rotation" << endl;
                cout << "Enter the angle of rotation" << endl;
                cin >> r;
                setcolor(BLUE);

                r = (r * 3.14) / 180;

                nx1 = abs(x1 * cos(r) - y1 * sin(r));
                ny1 = abs(x1 * sin(r) + y1 * cos(r));
                nx2 = abs(x2 * cos(r) - y2 * sin(r));
                ny2 = abs(x2 * sin(r) + y2 * cos(r));
                nx3 = abs(x3 * cos(r) - y3 * sin(r));
                ny3 = abs(x3 * sin(r) + y3 * cos(r));

                line(midx + nx1, midy - ny1, midx + nx2, midy - ny2);
                line(midx + nx2, midy - ny2, midx + nx3, midy - ny3);
                line(midx + nx3, midy - ny3, midx + nx1, midy - ny1);

                break;
            }

            case 4: {
                cout << "Reflection" << endl;
                cout << "Reflect about x-axis (1) or y-axis (2): ";
                int axis;
                cin >> axis;
                setcolor(GREEN);

                if (axis == 1) {
                    ny1 = -y1; ny2 = -y2; ny3 = -y3;
                    nx1 = x1; nx2 = x2; nx3 = x3;
                } else {
                    nx1 = -x1; nx2 = -x2; nx3 = -x3;
                    ny1 = y1; ny2 = y2; ny3 = y3;
                }

                line(midx + nx1, midy - ny1, midx + nx2, midy - ny2);
                line(midx + nx2, midy - ny2, midx + nx3, midy - ny3);
                line(midx + nx3, midy - ny3, midx + nx1, midy - ny1);

                break;
            }

            case 5: {
                cout << "Shearing" << endl;
                cout << "Shear in x direction (1) or y direction (2): ";
                int direction;
                float sh;
                cin >> direction;
                setcolor(CYAN);

                if (direction == 1) {
                    cout << "Enter the shear factor in x direction: ";
                    cin >> sh;

                    nx1 = x1 + sh * y1; nx2 = x2 + sh * y2; nx3 = x3 + sh * y3;
                    ny1 = y1; ny2 = y2; ny3 = y3;
                } else {
                    cout << "Enter the shear factor in y direction: ";
                    cin >> sh;

                    nx1 = x1; nx2 = x2; nx3 = x3;
                    ny1 = y1 + sh * x1; ny2 = y2 + sh * x2; ny3 = y3 + sh * x3;
                }

                line(midx + nx1, midy - ny1, midx + nx2, midy - ny2);
                line(midx + nx2, midy - ny2, midx + nx3, midy - ny3);
                line(midx + nx3, midy - ny3, midx + nx1, midy - ny1);

                break;
            }

            default: {
                cout << "Invalid input!! Try Again!" << endl;
            }
        }

        cout << "Do you want to continue(0/1): ";
        cin >> tocontinue;
    }

    getch();
    closegraph();

    return 0;
}
