#define M_PI           3.14159265358979323846  /* pi */

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cmath>
#include <graphics.h>
#include <conio.h>

using namespace std;

int main() {
    initwindow(800, 600);
    int x, y;
    line(0, 300, getmaxx(), 300);
    line(400, 0, 400, getmaxy());
    float pi = 3.1415;
    for (int i=-360; i<=360; i++){
        x=(int)400+i;
        y=(int)300-cos(i*pi/100)*25;
        putpixel(x, y, WHITE);
        }
    getch();
    closegraph();
    return 0;
}