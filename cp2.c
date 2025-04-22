#include <stdio.h>
#include <stdlib.h>

int* inputArray(int size) {
    int *arr = (int *)calloc(size, sizeof(int));
    if (arr == NULL) {
        printf("RAM error:\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        printf("arr[%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }

    return arr;
}

int* filterOddNumbers(int* arr, int size, int* oddCount) {
    int* oddArr = NULL;
    *oddCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            oddArr = (int *)realloc(oddArr, (*oddCount + 1) * sizeof(int));
            if (oddArr == NULL) {
                printf("RAM error\n");
                exit(1);
            }
            oddArr[*oddCount] = arr[i];
            (*oddCount)++;
        }
    }

    return oddArr;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size1, size2;
    int *array1, *array2;
    int *oddArray1, *oddArray2;
    int oddCount1 = 0, oddCount2 = 0;

    printf("Enter size of first Array: ");
    scanf("%d", &size1);
    printf("enter elements:\n");
    array1 = inputArray(size1);

    printf("ՄEnter size of second Array: ");
    scanf("%d", &size2);
    printf("Enter elements\n");
    array2 = inputArray(size2);

    oddArray1 = filterOddNumbers(array1, size1, &oddCount1);
    oddArray2 = filterOddNumbers(array2, size2, &oddCount2);

    int totalOdd = oddCount1 + oddCount2;
    int* finalArray = (int *)malloc(totalOdd * sizeof(int));
    if (finalArray == NULL) {
        printf("Հիշողության բաշխման սխալ (finalArray):\n");
        exit(1);
    }

    for (int i = 0; i < oddCount1; i++) {
        finalArray[i] = oddArray1[i];
    }
    for (int i = 0; i < oddCount2; i++) {
        finalArray[oddCount1 + i] = oddArray2[i];
    }
    printArray(finalArray, totalOdd);


    free(array1);
    free(array2);
    free(oddArray1);
    free(oddArray2);
    return 0;
}

