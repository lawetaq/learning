#include <stdio.h>

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5, 9, 11, 13};
    int length = 8;
    int found = 0;
    int target;

    printf("Target: ");
    scanf("%i", &target);
    
    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;

        if (numbers[middle] == target)
        {
            printf("Found\n");
            found = 1;
            break;
        }

        else if (numbers[middle] > target)
        {
            right = middle - 1;
        }

        else 
        {
            left = middle + 1;
        }
    }

    if (found == 0)
    {
        printf("Not found\n");
    }

    return 0;
}