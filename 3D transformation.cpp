#include<iostream>
#include<graphics.h>
#include<cmath>

using namespace std;

const double PI = 3.14159265;

int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int midx = getmaxx() / 2;
    int midy = getmaxy() / 2;

    line(midx, 0, midx, getmaxy());
    line(0, midy, getmaxx(), midy);

    int left, top, right, bottom, nleft, ntop, nright, nbottom;
    int new_left, new_right, new_top, new_bottom;
    int tx, ty, sx, sy, sz, choice, tocontinue = 1;
    double r;

    cout << "Enter the 3D object left, top, right, bottom points: ";
    cin >> left >> top >> right >> bottom;

    bar3d(midx + left, midy - top, midx + right, midy - bottom, 20, 5);

    while (tocontinue) {

        cout << "Menu\n" << "1> Translation \n" << "2> Scaling\n" << "3> Rotation\n" << "4> Reflection\n" << "5> Shearing" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
            {
                cout << "Translation" << endl;
                cout << "Enter the value of tx and ty: ";
                cin >> tx >> ty;
                setcolor(RED);
                nleft = left + tx;
                ntop = top + ty;
                nright = right + tx;
                nbottom = bottom + ty;
                bar3d(midx + nleft, midy - ntop, midx + nright, midy - nbottom, 20, 5);
                break;
            }

            case 2:
            {
                cout << "Scaling" << endl;
                cout << "Enter the scaling factor sx sy sz: ";
                cin >> sx >> sy >> sz;
                setcolor(GREEN);
                nleft = left * sx;
                ntop = top * sy;
                nright = right * sx;
                nbottom = bottom * sy;
                bar3d(midx + nleft, midy - ntop, midx + nright, midy - nbottom, 20 * sz, 5);
                break;
            }

            case 3:
            {
                cout << "Rotation" << endl;
                cout << "Enter the angle of rotation (in degrees): ";
                cin >> r;
                setcolor(BLUE);

                double rad = r * PI / 180.0;

                int cx = (left + right) / 2;
                int cy = (top + bottom) / 2;

                new_left = cx + (left - cx) * cos(rad) - (top - cy) * sin(rad);
                new_top = cy + (left - cx) * sin(rad) + (top - cy) * cos(rad);
                new_right = cx + (right - cx) * cos(rad) - (bottom - cy) * sin(rad);
                new_bottom = cy + (right - cx) * sin(rad) + (bottom - cy) * cos(rad);

                bar3d(midx + new_left, midy - new_top, midx + new_right, midy - new_bottom, 20, 5);
                break;
            }

            case 4:
            {
                cout << "Reflection" << endl;
                cout << "Enter reflection axis 1> x-axis 2> y-axis" << endl;
                int axis;
                cin >> axis;

                setcolor(CYAN);
                if (axis == 1) {
                    new_left = left;
                    new_top = -top;
                    new_right = right;
                    new_bottom = -bottom;
                } else {
                    new_left = -left;
                    new_top = top;
                    new_right = -right;
                    new_bottom = bottom;
                }
                bar3d(midx + new_left, midy - new_top, midx + new_right, midy - new_bottom, 20, 5);
                break;
            }

            case 5:
            {
                cout << "Shearing" << endl;
                cout << "Enter shearing about 1> x-axis 2> y-axis" << endl;
                int direction;
                cin >> direction;

                setcolor(MAGENTA);
                if (direction == 1) {
                    cout << "Enter the x-axis shearing factor: ";
                    int shx;
                    cin >> shx;

                    new_left = left + top * shx;
                    new_top = top;
                    new_right = right + bottom * shx;
                    new_bottom = bottom;
                } else {
                    cout << "Enter the y-axis shearing factor: ";
                    int shy;
                    cin >> shy;

                    new_left = left;
                    new_top = top + left * shy;
                    new_right = right;
                    new_bottom = bottom + right * shy;
                }
                bar3d(midx + new_left, midy - new_top, midx + new_right, midy - new_bottom, 20, 5);
                break;
            }

            default:
            {
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
