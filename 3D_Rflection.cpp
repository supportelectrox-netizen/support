#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

// DDA Line Drawing Algorithm
void drawLine(int x1, int y1, int x2, int y2, int color)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    if (steps == 0)
    {
        putpixel(x1, y1, color);
        return;
    }

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

// 3D Point
struct Point3D
{
    int x, y, z;
};

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    Point3D p[8];

    // Input vertices
    cout << "Enter 8 vertices of Cube (x y z):\n";

    for (int i = 0; i < 8; i++)
    {
        cout << "Vertex " << i + 1 << ": ";
        cin >> p[i].x >> p[i].y >> p[i].z;
    }

    // Reflection choice
    int choice;

    cout << "\n3D Reflection Options:\n";
    cout << "1. Reflection about XY Plane\n";
    cout << "2. Reflection about XZ Plane\n";
    cout << "3. Reflection about YZ Plane\n";
    cout << "4. Reflection about X Axis\n";
    cout << "5. Reflection about Y Axis\n";
    cout << "6. Reflection about Z Axis\n";

    cout << "\nEnter your choice: ";
    cin >> choice;

    // Edges of cube
    int edges[12][2] =
    {
        {0,1}, {1,2}, {2,3}, {3,0},
        {4,5}, {5,6}, {6,7}, {7,4},
        {0,4}, {1,5}, {2,6}, {3,7}
    };

    // -------------------------------
    // Draw Original Cube
    // -------------------------------

    for (int i = 0; i < 12; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        drawLine(
            p[a].x,
            p[a].y,
            p[b].x,
            p[b].y,
            WHITE
        );
    }

    // -------------------------------
    // 3D Reflection
    // -------------------------------

    Point3D np[8];

    for (int i = 0; i < 8; i++)
    {
        np[i] = p[i];

        // Reflection about XY Plane
        if (choice == 1)
        {
            np[i].z = -p[i].z;
        }

        // Reflection about XZ Plane
        else if (choice == 2)
        {
            np[i].y = -p[i].y;
        }

        // Reflection about YZ Plane
        else if (choice == 3)
        {
            np[i].x = -p[i].x;
        }

        // Reflection about X Axis
        else if (choice == 4)
        {
            np[i].y = -p[i].y;
            np[i].z = -p[i].z;
        }

        // Reflection about Y Axis
        else if (choice == 5)
        {
            np[i].x = -p[i].x;
            np[i].z = -p[i].z;
        }

        // Reflection about Z Axis
        else if (choice == 6)
        {
            np[i].x = -p[i].x;
            np[i].y = -p[i].y;
        }
    }

    // -------------------------------
    // Draw Reflected Cube
    // -------------------------------

    // Move reflected cube to the right
    int offsetX = 250;

    for (int i = 0; i < 12; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        drawLine(
            np[a].x + offsetX,
            np[a].y,
            np[b].x + offsetX,
            np[b].y,
            RED
        );
    }

    // Labels
    setcolor(WHITE);
    outtextxy(50, 30, "Original Cube");

    setcolor(RED);
    outtextxy(300, 30, "Reflected Cube");

    getch();

    closegraph();

    return 0;
}