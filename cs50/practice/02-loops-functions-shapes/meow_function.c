#include <stdio.h>

void meow(void)
{
    printf("Meow!\n");
}

int main(void)
{
    int n;

    do
    {
        printf("How many times? ");
        scanf("%i", &n);
    }
    while (n < 1);

    for (int i = 0; i < n; i++)
    {
        meow();
    }

    return 0;
}