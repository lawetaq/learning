#include <stdio.h>

int main(void)
{
    int num[] = {3, 53, 6, 33, 9, 10, 1};
    int length = 7;
    int min = num[0];
    
    for (int i = 0; i < length; i++)
    {
        if (num[i] < min)
        {
            min = num[i];
        }
    }

    printf("The minimum is: %i\n", min);

    return 0;
}