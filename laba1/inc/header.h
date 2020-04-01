#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include "list.h"
#include "binary_tree.h"

void print_char(char s);
void print_str(char *str);
int *array_atoi(char **arr, int size);
t_node *setup_list(int *arr, int size);
void print_list(t_node *start);
void print_binary_tree(t_bin_node *root);
void test(void);

#endif
