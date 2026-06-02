#include <stdio.h>

void print_row(int width)
{
    for (int col = 0; col < width; col++)
    {
        printf("#");
    }

    printf("\n");
}

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

    for (int row = 0; row < height; row++)
    {
        print_row(width);
    }

    return 0;
}