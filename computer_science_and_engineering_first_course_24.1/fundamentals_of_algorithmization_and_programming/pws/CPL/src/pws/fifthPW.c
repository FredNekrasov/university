//
// Created by fred on 15.10.2024.
//
#include <stdio.h>
#include <stdlib.h>

int* createIntArray(const int n) {
    int* array = calloc(n, sizeof(int));
    if (array == NULL) {
        free(array);
        return nullptr;
    }
    for (int i = 0; i < n; i++) array[i] = rand() % 10;
    return array;
}
float* createFloatArray(int n, const int* array1, const int* array2) {
    float* array = calloc(n, sizeof(float));
    if (array == NULL) {
        free(array);
        return nullptr;
    }
    for (int i = 0; i < n; i++) {
        if (array2[i] != 0) array[i] = (float)array1[i] / (float)array2[i];
    }
    return array;
}
void outputIntArray(const int n, int array[]) {
    for (int i = 0; i < n; i++) printf("%d ", array[i]);
}
void outputFloatArray(const int n, float array[]) {
    for (int i = 0; i < n; i++) printf("%.3f ", array[i]);
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
                float temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    // printf("\n%.2f\n", array[n / 2]);
    // printf("\n%.2f\n", array[n / 2 - 1]);
    // outputFloatArray(n, array);
    if (n % 2 == 0) return  (array[n / 2 - 1] + array[n / 2]) / 2;
    return array[n / 2];
}
int fifthPW3Task() {
    srand(3u);
    int n = 0;
    printf("input n: ");
    scanf_s("%d", &n);
    if (n > 13) return printf("error: n > 13");
    int *array1 = createIntArray(n), *array2 = createIntArray(n);
    if (array1 == NULL || array2 == NULL) {
        free(array1);
        free(array2);
        return printf("error: array1 and array2 are NULL");
    }
    printf("\narray1: ");
    outputIntArray(n, array1);
    printf("\narray2: ");
    outputIntArray(n, array2);

    float* array3 = createFloatArray(n, array1, array2);
    if (array3 == NULL) {
        free(array1);
        free(array2);
        free(array3);
        return printf("error: array3 is NULL");
    }
    printf("\narray3: ");
    outputFloatArray(n, array3);

    const float median = calculateMedian(array3, n);
    printf("\nmedian: %.3f", median);
    const float sum = sumOfArrayElements(array3, n);
    const float average = sum / (float)n;
    printf("\naverage: %.3f", average);

    const float deviation = median - average;
    printf("\ndeviation: %.3f", deviation);
    free(array1);
    free(array2);
    free(array3);
    return 0;
}