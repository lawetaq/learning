#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;

    printf("n: %i\n", n);
    printf("address of n: %p\n", (void *) &n);

    printf("p: %p\n", p);
    printf("address of p: %p\n", (void *) &p);

    return 0;
}