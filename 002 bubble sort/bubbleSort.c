#include <stdio.h>

void bubbleSort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
}

int main()
{

    int array[] = {15, 10, 2, 7, 4, 21, 50};
    int size = sizeof(array) / sizeof(array[0]);
    printf("initial array : ");
    printArray(array, size);
    bubbleSort(array, size);
    printf("sorted array : ");
    printArray(array, size);
    return 0;
}