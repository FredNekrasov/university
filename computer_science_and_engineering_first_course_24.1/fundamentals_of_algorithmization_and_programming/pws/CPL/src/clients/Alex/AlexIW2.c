//
// Created by fred on 09.12.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Занести в массив значения функции f(x, y) = max(x / 2, y / 3, y - x), 0 <= x <= 8, 0 <= y <= 6 и вывести на экран
float f(float x, float y) {
    if (x <= 0 || x >= 8 || y <= 0 || x >= 6) return 0;
    float val1 = x / 2, val2 = y / 3, val3 = y - x;
    if (val1 > val2 && val1 > val3) return val1;
    if (val2 > val1 && val2 > val3) return val2;
    return val3;
}
int AlIW1Task() {
    srand(time(nullptr));
    int n = 0;
    printf("input n:");
    scanf_s("%d", &n);
    if (n <= 0) return printf("error: n <= 0");
    float array[n];
    printf("array: ");
    for (int i = 0; i < n; ++i) {
        array[i] = f(rand() % 10, rand() % 10);
        printf("%.3f ", array[i]);
    }
    return 0;
}
// Дана матрица размером 10х10, заполненный случайными числами. Вычислить сумму элементов главной диагонали
int AlIW2Task() {
    srand(time(nullptr));
    int n = 3, sum = 0;
    int array[n][n];
    printf("array:");
    for (int i = 0; i < n; ++i) {
        printf("\n|");
        for (int j = 0; j < n; ++j) {
            array[i][j] = rand() % 10;
            printf(" %d |", array[i][j]);
        }
        sum += array[i][i];
    }
    printf("\nsum = %d", sum);
    return 0;
}
// Найти значение максимального элемента массива и число его вхождений в массив
int AlIW3Task() {
    srand(time(nullptr));
    int n;
    printf("input n:");
    scanf_s("%d", &n);
    if (n <= 0) return printf("error: n <= 0");
    int array[n], maxIndex = 0;
    printf("array:");
    for (int i = 0; i < n; ++i) {
        array[i] = rand() % 10;
        printf(" %d", array[i]);
        // поиск максимального элемента в массиве
        if (array[i] >= array[maxIndex]) maxIndex = i;
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        /*
         * Считаем количество вхождений в массив максимального элемента
         * Число вхождений в массив - это количество раз, которое заданное значение(в данном случае максимальное число) встречается в данном массиве.
         */
        if (array[i] >= array[maxIndex]) count++;
    }
    printf("\nmax = %d, count = %d", array[maxIndex], count);
    return 0;
}
// Создайте матрицу mxm, значение каждого элемента которой равно сумме номера строки и номера столбца, на пересечении которых он находится, и вычислите сумму элементов каждой строки
int AlIW4Task() {
    srand(time(nullptr));
    int n;
    printf("input n:");
    scanf_s("%d", &n);
    if (n <= 0) return printf("error: n <= 0");
    int array[n][n], sum = 0;
    printf("array:");
    for (int i = 0; i < n; i++) {
        printf("\n|");
        sum = 0;
        for (int j = 0; j < n; j++) {
            array[i][j] = (i + 1) + (j + 1);
            sum += array[i][j];
            printf(" %d |", array[i][j]);
        }
        printf(" sum = %d", sum);
    }
    return 0;
}