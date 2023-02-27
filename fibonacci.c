#include <stdio.h>
#include <emscripten/emscripten.h>

int main()
{
    printf("Hello from the worst fibonacci calculator!\n");
    return 0;
}

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

// n should be a non-negative integer
EXTERN EMSCRIPTEN_KEEPALIVE int fib(int n)
{
    if (n < 2)
        return n;
    return fib(n - 1) + fib(n - 2);
}
