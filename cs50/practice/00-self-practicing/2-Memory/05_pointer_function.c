#include <stdio.h>

void set_to_100(int *p)
{
    *p = 100;
}

int main(void)
{
    int n = 50;
    int i = 20;

    printf("Before: n = %i, i = %i\n", n, i);
    
    set_to_100(&n);

    printf("After: n = %i, i = %i\n", n, i);

    return 0;
}