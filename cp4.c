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

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* mergeAlternate(int* arr1, int size1, int* arr2, int size2, int* mergedSize) {
    *mergedSize = size1 + size2;
    int* merged = (int*)malloc(*mergedSize * sizeof(int));
    if (merged == NULL) {
        printf("RAM error!\n");
        exit(1);
    }

    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        merged[k++] = arr1[i++];
        merged[k++] = arr2[j++];
    }

    while (i < size1) {
        merged[k++] = arr1[i++];
    }

    while (j < size2) {
        merged[k++] = arr2[j++];
    }

    return merged;

}
int main() {
    int size1, size2;
    int *array1, *array2, *mergedArray;
    int mergedSize;

    printf("Enter size of first array: ");
    scanf("%d", &size1);
    printf("Enter elements:\n");
    array1 = inputArray(size1);

    printf("Enter size of seconf array: ");
    scanf("%d", &size2);
    printf("Enter elements:\n");
    array2 = inputArray(size2);

    mergedArray = mergeAlternate(array1, size1, array2, size2, &mergedSize);

    printArray(mergedArray, mergedSize);

    free(array1);
    free(array2);

    return 0;
}

