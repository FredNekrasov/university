//
// Created by fred on 20.10.2024.
//
#include <stdio.h>
#include <stdlib.h>
// В квадратной матрице с числом строк не более 15 найти:
// максимальный элемент для каждой строки;
// подсчитать сумму найденных элементов;
// выбрать минимальный из них.
int sixthPW3Task() {
    srand(3u);
    int n = 0, m = 0;
    printf("input n, m:");
    scanf_s("%d%d", &n, &m);
    if (n > 15 || m > 15) return printf("error: n or m > 15");
    int array[n][m];
    for (int i = 0; i < n; i++) {
        printf("|");
        for (int j = 0; j < m; j++) {
            array[i][j] = rand() % 10;
            printf(" %d |", array[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        int max = 0;
        for (int j = 0; j < m; j++) {
            if (array[i][j] > max) max = array[i][j];
        }
        printf("max element in %d row = %d\n", i, max);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += array[i][j];
        }
    }
    printf("sum of all elements = %d\n", sum);
    int min = array[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (array[i][j] < min) min = array[i][j];
        }
    }
    printf("min = %d\n", min);
    return 0;
}