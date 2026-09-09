#include <stdio.h>

int main()
{
    int i, j, n;
    float x[10], y[10], xp, yp = 0, p;

    printf("enter number of data points: ");
    scanf("%d", &n);
    // 3

    printf("enter data point(x,y)\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
        // x[0]=1 y[0]=1
        // x[1]=2 y[1]=4
        // x[2]=3 y[2]=9
    }

    printf("enter value of x find y:");
    scanf("%f", &xp);
    // 2.5

    for (i = 0; i < n; i++)
    {
        p = 1;
        for (j = 0; j < n; j++)
        {
            if (j != i)
            {
                p = p * (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp = yp + p * y[i];
    }

    printf("interpolation vlaue at x=%.2f is y=%.4f", xp, yp);

    return 0;
}