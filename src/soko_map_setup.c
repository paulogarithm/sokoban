/*
** EPITECH PROJECT, 2023
** sokoban_re
** File description:
** soko_map_setup
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "../include/soko.h"

char **my_convert(char *str);
char *my_parcing(char *file_path);
char *my_dupstr(char *str);

int map_validchars(char *str);
int map_validnums(char *str);

char **dup_the_array(char **array)
{
    int len = 0;
    while (array[len] != NULL)
        len += 1;

    char **new_array = malloc(sizeof(char *) * (len + 1));
    int n = 0;
    while (n < len) {
        new_array[n] = my_dupstr(array[n]);
        n += 1;
    }
    new_array[len] = NULL;
    return new_array;
}

pos_t setpos(int ver, int hor)
{
    pos_t pos = {ver, hor};
    return pos;
}

pos_t where_player(char **array)
{
    pos_t pos = {-1, -1};
    int ver = 0;

    while (array[ver] != NULL) {
        int hor = 0;
        while (array[ver][hor] != '\0') {
            pos = array[ver][hor] == 'P' ? setpos(ver, hor) : pos;
            hor += 1;
        }
        ver += 1;
    }
    return pos;
}

map_t map_setup(char *file_path)
{
    map_t map;
    map.array = NULL;
    char *str = my_parcing(file_path);
    if (str == NULL)
        return map;

    char **array = my_convert(str);
    if (array == NULL)
        return map;
    if (!map_validchars(str) || !map_validnums(str))
        return map;

    pos_t player_pos = where_player(array);
    if (player_pos.x < 0)
        return map;

    map.array = dup_the_array(array);
    map.origin = dup_the_array(array);
    map.player = player_pos;
    return map;
}
