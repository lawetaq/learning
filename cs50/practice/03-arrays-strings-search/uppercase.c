#include <stdio.h>

int main(void)
{
    char text[100];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            printf("%c", text[i] - ('a' - 'A'));
        }

        else
        {
            printf("%c", text[i]);
        }
    }

    return 0;
}