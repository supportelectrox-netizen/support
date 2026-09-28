
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
    int choice;

    cout << "Enter coordinates of Triangle:\n";

    cout << "Vertex 1 (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Vertex 2 (x2 y2): ";
    cin >> x2 >> y2;

    cout << "Vertex 3 (x3 y3): ";
    cin >> x3 >> y3;

    cout << "\nReflection Options:\n";
    cout << "1. Reflection about X-axis\n";
    cout << "2. Reflection about Y-axis\n";
    cout << "3. Reflection about Origin\n";

    cout << "Enter your choice: ";
    cin >> choice;

    // Screen center as Origin
    int cx = getmaxx() / 2;
    int cy = getmaxy() / 2;

    // Draw X-axis using drawLine()
    drawLine(0, cy, getmaxx(), cy, WHITE);

    // Draw Y-axis using drawLine()
    drawLine(cx, 0, cx, getmaxy(), WHITE);

    // -----------------------------
    // Original Triangle
    // -----------------------------

    drawLine(cx + x1, cy - y1,
             cx + x2, cy - y2, WHITE);

    drawLine(cx + x2, cy - y2,
             cx + x3, cy - y3, WHITE);

    drawLine(cx + x3, cy - y3,
             cx + x1, cy - y1, WHITE);


    int nx1, ny1;
    int nx2, ny2;
    int nx3, ny3;


    // -----------------------------
    // Reflection
    // -----------------------------

    if (choice == 1)
    {
        // Reflection about X-axis

        nx1 = x1;
        ny1 = -y1;

        nx2 = x2;
        ny2 = -y2;

        nx3 = x3;
        ny3 = -y3;
    }

    else if (choice == 2)
    {
        // Reflection about Y-axis

        nx1 = -x1;
        ny1 = y1;

        nx2 = -x2;
        ny2 = y2;

        nx3 = -x3;
        ny3 = y3;
    }

    else if (choice == 3)
    {
        // Reflection about Origin

        nx1 = -x1;
        ny1 = -y1;

        nx2 = -x2;
        ny2 = -y2;

        nx3 = -x3;
        ny3 = -y3;
    }

    else
    {
        cout << "Invalid Choice!";

        getch();
        closegraph();

        return 0;
    }


    // -----------------------------
    // Reflected Triangle
    // -----------------------------

    drawLine(cx + nx1, cy - ny1,
             cx + nx2, cy - ny2, RED);

    drawLine(cx + nx2, cy - ny2,
             cx + nx3, cy - ny3, RED);

    drawLine(cx + nx3, cy - ny3,
             cx + nx1, cy - ny1, RED);


    getch();

    closegraph();

    return 0;
}
