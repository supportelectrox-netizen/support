#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;


const int INSIDE = 0; // 0000
const int LEFT   = 1; // 0001
const int RIGHT  = 2; // 0010
const int BOTTOM = 4; // 0100
const int TOP    = 8; // 1000

// clipping window
float xmin, ymin, xmax, ymax;

void drawLine(int x1, int y1, int x2, int y2, int color)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    for(int i = 0; i <= steps; i++)
    {
        putpixel(round(x), round(y), color);
        x += xInc;
        y += yInc;
    }
}

// compute region code
int computeCode(float x, float y)
{
    int code = INSIDE;

    if(x < xmin)
        code |= LEFT;
    else if(x > xmax)
        code |= RIGHT;

    if(y < ymin)
        code |= BOTTOM;
    else if(y > ymax)
        code |= TOP;

    return code;
}

// cohen-sutherland line clipping
void lineClip(float x1, float y1, float x2, float y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    bool accept = false;

    while(true)
    {
        if((code1 == 0) && (code2 == 0))
        {
            accept = true;
            break;
        }
        else if(code1 & code2)
        {
            break;
        }
        else
        {
            float x, y;

            int codeOut = code1 ? code1 : code2;

            if(codeOut & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if(codeOut & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if(codeOut & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if(codeOut == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if(accept)
    {
        drawLine(round(x1), round(y1), round(x2), round(y2), RED);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float x1, y1, x2, y2;

    cout << "Enter Clipping Window (xmin ymin xmax ymax): ";
    cin >> xmin >> ymin >> xmax >> ymax;

    cout << "Enter Line Endpoints (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    // draw clipping window
    drawLine(xmin, ymin, xmax, ymin, WHITE);
    drawLine(xmax, ymin, xmax, ymax, WHITE);
    drawLine(xmax, ymax, xmin, ymax, WHITE);
    drawLine(xmin, ymax, xmin, ymin, WHITE);

    // draw original line
    drawLine(x1, y1, x2, y2, YELLOW);

    // draw clipped line
    lineClip(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}
