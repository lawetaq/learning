#include <stdio.h>

int main(void)
{
    char s[] = "hello";
    char *t = s;

    printf("Before:\n");
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    t[0] = 'H';

    printf("After:\n");
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    printf("s address: %p\n", (void *) s);
    printf("t value: %p\n", (void *) t);

    return 0;
}