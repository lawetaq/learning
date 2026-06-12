#include <stdio.h>

void print_array(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%i ", arr[i]);
    }

    printf("\n");
}

int main(void)
{
    int num[] = {7, 15, 9, 5, 1, 6, 10};
    int length = 7;

    printf("Before: ");
    print_array(num, length);

    for (int i = 0; i < length; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < length; j++)
        {
            if (num[j] < num[min_index])
            {
                min_index = j;
            }
        }

        int temp = num[i];
        num[i] = num[min_index];
        num[min_index] = temp;
    }

    printf("After: ");
    print_array(num, length);

    return 0;
}