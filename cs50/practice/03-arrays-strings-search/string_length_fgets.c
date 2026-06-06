#include <stdio.h>

int main(void)
{
    char text[100];

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    int length = 0;

    while (text[length] != '\0' && text[length] != '\n')
    {
        length++;
    }

    printf("Length: %i\n", length);

    return 0;
}