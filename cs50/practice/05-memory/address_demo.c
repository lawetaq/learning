#include <stdio.h>

int main(void)
{
    int n = 50;
    char c = 'A';

    printf("n value: %i\n", n);
    printf("n address: %p\n", (void *) &n);

    printf("c value: %c\n", c);
    printf("c address: %p\n", (void *) &c);

    return 0;
}