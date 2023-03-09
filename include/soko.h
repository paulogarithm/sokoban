/*
** EPITECH PROJECT, 2023
** sokoban_re
** File description:
** soko
*/

#ifndef SOKO_H_
    #define SOKO_H_

typedef struct {
    int x;
    int y;
} pos_t;

typedef struct {
    char **array;
    char **origin;

    pos_t player;

} map_t;

#endif /* !SOKO_H_ */
