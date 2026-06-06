#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }

    else
    {
        printf("Usage: ./greet_args name\n");
    }

    return 0;
}