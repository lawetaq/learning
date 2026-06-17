#include <stdio.h>

int main(void)
{
    char s[] = "hello";

    printf("s: %s\n", s);
    printf("s address: %p\n", (void *) s);
    printf("&s address: %p\n", (void *) &s);
    printf("first char: %c\n", s[0]);

    return 0;
}