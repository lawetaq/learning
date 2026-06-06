#include <stdio.h>

int main(void)
{
    char text[100];
    int key;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    printf("Key: ");
    scanf("%i", &key);

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            printf("%c", (text[i] - 'a' + key) % 26 + 'a');
        }

        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            printf("%c", (text[i] - 'A' + key) % 26 + 'A');
        }

        else
        {
            printf("%c", text[i]);
        }
    }

    return 0;
}