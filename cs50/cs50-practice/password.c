#include <stdio.h>
#include <string.h>

int main(void)
{
    char password[100];
    char attempt[100];
    
    printf("Create your password: ");
    scanf("%99s", password);

    printf("Enter your password: ");
    scanf("%99s", attempt);

    if (strcmp(password, attempt) == 0)
    {
        printf("Welcome!\n");
    }
    else
    {
        printf("Password is incorrect!\n");
    }
    
    return 0;
}