//
// Created by fred on 13.10.2024.
//
#include <stdio.h>
#include <math.h>
#include <limits.h>

int thirdPW3Task() {
    float p = 0;
    printf("Input p ");
    scanf_s("%f", &p);
    for (double a = 0.5; a <= 2; a += 0.5) {
        printf("\t a = %.2f\n", a);
        double maxY = INT_MIN, maxX = 0, minY = INT_MAX, minX = 0;
        for (double x = 1; x < 2.1; x += 0.1) {
            const float y = a * sqrt(x) - cos(p * (x / 2));
            printf("x= %.3f y = %.3f\n", x, y);
            if (y > maxY) {
                maxY = y;
                maxX = x;
            }
            if (y < minY) {
                minY = y;
                minX = x;
            }
        }
        printf("*************\n");
        printf("maxY=%.3f\n", maxY);
        printf("maxX=%.3f\n", maxX);
        printf("minY=%.3f\n", minY);
        printf("minX=%.3f\n", minX);
        printf("==============\n");
    }
    return 0;
}