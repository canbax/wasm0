int mathMin(int *arr, int size)
{
    int currMin = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < currMin)
            currMin = arr[i];
    }
    return currMin;
}

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

float mathAvg(int *arr, int size)
{
    int currMax = -1;
    double total = 0;
    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }
    return total / size;
}