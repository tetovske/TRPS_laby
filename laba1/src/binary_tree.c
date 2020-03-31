#include "header.h"
#include "binary_tree.h"

t_bin_node *create_tree(int *arr, int size)
{
    int i = 0;
    t_bin_node *root;

    if (size < 1 || !arr)
        return NULL;
    root = create_tree_node(arr[0]);
    while (++i < size)
        push_tree_node(root, arr[i]);
    return (root);
}

t_bin_node *create_tree_node(int value)
{
    t_bin_node *new_root;

    new_root = (t_bin_node *)malloc(sizeof(t_bin_node));
    new_root->value = value;
    return (new_root);
}

void push_tree_node(t_bin_node *root, int value)
{
    if (value > root->value)
    {
        if (!(root->right))
        {
            root->right = (t_bin_node *)malloc(sizeof(t_bin_node));
            root->right->value = value;
        }
        else
            push_tree_node(root->right, value);
    }
    else if (value < root->value)
    {
        if (!(root->left))
        {
            root->left = (t_bin_node *)malloc(sizeof(t_bin_node));
            root->left->value = value;
        }
        else
            push_tree_node(root->left, value);
    }
}

static t_bin_node *min_from_subtree(t_bin_node *root)
{
    if (root->left)
        return (min_from_subtree(root->left));
    else
        return (root);
}

t_bin_node *remove_tree_node(t_bin_node *root, t_bin_node *node)
{
    if (!root)
        return (NULL);
    if (node->value > root->value)
        root->right = remove_tree_node(root->right, node);
    else if (node->value < root->value)
        root->left = remove_tree_node(root->left, node);
    else
    {
        if (!(root->left) && !(root->right))
        {
            free(root);
            return (NULL);
        }
        else if (!(root->left))
        {
            t_bin_node *mem = root->right;
            free(root);
            return (mem);
        }
        else if (!(root->right))
        {
            t_bin_node *mem = root->left;
            free(root);
            return (mem);
        }
        else
        {
            t_bin_node *min = min_from_subtree(root->right);
            root->value = min->value;
            root->right = remove_tree_node(root->right, min);
        }
    }
    return (root);
}