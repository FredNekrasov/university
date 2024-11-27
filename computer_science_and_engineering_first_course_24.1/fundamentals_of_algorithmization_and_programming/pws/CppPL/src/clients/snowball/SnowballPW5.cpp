//
// Created by fred on 27.11.2024.
//
/*
 * В массиве, содержащем не более 21 числа, подсчитать среднее арифметическое для положительных элементов.
 * Если среднее больше заданного числа, положительные элементы исходного массива уменьшить на это число, а отрицательные - увеличить.
 * Найти максимальный элемент полученного массива и его номер. Формат числа цц.ц.
 */
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
        array[i] = rand() % 200 - 100;
    }
    return array;// Возвращаем указатель на массив
}
void outputArray(const int n, int array[]) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";// c++'ный аналог printf("%d ", array[i]);
    }
}
int calculateAverage(const int array[], const int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] > 0) sum += array[i];
    }
    return sum / n;// сначала происходит деление суммы положительных элементов на количество элементов, а затем возвращается результат
}
/*
 * Положительные элементы исходного массива уменьшить на заданное число, а отрицательные - увеличить.
 * int* - int с указателем, так как мы возвращаем указатель на массив
 * changeArray - название функции
 * int n, int array[], int specificNumber - аргумент функции, то есть это значение извне, которое мы будем использовать внутри функции.
 * int n - количество элементов в массиве
 * int array[] - массив целых чисел
 * int specificNumber - заданное число
 */
int* changeArray(const int n, int array[], int specificNumber) {
    for (int i = 0; i < n; i++) {
        if (array[i] > 0) {
            array[i] -= specificNumber;
        } else array[i] += specificNumber;
    }
    return array;
}
/*
 * Найти максимальный элемент полученного массива и его номер.
 * void - означает, что функция ничего не возвращает
 * findAndPrintMaxValue - название функции
 * int array[], int n - аргументы функции
 * int array[] - массив целых чисел
 * int n - количество элементов в массиве
 */
void findAndPrintMaxValue(const int array[], const int n) {
    // Сразу присваиваем переменной max значение первого элемента соответствующего массива, чтобы пропустить 1 проход цикла.
    int max = array[0];// max - максимальное значение
    int maxIndex = 0;// maxIndex - индекс/позиция максимального значения или номер на котором находится максимальное значение
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {// если текущее значение больше максимального значения, то обновляем максимальное значение и его индекс
            max = array[i];
            maxIndex = i;
        }
    }
    cout <<"\nmax: " <<max;
    cout <<"\nindex: " <<maxIndex;
}
int pw5Snowball() {
    srand(21u);
    int n = 0;
    cout << "input n: ";
    cin >> n;
    if (n > 21) {// если число элементов массива больше 21, то выводим сообщение об ошибке и завершаем программу
        cout <<"error: n > 21";
        return 1;
    }
    int *array = createArray(n);

    cout <<"\narray: ";
    outputArray(n, array);

    int average = calculateAverage(array, n);
    cout <<"\naverage: " <<average;

    int specificNumber = 0;
    cout <<"input specificNumber: ";
    cin >> specificNumber;
    if (average > specificNumber) {
        array = changeArray(n, array, specificNumber);
    }

    cout <<"changed array: ";
    outputArray(n, array);

    findAndPrintMaxValue(array, n);

    delete[] array;// delete[] - для освобождения памяти массива объектов.
    return 0;
}