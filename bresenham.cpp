#include <graphics.h>
#include <iostream>
# include <cmath>

using namespace std;

void drawLine(int x1, int y1, int x2, int y2, int color)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    int steps;

    if (abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        putpixel((int)(x + 0.5), (int)(y + 0.5), color);
        x += xInc;
        y += yInc;
    }
}

void boundaryFill(int x, int y, int bColor, int fColor)
{
    int cColor = getpixel(x, y);

    if (cColor != fColor && cColor != bColor)
    {
        putpixel(x, y, fColor);
        boundaryFill(x + 1, y, bColor, fColor);
        boundaryFill(x - 1, y, bColor, fColor);
        boundaryFill(x, y + 1, bColor, fColor);
        boundaryFill(x, y - 1, bColor, fColor);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    int seedX, seedY;

    cout << "Enter Top Left Corner (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter Bottom Right Corner (x2 y2): ";
    cin >> x2 >> y2;
    cout << "Enter Seed Point Inside Rectangle (x y): ";
    cin >> seedX >> seedY;

    int boundaryColor = WHITE;
    int fillColor = RED;

    // draw rectangle using dda
    drawLine(x1, y1, x2, y1, boundaryColor);
    drawLine(x2, y1, x2, y2, boundaryColor);
    drawLine(x2, y2, x1, y2, boundaryColor);
    drawLine(x1, y2, x1, y1, boundaryColor);

    // boundary fill
    boundaryFill(seedX, seedY, boundaryColor, fillColor);

    getch();
    closegraph();
    return 0;
}
