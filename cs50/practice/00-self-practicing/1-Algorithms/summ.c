#include <stdio.h>

int main(void)
{
    int num[] = {1, 2, 67, 33, 72, 8, 100};
    int length = 7;
    int summ = 0;

    for (int i = 0; i < length; i++)
    {
        summ += num[i];
    }

    printf("%i\n", summ);

    return 0;
}