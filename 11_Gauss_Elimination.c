#include <stdio.h>

int main()
{
    int i, j, k, n;
    float a[10][11], ratio, x[10];

    // Step 1: Enter the number of equations
    printf("Enter number of equations: ");
    scanf("%d", &n); // 3

    // Step 2: Enter the augmented matrix
    printf("Enter augmented matrix row-wise:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    // For given equations, enter:
    // 1  1  1   3
    // 1  2  3   0
    // 1  3  2  -3

    // Step 3: Forward Elimination
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            // Calculate ratio
            ratio = a[j][i] / a[i][i];

            // i = 0, j = 1
            // ratio = a[1][0] / a[0][0] = 1 / 1 = 1
            // R2 = R2 - 1 * R1
            // R2 = [1  2  3  0] - [1  1  1  3]
            // R2 = [0  1  2 -3]

            // i = 0, j = 2
            // ratio = a[2][0] / a[0][0] = 1 / 1 = 1
            // R3 = R3 - 1 * R1
            // R3 = [1  3  2 -3] - [1  1  1  3]
            // R3 = [0  2  1 -6]

            // i = 1, j = 2
            // ratio = a[2][1] / a[1][1] = 2 / 1 = 2
            // R3 = R3 - 2 * R2
            // R3 = [0  2  1 -6] - 2 * [0  1  2 -3]
            // R3 = [0  0 -3  0]

            // Update each element of the current row
        
            for (k = 0; k <= n; k++)
            {
                a[j][k] = a[j][k] - ratio * a[i][k];

                // i = 0, j = 1
                // ratio = 1 / 1 = 1
                // a[1][0] = 1 - 1 * 1 = 0
                // a[1][1] = 2 - 1 * 1 = 1
                // a[1][2] = 3 - 1 * 1 = 2
                // a[1][3] = 0 - 1 * 3 = -3
                // R2 = [0  1  2  -3]

                // i = 0, j = 2
                // ratio = 1 / 1 = 1
                // a[2][0] = 1 - 1 * 1 = 0
                // a[2][1] = 3 - 1 * 1 = 2
                // a[2][2] = 2 - 1 * 1 = 1
                // a[2][3] = -3 - 1 * 3 = -6
                // R3 = [0  2  1  -6]

                // i = 1, j = 2
                // ratio = 2 / 1 = 2
                // a[2][0] = 0 - 2 * 0 = 0
                // a[2][1] = 2 - 2 * 1 = 0
                // a[2][2] = 1 - 2 * 2 = -3
                // a[2][3] = -6 - 2 * (-3) = 0
                // R3 = [0  0  -3  0]
            }
        }
    }

    // Step 4: Display Upper Triangular Matrix
    printf("\nUpper Triangular Matrix (UTM):\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            printf("%.4f\t", a[i][j]);
        }
        printf("\n");
    }

    // Step 5: Back Substitution
    // Calculate z using the third equation
    // -3z = 0
    // x[2] = a[2][3] / a[2][2]
    // x[2] = 0 / (-3) = 0

    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    // Calculate the remaining variables from bottom to top
    for (i = n - 2; i >= 0; i--)
    {
        // Take the constant term of the current equation
        x[i] = a[i][n];

        // Subtract the known variables multiplied by coefficients
        for (j = i + 1; j < n; j++)
        {
            x[i] = x[i] - a[i][j] * x[j];

            // For i = 1:
            // y = -3 - 2 * 0 = -3

            // For i = 0:
            // x = 3 - 1 * (-3) - 1 * 0 = 6
        }

        // Divide by the coefficient of the current variable
        x[i] = x[i] / a[i][i];
    }

    // Step 6: Display the final solution
    printf("\nSolution:\n");

    for (i = 0; i < n; i++)
    {
        printf("x%d = %.2f\n", i + 1, x[i]);
    }

    return 0;
}