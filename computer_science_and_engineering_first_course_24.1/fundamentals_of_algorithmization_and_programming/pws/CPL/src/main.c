#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

int* createIntArray(const int n) {
    int* array = calloc(n, sizeof(int));
    if (array == NULL) {
        free(array);
        return nullptr;
    }
    for (int i = 0; i < n; i++) array[i] = rand() % 10;
    return array;
}
float* createFloatArray(const int n, int* array1, int* array2) {
    float* array = calloc(n, sizeof(float));
    if (array == NULL) {
        free(array);
        return nullptr;
    }
    for (int i = 0; i < n; i++) array[i] = rand() % 10;
    return array;
}
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

    float* array3 = calloc(n, sizeof(float));
    if (array3 == NULL) {
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

    const float deviation = average - median;
    printf("\ndeviation: %.3f", deviation);
    free(array3);
    return 0;
}
int main() {
    printf("Hello, World!\n");
    fifthPW3Task();
    return 0;
}

void independentWork() {
    float y = 0;
    for (int a = 1; a <= 3; a += 1) {
        float maxY = -1 * exp(24);
        float maxX = 0;
        float minY = exp(24);
        float minX = 0;
        printf("a = %d\n", a);
        for (float x = 0.5f; x < 3.5; x += 0.5f) {// здесь интервал меняем
            y = sin(x) + fabsf(x) + pow(2, x);// здесь формулу поменять
            printf("x = %.2f, y = %.2f\n", x, y);
            if (y > maxY) {
                maxY = y;
                maxX = x;
            }
            if (y < minY) {
                minY = y;
                minX = x;
            }
        }
        printf("maxX = %.2f, maxY = %.2f\nminX = %.2f, minY = %.2f\n", maxX, maxY, minX, minY);
    }
}