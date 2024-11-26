#include <stdio.h>
#include <math.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}

void independentWork() {
    float y = 0;
    for (int a = 1; a <= 3; a += 1) {
        double maxY = -1 * exp(24);
        double maxX = 0;
        double minY = exp(24);
        double minX = 0;
        printf("a = %d\n", a);
        for (double x = 0.5; x < 3.5; x += 0.5) {
            y = sin(x) + fabs(x) + pow(2, x);
            printf("x = %.2f, y = %.2f\n", x, y);
            if (y > maxY) {
                maxY = y;
                maxX = x;
            }
            if (y < minY) {
                minY = y;
                minX = x;
            }
        }
        printf("maxX = %.2f, maxY = %.2f\nminX = %.2f, minY = %.2f\n", maxX, maxY, minX, minY);
    }
}