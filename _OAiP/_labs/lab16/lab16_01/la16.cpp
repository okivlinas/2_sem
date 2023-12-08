#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Функция для сортировки пузырьком
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Функция для разделения массива в сортировке Хоара
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] > pivot);

        do {
            j--;
        } while (arr[j] < pivot);

        if (i >= j) {
            return j;
        }

        swap(arr[i], arr[j]);
    }
}

// Функция для сортировки Хоара
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot);
        quickSort(arr, pivot + 1, high);
    }
}

// Функция для генерации случайного числа в заданном диапазоне
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {

    setlocale(LC_CTYPE, "Russian");

    srand(static_cast<unsigned>(time(0)));

    int size, kol = 0;
    cout << "Введите размер массивов: ";
    cin >> size;

    int* arrA = new int[size];
    int* arrB = new int[size];

    // Заполнение массивов случайными числами
    for (int i = 0; i < size; i++) {
        arrA[i] = generateRandomNumber(1, 100);
        arrB[i] = generateRandomNumber(1, 100);
    }

    int* arrC = new int[size * 2];
    int cIndex = 0;

    // Перенос четных элементов из arrA и нечетных элементов из arrB в arrC
    for (int i = 0; i < size; i++) {
        if (arrA[i] % 2 == 0) {
            arrC[cIndex] = arrA[i];
            cIndex++;
            kol++;
        }
        if (arrB[i] % 2 != 0) {
            arrC[cIndex] = arrB[i];
            cIndex++;
            kol++;
        }
    }

    // Измерение времени выполнения сортировки пузырьком
    auto startTime = high_resolution_clock::now();
    bubbleSort(arrC, cIndex);
    auto endTime = high_resolution_clock::now();
    auto durationBubbleSort = duration_cast<microseconds>(endTime - startTime).count();

    // Измерение времени выполнения сортировки Хоара
    startTime = high_resolution_clock::now();
    quickSort(arrC, 0, cIndex - 1);
    endTime = high_resolution_clock::now();
    auto durationQuickSort = duration_cast<microseconds>(endTime - startTime).count();

    // Вывод времени выполнения алгоритмов
    cout << "Массив А: " << endl;
    for (int i = 0; i < size; i++)cout << arrA[i] << " ";
    cout << endl;
    cout << "Массив B: " << endl;
    for (int i = 0; i < size; i++)cout << arrB[i] << " ";
    cout << endl;
    cout << "Массив C: " << endl;
    for (int i = 0; i < kol; i++)cout << arrC[i] << " ";
    cout << endl;
    cout << "Время выполнения сортировки пузырьком: " << durationBubbleSort << " микросекунд." << endl;
    cout << "Время выполнения сортировки Хоара: " << durationQuickSort << " микросекунд." << endl;

    // Освобождение памяти
    delete[] arrA;
    delete[] arrB;
    delete[] arrC;

    return 0;
}