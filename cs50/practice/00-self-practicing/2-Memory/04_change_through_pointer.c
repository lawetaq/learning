#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;

    printf("Before: n = %i\n",n);

    *p = 100;

    printf("After: n = %i\n", n);

    return 0;
}