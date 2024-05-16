// AMMAR AHMAD KIDWAI
// 2022-350-005

// AIM : Write a program to find Maximum and Minimum of the given set of integer values.

#include <stdio.h>

/*
approach : 
Assume first member to be smallest/largest, 
if encountering larger/smaller element, declare it the largest/smallest
repeat until entire array is traversed
*/

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
}

void minMaxOfArray(int* array, int size, int* minVal, int* maxVal)
{
    *minVal = array[0]; *maxVal = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] < *minVal) *minVal = array[i];
        else if (array[i] > *maxVal) *maxVal = array[i];
    }
}

int main()
{
    int array[] = {21, 34, 54, 1, 4, 23, -5, 34};
    int size = sizeof(array) / sizeof(array[0]);
    int min, max;
    printf("array : ");
    printArray(array, size);
    minMaxOfArray(array, size, &min, &max);
    printf("max value : %d\nmin value : %d", max, min);
    return 0;
}