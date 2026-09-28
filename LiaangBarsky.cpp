#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

// DDA Line Drawing Algorithm
void drawLine(float x1, float y1, float x2, float y2, int color)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    float steps;

    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        putpixel(round(x), round(y), color);

        x = x + xIncrement;
        y = y + yIncrement;
    }
}


// Rectangle manually draw
void drawRectangle(float xmin, float ymin,
                   float xmax, float ymax, int color)
{
    // Top
    drawLine(xmin, ymin, xmax, ymin, color);

    // Right
    drawLine(xmax, ymin, xmax, ymax, color);

    // Bottom
    drawLine(xmax, ymax, xmin, ymax, color);

    // Left
    drawLine(xmin, ymax, xmin, ymin, color);
}


// Liang-Barsky Algorithm
void liangBarsky(float *x1, float *y1,
                 float *x2, float *y2,
                 float *xmin, float *ymin,
                 float *xmax, float *ymax)
{
    float dx = *x2 - *x1;
    float dy = *y2 - *y1;

    float p[4], q[4];

    // p values
    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = dy;

    // q values
    q[0] = *x1 - *xmin;
    q[1] = *xmax - *x1;
    q[2] = *y1 - *ymin;
    q[3] = *ymax - *y1;

    float u1 = 0.0;
    float u2 = 1.0;

    // Check all 4 boundaries
    for (int i = 0; i < 4; i++)
    {
        // Line parallel to boundary
        if (p[i] == 0)
        {
            if (q[i] < 0)
            {
                cout << "Line is completely outside.\n";
                return;
            }
        }

        else
        {
            float r = q[i] / p[i];

            // Entering point
            if (p[i] < 0)
            {
                if (r > u1)
                    u1 = r;
            }

            // Leaving point
            else
            {
                if (r < u2)
                    u2 = r;
            }
        }
    }

    // No valid portion
    if (u1 > u2)
    {
        cout << "Line is completely outside.\n";
        return;
    }

    // Calculate clipped coordinates
    float nx1 = *x1 + u1 * dx;
    float ny1 = *y1 + u1 * dy;

    float nx2 = *x1 + u2 * dx;
    float ny2 = *y1 + u2 * dy;

    cout << "Clipped Line:\n";

    cout << "(" << nx1 << ", " << ny1 << ") to ";
    cout << "(" << nx2 << ", " << ny2 << ")\n";

    // Draw clipped line using DDA
    drawLine(nx1, ny1, nx2, ny2, GREEN);
}


int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    float x1, y1, x2, y2;
    float xmin, ymin, xmax, ymax;

    // Line input
    cout << "Enter line coordinates (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Clipping window input
    cout << "Enter clipping window (xmin ymin xmax ymax): ";
    cin >> xmin >> ymin >> xmax >> ymax;


    // Draw clipping window manually
    drawRectangle(xmin, ymin, xmax, ymax, WHITE);


    // Draw original line manually
    drawLine(x1, y1, x2, y2, RED);


    // Apply Liang-Barsky
    liangBarsky(&x1, &y1,
                &x2, &y2,
                &xmin, &ymin,
                &xmax, &ymax);


    getch();

    closegraph();

    return 0;
}