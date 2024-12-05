//
// Created by fred on 06.12.2024.
//
#include <stdio.h>

int AlexIW1() {
    char M[7][12];
    int i, j = 0, m = 0;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 12; j++) {
            M[i][j] = ' ';
        }
    }
    j = 0;
    do {
        M[5][2 + j] = 'A' + j;
        j++;
    } while (j < 12);
    for (i = 6; i >= 2; i--) {
        for (j = 0; j <= 1; ++j) {
            M[i][6 - i + j] = M[i][4+i-j] = (j + i) % 2 ? '#' : '*';
        }
    }
    while (m < 6) {
        switch(m % 3) {
            case 0:
                M[m / 3][4 + m % 3] = '(';
                break;
            case 1:
                M[m / 3][4 + m % 3] = '-';
                break;
            case 2:
                M[m / 3][4 + m % 3] = ')';
                break;
            default:
                break;
        }
        ++m;
    }
    for (i = 0; i < 7; i++) {
        printf("%s\n", M[i]);
    }
    return 0;
}