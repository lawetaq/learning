#include <stdio.h>
#include <string.h>

int main(void)
{
    char password[100];
    char attempt[100];
    int success = 0;

    printf("Create your password: ");
    scanf("%99s", password);

    for (int i = 0; i < 3; i++)
    {
        printf("Enter your password: ");
        scanf("%99s", attempt);

        if (strcmp(password, attempt) == 0)
        {
            printf("Welcome!\n");
            success = 1;
            break;
        }

        else
        {
            if (i < 2)
            {
                printf("Password is incorrect, try again!\n");
            }

            else
            {
                printf("Password is incorrect.\n");
            }
        }

    }

    if (success == 0)
    {
        printf("Access denied.\n");
    }

    return 0;
}