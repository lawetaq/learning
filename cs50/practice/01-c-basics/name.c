#include <stdio.h>

int main(void)
{
    char answer[100];

    printf("What's your name? ");

    fgets(answer, sizeof(answer), stdin);

    printf("Hello, %s", answer);
}