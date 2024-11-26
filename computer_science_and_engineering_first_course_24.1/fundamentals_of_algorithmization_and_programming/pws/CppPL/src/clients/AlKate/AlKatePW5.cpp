//
// Created by fred on 26.11.2024.
//
#include <iostream>

using namespace std;//Импорт пространства имен std, благодаря которому мы можем использовать функции cout, cin и т.д. без указания std::

/*
 * int* - тип возвращаемого значения
 * createArray - название функции
 * int n - аргумент функции, то есть это значение извне, которое мы будем использовать внутри функции.
 * Получается, что шаблон функции выглядит следующим образом:
 *
 * тип_возвращаемого_значения название_функции(аргументы_функции) {
 *    тело_функции
 *    return значение(которое имеет такой же тип, как и 'тип_возвращаемого_значения');
 * }
 */
int* createArray(const int n) {
    // new int[n] - выделяет память под массив целых чисел из n элементов и возвращает указатель на него.
    int* array = new int[n];
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 10;
    }
    return array;// Возвращаем указатель на массив
}
void outputArray(const int n, int array[]) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";// c++'ный аналог printf("%d ", array[i]);
    }
}
int findMinValue(const int* array, int n) {
    int minValue = array[0];// Сразу присваиваем переменной значение первого элемента соответствующего массива, чтобы пропустить 1 проход цикла.
    for (int i = 1; i < n; i++) {
        /*
         * Если элемент массива в позиции i меньше minValue, то присваиваем minValue значение элемента массива в позиции i, потому что он является минимальным в результате сравнения.
         * Если элемент массива в позиции i больше minValue, то мы ничего не делаем
         * Таким образом находим минимальные элементы массивов
         */
        if (array[i] < minValue) minValue = array[i];
    }
    return minValue;// Возвращаем значение переменной minValue
}
int multiplyPositiveElementsOfArray(const int array[], const int n) {
    int multiplication = 1;
    for (int i = 0; i < n; i++) {
        if (array[i] > 0) multiplication *= array[i];
    }
    return multiplication;
}
int pw5AlKate() {
    srand(21u);
    int n = 0;
    cout << "input n: ";
    cin >> n;
    if (n > 10) {// если число элементов массива больше 10, то выводим сообщение об ошибке и завершаем программу
        cout <<"error: n > 10";
        return 1;
    }
    int *array1 = createArray(n), *array2 = createArray(n);

    cout <<"\narray1: ";// c++'ный аналог printf("array1: ");
    outputArray(n, array1);
    cout <<"\narray2: ";
    outputArray(n, array2);

    int min1 = findMinValue(array1, n), min2 = findMinValue(array2, n);

    cout <<"\nthe min element of the array1: " << min1;// c++'ный аналог printf("the min element of the array1: %d", min1);
    cout <<"\nthe min element of the array2: " << min2;

    int multiplication = 0;
    if (min1 < min2) {
        multiplication = multiplyPositiveElementsOfArray(array1, n);
    } else multiplication = multiplyPositiveElementsOfArray(array2, n);

    cout <<"\nmultiplication of positive elements of the array: " << multiplication;// c++'ный аналог printf("multiplication of positive elements of the array: %d", multiplication);

    delete[] array1;// delete[] - для освобождения памяти массива объектов.
    delete[] array2;
    return 0;
}