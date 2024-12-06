//
// Created by fred on 06.12.2024.
//
#include <stdio.h>

/* x  xn %c
 * 9  9  Т
 * 2  6  Р
 * 6  10 Е
 * 4  8  Н
 * 15 13 И
 * 12 9  T
 */
void ValT1() {
    printf("Hello, World!\n");
    char TC[16] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P' };
    int x;
    printf("Enter x: ");
    scanf_s("%d", &x);
    if (x >= 2) {
        if (x <= 6) x += 4;
    }
    if (x > 10) {
        x--;
    } else if (x <= 12) x--;
    if (x < 4) {
        if (x > 13) x += 5;
    }
    if (x <= 3 || x > 10) x -= 2;
    printf("%d | %c\n", x, TC[x]);
}
void ValT2() {
    printf("Hello, World!\n");
    char TB[8][8] = { 0 };
    int i = 0, j = 0, x = 0;
    printf("Enter x: ");
    scanf_s("%d", &x);
    for (i = 0; i < 7; ++i) {
        if (i <= 3) x = i + i % 2;
        else x = i - i % 3;
        for (j = x; j < 7; j += 2) {
            TB[i][j] = 0;
            if (j == i) TB[7][j] = 0;
            if (j == x) TB[0][j] = 0;
        }
        if (i % 2 == 0) {
            if (TB[i][i] == 0) {//я не понял, откуда у вас тут M, но я поменял его на TB
                TB[i][i - 3] = 1;
            } else TB[i][i] = 0;
        } else {
            for (j = 1; j < 5; j += 2) {
                if (TB[i][j] == 0) {
                    TB[i][j - 1] = 0;
                } else TB[i][j] = 0;
            }
        }
        if (i < 4) {
            if (i < 2) {
                TB[1][3 + i * 2] = 0;
                TB[5 + i][6 + i] = 0;
            } else TB[i][7] = 0;
        } else {
            if (i < 6) {
                TB[5][i - 4] = 0;
                TB[3][i - 3] = 0;
            } else TB[i][4] = 0;
        }
    }
    for (j = 0; j < 7; j++) {
        for (i = 0; i < 7; i++) {
            if (TB[i][j] != 0) printf("%d ", TB[i][j]);
        }
    }
}
void ValT3() {
    printf("Hello, World!\n");
    int i = 4;
    do {
        if (i < 24) {
            if (i == 4) i += 6;
            else i += 5;
        } else {
            if (i > 300) i += 4;
            else i += 1;
        }
        printf("qwerty %d\n", i);
    } while (i != 28);
}