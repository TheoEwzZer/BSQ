/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include <stdlib.h>
#include "my.h"

int contain_o_or_point(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'o' && str[i] != '.' && str[i] != '\n') {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv)
{
    if (argc == 3) {
        int number = my_getnbr(argv[1]);
        char *pattern = argv[2];
        if (!contain_o_or_point(pattern) || number <= 0)
            return 84;
        return generation(number, pattern);
    }
    if (argc == 2)
        return bsq(argv[1]);
    return 84;
}
