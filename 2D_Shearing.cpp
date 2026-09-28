#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

void drawLine(int x1, int y1, int x2, int y2, int color)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        putpixel(round(x), round(y), color);
        x += xInc;
        y += yInc;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2, x3, y3;
    float shx, shy;

    cout << "Enter coordinates of Triangle:\n";

    cout << "Vertex 1 (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Vertex 2 (x2 y2): ";
    cin >> x2 >> y2;

    cout << "Vertex 3 (x3 y3): ";
    cin >> x3 >> y3;

    cout << "Enter Shearing Factors (shx shy): ";
    cin >> shx >> shy;

    drawLine(x1, y1, x2, y2, WHITE);
    drawLine(x2, y2, x3, y3, WHITE);
    drawLine(x3, y3, x1, y1, WHITE);

    int nx1 = round(x1 + shx * y1);
    int ny1 = round(y1 + shy * x1);

    int nx2 = round(x2 + shx * y2);
    int ny2 = round(y2 + shy * x2);

    int nx3 = round(x3 + shx * y3);
    int ny3 = round(y3 + shy * x3);

    drawLine(nx1, ny1, nx2, ny2, RED);
    drawLine(nx2, ny2, nx3, ny3, RED);
    drawLine(nx3, ny3, nx1, ny1, RED);

    getch();
    closegraph();

    return 0;
}
