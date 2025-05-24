#include <stdio.h>
#include <math.h>

#define TOLERANCE 0.0001
#define MAX_ITERATION 50

// f(x) = x^3 - x - 2
float f(float x) {
    return x * x * x - x - 2;
}

// f'(x) = 3x^2 - 1
float f_dash(float x) {
    return 3 * x * x - 1;
}

int main() {
    float x0, x1;
    int iteration = 0;

    printf("Enter initial guess: ");
    scanf("%f", &x0);

    // x1 = x0;

    printf("Iter.  \t x         \t f(x)     \t f'(x)     \t Error \n");
    while (iteration < MAX_ITERATION) {
        float fx = f(x0);
        float fdx = f_dash(x0);

        x1 = x0 - fx / fdx;

        float error = fabs((x1 - x0) / x1);

        printf("%d \t %f \t %f \t %f \t %f\n", iteration, x0, fx, fdx, error);

        x0 = x1;
        
        if (error < TOLERANCE) {
            printf("Root: %f", x1);
            printf("\nProgrammed by Milan Bairagi...");
            return 0;
        }

        iteration++;
    }

    printf("Maximum iteration reached. Best approximation: %f", x1);

    return 0;
}