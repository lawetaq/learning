#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = "hello";
    int length = strlen(s);

    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c, %c\n", s[i], *(s + i));
    }

    return 0;
}