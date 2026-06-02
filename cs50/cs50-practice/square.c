#include <stdio.h>

int main(void)
{
    int size;

    do
    {
        printf("Enter the size: ");
        scanf("%i", &size);
    }
    while (size < 1);

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
