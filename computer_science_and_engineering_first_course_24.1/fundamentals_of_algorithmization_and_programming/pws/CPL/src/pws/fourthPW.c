//
// Created by fred on 13.10.2024.
//
#include <stdio.h>
#include <stdlib.h>
// Даны два массива.
// Найти отклонение медианы от среднего арифметического для третьего массива, элементы которого - частное от деления соответствующих элементов 1-го массива на 2-ой(исключайте деление на ноль).
// Число элементов в массиве не более 13. Формат числа ццц.
int fourthPW3Task() {
    srand(3u);
    int n = 0;
    printf("input n: ");
    scanf_s("%d", &n);
    if (n > 13) return printf("error: n > 13");
    int array1[n], array2[n];
    float array3[n];
    for (int i = 0; i < n; i++) array1[i] = rand() % 10;
    for (int i = 0; i < n; i++) array2[i] = rand() % 15;
    printf("\narray1: ");
    for (int i = 0; i < n; i++) printf("%d ", array1[i]);
    printf("\narray2: ");
    for (int i = 0; i < n; i++) printf("%d ", array2[i]);
    for (int i = 0; i < n; i++) {
        if (array2[i] != 0) array3[i] = (float)array1[i] / (float)array2[i];
    }
    // Сортировка третьего массива для нахождения медианы
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array3[i] > array3[j]) {
                const float temp = array3[i];
                array3[i] = array3[j];
                array3[j] = temp;
            }
        }
    }
    printf("\narray3: ");
    for (int i = 0; i < n; i++) printf("%.3f ", array3[i]);
    float median = 0, sum = 0;
    if (n % 2 == 0) {// Если количество элементов четное, то выбираем среднее арифметическое двух средних элементов
        median = (array3[n / 2 - 1] + array3[n / 2]) / 2;
    } else median = array3[n / 2];// Если количество элементов нечетное, то выбираем среднее арифметическое
    printf("\nmedian: %.3f", median);
    for (int i = 0; i < n; i++) sum += array3[i];
    const float average = sum / (float)n;
    printf("\naverage: %.3f", average);
    const float deviation = average - median;
    printf("\ndeviation: %.3f", deviation);
    return 0;
}