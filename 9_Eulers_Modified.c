#include <stdio.h>
#include <math.h>

float f(float x, float y)
{
    // Define the differential equation dy/dx = f(x,y)
    return ((sqrt(y) - sqrt(x))/(sqrt(y) + sqrt(x)));  // Example: dy/dx = x + y
}

int main()
{
    float x0, y0, xn, h, x, y;
    float yp, yc, error;
    int i, n;

    // Step 1: Enter initial values
    printf("Enter initial value of x: ");
    scanf("%f", &x0);

    printf("Enter initial value of y: ");
    scanf("%f", &y0);

    // Step 2: Enter final value and step size
    printf("Enter final value of x: ");
    scanf("%f", &xn);

    printf("Enter step size h: ");
    scanf("%f", &h);

    // Calculate the number of steps
    n = (int)((xn - x0) / h);

    x = x0;
    y = y0;

    printf("\n x\t y\n");
    printf("%.4f\t%.4f\n", x, y);

    // Step 3: Apply Euler's Modified Method
    for (i = 1; i <= n; i++)
    {
        // Calculate the predicted value of y
        yp = y + h * f(x, y);

        // Calculate the corrected value of y
        // using the average of the two slopes
        yc = y + (h / 2) * (f(x, y) + f(x + h, yp));

        // Repeat correction to improve accuracy
        do
        {
            error = yc - yp;
            yp = yc;

            yc = y + (h / 2) * (f(x, y) + f(x + h, yp));

        } while (error > 0.0001 || error < -0.0001);

        // Update x and y for the next step
        x = x + h;
        y = yc;

        // Display the calculated values
        printf("%.4f\t%.4f\n", x, y);
    }

    return 0;
}