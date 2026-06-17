#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char s[] = "hello";

    char *t = malloc(strlen(s) + 1);

    if (t == NULL)
    {
        return 1;
    }

    for (int i = 0; i <= strlen(s); i++)
    {
        t[i] = s[i];
    }

    printf("Before:\n");
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    t[0] = 'H';

    printf("After:\n");
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    printf("s address: %p\n", (void *) s);
    printf("t value: %p\n", (void *) t);

    free(t);

    return 0;
}