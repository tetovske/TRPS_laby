#include "header.h"

void print_char(char s)
{
    write(1, &s, 1);
}

void print_str(char *str)
{
    int i = -1;

    while (*(str + (++i)) != '\0')
        print_char(*(str + i));
    print_char('\n');
}
