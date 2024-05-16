/*
pseudocode for factorial of a number

function factorial (i/p -> number) : 
if number = 0, return 1
else
    result := 1
    for i from 1 to n, 
        set result := result * i
    return result
*/

#include <stdio.h>
#include <limits.h>

int factorial(int n, int* ptrToOperations)
{
    if (n == 0) 
    {
        (*ptrToOperations)++; 
        return 1;
    }
    else
    {
        (*ptrToOperations)++;
        int res = 1;
        for (int i = 1; i <= n; i++)
        {
            res *= i;
            (*ptrToOperations) += 2;
        }
        return res;
    }
}

int main()
{
    int operations = 0;
    printf("enter number to calculate factorial for : ");
    int number;
    scanf("%d", &number);
    int result = factorial(number, &operations);
    printf("%d! = %d (calculated in %d operations)\n",number, result, operations);
    return 0;
}