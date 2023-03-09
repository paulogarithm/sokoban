/*
** EPITECH PROJECT, 2023
** sokoban_final
** File description:
** soko_check_corner
*/

#include <ncurses.h>

#include "../include/soko.h"

int check_blocked_invalid(map_t *map, int x, int y)
{
    if (map->array[x][y] != 'X')
        return 1;
    if (x == 0 || y == 0)
        return 1;
    if (map->array[x + 1] == NULL || map->array[x][y + 1] == '\0')
        return 1;
    return 0;
}

int check_blocked(map_t *map, int x, int y)
{
    if (check_blocked_invalid(map, x, y))
        return 0;

    int val = 0;
    int top = map->array[x - 1][y] == '#';
    int bot = map->array[x + 1][y] == '#';
    int left = map->array[x][y - 1] == '#';
    int right = map->array[x][y + 1] == '#';

    top = top || map->array[x - 1][y] == 'X';
    bot = bot || map->array[x + 1][y] == 'X';
    left = left || map->array[x][y - 1] == 'X';
    right = right || map->array[x][y + 1] == 'X';

    val = (top && right) || (top && left);
    val = val || (bot && right) || (bot && left);
    return val;
}

int check_boxes_corner(map_t *map)
{
    int blocked = 0;
    int boxes = 0;
    int x = 0;
    int y = 0;

    while (map->array[x] != NULL) {
        y = 0;
        while (map->array[x][y] != '\0') {
            boxes += map->array[x][y] == 'X' ? 1 : 0;
            blocked += check_blocked(map, x, y);
            y += 1;
        }
        x += 1;
    }
    return boxes == blocked;
}
