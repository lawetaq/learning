#include <stdio.h>

int main(void)
{
    int n = 50;

    printf("n: %i\n", n);
    printf("address of n: %p\n", (void *) &n);
    
    return 0;
}