#include <stdio.h>

void print_array(int numbers[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%i ", numbers[i]);
    }

    printf("\n");
}

int main(void)
{
    int numbers[] = {5, 2, 1, 9, 3};
    int length = 5;

    printf("Before: ");
    print_array(numbers, length);

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    printf("After: ");
    print_array(numbers, length);

    return 0;
}