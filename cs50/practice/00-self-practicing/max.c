#include <stdio.h>

int main(void)
{
    int num[] = {67, 1, 46, 9, 3, 12, 11};
    int length = 7;
    int max = num[0];

    for (int i = 0; i < length; i++)
    {
        if (max < num[i])
        {
            max = num[i];
        }
    }

    printf("The maximum is: %i\n", max);

    return 0;
}