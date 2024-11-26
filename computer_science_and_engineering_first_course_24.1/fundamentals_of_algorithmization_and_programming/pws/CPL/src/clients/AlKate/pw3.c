//
// Created by fred on 25.11.2024.
//
#include <stdio.h>
#include <math.h>
#include <limits.h>

int AlKatePW3() {
    for (int a = 1; a <= 10; a += 3) {
        printf("\t a = %d\n", a);// \t это tab, а \n это перевод на следующую строку
        /*
         * Для переменной maxY указываем минимально возможное число, потому что любое число в результате вычислений будет больше указанного.
         * Для переменной minY все наоборот
         * А maxX и minX указываем 0, потому что программа в основном будет работать с y, maxY и minY
         */
        double maxY = INT_MIN, maxX = 0, minY = INT_MAX, minX = 0;
        for (double x = 0.5; x < 2.1; x += 0.1) {
            const float y = pow(x, 4) + a * atan(x);
            printf("x= %.3f y = %.3f\n", x, y);// %.3f - означает 3 значения после запятой
            /*
             * Если значение y больше, чем значение maxY, то обновляем значение maxY.
             * К тому же запоминаем в переменной maxX значение x, при котором maxY является максимальным значением y
             * Также с minY и minX
             */
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