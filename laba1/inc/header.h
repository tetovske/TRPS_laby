#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include "list.h"

void print_char(char s);
void print_str(char *str);
int *array_atoi(char **arr, int size);
t_node *setup_list(int *arr, int size);
void print_list(t_node *start);
t_node *bubble_sort(t_node *start);

#endif
