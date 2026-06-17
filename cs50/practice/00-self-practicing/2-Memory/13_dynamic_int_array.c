#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int length = 5;
    int *numbers = malloc(length * sizeof(int));

    if (numbers == NULL)
    {
        return 1;
    }

    for (int i = 0; i < length; i++)
    {
        printf("Enter number (%i/%i) ", i + 1, length);
        scanf("%i", &numbers[i]);
    }

    for (int n = 0; n < length; n++)
    {
        printf("%i ", numbers[n]);
    }

    printf("\n");

    free(numbers);

    return 0;
}