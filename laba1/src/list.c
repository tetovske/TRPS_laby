#include "header.h"
#include "list.h"

t_node *new_node(int value)
{
    new_start = (struct node *)malloc(sizeof(t_node));
    printf("node size: %d", sizeof(t_node));
    if (new_start != NULL)
        new_start->value = value;
    return (new_start);
}

t_node *push_back(t_node *start, int value)
{
    t_node *node;

    node = new_node(value);
    if (start != NULL && node != NULL)
        node->next = start;
    return (node);
}

t_node *push_front(t_node *start, int value)
{
    t_node *node;
    t_node *sv_start;

    sv_start = start;
    node = new_node(value);
    if (start != NULL && node != NULL)
    {
        while (start->next != NULL)
            start = start->next;
        start->next = node;
    }
    return (node);
}


void free_list(t_node *start)
{
    if (start->next != NULL)
        free_list(start->next);
    free(start);
}


void remove_node(t_node *prev_node)
{

}

