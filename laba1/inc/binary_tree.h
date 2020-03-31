#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct s_bin_node
{
    int value;
    struct s_bin_node *right, *left;
}   t_bin_node;

t_bin_node *create_tree_node(int value);
t_bin_node *create_tree(int *arr, int size);
void push_tree_node(t_bin_node *root, int value);
t_bin_node *remove_tree_node(t_bin_node *root, t_bin_node *node);

#endif