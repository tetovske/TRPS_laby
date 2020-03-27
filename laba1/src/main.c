#include "header.h"
#include "list.h"
#include "sorts.h"

static inline uint64_t RDTSC()
{
    unsigned int hi, lo;
    __asm__ volatile("rdtsc" : "=a" (lo), "=d" (hi));
    return ((uint64_t)hi << 32) | lo;
}

int main(int argc, char **argv)
{
    int *values = array_atoi(argv, argc);
    //unsigned int begin = RDTSC();
    t_node *list = setup_list(values, argc - 1);
    //unsigned int end = RDTSC();
    //printf("time: %d\n", end - begin);
    printf("list: ");
    print_list(list);
    printf("sorted list:\n");
    list = merge_sort(&list);
    print_list(list);
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
        printf("%d\n", start->value);
        print_list(start->next);
    }
}
