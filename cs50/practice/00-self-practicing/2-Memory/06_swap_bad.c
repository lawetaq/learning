#include <stdio.h>

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main(void)
{
    int a;
    int b;

    printf("Enter a: \n");
    scanf("%i", &a);

    printf("Enter b: \n");
    scanf("%i", &b);

    printf("Before: a = %i, b = %i\n", a, b);

    swap(a, b);

    printf("After: a = %i, b =%i\n", a, b);

    return 0;
}