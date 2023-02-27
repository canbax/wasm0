#pragma once
#ifdef __cplusplus
extern "C"
{
#endif

    int fib(int n)
    {
        if (n < 2)
            return n;
        return fib(n - 1) + fib(n - 2);
    }

#ifdef __cplusplus
}
#endif