#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;

    cout << "Enter x1 y1: ";
    cin >> x1 >> y1;

    cout << "Enter x2 y2: ";
    cin >> x2 >> y2;


    float dx = x2 - x1;
    float dy = y2 - y1;


    float steps;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    float Xinc = dx / steps;
    float Yinc = dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        putpixel(round(x), round(y), WHITE);
        x += Xinc;
        y += Yinc;

        delay(20);
    }

    getch();
    closegraph();

    return 0;
}
