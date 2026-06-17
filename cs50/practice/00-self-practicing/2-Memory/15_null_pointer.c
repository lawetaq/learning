#include <stdio.h>

int  main(void)
{
    int *p = NULL;

    if (p == NULL)
    {
        printf("Pointer is NULL\n");
        return 1;
    }

    return 0;
}