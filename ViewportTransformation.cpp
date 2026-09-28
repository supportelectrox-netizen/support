
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

    // Window coordinates
    float wxmin, wymin, wxmax, wymax;
    // Viewport coordinates
    float vxmin, vymin, vxmax, vymax;
    // Triangle coordinates
    float x1, y1, x2, y2, x3, y3;

    cout << "Enter Window (wxmin wymin wxmax wymax): ";
    cin >> wxmin >> wymin >> wxmax >> wymax;

    cout << "Enter Viewport (vxmin vymin vxmax vymax): ";
    cin >> vxmin >> vymin >> vxmax >> vymax;

    cout << "Enter Triangle Coordinates:\n";

    cout << "Vertex 1: ";
    cin >> x1 >> y1;

    cout << "Vertex 2: ";
    cin >> x2 >> y2;

    cout << "Vertex 3: ";
    cin >> x3 >> y3;

    // draw original window
    drawLine(wxmin, wymin, wxmax, wymin, WHITE);
    drawLine(wxmax, wymin, wxmax, wymax, WHITE);
    drawLine(wxmax, wymax, wxmin, wymax, WHITE);
    drawLine(wxmin, wymax, wxmin, wymin, WHITE);

    // draw original triangle
    drawLine(x1, y1, x2, y2, WHITE);
    drawLine(x2, y2, x3, y3, WHITE);
    drawLine(x3, y3, x1, y1, WHITE);

    // viewport transformation
    float sx = (vxmax - vxmin) / (wxmax - wxmin);
    float sy = (vymax - vymin) / (wymax - wymin);

    float nx1 = vxmin + (x1 - wxmin) * sx;
    float ny1 = vymin + (y1 - wymin) * sy;

    float nx2 = vxmin + (x2 - wxmin) * sx;
    float ny2 = vymin + (y2 - wymin) * sy;

    float nx3 = vxmin + (x3 - wxmin) * sx;
    float ny3 = vymin + (y3 - wymin) * sy;

    // draw viewport
    drawLine(vxmin, vymin, vxmax, vymin, YELLOW);
    drawLine(vxmax, vymin, vxmax, vymax, YELLOW);
    drawLine(vxmax, vymax, vxmin, vymax, YELLOW);
    drawLine(vxmin, vymax, vxmin, vymin, YELLOW);

    // draw transformed triangle
    drawLine(nx1, ny1, nx2, ny2, RED);
    drawLine(nx2, ny2, nx3, ny3, RED);
    drawLine(nx3, ny3, nx1, ny1, RED);

    getch();
    closegraph();

    return 0;
}

//50 50 250 250
//300 50 500 250
//80 80
//200 100
//120 200
