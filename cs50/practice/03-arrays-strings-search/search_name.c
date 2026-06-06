#include <stdio.h>
#include <string.h>

int main(void)
{
    char *names[] = {"Nikita", "Alex", "Bob", "Sasha"};
    int length = 4;
    char target[100];
    int found = 0;

    printf("Target: ");
    scanf("%99s", target);

    for (int i = 0; i < length; i++)
    {
        if (strcmp(names[i], target) == 0)
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