#include <stdio.h>

int main(void)
{
    int width;

    do
    {
        printf("Enter the width: ");
        scanf("%i", &width);
    }
    while (width < 1);

    for (int i = 0; i < width; i++)
    {
        printf("#");
    }

    printf("\n");

    return 0;
}