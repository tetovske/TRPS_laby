#include "header.h"
#include "sorts.h"
#include "list.h"

static t_node *merge(t_node *half_a, t_node *half_b)
{
    t_node *result = NULL;
  
    if (half_a == NULL) 
        return (half_b); 
    else if (half_b == NULL) 
        return (half_a); 
  
    if (half_a->value <= half_b->value) { 
        result = half_a; 
        result->next = merge(half_a->next, half_b); 
    } 
    else { 
        result = half_b; 
        result->next = merge(half_a, half_b->next); 
    } 
    return (result); 
}

static void split_lists(t_node *head, t_node **half_a, t_node **half_b)
{
    t_node *fast; 
    t_node *slow; 

    slow = head; 
    fast = head->next;

    while (fast != NULL) 
    { 
        fast = fast->next;
        if (fast != NULL) 
        { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
  
    *half_a = head; 
    *half_b = slow->next; 
    slow->next = NULL; 
}

t_node *merge_sort(t_node **list)
{
    //t_node *head = *list;
    t_node *half_a, *half_b;

    if ((*list == NULL) || ((*list)->next == NULL))
        return *list;
    split_lists(*list, &half_a, &half_b);
    merge_sort(&half_a);
    merge_sort(&half_b);
    *list = merge(half_a, half_b);
    return (*list);
}