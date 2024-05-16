// adding auxiliary functions here

// names pretty self explanatory
void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
}

// yeah
void swapValues(int *a, int *b)
{
    int temp = *a; *a = *b; *b = temp;
}