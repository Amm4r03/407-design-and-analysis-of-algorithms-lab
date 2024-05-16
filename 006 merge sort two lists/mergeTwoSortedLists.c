#include <stdio.h>
#include <stdlib.h>

// approach : merge two arrays and then perform mergesort on the merged array

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
}

int* mergeTwoArray(int* array1, int arr1Size, int *array2, int arr2Size)
{
    int* mergedArray = malloc((arr1Size + arr2Size) * sizeof(int));
    for (int i = 0; i < arr1Size; i++)
    {
        mergedArray[i] = array1[i];
    }
    for (int i = 0; i < arr2Size; i++)
    {
        mergedArray[i + arr1Size] = array2[i]; 
    }
    return mergedArray;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr2[] = {15, 16, 17, 2, -5, 6, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int* mergedArr = mergeTwoArray(arr, size, arr2, size2);

    printf("array 1 : ");
    printArray(arr, size);
    printf("array 2 : ");
    printArray(arr2, size2);
    printf("merged array : ");
    printArray(mergedArr, size + size2);
    mergeSort(mergedArr, 0, size+size2 - 1);
    printf("Sorted array : ");
    printArray(mergedArr, size + size2);
    free(mergedArr);
    return 0;
}
