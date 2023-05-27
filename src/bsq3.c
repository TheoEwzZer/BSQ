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

int check_one_line(int size, char *buffer)
{
    for (int i = 0; i < size; i++) {
        if (buffer[i] == '\n' && buffer[i + 1])
            return 0;
    }
    return 1;
}

char *load_file_in_memory(char const *filepath, int *height)
{
    struct stat buf;
    if (stat(filepath, &buf) == -1)
        return NULL;
    int size = buf.st_size;
    char *buffer = malloc(sizeof(char) * (size + 1));
    buffer[size] = '\0';
    int fd = open(filepath, O_RDONLY);
    if (fd == -1 || !size || read(fd, buffer, size) == -1)
        return NULL;
    if (check_one_line(size, buffer) == 1)
        return NULL;
    *height = getheight(buffer);
    for (int i = 0; buffer[0] != '\n'; i++) {
        buffer++;
    }
    buffer++;
    close(fd);
    return buffer;
}

int getwidth(char **map)
{
    int width = 0;
    while (map[0][width] != '\0') {
        width++;
    }
    return width;
}

int contain_n_occurence_of_backslah_n(char *str, int n)
{
    if (!n)
        return 0;
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            j++;
    }
    if (j == n)
        return 1;
    return 0;
}

int bsq_end(char **map2d, int max_row, int max_col, int max_size)
{
    complete_biggest_square(map2d, max_row, max_col, max_size);
    my_show_word_array(map2d);
    free(map2d);
    return 0;
}
