#include <stdio.h>
#include <conio.h>

// Define the differential equation dy/dx = f(x, y)
// Example: dy/dx = x + y
float f(float x, float y) {
    return ((x * x) + y);
}

void main() {
    float x0, y0, xn, h, x, y, y_predict, y_correct;
    int i, n;
    clrscr();

    // Step 1: Input initial conditions and parameters
    printf("Enter initial condition (x0 y0): ");
    scanf("%f %f", &x0, &y0);
    // 0 1

    printf("Enter value of x to find y (xn): ");
    scanf("%f", &xn);
    // 0.2

    printf("Enter step size (h): ");
    scanf("%f", &h);
    // 0.1

    // Step 2: Calculate number of steps
    n = (int)((xn - x0) / h);
    // n = (0.2 - 0) / 0.1 = 2

    x = x0;
    y = y0;

    // Step 3: Apply Euler's Modified Method (Heun's Method)
    for (i = 0; i < n; i++) 
    // i=0, 1
    {
        // Predictor step (Standard Euler)
        // y_predict = y + h * f(x, y)
        y_predict = y + h * f(x, y);
        // For i=0:
        // x = 0, y = 1
        // f(0, 1) = 0 + 1 = 1
        // y_predict = 1 + 0.1 * 1 = 1.1

        // Corrector step (Average of slopes)
        // y_correct = y + (h / 2) * (f(x, y) + f(x + h, y_predict))
        y_correct = y + (h / 2.0) * (f(x, y) + f(x + h, y_predict));
        // f(0.1, 1.1) = 0.1 + 1.1 = 1.2
        // y_correct = 1 + (0.1 / 2) * (1 + 1.2)
        //           = 1 + 0.05 * 2.2 = 1 + 0.11 = 1.11

        // Update values for next step
        x = x + h;
        // x = 0 + 0.1 = 0.1
        y = y_correct;
        // y = 1.11

        // For i=1:
        // x = 0.1, y = 1.11
        // f(0.1, 1.11) = 1.21
        // y_predict = 1.11 + 0.1 * 1.21 = 1.11 + 0.121 = 1.231
        // f(0.2, 1.231) = 0.2 + 1.231 = 1.431
        // y_correct = 1.11 + (0.1 / 2) * (1.21 + 1.431)
        //           = 1.11 + 0.05 * 2.641 = 1.11 + 0.13205 = 1.24205
        // x = 0.2, y = 1.24205
    }

    // Step 4: Display final result
    printf("\nValue of y at x = %.2f is y = %.4f\n", xn, y);

    getch();
}