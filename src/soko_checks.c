/*
** EPITECH PROJECT, 2023
** sokoban_final
** File description:
** soko_checks
*/

#include <ncurses.h>

#include "../include/soko.h"

int my_countstr(char *str);

int get_rows(map_t *map)
{
    int x = 0;
    int y = 0;
    int max = 0;

    while (map->array[x] != NULL) {
        y = 0;
        while (map->array[x][y] != '\0')
            y += 1;
        if (y > max)
            max = y;
        x += 1;
    }
    return max;
}

int get_cols(map_t *map)
{
    int n = 0;
    while (map->array[n] != NULL)
        n += 1;
    return n;
}

int check_terminal_size(map_t *map)
{
    int rows = 0;
    int cols = 0;
    int min_rows = get_rows(map);
    int min_cols = get_cols(map);
    char *message = "Terminal trop petit";

    getmaxyx(stdscr, rows, cols);
    if (rows < min_rows || cols < min_cols) {
        clear();
        mvprintw(rows / 2, (cols - my_countstr(message)) / 2, message);
        refresh();
        return 0;
    }
    return 1;
}

int check_slots(map_t *map)
{
    int correct = 0;
    int on_game = 0;
    int x = 0;

    while (map->origin[x] != NULL) {
        int y = 0;
        while (map->origin[x][y] != '\0') {
            char o_char = map->origin[x][y];
            char a_char = map->array[x][y];

            correct += o_char == 'O' ? 1 : 0;
            on_game += o_char == 'O' && a_char == 'X' ? 1 : 0;
            map->array[x][y] = o_char == 'O' && a_char == ' ' ? 'O' : a_char;
            y += 1;
        }
        x += 1;
    }
    return correct == on_game;
}
