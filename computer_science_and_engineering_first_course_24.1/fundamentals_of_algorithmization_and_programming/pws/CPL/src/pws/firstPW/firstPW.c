//
// Created by fred on 29.09.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

void task1() {
    printf_s("linear processes");
    int x = 0;
    scanf_s("%d", &x);
    const float y = (abs(x) + pow(sin(x - 3), 2)) / pow(5 * x, 3);
    printf_s("y = %f\n", y);
}
void task2P1() {
    printf_s("Branching computing processes");
    int x = 0;
    scanf_s("%d", &x);
    float y = 0;
    if (x <= 3) {
        y = pow(sin(x), 2) - 3;
    } else y = pow(log(x), 0.5) + pow(cos(x), 2);
    //const float y = x <= 3 ? pow(sin(x), 2) - 3 : pow(log(x), 0.5) + pow(cos(x), 2);
    printf_s("y = %f\n", y);
}
void task2P2() {
    printf_s("Branching computing processes");
    float y = 0, z = 0;
    scanf_s("%f", &y);
    if (1 <= y <= 2) {
        z = pow(y, 1 / 3) + exp(y);
    } else if (3 < y <= 5) {
        z = y + 2;
    } else if (y > 7) {
        z = atan(y) - pow(y, 1 / 3);
    }
    printf_s("z = %f\n", z);
}
void task3() {
    printf_s("cyclic processes");
    for (float x = 0.5f; x < 3.5; x += 0.5f) {
        const float y = sin(x) + fabsf(x) + pow(2, x);
        printf_s("y = %.2f\n", y);
    }
}
void task4() {
    printf_s("tabulating functions of 2 variables");
    float a = -3.1f;
    for (float x = 0; x <= 1; x += 0.1f) {
        for (float t = 0; t <= M_PI_2; t += 0.3f) {
            const float y = a * pow(M_E, 2 * x * t) * cos(M_PI_2 + t);
            printf_s("x = %.1f, t = %.1f, y = %.2f\n", x, t, y);
        }
    }
}
void task5P1() {
    printf_s("calculating the sum\n");
    int x = 0, sumN = 0;
    scanf_s("%d", &x);
    for (int n = 1; n <= 10; n++) {
        sumN += n;
    }
    const float y = (pow(sumN, 2) + sin(x)) / (x + 2);
    printf_s("y = %.2f\n", y);
}
void task5P2() {
    printf_s("calculating the multiplication\n");
    int y = 0, multiplyN = 1;
    scanf_s("%d", &y);
    for (int n = 1; n <= 3; n++) {
        multiplyN *= n;
    }
    const float z = pow(y, 3) + pow(multiplyN, 2);
    printf_s("z = %.2f\n", z);
}
void task6() {
    printf_s("tabulating the function and finding the min, max\n");
    float a = 0, b = 0, min = INT_MAX, max = INT_MIN, y = 0, p = 1, s = 0;
    for (int k = 1; k <= 5; k++) {
        p *= pow(k, 3);
    }
    for (float i = 0; i < 3; i += 0.2f) {
        scanf_s("%f %f", &a, &b);
        const float x = sqrt(a) + 2 * a * b + cos(a);
        if (x < 3) {
            for (int n = 1; n <= 10; n++) {
                s += cos(n * x);
            }
            y = pow(x, 2) + s;
        } else if (4 <= x <= 5) {
            y = x + 3 * pow(tan(x), 2);
        } else if (x > 6) {
            y = p + pow(M_E, x);
        }
        if (y < min) min = y;
        if (y > max) max = y;
        printf("x = %.2f, y = %.2f\n", x, y);
    }
    printf("min = %.2f, max = %.2f\n", min, max);
}
// In an array of n elements, determine:
// the sum of positive elements,
// find the max element and its index,
// build a new array of elements whose value is greater than the specified number of P.
void task7() {
    printf_s("array of n elements\ninput n: ");
    int n = 0, sum = 0, max = 0, maxIndex = 0;
    scanf_s("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
        if (arr[i] > 0) sum += arr[i];
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }
    printf("sum = %d, max = %d, maxIndex = %d\n", sum, max, maxIndex);
    printf_s("input p: ");
    int p = 0;
    scanf_s("%d", &p);
    int newArr[n];
    for (int i = 0; i < n; i++) {
        newArr[i] = arr[i] > p ? arr[i] : 0;
    }
    printf("new array: ");
    for (int i = 0; i < n; i++) {
        if (newArr[i] == 0) continue;
        printf("%d ", newArr[i]);
    }
}
// В матрице nxm найти min элемент и его индексы,
// построить вектор из максимальных элементов по строкам,
// найти среднее положительных элементов матрицы
void task8() {
    printf_s("matrix nxm\ninput n, m: ");
    int n = 0, m = 0;
    scanf_s("%d%d", &n, &m);
    int matrix[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }
    int min = INT_MAX, minI = 0, minJ = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                minI = i, minJ = j;
            }
        }
    }
    printf("min = %d, minI = %d, minJ = %d\n", min, minI, minJ);
    int maxVector[n > m ? n : m];
    for (int i = 0; i < n; i++) {
        maxVector[i] = 0;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] > maxVector[i]) {
                maxVector[i] = matrix[i][j];
            }
        }
    }
    printf("maxVector: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", maxVector[i]);
    }
    printf("\n");
    // найти среднее положительных элементов матрицы
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] > 0) {
                sum += matrix[i][j];
                count++;
            }
        }
    }
    const float average = (float)sum / (float)count;
    printf("average positive elements = %.2f\n", average);
}