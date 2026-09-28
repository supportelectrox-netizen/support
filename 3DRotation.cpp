#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265


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
    float x, y, z;
};

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Point3D p[8], np[8];
    float angle;

    cout << "Enter 8 vertices of Cube (x y z):\n";

    for(int i = 0; i < 8; i++)
    {
        cout << "Vertex " << i + 1 << ": ";
        cin >> p[i].x >> p[i].y >> p[i].z;
    }

    cout << "Enter Rotation Angle (degrees): ";
    cin >> angle;

    float rad = angle * PI / 180.0;

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

        drawLine((int)p[a].x, (int)p[a].y,
                 (int)p[b].x, (int)p[b].y, WHITE);
    }

    for(int i = 0; i < 8; i++)
    {
        np[i].x = p[i].x * cos(rad) - p[i].y * sin(rad);
        np[i].y = p[i].x * sin(rad) + p[i].y * cos(rad);
        np[i].z = p[i].z;
    }

    for(int i = 0; i < 12; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        drawLine((int)np[a].x, (int)np[a].y,
                 (int)np[b].x, (int)np[b].y, RED);
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
//20
