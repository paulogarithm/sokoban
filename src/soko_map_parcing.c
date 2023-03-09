/*
** EPITECH PROJECT, 2023
** sokoban_re
** File description:
** soko_map_parcing
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "../include/soko.h"

char *my_cutstr(char *str, int beggin, int end);

int getver(char *str)
{
    int n = 0;
    int size = 0;
    while (str[n])
        size += str[n ++] == '\n' ? 1 : 0;
    return size;
}

int gethor(char *str, int begin)
{
    int n = begin;
    while (str[n] && str[n] != '\n')
        n += 1;
    return n - begin;
}

char **my_convert(char *str)
{
    int ver = getver(str) + 1;
    char **array = malloc(sizeof(char *) * (ver + 1));
    int n = 0;
    int index = 0;

    while (str[n]) {
        int hello = gethor(str, n);
        array[index] = malloc(sizeof(char) * (hello + 1));
        array[index] = my_cutstr(str, n, n + hello);
        n += hello + 1;
        index += 1;
    }
    array[ver] = NULL;
    return array;
}

char *my_parcing(char *file_path)
{
    char *buf;
    struct stat st;

    int fd = open(file_path, O_RDONLY);
    if (fd < 0)
        return NULL;
    if (stat(file_path, &st) < 0)
        return NULL;

    buf = malloc(sizeof(char) * (st.st_size + 1));
    if (buf == NULL)
        return NULL;
    if (read(fd, buf, st.st_size) < 0)
        return NULL;

    return buf;
}
