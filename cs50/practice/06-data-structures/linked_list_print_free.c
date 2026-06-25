#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

void print_list(node *list);
void free_list(node *list);

int main(void)
{
    node *list = NULL;

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 10;
    n->next = list;
    list = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_list(list);
        return 1;
    }
    n->number = 20;
    n->next = list;
    list = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free_list(list);
        return 1;
    }
    n->number = 30;
    n->next = list;
    list = n;

    print_list(list);
    free_list(list);

    return 0;
}

void print_list(node *list)
{
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }
}

void free_list(node *list)
{
    node *ptr = list;

    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}