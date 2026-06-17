#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = "hello";
    char *t = malloc(strlen(s) + 1);

    if (t == NULL)
    {
        return 1;
    }

    strcpy(t, s);

    printf("s = %s, t = %s\n", s, t);
    printf("Addresses: s = %p, t = %p\n", (void *) s, (void *) t);

    free(t);

    return 0;
}