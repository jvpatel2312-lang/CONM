#include <stdio.h>
#include <math.h>

// function f(x) = 1 / (1 + x * x)
float f(float x)
{
    return 1.0 / (1.0 + x * x);
}

int main()
{
    float a, b, h, sum = 0.0, integral;
    int n, i;

    // step 1:input
    printf("enter lover limit (a): ");
    scanf("%f", &a); // 0

    printf("enter upper limit (b): ");
    scanf("%f", &b); // 1

    printf("enter number of sub-interval (n): ");
    scanf("%d", &n); // 4

    // step 2:calculation step size h
    h = (b - a) / n;
    // 1 - 0 / 4 = 0.25

    // step 3:apply trapezoidal rule
    sum = f(a) + f(b);
    // frist + last term

    // a = 0
    // b = 1
    // f(a) = f(0) - 1 / (1 + 0 * 0) = 1 / 1 = 1
    // f(b) = f(1) - 1 / (1 + 1 * 1) = 1 / 2 = 0.5

    // x  0  0.25      0.5  0.75  1
    // y  1  0.901176  0.8  0.64  0.5

    // sum = 1 + 0.5 = 1.5

    for (i = 1; i < n; i++)
    {
        float x = a + i * h;
        // x = 0 + 1 * 0.25
        // x = 0.25

        sum += 2.0 * f(x);
        // middle term mul by 2

        // i = 1
        // f(0.25) = 1 / (1 + 0.25 * 0.25) = 1 / 1.0625 = 0.941176
        // 2*f(x) = 1.882352
        // sum = 1.5 + 1.882352
        // sum = 3.382352

        // i = 2
        // x = 0 + 2 * 0.25 = 0.5
        // f(0.5) = 1 / (1 + 0.5 * 0.5) = 1 / 1.25 = 0.8
        // sum = 3.382352 + 1.6
        // sum = 4.932352

        // i = 3
        // x = 0 + 3 * 0.25
        // f(0.75) = 1 / (1 + 0.75 * 0.75) = 1 / 1.5625 = 0.64
        // 2 * f(x) = 2 * 0.64 = 1.28
        // sum = 4.982352 + 1.28
        // sum = 6.262352
    }

    // step 4:final formula
    integral = (h / 2.0) * sum;
    // 0.25 / 2 = 0.125 * 6.262352 = 0.782794

    // step 5:output
    printf("value of intehral = %f\n", integral);

    return 0;
}