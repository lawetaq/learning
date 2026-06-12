#include <stdio.h>

int main(void)
{
    int num[] = {3, 53, 6, 33, 9, 10, 1};
    int length = 7;
    int found = 0;
    int target;

    printf("What's the target? ");
    scanf("%i", &target);

    for (int i = 0; i < length; i++)
    {
        if (num[i] == target)
        {
            printf("Found.");
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Not found");
    }
    
    printf("\n");
    return 0;
}