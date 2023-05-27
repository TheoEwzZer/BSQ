/*
** EPITECH PROJECT, 2022
** bsq.c
** File description:
** bsq
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "structbsq.h"

int getwidth1d(char *map)
{
    int width = 0;
    while (map[width] != '\0' && map[width] != '\n') {
        width++;
    }
    return width;
}

int is_square_of_size(char **map, var_bsq var, int nb_rows)
{
    int a = 1;
    for (int i = var.row; i < var.square_size + var.row; i++) {
        for (int j = var.col; j < var.square_size + var.col; j++) {
            a *= is_square_of_size2(map, nb_rows, i, j);
        }
    }
    return a;
}

int find_biggest_square(char **map, int nb_rows, var_bsq var)
{
    while (is_square_of_size(map, var, nb_rows)) {
        var.square_size++;
    }
    return var.square_size - 1;
}

char **load_file_in_memory_2d(char *str, int height)
{
    char **str2 = malloc(sizeof(char *) * (height + 1));
    str2[height] = '\0';
    int width = getwidth1d(str);
    if (!str2)
        return 0;
    int i = 0;
    for (int j = 0; str[i]; j++) {
        str2[j] = malloc(sizeof(char) * (width + 1));
        str2[j][width] = 0;
        for (int k = 0; str[i] != '\n' && str[i] != '\0'; k++) {
            str2[j][k] = str[i];
            i++;
        }
        i++;
    }
    return str2;
}

int bsq(char *filepath)
{
    var_bsq var;
    int max_size = 0, max_row = 0, max_col = 0, nb_rows = 0;
    char *map1d = load_file_in_memory(filepath, &nb_rows);
    if (!map1d || !contain_o_or_point(map1d) || nb_rows <= 0)
        return 84;
    if (!contain_n_occurence_of_backslah_n(map1d, nb_rows))
        return 84;
    char **map2d = load_file_in_memory_2d(map1d, nb_rows);
    var.size = 0; var.square_size = 0; int nb_cols = getwidth(map2d);
    for (var.row = 0; var.row < nb_rows; var.row++) {
        if (map2d[var.row][nb_cols] != '\0' || map2d[var.row][0] == '\0')
            return 84;
        for (var.col = 0; var.col < nb_cols; var.col++) {
            var.size = find_biggest_square(map2d, nb_rows, var);
            found_max(&max_size, &max_row, &max_col, var);
            if (var.size >= nb_rows) {
                return bsq_end(map2d, max_row, max_col, max_size);
            }
        }
    }
    return bsq_end(map2d, max_row, max_col, max_size);
}
