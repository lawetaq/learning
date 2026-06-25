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

    int values[] = {5, 1, 9, 3};
    int length = 4;

    for (int i = 0; i < length; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            free_list(list);
            return 1;
        }

        n->number = values[i];
        n->next = NULL;

        node *previous = NULL;
        node *current = list;

        while (current != NULL && current->number < n->number)
        {
            previous = current;
            current = current->next;
        }

        if (previous == NULL)
        {
            n->next = list;
            list = n;
        }
        else
        {
            previous->next = n;
            n->next = current;
        }
    }

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