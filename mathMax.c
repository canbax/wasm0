int mathMax(int *arr, int size)
{
    int currMax = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > currMax)
            currMax = arr[i];
    }
    return currMax;
}
