#include "header.h"
#include "binary_tree.h"

int *bubble_sort(int *arr, int size)
{
    int i = -1, j;

    while (++i < size - 1)
    {
        j = -1;
        while (++j < size - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                int mem = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = mem;
            }
        }
    }
    return (arr);
}

t_bin_node *create_balanced_tree(int *arr, int from, int to)
{
    int center = (to + from) / 2;

    if (from > to)
        return (NULL);
    t_bin_node *node = create_tree_node(arr[center]);
    node->right = create_balanced_tree(arr, center + 1, to);
    node->left = create_balanced_tree(arr, from, center - 1);
    return (node);
}

t_bin_node *create_tree(int *arr, int size)
{
    t_bin_node *root;
    int *(*sort)(int *, int) = &bubble_sort;

    arr = sort(arr, size);
    root = create_balanced_tree(arr, 0, size - 1);
    return (root);
}

t_bin_node *create_tree_node(int value)
{
    t_bin_node *new_root;

    new_root = (t_bin_node *)malloc(sizeof(t_bin_node));
    new_root->value = value;
    return (new_root);
}

t_bin_node *push_tree_node(t_bin_node *root, int value)
{
    if (!root)
    {
        t_bin_node *root = (t_bin_node *)malloc(sizeof(t_bin_node));
        root->value = value;
        return (root);
    }
    else if (value > root->value)
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
    return (root);
}

static t_bin_node *min_from_subtree(t_bin_node *root)
{
    if (root->left)
        return (min_from_subtree(root->left));
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