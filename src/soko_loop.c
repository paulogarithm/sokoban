/*
** EPITECH PROJECT, 2023
** sokoban_re
** File description:
** soko_loop
*/

#include <ncurses.h>

#include "../include/soko.h"

int get_action(map_t *map);
int check_terminal_size(map_t *map);
int check_slots(map_t *map);
int check_boxes_corner(map_t *map);

void screen_init(void)
{
    initscr();
    noecho();
    refresh();
    clear();
}

void show_map(map_t *map)
{
    clear();
    int n = 0;
    while (map->array[n] != NULL) {
        printw("%s\n", map->array[n]);
        n += 1;
    }
    refresh();
}

void draw_player(map_t *map, int draw)
{
    if (draw)
        map->array[map->player.x][map->player.y] = 'P';
    else
        map->array[map->player.x][map->player.y] = ' ';
}

int my_loop(map_t *map)
{
    int action = 0;
    screen_init();
    if (check_terminal_size(map))
        show_map(map);

    while (1) {
        draw_player(map, 0);
        action = get_action(map);
        draw_player(map, 1);
        action += check_slots(map);
        if (check_terminal_size(map))
            show_map(map);
        if (check_boxes_corner(map) && !action)
            action = -1;
        if (action)
            break;
    }
    endwin();
    return action > 0 ? 0 : 1;
}
