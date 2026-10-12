#include <conio.h>
#include <stdio.h>

void main()
{
    float x1, y1, z1, d1;
    float x2, y2, z2, d2;
    float x3, y3, z3, d3;
    float x0, y0, z0;
    float x, y, z;
    int i, n;
    clrscr();

    printf("Enter coefficients of equation 1 (x1 y1 z1 d1): ");
    scanf("%f %f %f %f", &x1, &y1, &z1, &d1);

    printf("Enter coefficients of equation 2 (x2 y2 z2 d2): ");
    scanf("%f %f %f %f", &x2, &y2, &z2, &d2);

    printf("Enter coefficients of equation 3 (x3 y3 z3 d3): ");
    scanf("%f %f %f %f", &x3, &y3, &z3, &d3);

    printf("Enter initial guesses (x0 y0 z0): ");
    scanf("%f %f %f", &x0, &y0, &z0);

    printf("Enter number of iterations: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        x = (d1 - y1 * y0 - z1 * z0) / x1;
        y = (d2 - x2 * x0 - z2 * z0) / y2;
        z = (d3 - x3 * x0 - y3 * y0) / z3;

        printf("Iteration %d: x = %.4f, y = %.4f, z = %.4f\n",
               i, x, y, z);

        x0 = x;
        y0 = y;
        z0 = z;
    }

    getch();
}
