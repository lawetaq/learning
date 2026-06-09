#include <stdio.h>

void print_row(int width)
{
    for (int i = 0; i < width; i++)
    {
        printf("#");
    }
    
    printf("\n");
}   

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
        print_row(size);
    }

    return 0;
}