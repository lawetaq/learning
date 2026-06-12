#include <stdio.h>

int main(void)
{
    int num[] = {1, 5, 6, 7, 9, 10, 15};
    int length = 7;
    int found = 0;
    int target;
    
    printf("Target? ");
    scanf("%i", &target);

    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;

        if (num[middle] == target)
        {
            printf("Found at index %i\n", middle);
            found = 1;
            break;
        }

        else if (target > num[middle])
        {
            left = middle + 1;
        }

        else
        {
            right = middle - 1;
        }
    }

    if (found == 0)
    {
        printf("Not found.\n");
    }

    return 0;
}