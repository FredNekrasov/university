#include <stdio.h>
#include <tgmath.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}

void independentWork() {
    float y = 0;
    for (int a = 1; a <= 3; a += 1) {
        float maxY = -1 * exp(24);
        float maxX = 0;
        float minY = exp(24);
        float minX = 0;
        printf("a = %d\n", a);
        for (float x = 0.5f; x < 3.5; x += 0.5f) {// здесь интервал меняем
            y = sin(x) + fabsf(x) + pow(2, x);// здесь формулу поменять
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