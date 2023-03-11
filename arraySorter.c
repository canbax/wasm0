#include <stdlib.h>
#include <stdio.h>

int compareFn(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void arraySorter(int *arr, int size)
{
    qsort(arr, size, sizeof(int), compareFn);
}
