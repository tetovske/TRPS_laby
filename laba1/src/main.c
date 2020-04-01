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

    if (argc == 1)
    {
        test();
        return (0);
    }

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

void test(void)
{
    srand(time(NULL));
    char str_buf[BUF_SIZE]; 
    unsigned int begin, end;
    FILE *file_addition = fopen("data_add", "a");
    FILE *file_remove = fopen("data_remove", "a");
    t_node *list = new_node(rand() % 10000);
    t_bin_node *tree_root = create_tree_node(rand() % 10000);

    for (int i = 1; i < 10000; ++i)
    {
        int tacts_add, tacts_remove;
        int value = rand() % 10000;
        push_front(list, value);
        push_tree_node(tree_root, value);

        value = rand() % 10000;

        begin = RDTSC();
        push_front(list, -4);
        end = RDTSC();
        tacts_add = end - begin;

        begin = RDTSC();
        remove_node(&list, );
        end = RDTSC();
        tacts_add = end - begin;
        sprintf(str_buf, "%d %d %d", i, tacts_add, tacts_remove);
    }
    sprintf(s_number, "%d", num); 
    printf("%s", result);
    fputs("hello", file);
    close(file);

    for (int i = 0; i < 1000; ++i);
    {
        int num
        printf("%d\n", rand() % 10000);
    }
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
