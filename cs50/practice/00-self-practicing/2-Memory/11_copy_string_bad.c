#include <stdio.h>

int main(void)
{
    char *s = "hello";
    char *t = s;

    printf("s = %s, t = %s\n", s, t);
    printf("addresses: s = %p, t = %p\n", (void *) s, (void *) t);

    return 0;
}