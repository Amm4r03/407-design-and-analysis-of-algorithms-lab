#include <stdio.h>

// Signature for partition
int partition(int*, int, int);

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++) 
        printf("%d ", array[i]);
    printf("\n");
}

void quickSort(int *array, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(array, low, high);

        quickSort(array, low, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, high);
    }
}

void swapValues(int *a, int *b)
{
    int temp = *a; 
    *a = *b; 
    *b = temp;
}

int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swapValues(&array[i], &array[j]);   
        }
    }
    swapValues(&array[i + 1], &array[high]);
    return (i + 1);
}

int main()
{
    int array[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(array) / sizeof (array[0]);
    printf("Initial array : "); 
    printArray(array, size);
    quickSort(array, 0, size - 1);
    printf("Sorted array : "); 
    printArray(array, size);
    return 0;
}
