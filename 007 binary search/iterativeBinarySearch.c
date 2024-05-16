// ITERATIVE APPROACH

#include <stdio.h>

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
}

int iterativeBinarySearch(int *array, int size, int key)
{
    int low = 0;
    int high = size;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] == key) return mid;
        else if (array[mid] > key) high = mid - 1;
        else low = mid - 1;
    }
    return -1;
}

int main()
{
    int array[] = {2, 3, 4, 5, 6, 21, 56, 67, 78, 107};
    int size = sizeof(array) / sizeof(array[0]);
    int key = 67;
    int result = iterativeBinarySearch(array, size, key);
    (result == -1) ? printf("value not found in array\n") : printf("%d found at index %d in array\n", key, result);
    return 0;
}