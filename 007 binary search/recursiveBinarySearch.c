// RECURSIVE APPROACH

#include <stdio.h>

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
}

int recursiveBinarySearch(int* arr, int low, int high, int key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] > key) return recursiveBinarySearch(arr, low, mid - 1, key);
        else return recursiveBinarySearch(arr, mid + 1, high, key); 
    }
    else return -1;
}

int main()
{
    int array[] = {2, 3, 4, 5, 6, 21, 56, 67, 78, 107};
    int size = sizeof(array) / sizeof(array[0]);
    int key = 68;
    int result = recursiveBinarySearch(array, 0, size - 1, key);
    (result == -1) ? printf("value not found in array\n") : printf("%d found at index %d in array\n", key, result);
    return 0;
}