#include <stdio.h>
#include <stdlib.h>

//сортировка
void shakerSort(int array[], int size) {
    int left = 0;
    int right = size - 1;
    int swapped = 1;
    
while (left < right && swapped) {
    swapped = 0;
        
    //проход слева направо
    for (int i = left; i < right; i++) {
        if (array[i] > array[i + 1]) {
            int temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            swapped = 1;
        }
    }
    right--;
        
    //проход справа налево
    for (int i = right; i > left; i--) {
        if (array[i] < array[i - 1]) {
            int temp = array[i];
            array[i] = array[i - 1];
            array[i - 1] = temp;
            swapped = 1;
        }
    }
    left++; 
    }
}

//создание массива рандомных чисел
void initializeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (1000 - -1000 + 1) + -1000;
    }
}

//вывод
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int size;
    int arr[size];
    printf("Введите размер массива:\n");
    scanf("%d", &size);
    initializeArray(arr, size);
    
    printf("Исходный массив:\n");
    printArray(arr, size);
    
    shakerSort(arr, size);
    
    printf("Отсортированный массив:\n");
    printArray(arr, size);
    
    return 0;
}