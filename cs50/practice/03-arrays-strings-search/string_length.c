#include <stdio.h>

int main(void)
{
    char text[100];

    printf("Enter text: ");
    scanf("%99s", text);

    int length = 0;

    while (text[length] != '\0')
    {
        length++;
    }

    printf("Length: %i\n", length);

    return 0;
}