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
    int numbers[] = {5, 9, 1, 3, 2, 8, 7};
    int length = 7;
    
    printf("Before: ");
    print_array(numbers, length);

    for (int i = 0; i < length - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < length; j++)
        {
            if (numbers[j] < numbers[min_index])
            {
                min_index = j;
            }
        }

        int temp = numbers[i];
        numbers[i] = numbers[min_index];
        numbers[min_index] = temp;
    }

    printf("After: ");
    print_array(numbers, length);

    return 0;
}