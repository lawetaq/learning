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
    node *list = NULL;

    node *first = malloc(sizeof(node));
    if (first == NULL)
    {
        return 1;
    }
    first->number = 10;
    first->next = list;
    list = first;

    node *second = malloc(sizeof(node));
    if (second == NULL)
    {
        free(first);
        return 1;
    }
    second->number = 20;
    second->next = list;
    list = second;

    node *third = malloc(sizeof(node));
    if (third == NULL)
    {
        free(first);
        free(second);
        return 1;
    }
    third->number = 30;
    third->next = list;
    list = third;

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    node *ptr = list;
    
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;
}