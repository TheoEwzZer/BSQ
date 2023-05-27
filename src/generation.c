/*
** EPITECH PROJECT, 2022
** generate.c
** File description:
** Generate a board
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int bsq_generation(char **map2d, int number)
{
    var_bsq var;
    int nb_rows = number;
    int max_size = 0;
    int max_row = 0;
    int max_col = 0;
    var.size = 0;
    var.square_size = 0;
    int width = getwidth(map2d);
    for (var.row = 0; var.row < nb_rows; var.row++) {
        for (var.col = 0; var.col < width; var.col++) {
            var.size = find_biggest_square(map2d, nb_rows, var);
            found_max(&max_size, &max_row, &max_col, var);
        }
    }
    complete_biggest_square(map2d, max_row, max_col, max_size);
    my_show_word_array(map2d);
    free(map2d);
    return 0;
}

int contain_only_point(int number, char *pattern)
{
    for (int i = 0; pattern[i]; i++) {
        if (pattern[i] != '.')
            return 0;
    }
    char *new_pattern = malloc(sizeof(char) * (number + 1));
    new_pattern[number] = '\0';
    for (int i = 0; i < number; i++) {
        new_pattern[i] = 'x';
    }
    for (int i = 0; i < number; i++) {
        write(1, new_pattern, number);
        write(1, "\n", 1);
    }
    free(new_pattern);
    return 1;
}

int generation(int number, char *pattern)
{
    int k = 0;
    if (!my_strlen(pattern))
        return 84;
    if (contain_only_point(number, pattern))
        return 0;
    char **pattern2d = malloc(sizeof(char *) * (number + 1));
    pattern2d[number] = 0;
    for (int i = 0; i < number; i++) {
        pattern2d[i] = malloc(sizeof(char) * (number + 1));
        pattern2d[i][number] = 0;
        for (int j = 0; j < number; j++) {
            pattern2d[i][j] = pattern[k];
            k++;
            k = !pattern[k] ? 0 : k;
        }
    }
    return bsq_generation(pattern2d, number);
}
