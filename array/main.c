#include <stdio.h>
#include <stdlib.h>

int insert_element(int *arr, int *size, int capacity, int element, int position) {
    if (*size >= capacity) {
        return -1; // Массив переполнен, невозможно вставить элемент
    }
    if (position > *size) {
        return -2; // Неверная позиция для вставки
    }

    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
    return *size;
}

int delete_element(int *arr, int *size, int position) {
    if (position >= *size) {
        return -1; // Неверная позиция для удаления
    }

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    return *size;
}

void traverse_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int capacity = 10;
    int size = 5;
    int *arr = (int *)malloc(capacity * sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    // Исходный массив
    traverse_array(arr, size);

    // Массив после вставки
    insert_element(arr, &size, capacity, 10, 2);
    traverse_array(arr, size);

    // Массив после удаления
    delete_element(arr, &size, 3);
    traverse_array(arr, size);

    free(arr);
    return 0;
}