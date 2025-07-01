#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// сортировка
void shakerSort(int arr[], int size) {
    int left = 0;
    int right = size - 1;
    int swapped = 1; 
    
    while (left < right && swapped) {
        swapped = 0;
        
        // проход слева направо 
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
        right--; 
        
        // проход справа налево
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swapped = 1;
            }
        }
        left++; 
    }
}

// вывод массива
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// создание массива рандомных чисел
void initializeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (1000 - -1000 + 1) + -1000;
    }
}

// запись массива в файл
void writeArrToFile(int arr[], int size, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка открытия файла для записи!\n");
        return;
    }
    
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fprintf(file, "\n");
    
    fclose(file);
}

int main() {
    int size;
    printf("Введите размер массива:\n");
    scanf("%d", &size);
    
    //динамическое выделение памяти для массива
    int *arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    
    initializeArray(arr, size);
    
    printf("Исходный массив (первые 100 элементов):\n");
    printArray(arr, size > 100 ? 100 : size);

    clock_t start = clock();                 // время до сортировки
 
    shakerSort(arr, size);

    clock_t stop = clock();                  // время после сортировки
    double time = (double)(stop - start) / CLOCKS_PER_SEC; // время сортировки в секундах

    printf("Отсортированный массив записан в файл\n");
    printf("Время сортировки: %f секунд\n", time);

    writeArrToFile(arr, size, "shakerSort.txt");
    
    //освобождение памяти
    free(arr);

    return 0;
}