#include <graphics.h>
#include <iostream>
#include<cmath>

using namespace std;

void drawLine(int x1, int y1, int x2, int y2, int color)
{

    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float x_inc = dx / steps;
    float y_inc = dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i < steps; i++){
        putpixel(round(x), round(y), color);
         x += x_inc;
         y += y_inc;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float xwmin, xwmax, ywmin, ywmax;
    float xvmin, xvmax, yvmin, yvmax;

    float x1, y1, x2, y2, x3, y3;

    cout << "Enter Window (wxmin wymin wxmax wymax): ";
    cin >> xwmin >> ywmin >> xwmax >> ywmax;

    cout << "Enter Viewport (vxmin vymin vxmax vymax): ";
    cin >> xvmin >> yvmin >> xvmax >> yvmax;

    cout << "Enter Triangle Coordinates:\n";

    cout << "Vertex 1: ";
    cin >> x1 >> y1;

    cout << "Vertex 2: ";
    cin >> x2 >> y2;

    cout << "Vertex 3: ";
    cin >> x3 >> y3;

    drawLine(xwmin, ywmin, xwmax, ywmin, GREEN);
    drawLine(xwmin, ywmax, xwmax, ywmax, GREEN);
    drawLine(xwmin, ywmin, xwmin, ywmax, GREEN);
    drawLine(xwmax, ywmin, xwmax, ywmax, GREEN);


    drawLine(x1, y1, x2, y2, WHITE);
    drawLine(x2, y2, x3, y3, WHITE);
    drawLine(x3, y3, x1, y1, WHITE);

    float sx = (xvmax - xvmin) / (xwmax - xwmin);
    float sy = (yvmax - ywmin) / (ywmax - ywmin);

    float nx1 = xvmin + (x1 - xwmin) * sx;
    float ny1 = yvmin + (y1 - ywmin) * sx;

    float nx2 = xvmin + (x2 - xwmin) * sx;
    float ny2 = yvmin + (y2 - ywmin) * sx;

    float nx3 = xvmin + (x3 - xwmin) * sx;
    float ny3 = yvmin + (y3 - ywmin) * sx;

    drawLine(xvmin, yvmin, xvmax, yvmin, WHITE);
    drawLine(xvmin, yvmax, xvmax, yvmax, WHITE);
    drawLine(xvmin, yvmin, xvmin, yvmax, WHITE);
    drawLine(xvmax, yvmin, xvmax, yvmax, WHITE);


    drawLine(nx1, ny1, nx2, ny2, RED);
    drawLine(nx2, ny2, nx3, ny3, RED);
    drawLine(nx3, ny3, nx1, ny1, RED);

    getch();
    closegraph();

    return 0;

}
