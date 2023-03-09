/*
** EPITECH PROJECT, 2023
** sokoban_re
** File description:
** soko_action
*/

#include <ncurses.h>
#include <unistd.h>

#include "../include/soko.h"

char **dup_the_array(char **array);
pos_t where_player(char **array);

int check_valid_place(map_t *map, pos_t *pos)
{
    if (pos->x < 0 || pos->y < 0)
        return 0;
    if (map->array[pos->x] == NULL || map->array[pos->x][pos->y] == '\0')
        return 0;
    if (map->array[pos->x][pos->y] == '#')
        return 0;
    return 1;
}

int can_push(map_t *map, pos_t pos, int x, int y)
{
    pos_t cpos = {pos.x + x, pos.y + y};
    if (!check_valid_place(map, &cpos))
        return 0;
    if (map->array[cpos.x][cpos.y] == 'X')
        return 0;
    map->array[cpos.x][cpos.y] = 'X';
    return 1;
}

void move_player(map_t *map, int x, int y)
{
    pos_t pos = {map->player.x + x, map->player.y + y};
    if (!check_valid_place(map, &pos))
        return;
    if (map->array[pos.x][pos.y] == 'X' && !can_push(map, pos, x, y))
        return;
    map->player = pos;
}

void arrow_pressed(map_t *map)
{
    getch();
    int my_char = getch();

    switch (my_char) {
    case 'A':
        move_player(map, -1, 0);
        break;
    case 'B':
        move_player(map, 1, 0);
        break;
    case 'C':
        move_player(map, 0, 1);
        break;
    case 'D':
        move_player(map, 0, -1);
        break;
    default:
        break;
    }
}

int get_action(map_t *map)
{
    int c = getch();
    if (c == 'q')
        return 1;
    if (c == '\033')
        arrow_pressed(map);
    if (c == ' ') {
        map->array = dup_the_array(map->origin);
        map->player = where_player(map->array);
    }
    return 0;
}
