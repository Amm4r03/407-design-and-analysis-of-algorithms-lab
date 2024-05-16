#include <stdio.h>

void insertionSort(int *array, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int array[] = {50, 2, 49, 4, 42, 12, 31, 17, 21, 8};
    int size = sizeof(array) / sizeof(array[0]);
    printf("initial array : ");
    printArray(array, size);
    insertionSort(array, size);
    printf("sorted array : ");
    printArray(array, size);
    return 0;
}