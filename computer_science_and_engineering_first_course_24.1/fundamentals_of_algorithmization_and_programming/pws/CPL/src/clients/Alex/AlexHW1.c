//
// Created by fred on 06.12.2024.
//
#include <stdio.h>

void printMatrix(char M[10][11], int Ni, int Nj) {
    printf("   ");
    for (int i = 0; i < Nj; ++i) {
        printf(" %d  ", i);
    }
    printf("\n");
    for (int i = 0; i < Ni; ++i) {
        printf("%d |", i);
        for (int j = 0; j < Nj; ++j) {
            printf(" %c |", M[i][j]);
        }
        printf("\n");
    }
}
void F2(char M[10][11], int i0, int j0, int N, char c) {
    for (int i = 0; i < N; ++i) M[i0 + i][j0] = c;
    printMatrix(M, 10, 11);
}
void F3(char M[10][11], int i0, int j0, int Ni, int Nj, char c) {
    for (int i = 0; i < Ni; ++i)
        for (int j = 0; j < Nj; ++j)
            M[i0 + i][j0 + j] = c;
    printMatrix(M, 10, 11);
}
void F17(char M[10][11], int i0, int j0, int Ni, int Nj, char c) {
    for (int i = 0; i < Ni; ++i) {
        M[i0 + i][j0] = M[i0 + i][j0 + Nj - 1] = c;
    }
    for (int j = 0; j < Nj; ++j) {
        M[i0][j0 + j] = M[i0 + Ni - 1][j0 + j] = c;
    }
    printMatrix(M, 10, 11);
}
void F18(char M[10][11], int i0, int j0, int Ni, int Nj, char c) {
    for (int i = 0; i < Ni; ++i)
        for (int j = 0; j < Nj; ++j) M[i0 - j - i][j0 + j] = c;
    printMatrix(M, 10, 11);
}
void testF() {
    char M[10][11] = { 0 };
    printf("\n\n\nF2:\n");
    F2(M, 4, 1, 6, '[');
    char N[10][11] = { 0 };
    printf("\n\n\nF3:\n");
    F3(N, 4, 7, 5, 3, 'y');
    char B[10][11] = { 0 };
    printf("\n\n\nF17:\n");
    F17(B, 4, 2, 4, 4, '%');
    char V[10][11] = { 0 };
    printf("\n\n\nF18:\n");
    F18(V, 7, 1, 4, 2, '+');
}
/*
 * how to create char matrix that contains this using C:
 *     0   1   2   3   4   5   6   7   8   9
 * 0 |   |   |   | * | * | * |   |   |   |   |
 * 1 |   |   | / | * | . | * |   |   |   |   |
 * 2 |   | / | / | * | . | * |   |   |   |   |
 * 3 | / | / | / | * | . | * |   |   |   |   |
 * 4 | / | / |   | * | . | * |   |   |   |   |
 * 5 | / |   |   | * | . | * |   |   |   |   |
 * 6 |   |   |   | * | . | * |   |   |   |   |
 * 7 |   |   |   | * | * | * |   |   |   |   |
 * 8 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
 * 9 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
 */
void AlTask2() {
    int i = 0, j = 0;
    char M[10][11] = { 0 };
    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            M[i][j] = ' ';
        }
    }
    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            if ((i + j) >= 3 && (i + j) <= 5) M[i][j] = '/';
            if (i < 8) {
                if (j >= 3 && j <= 5) M[i][3] = M[i][4] = M[i][5] = '*';
                if (i > 0 && i < 7) M[i][4] = '.';
            } else M[i][j] = '~';
        }
    }
    printf("pretty print:\n");
    printMatrix(M, 10, 11);
    printf("\nsimple print:\n");
    for (i = 0; i < 10; ++i) printf("%s\n", M[i]);
    // or
    char V[10][11] = { 0 };
    F18(V, 5, 0, 3, 3, '/');
    F17(V, 0, 3, 8, 3, '*');
    F2(V, 1, 4, 6, '.');
    F3(V, 8, 0, 2, 11, '~');
    printMatrix(V, 10, 11);
}
int A(int x) {
    if (x > 7) return 1; else return 0;
}
int B(int x) {
    int r = 0;
    if (x <= 25) r = 1; return r;
}
int C(int x) {
    return (x != 6) ? 1:0;
}
int D(int x) {
    return (x < 15 && x >= 8);
}
int E(int x) {
    if (x < 5 || x >= 20) return 1;
    return 0;
}
int F(int x) {
    int r;
    r = (x < 0 || x>=10 && x>22) ? 1 :0;
    return r;
}
void G() {
    printf("| %d | %d | %d | %d | %d |\n", E(5), C(8), A(8), F(26), B(3));
    printf("| %d | %d | %d | %d | %d |\n", D(5), F(-2), D(9), C(3), E(20));
    printf("| %d | %d | %d | 1 | %d |\n", B(30), C(6), E(4), A(5));
    printf("| %d | %d | %d | %d | %d |\n", E(7), A(12), B(25), F(23), D(8));
    printf("| %d | %d | %d | %d | %d |\n", D(20), F(8), A(3), B(41), C(6));
}
void AlTask3P1() {
    int i = 0, j = 0;
    char M[10][11] = { 0 };
    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            M[i][j] = ' ';
        }
    }
    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            if (i > 2 && i < 9) {
                M[i][1] = M[i][2] = M[i][3] = '0';
                if (i > 5 && j > 2 && j < 7) M[i][j] = M[i][j] = M[i][j] = '0';
            }
        }
    }
    printf("pretty print:\n");
    printMatrix(M, 10, 11);
    printf("\nsimple print:\n");
    for (i = 0; i < 10; ++i) printf("%s\n", M[i]);
}
void AlTask3P2() {
    int i = 0, j = 0;
    char M[10][11] = { 0 };
    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            M[i][j] = ' ';
        }
    }
    for (i = 0; i < 10; ++i) {
        for (j = 0; j < 10; ++j) {
            if (j <= i) M[i][j] = '*';
        }
    }
    printf("pretty print:\n");
    printMatrix(M, 10, 11);
    printf("\nsimple print:\n");
    for (i = 0; i < 10; ++i) printf("%s\n", M[i]);
}
int A2(int X) {
    return X & 74;
}
int B2(int X) {
    return X ^ 56;
}
int C2(int X, int Y) {
    return X & Y;
}
int D2(int X, int Y) {
    return X ^ Y;
}
int E2(int X, int Y) {
    return (X | Y) & 100;
}
int F1(int X, int Y, int Z) {
    return (X | Y) ^ Z;
}
void testSymbols() {
    printf("| %d | %d | %d | %d |\n", A2(21), C2(18,96), F1(4,9,13), C2(37,61));
    printf("| %d | %d | %d | %d | %d |\n", F1(2,5,7), D2(11,11), E2(8,3), B2(6), D2(7,8));
    printf("| %d | %d | %d | %d | %d |\n", B2(56), F1(11,21,31), A2(8), E2(128,1), B2(56));
    printf("| %d | %d | %d | %d | %d |\n", E2(32,12), F1(10,13,7), D2(38,38), F1(24,7,31), D2(19,19));
    printf("| %d | %d | %d | %d | %d |\n", A2(2), C2(48,25), B2(56), C2(20,2), A2(16));
}