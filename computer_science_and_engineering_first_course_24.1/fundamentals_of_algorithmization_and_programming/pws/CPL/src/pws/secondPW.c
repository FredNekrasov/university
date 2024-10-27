//
// Created by fred on 21.10.2024.
//
#include <stdio.h>
#include <tgmath.h>

int calculateCircleLenth() {
    int r;
    printf("enter the radius of the circle: ");
    scanf_s("%d", &r);
    printf("the length of the circle is equal to: %.2f", 2 * M_PI * r);
    return 0;
}
int printMyData() {
    printf("Hello, World!\n");
    printf("Hello, World!\nAsylbek uulu Bakyt - 09.03.01 24/1 sg/2");
    return 0;
}
int calculateLenthBetweenTwoPoints() {
    printf("Hello, World!\n");
    printf("a program to calculate the length between two points\n");
    float xa, ya, xb, yb;
    printf("input a coordinates of x point a:");
    scanf_s("%f", &xa);
    printf("\ninput a coordinates of y point a:");
    scanf_s("%f", &ya);
    printf("\ninput a coordinates of x point b:");
    scanf_s("%f", &xb);
    printf("\ninput a coordinates of y point b:");
    scanf_s("%f", &yb);
    const float ab = sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
    printf("the length between two points is equal to: %.2f", ab);
    return 0;
}