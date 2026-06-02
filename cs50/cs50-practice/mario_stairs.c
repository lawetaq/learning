#include <stdio.h>

int main(void)
{
    int height;
    char dir;

    do
    {
        printf("Enter height: ");
        scanf("%i", &height);
    }
    while (height < 1);

    printf("Choose direction (l/r): ");
    scanf(" %c", &dir);

    if (dir == 'l' || dir == 'L')
    {
        for (int row = 0; row < height; row++)
        {
            for (int col = 0; col < row + 1; col++)
            {
                printf("#");
            }

            printf("\n");
        }
    }

    else if (dir == 'r' || dir == 'R')
    {
        for (int row = 0; row < height; row++)
        {
            for (int space = 0; space < height - row -1; space++)
            {
                printf(" ");
            }

            for (int hash = 0; hash < row + 1; hash++)
            {
                printf("#");
            }

            printf("\n");
        }
    }  

    else 
    {
        printf("Invalid direction!\n");
    }

    return 0;
}