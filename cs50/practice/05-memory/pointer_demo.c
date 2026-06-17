#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;

    printf("n value: %i\n", n);
    printf("n address: %p\n", (void *) &n);

    printf("p value: %p\n", (void *) p);
    printf("p address: %p\n", (void *) &p);

    printf("*p value: %i\n", *p);

    *p = 100;

    printf("n value after *p = 100: %i\n", n);
    printf("*p value after *p = 100: %i\n", *p); 

    return 0;
}