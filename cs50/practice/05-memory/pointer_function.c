#include <stdio.h>

void change(int *p);

int main(void)
{
    int n = 50;

    printf("Before: %i\n", n);

    change(&n);

    printf("After: %i\n", n);

    return 0;
}

void change(int *p)
{
    *p = 100;
}