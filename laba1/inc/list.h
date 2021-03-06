#ifndef LIST_H
#define LIST_H

typedef struct s_node
{
    int value;
    struct s_node *next;
}   t_node;

t_node *new_node(int value);
t_node *push_back(t_node *start, int value);
t_node *push_front(t_node *start, int value);
void free_list(t_node *start);
void remove_node(t_node **head, t_node *elem);

#endif
