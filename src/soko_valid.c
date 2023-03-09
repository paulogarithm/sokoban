/*
** EPITECH PROJECT, 2023
** sokoban_re
** File description:
** soko_valid
*/

int my_findchar(char *src, char c);

int map_validchars(char *str)
{
    int n = 0;
    char *valid = "POX# \n";

    while (str[n] != '\0') {
        if (my_findchar(valid, str[n]) < 0)
            return 0;
        n += 1;
    }
    return 1;
}

int map_validnums(char *str)
{
    int n = 0;
    int how_many_P = 0;
    int how_many_O = 0;
    int how_many_X = 0;

    while (str[n] != '\0') {
        if (str[n] == 'P')
            how_many_P += 1;
        if (str[n] == 'O')
            how_many_O += 1;
        if (str[n] == 'X')
            how_many_X += 1;
        n += 1;
    }

    if ((how_many_O != how_many_X) || how_many_O <= 0 || how_many_P != 1)
        return 0;

    return 1;
}
