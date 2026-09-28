
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

    int x1, y1, x2, y2;
    int tx, ty;

    cout << "Enter coordinates of Rectangle:\n";

    cout << "Enter Top Left Coordinates (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter Top Left Coordinates (x2 y2): ";
    cin >> x2 >> y2;

    cout << "Enter Translation Factors (tx ty): ";
    cin >> tx >> ty;

    drawLine(x1, y1, x2, y1, WHITE); 
    drawLine(x1, y2, x2, y2, RED); 
    drawLine(x1, y1, x1, y2, BLUE); 
    drawLine(x2, y1, x2, y2, YELLOW); 
    
    int nx1 = x1 + tx;
    int ny1 = y1 + ty;

    int nx2 = x2 + tx;
    int ny2 = y2 + ty;

    drawLine(nx1, ny1, nx2, ny1, GREEN); 
    drawLine(nx1, ny2, nx2, ny2, GREEN); 

    setcolor(WHITE);
    outtextxy(x1, y1 - 20, "Original");

    setcolor(GREEN);
    outtextxy(nx1, ny1 - 20, "Translated");

    getch();
    closegraph();
    return 0;
}

