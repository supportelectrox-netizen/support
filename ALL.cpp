#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    if (steps == 0)
    {
        putpixel(x1, y1, WHITE);
        return;
    }

    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        putpixel(round(x), round(y), WHITE);

        x += xIncrement;
        y += yIncrement;
    }
}


void drawEllipse(int xc, int yc, int rx, int ry)
{
    float x = 0;
    float y = ry;

    float rx2 = rx * rx;
    float ry2 = ry * ry;

    float p1 = ry2 - (rx2 * ry) + (0.25 * rx2);

    float dx = 2 * ry2 * x;
    float dy = 2 * rx2 * y;


    while (dx < dy)
    {
        putpixel(xc + round(x), yc + round(y), WHITE);
        putpixel(xc - round(x), yc + round(y), WHITE);
        putpixel(xc + round(x), yc - round(y), WHITE);
        putpixel(xc - round(x), yc - round(y), WHITE);

        if (p1 < 0)
        {
            x++;
            dx = 2 * ry2 * x;
            p1 = p1 + dx + ry2;
        }
        else
        {
            x++;
            y--;

            dx = 2 * ry2 * x;
            dy = 2 * rx2 * y;
            p1 = p1 + dx - dy + ry2;
        }
    }

    float p2 = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;


    while (y >= 0)
    {
        putpixel(xc + round(x), yc + round(y), WHITE);
        putpixel(xc - round(x), yc + round(y), WHITE);
        putpixel(xc + round(x), yc - round(y), WHITE);
        putpixel(xc - round(x), yc - round(y), WHITE);

        if (p2 > 0)
        {
            y--;
            dy = 2 * rx2 * y;
            p2 = p2 + rx2 - dy;
        }
        else
        {
            y--;
            x++;

            dx = 2 * ry2 * x;
            dy = 2 * rx2 * y;

            p2 = p2 + dx - dy + rx2;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
        initgraph(&gd, &gm, "");

    int xc, yc;
    int rx1, ry1;
    int rx2, ry2;
    int topX, topY;
    int bottomX, bottomY;
    int leftX, leftY;
    int rightX, rightY;

    cout << "\nEnter center of ellipses (xc yc): ";
    cin >> xc >> yc;

    cout << "\nEnter First Ellipse Rx Ry: ";
    cin >> rx1 >> ry1;
    cout << "Enter Second Ellipse Rx Ry: ";
    cin >> rx2 >> ry2;
    
    cout << "\nEnter TOP point (x y): ";
    cin >> topX >> topY;
    cout << "Enter BOTTOM point (x y): ";
    cin >> bottomX >> bottomY;
    cout << "Enter LEFT point (x y): ";
    cin >> leftX >> leftY;
    cout << "Enter RIGHT point (x y): ";
    cin >> rightX >> rightY;

    drawLine(leftX, leftY, topX, topY);
    drawLine(topX, topY, rightX, rightY);
    drawLine(rightX, rightY, bottomX, bottomY);
    drawLine(bottomX, bottomY, leftX, leftY);

    drawLine(leftX, leftY, rightX, rightY);
    drawLine(topX, topY, bottomX, bottomY);

    drawEllipse(xc, yc, rx1, ry1);
    drawEllipse(xc, yc, rx2, ry2);


    getch();
    closegraph();
    return 0;
}
