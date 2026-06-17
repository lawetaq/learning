#include <stdio.h>

int main(void)
{
    char *s = "HI!";

    printf("String: %s\n", s);
    printf("s address: %p\n", (void *) s);

    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("s[%i]: %c | address: %p | *(s + %i): %c\n",
               i,
               s[i],
               (void *) &s[i],
               i,
               *(s + i));
    }

    return 0;
}