#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

void print_list(node *list);
int search_list(node *list, int target);
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

    int target;
    printf("Target: ");
    scanf("%i", &target);

    if (search_list(list, target) == 1)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not found\n");
    }

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

int search_list(node *list, int target)
{
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->number == target)
        {
            return 1;
        }
    }

    return 0;
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