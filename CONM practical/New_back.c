#include <stdio.h>

int main()
{
    int n, i, j;
    float x[10], y[10][10], xi, h, u, result, term = 1;

    printf("enter number of data points: ");
    scanf("%d", &n);

    printf("enter x values:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    //x[0] = 10
    //x[1] = 15
    //x[2] = 20

    printf("enter y values:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &y[i][0]);
    }
    //y[0][0] = 100
    //y[1][0] = 225
    //y[2][0] = 400

    for (j = 1; j < n; j++)
    {
        for (i = n - 1; i >= j; i--)
        {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }

    printf("enter value of x to interpolate: ");
    scanf("%f", &xi);
    //x= 18

    h = x[1] - x[0];
    u = (xi - x[n - 1]) / h;

    result = y[n - 1][0];

    for (i = 1; i < n; i++)
    {
        term = term * (u + (i - 1)) / i;
        result = result + term * y[n - 1][i];
    }


    printf("interpolate value at %.2f = %.4f", xi, result);

    return 0;
}