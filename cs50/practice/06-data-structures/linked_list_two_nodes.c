#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    node *first = malloc(sizeof(node));
    if (first == NULL)
    {
        return 1;
    }

    node *second = malloc(sizeof(node));
    if (second == NULL)
    {
        free(first);
        return 1;
    }

    first->number = 10;
    second->number = 20;

    first->next = second;
    second->next = NULL;

    printf("%i\n", first->number);
    printf("%i\n", first->next->number);

    free(first);
    free(second);

    return 0;
}