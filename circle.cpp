# include <graphics.h>
# include <iostream>

using namespace std;

void drawCircle(int x, int y, int h, int k)
{
    putpixel(x + h, y + k, BLUE);
    putpixel(x - h, y + k, WHITE);
    putpixel(x + h, y - k, YELLOW);
    putpixel(x - h, y - k, RED);

    putpixel(x + k, y + h, GREEN);
    putpixel(x - k, y + h, MAGENTA);
    putpixel(x + k, y - h, CYAN);
    putpixel(x - k, y - h, BROWN);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc, r;

    cout << "Enter Center (xc, yc): ";
    cin >> xc >> yc;

    cout << "Enter Radius: ";
    cin >> r;

    int x = 0;
    int y = r;
    int p = 1 - r;

    while (x <= y)
    {
        drawCircle(xc, yc, x, y);
        delay(20);
        x++;
        if (p < 0){
            p = p + 2 * x + 1;
        }
        else {
            y--;
            p = p + 2 * x - 2 * y + 1;
        }
    }

    getch();
    closegraph();
    return 0;
}
