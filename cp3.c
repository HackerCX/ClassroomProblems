#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

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

int* filterPrimes(int* arr, int size, int* primeCount) {
    int* primes = NULL;
    *primeCount = 0;

    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            primes = (int*)realloc(primes, (*primeCount + 1) * sizeof(int));
            if (primes == NULL) {
                printf("RAM error\n");
                exit(1);
            }
            primes[*primeCount] = arr[i];
            (*primeCount)++;
        }
    }

    return primes;
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
    int *primeArray1, *primeArray2;
    int primeCount1 = 0, primeCount2 = 0;

    printf("Enter size of first array: ");
    scanf("%d", &size1);
    printf("Enter elements:\n");
    array1 = inputArray(size1);

    printf("Enter size of seconf array: ");
    scanf("%d", &size2);
    printf("Enter elements:\n");
    array2 = inputArray(size2);

    primeArray1 = filterPrimes(array1, size1, &primeCount1);
    primeArray2 = filterPrimes(array2, size2, &primeCount2);

    int totalPrimes = primeCount1 + primeCount2;
    int* finalArray = (int*)malloc(totalPrimes * sizeof(int));
    if (finalArray == NULL) {
        printf("RAM error\n");
        exit(1);
    }

    for (int i = 0; i < primeCount1; i++) {
        finalArray[i] = primeArray1[i];
    }
    for (int i = 0; i < primeCount2; i++) {
        finalArray[primeCount1 + i] = primeArray2[i];
    }

    printArray(finalArray, totalPrimes);

    free(array1);
    free(array2);
    free(primeArray1);
    free(primeArray2);
    return 0;
}

