//
// Created by fred on 15.10.2024.
//
#include <stdio.h>
#include <stdlib.h>

void outputIntArray(const int n, int array[]) {
    for (int i = 0; i < n; i++) printf("%d ", array[i]);
}
void outputFloatArray(const int n, float array[]) {
    for (int i = 0; i < n; i++) printf("%.3f ", array[i]);
}
bool isZero(const int n) {
    return n == 0;
}
bool isEven(const int n) {
    return n % 2 == 0;
}
float sumOfArrayElements(const float array[], const int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) sum += array[i];
    return sum;
}
float calculateMedian(float array[], const int n) {
    // Сортировка первого массива для нахождения медианы
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                const float temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    if (isEven(n)) return  (array[n / 2 - 1] + array[n / 2]) / 2;
    return array[n / 2];
}
int fifthPW3Task() {
    srand(3u);
    int n = 0;
    printf("input n: ");
    scanf_s("%d", &n);
    if (n > 13) return printf("error: n > 13");
    int array1[n], array2[n];
    for (int i = 0; i < n; i++) array1[i] = rand() % 10;
    for (int i = 0; i < n; i++) array2[i] = rand() % 10;
    printf("\narray1: ");
    outputIntArray(n, array1);
    printf("\narray2: ");
    outputIntArray(n, array2);

    float* array3 = calloc(n, sizeof(float));
    if (array3 == NULL) {
        free(array3);
        return printf("error: array3 is NULL");
    }
    for (int i = 0; i < n; i++) {
        if (!isZero(array2[i])) array3[i] = (float)array1[i] / (float)array2[i];
    }
    printf("\narray3: ");
    outputFloatArray(n, array3);
    const float median = calculateMedian(array3, n);
    printf("\nmedian: %.3f", median);
    const float sum = sumOfArrayElements(array3, n);
    const float average = sum / (float)n;
    printf("\naverage: %.3f", average);

    const float deviation = average - median;
    printf("\ndeviation: %.3f", deviation);
    free(array3);
    return 0;
}