#include <stdio.h>

void countdown(int n);

int main(void)
{
    int n;

    printf("Start: ");
    scanf("%i", &n);

    countdown(n);

    return 0;
}

void countdown(int n)
{
    if (n <= 0)
    {
        printf("Blastoff!\n");
        return;
    }

    printf("%i\n", n);
    countdown(n - 1);
}