#include <graphics.h>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    int x, y;

    cout << "Enter top-left corner (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter bottom-right corner (x2 y2): ";
    cin >> x2 >> y2;

    // draw top and bottom edges
    for (x = x1; x <= x2; x++)
    {
        putpixel(x, y1, WHITE); // TOP EDGE
        putpixel(x, y2, WHITE); // BOTTOM EDGE
    }

    // draw left and right edges
    for (y = y1; y <= y2; y++)
    {
        putpixel(x1, y, WHITE); // LEFT EDGE
        putpixel(x2, y, WHITE);
    }

    // fill the rectangle
    for (y = y1 + 1; y < y2; y++)
    {
        for (x = x1 + 1; x < x2; x++)
        {
            putpixel(x, y, GREEN);
        }
    }

    getch();
    closegraph();
    return 0;
}
