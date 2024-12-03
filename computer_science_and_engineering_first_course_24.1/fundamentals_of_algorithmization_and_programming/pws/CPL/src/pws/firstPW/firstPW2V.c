//
// Created by fred on 30.09.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void secondVTask1() {
    printf_s("linear processes\ninput x and a: ");
    float x = 0, a = 0;
    scanf_s("%f%f", &x, &a);
    const float y = sin(a * x) + pow(M_E, x) + 2 * log(x);
    printf_s("y = %f\n", y);
}
void secondVTask2P1() {
    printf_s("Branching computing processes\ninput x: ");
    float x = 0;
    scanf_s("%f", &x);
    float y = 0;
    if (x < 3) {
        y = sin(x) * pow(2, x);
    } else y = pow(x, 3) + x * 0.5f;
    printf_s("y = %f\n", y);
}
void secondVTask2P2() {
    printf_s("Branching computing processes\ninput y: ");
    float y = 0, z = 0;
    scanf_s("%f", &y);
    if (y < 5) {
        z = pow(y, 3) + cos(fabsf(y)) - 2;
    } else if (6 <= y || y <= 7) {
        z = y * 0.5f + log(y);
    } else if (y > 7) {
        z = atan(y);
    }
    printf_s("z = %f\n", z);
}
void secondVTask3() {
    printf_s("cyclic processes");
    for (float x = 1; x < 2; x += 0.1f) {
        const float y = pow(sin(x), 0.5) + pow(M_E, x) - 3;
        printf_s("y = %.2f\n", y);
    }
}
void secondVTask4() {
    printf_s("tabulating functions of 2 variables");
    float a = 0.75f;
    for (float x = -1; x <= 1; x += 0.2f) {
        for (float t = 1; t <= 5; t += 1.5f) {
            const float y = a * pow(M_E, -x) * sin(x * x) + sqrt( a + t);
            printf_s("x = %.1f, t = %.1f, y = %.2f\n", x, t, y);
        }
    }
}
void secondVTask5P1() {
    printf_s("calculating the sum\ninput x: ");
    float x = 0, sumN = 0;
    scanf_s("%f", &x);
    for (int i = 1; i <= 5; i++) {
        sumN += log(i * x);
    }
    const float y = 2 * sumN + pow(x, 5);
    printf_s("y = %.2f\n", y);
}
void secondVTask5P2() {
    printf_s("calculating the multiplication\ninput x: ");
    float x = 0, multiplyN = 1;
    scanf_s("%f", &x);
    for (int k = 1; k <= 3; k++) {
        multiplyN *= sin(k * x);
    }
    const float z = multiplyN + 2;
    printf_s("z = %.2f\n", z);
}
void secondVTask6() {
    printf_s("tabulating the function and finding the min, max\n");
    float x = 0, min = INT_MAX, max = INT_MIN;
    for (float i = 1; i <= 5; i += 0.5f) {
        float z = 0, s = 0, p = 1;
        printf_s("input x: ");
        scanf_s("%f", &x);
        const float y = pow(x, 5) + 2 * x - cos(x);
        if (y < 3) {
            for (int j = 1; j <= 10; j++) {
                s += cos(j * y);
            }
            z = fabsf(y) + s;
        } else if (4 <= y || y <= 5) {
            for (int m = 1; m <= 5; m++) {
                p = log(m * y);
            }
            z = p + fabsf(y);
        } else if (x > 7) {
            z = y + 3;
        }
        if (y < min) min = y;
        if (y > max) max = y;
        printf("y = %.2f, z = %.2f\n", y, z);
    }
    printf("min = %.2f, max = %.2f\n", min, max);
}
// В массиве из 50 случайных элементов. Определить: сумму элементов, max и min элементы.
// Построить вектор из отрицательных элементов исходного массива.
void secondVTask7() {
    srand(time(nullptr));
    printf_s("array 50 elements\n");
    int array[50];
    for (int i = 0; i < 50; i++) {
        /*
         * rand() % 100 - 50 - генерация чисел в диапазоне от -50 до 49
         */
        array[i] = rand() % 100 - 50;
        printf_s("%d ", array[i]);
    }
    int sum = 0, max = array[0], min = array[0];
    for (int i = 0; i < 50; i++) {
        sum += array[i];
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
    }
    printf("sum = %d, max = %d, min = %d\n", sum, max, min);
    int negativeVector[50];
    int count = 0;
    for (int i = 0; i < 50; i++) {
        if (array[i] < 0) {
            negativeVector[count] = array[i];
            count++;
        }
    }
    printf("negative vector: ");
    for (int i = 0; i < count; i++) {
        printf_s("%d ", negativeVector[i]);
    }
    printf("\n");
}
// В матрице nxm найти среднее элементов, max элемент и его индексы.
// Построить вектор из отрицательных элементов по матрицы
void secondVTask8() {
    printf_s("matrix nxm\ninput n, m: ");
    int n = 0, m = 0;
    scanf_s("%d%d", &n, &m);
    int matrix[n][m];
    // fill matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }
    // find average, max element and its indices
    int sumOfElements = 0, max = matrix[0][0], maxI = 0, maxJ = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sumOfElements += matrix[i][j];
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }
    const float average = (float)sumOfElements / (float)(n * m);
    printf("\naverage = %.2f, max = %d, maxI = %d, maxJ = %d\n", average, max, maxI, maxJ);
    int negativeVector[m * n];
    // create negative vector
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < 0) {
                negativeVector[count] = matrix[i][j];
                count++;
            }
        }
    }
    printf("negative vector: ");
    for (int i = 0; i < count; i++) {
        printf_s("%d ", negativeVector[i]);
    }
}