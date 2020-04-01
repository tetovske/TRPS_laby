#include "header.h"
#include "list.h"
#include "sorts.h"
#include "stdlib.h"

#define BUF_SIZE 10

static inline uint64_t RDTSC()
{
    unsigned int hi, lo;
    __asm__ volatile("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main(int argc, char **argv)
{
    unsigned int begin, end;

    int *values = array_atoi(argv, argc);
    t_node *list = setup_list(values, argc - 1);
    t_bin_node *tree_root = create_tree(values, argc - 1);

    begin = RDTSC();
    remove_tree_node(tree_root, tree_root->right);
    end = RDTSC();

    printf("количество таков CPU при удалении : %d\n", end - begin);

    begin = RDTSC();
    remove_node(&list, list->next->next);
    end = RDTSC();

    printf("remove node from list tacts: %d\n", end - begin);

    begin = RDTSC();
    push_front(list, -4);
    end = RDTSC();

    printf("add node to list tacts: %d\n", end - begin);

    begin = RDTSC();
    push_tree_node(tree_root, -4);
    end = RDTSC();

    printf("add node to tree tacts: %d\n", end - begin);
    return (0);
}

int *array_atoi(char **arr, int size)
{
    int *res = (int *)malloc(sizeof(int) * (size - 1));
    int i = 0;

    while (++i < size)
        res[i - 1] = atoi(arr[i]); 
    return (res);
}

t_node *setup_list(int *arr, int size)
{
    t_node *start;
    int i = 0;

    if (size < 1)
        return NULL;
    start = new_node(arr[0]);
    while (++i < size)
        push_front(start, arr[i]);
    return (start);
}

void print_list(t_node *start)
{
    if (start != NULL)
    {
        printf("%d ", start->value);
        print_list(start->next);
    }
}

void print_binary_tree(t_bin_node *root)
{
    if (root)
    {
        print_binary_tree(root->left);
        printf("%d ", root->value);
        print_binary_tree(root->right);
    }
}
