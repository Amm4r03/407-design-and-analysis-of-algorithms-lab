#include "auxiliaryCode.h"
#include <stdio.h>

int main()
{
    int arr[] = {12, 2, 4,5 , 5, 1,2,4, 4,5,1, 3};
    printArray(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}