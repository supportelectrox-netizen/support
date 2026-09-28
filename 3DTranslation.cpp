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

    for(int i = 0; i <= steps; i++)
    {
        putpixel(round(x), round(y), color);
        x += xInc;
        y += yInc;
    }
}

struct Point3D
{
    int x, y, z;
};

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Point3D p[8];
    int tx, ty, tz;

    cout << "Enter 8 vertices of Cube (x y z):\n";

    for(int i = 0; i < 8; i++)
    {
        cout << "Vertex " << i + 1 << ": ";
        cin >> p[i].x >> p[i].y >> p[i].z;
    }

    cout << "Enter Translation Factors (tx ty tz): ";
    cin >> tx >> ty >> tz;

    int edges[12][2] =
    {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    for(int i = 0; i < 12; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        drawLine(p[a].x, p[a].y, p[b].x, p[b].y, WHITE);
    }

    Point3D np[8];

    for(int i = 0; i < 8; i++)
    {
        np[i].x = p[i].x + tx;
        np[i].y = p[i].y + ty;
        np[i].z = p[i].z + tz;
    }

    for(int i = 0; i < 12; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        drawLine(np[a].x, np[a].y, np[b].x, np[b].y, RED);
    }

    getch();
    closegraph();
    return 0;
}

//100 100 0
//200 100 0
//200 200 0
//100 200 0
//150 150 100
//250 150 100
//250 250 100
//150 250 100
//100 50 20
