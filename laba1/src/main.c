#include "header.h"

int main(int argc, char **argv)
{
    int arr[argc];
    while (--argc > 0)
        arr[argc] = atoi(argv[argc]);
    arr[0] = argv[argc];
    return (0);
}

void setup_list(struct node *st_node, int arr, int size)
{

}
