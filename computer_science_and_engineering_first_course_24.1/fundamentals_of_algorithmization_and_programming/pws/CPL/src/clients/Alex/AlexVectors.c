//
// Created by fred on 27.10.2024.
// Обработка одномерных массивов
#include <stdlib.h>
#include <stdio.h>

// 1. Подсчитать разность сумм четных и нечетных элементов массива (элементов с четными и нечетными значениями).
int AlexV1Task() {// AlexVectorsFirstTask
    int n = 0;// количество элементов в массиве
    printf("input n:");
    scanf_s("%d", &n);// ввод количества элементов
    srand(n);// инициализация генератора случайных чисел
    int array[n];// объявление массива с n элементами
    printf("array: ");
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 10;// заполнение массива случайными числами от 0 до 9
        printf("%d ", array[i]);// вывод элемента массива
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] % 2 == 0) {// проверка значения массива на четность
            sum1 += array[i];// сумма четных значений элементов массива
        } else sum2 += array[i];// сумма нечетных значений элементов массива
    }
    printf("\nsum1 = %d, sum2 = %d\n", sum1, sum2);// вывод сумм четных и нечетных элементов
    printf("sum1 - sum2 = %d\n", sum1 - sum2);// вывод разности сумм четных и нечетных элементов
    return 0;
}
// 2. Найти значение максимального элемента среди четных (по значению) элементов, расположенных до первого нечетного элемента.
int AlexV2Task() {// AlexVectorsSecondTask
    int n = 0;// количество элементов в массиве
    printf("input n:");
    scanf_s("%d", &n);// ввод количества элементов
    srand(n);// инициализация генератора случайных чисел
    int array[n];// объявление массива с n элементами
    printf("array: ");
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 10;// заполнение массива случайными числами от 0 до 9
        printf("%d ", array[i]);// вывод элемента массива
    }
    int max = 0;// переменная, хранящая максимальное значение
    for (int i = 0; i < n; i++) {
        if (array[i] % 2 == 1) break;// выход из цикла, если найден первый нечетный элемент
        if (array[i] > max) {// проверка на максимальное значение
            max = array[i];// обновление максимального значения
        }
    }
    printf("\nmax = %d", max);// вывод максимального значения
    return 0;
}
// 3. Удалить все четные элементы массива. Например,
// массив                 7 2 6 5 4 4 10 3 9
// четные элементы          2 6   4 4 10
// массив после удаления  7 5 3 9
int AlexV3TaskV1() { // AlexVectorsThirdTaskVersion1
    int n = 0;// количество элементов в массиве
    printf("input n:");
    scanf_s("%d", &n);// ввод количества элементов
    srand(n);// инициализация генератора случайных чисел
    int array[n];// объявление массива с n элементами
    printf("array: ");
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 10;// заполнение массива случайными числами от 0 до 9
        printf("%d ", array[i]);// вывод элемента массива
    }
    printf("\neven elements: ");
    for (int i = 0; i < n; ++i) {
        if (array[i] % 2 == 0) {// если элемент делится на 2 без остатка, то элемент четный
            printf("%d ", array[i]);// вывод четных элементов
            array[i] = 0;// удаление четных элементов
        }
    }
    printf("\narray after deleting even elements: ");
    for (int i = 0; i < n; i++) {
        if (array[i] != 0) {// проверка на то, что элемент не равен 0
            printf("%d ", array[i]);// вывод элемента массива
        }
    }
    return 0;
}
int AlexV3TaskV2() { // AlexVectorsThirdTaskVersion2
    int n = 9;// количество элементов в массиве
    srand(n);// инициализация генератора случайных чисел
    int array[n];// объявление массива с n элементами
    array[0] = 7;// первый элемент массива
    array[1] = 2;// второй элемент массива
    array[2] = 6;// третий элемент массива
    array[3] = 5;// четвертый элемент массива
    array[4] = 4;// пятый элемент массива
    array[5] = 4;// шестидесятый элемент массива
    array[6] = 10;// седьмый элемент массива
    array[7] = 3;// восьмый элемент массива
    array[8] = 9;// девятый элемент массива
    printf("array:");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);// вывод элемента массива
    }
    printf("\neven elements: ");
    for (int i = 0; i < n; ++i) {
        if (array[i] % 2 == 0) {// если элемент делится на 2 без остатка, то элемент четный
            printf("%d ", array[i]);// вывод четных элементов
            array[i] = 0;// удаление четных элементов
        }
    }
    printf("\narray after deleting even elements: ");
    for (int i = 0; i < n; i++) {
        if (array[i] != 0) {// проверка на то, что элемент не равен 0
            printf("%d ", array[i]);// вывод элемента массива
        }
    }
    return 0;
}
// 4. если среднеарифметическое элементов массива больше 5, то отсортировать массив по возрастанию, иначе - по убыванию
int AlexV4Task() { // AlexVectorsFourthTask
    int n = 0;// количество элементов в массиве
    printf("input n:");
    scanf_s("%d", &n);// ввод количества элементов
    srand(n);// инициализация генератора случайных чисел
    int array[n];// объявление массива с n элементами
    printf("array: ");
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 10;// заполнение массива случайными числами от 0 до 9
        printf("%d ", array[i]);// вывод элемента массива
    }
    //если среднеарифметическое элементов массива больше 5, то отсортировать массив по возрастанию, иначе - по убыванию
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i];// суммирование элементов массива
    }
    float average = (float)sum / (float)n;// вычисление среднеарифметического значения элементов
    printf("\naverage = %f\n", average);// вывод среднеарифметического значения
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // выполнится только если среднеарифметическое значение больше 5
            if (average > 5 && array[i] > array[j]) {// сортировка по возрастанию
                // меняем элементы местами
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            // выполнится только если среднеарифметическое значение меньше 5
            if (average < 5 && array[i] < array[j]) {// сортировка по убыванию
                // меняем элементы местами
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);// вывод отсортированного массива
    }
    return 0;
}