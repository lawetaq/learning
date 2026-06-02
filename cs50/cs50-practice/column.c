#include <stdio.h>
 
int main(void)
{
    int height;

    do
    {
        printf("Enter the height: ");
        scanf("%i", &height);
    }
    while (height < 1);

    for (int i = 0; i < height; i++)
    {
        printf("#\n");
    }

    return 0;
}
