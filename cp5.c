#include <stdio.h>
#include <stdlib.h>

int* inputArray(int size) {
    int* arr = (int*)calloc(size, sizeof(int));
    if (arr == NULL) {
        printf("RAM error\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        printf("arr[%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }

    return arr;
}

int* removeEvenNumbers(int* arr, int size, int* newSize) {
    int* result = NULL;
    *newSize = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            result = (int*)realloc(result, (*newSize + 1) * sizeof(int));
            if (result == NULL) {
                printf("RAM error\n");
                exit(1);
            }
            result[*newSize] = arr[i];
            (*newSize)++;
        }
    }

    return result;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size, newSize;
    int *originalArray, *filteredArray;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    originalArray = inputArray(size);
    filteredArray = removeEvenNumbers(originalArray, size, &newSize);

    printArray(filteredArray, newSize);

    free(originalArray);
    free(filteredArray);
    return 0;
}

