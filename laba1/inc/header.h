#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <unistd.h>

#define NULL 0;

void print_char(char s);
void print_str(char *str);

typedef struct node
{
    int num;
    struct node *next;
}   t_node;

#endif
