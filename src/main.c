/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** main
*/

#include <unistd.h>

#include "../include/soko.h"

int my_printf(char *str, ...);
int my_compstr(char *str1, char *str2);

map_t map_setup(char *file_path);
int my_loop(map_t *map);

int usage(void)
{
    my_printf("\nUSAGE:\n");
    my_printf("\t./my_sokoban [map]\n\n");
    my_printf("DESCRIPTION:\n\n");
    my_printf("  [map]\t The map is a text file containing at at least\n");
    my_printf("\t a player 'P', walls '#', crates 'X', and crate's\n");
    my_printf("\t slots 'O'.\n\n");
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && my_compstr(av[1], "-h"))
        return usage();
    if (ac != 2)
        return 84;

    map_t map = map_setup(av[1]);
    if (map.array == NULL)
        return 84;

    int error = my_loop(&map);
    if (error)
        return 1;
    return 0;
}
