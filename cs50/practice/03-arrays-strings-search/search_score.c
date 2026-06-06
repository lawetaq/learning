#include <stdio.h>

int main(void)
{
    int scores[] = {73, 72, 33, 90, 100};
    int length = 5;
    int target;
    int found = 0;
    
    printf("Target: ");
    scanf("%i", &target);
    
    for (int i = 0; i < length; i++)
    {
        if (scores[i] == target)
        {
            printf("Found\n");
            found = 1;

            break;
        }
    }

    if (found == 0)
    {
        printf("Not found\n");
    }

    return 0;
}