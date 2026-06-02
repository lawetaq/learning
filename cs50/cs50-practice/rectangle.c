#include <stdio.h>

int main(void)
{
    int height;
    int width;

    do
    {
        printf("Enter the height: ");
        scanf("%i", &height);
    }
    while (height < 1);

    do
    {
        printf("Enter the width: ");
        scanf("%i", &width);
    }
    while (width < 1);

    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}