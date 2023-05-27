/*
** EPITECH PROJECT, 2022
** bsq2.c
** File description:
** bsq2
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "structbsq.h"

int getheight(char *buffer)
{
    int x = 0;
    while (buffer[x] != '\n')
        x++;
    char *len = malloc(sizeof(char) * (x + 1));
    x = 0;
    while (buffer[x] != '\n') {
        len[x] = buffer[x];
        x++;
    }
    len[x] = '\0';
    int height = my_getnbr(len);
    free(len);
    return height;
}

int is_square_of_size2(char **map, int nb_rows, int i, int j)
{
    if (i >= nb_rows || map[i][j] == 'o' || map[i][j] == '\0')
        return 0;
    return 1;
}

int complete_biggest_square(char **map, int max_row, int max_col, int max_size)
{
    for (int i = max_row; i < max_size + max_row; i++) {
        for (int j = max_col; j < max_size + max_col; j++) {
            map[i][j] = 'x';
        }
    }
    return 1;
}

void found_max(int *max_size, int *max_row, int *max_col, var_bsq var)
{
    if (var.size > *max_size) {
        *max_size = var.size;
        *max_row = var.row;
        *max_col = var.col;
    }
}
