#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

void drawEllipse(int xc, int yc, int rx, int ry)
{
    int x = 0;
    int y = ry;

    // Initial decision parameter for Region 1
    float p1 = (ry * ry) - (rx * rx * ry)
               + (0.25 * rx * rx);

    float dx = 2 * ry * ry * x;
    float dy = 2 * rx * rx * y;

    // -------------------------
    // Region 1
    // -------------------------
    while (dx < dy)
    {
        // Plot 4 symmetric points
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p1 < 0)
        {
            // Choose East pixel
            x++;

            dx = 2 * ry * ry * x;

            p1 = p1 + dx + (ry * ry);
        }
        else
        {
            // Choose South-East pixel
            x++;
            y--;

            dx = 2 * ry * ry * x;
            dy = 2 * rx * rx * y;

            p1 = p1 + dx - dy + (ry * ry);
        }
    }

    // Initial decision parameter for Region 2
    float p2 = (ry * ry) * (x + 0.5) * (x + 0.5)
               + (rx * rx) * (y - 1) * (y - 1)
               - (rx * rx) * (ry * ry);

    // -------------------------
    // Region 2
    // -------------------------
    while (y >= 0)
    {
        // Plot 4 symmetric points
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p2 > 0)
        {
            // Choose South pixel
            y--;

            dy = 2 * rx * rx * y;

            p2 = p2 - dy + (rx * rx);
        }
        else
        {
            // Choose South-East pixel
            x++;
            y--;

            dx = 2 * ry * ry * x;
            dy = 2 * rx * rx * y;

            p2 = p2 + dx - dy + (rx * rx);
        }
    }
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    int xc, yc, rx, ry;

    cout << "Enter center (xc, yc): ";
    cin >> xc >> yc;

    cout << "Enter X-radius (rx): ";
    cin >> rx;

    cout << "Enter Y-radius (ry): ";
    cin >> ry;

    drawEllipse(xc, yc, rx, ry);

    getch();
    closegraph();

    return 0;
}

// Enter center (xc, yc): 300 250
// Enter X-radius (rx): 150
// Enter Y-radius (ry): 100

