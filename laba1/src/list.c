#include "header.h"
#include "list.h"

t_node *new_node(int value)
{
    t_node *node;

    node = (t_node *)malloc(sizeof(t_node));
    if (node != NULL)
        node->value = value;
    return (node);
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

void remove_node(t_node **head, t_node *elem)
{
    t_node *node = *head;

    if (!(*head) || !elem)
        return;
    if (elem == *head)
        *head = (*head)->next;
    else
    {
        head = &node;
        while (head && (*head)->next != elem)
            *head = (*head)->next;
        (*head)->next = elem->next;
    }
    free(elem);
    return;
}