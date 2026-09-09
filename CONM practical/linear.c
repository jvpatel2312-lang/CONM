#include <stdio.h>

int main()
{
    float x0, y0, x1, y1, x, y;

    printf("enter 1st points (x0,y0):");
    scanf("%f %f", &x0, &y0);
    //2 4

    printf("enter 2st points (x1,y1):");
    scanf("%f %f", &x1, &y1);
    //6 8

    printf("enter x to find y:");
    scanf("%f", &x);
    //4

    y = y0 + (x - x0) * (y1 - y0) / (x1 - x0);

    printf("interpoation value y = %.2f\n", y);

    return 0;
}