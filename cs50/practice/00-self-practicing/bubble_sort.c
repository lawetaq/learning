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

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (num[j] > num[j + 1])
            {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }

    printf("After: ");
    print_array(num, length);

    return 0;
}