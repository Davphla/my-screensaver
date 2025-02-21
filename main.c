/*
** EPITECH PROJECT, 2020
** opening_a_window
** File description:
** graphical programming
*/

#include "include/screensaver.h"

int usages(char *str)
{
    char buff[600];

    switch (str[1]) {
    case('h'):
        read(open("./usages/help.txt", O_RDONLY), buff, 600);
        my_printf(buff, MAX_ID);
        break;
    case('d'):
        read(open("./usages/description.txt", O_RDONLY), buff, 600);
        my_putstr(buff);
        break;
    case('s'):
        read(open("./usages/settings.txt", O_RDONLY), buff, 600);
        my_printf(buff, FRAME_RATE, HEIGHT_WINDOW, LENGTH_WINDOW, COLORS_BITS,
        (RANDOM_SEED == 1) ? ("Activated") : ("Desactivated"), LOW_DETAIL == 1
        ? ("Activated") : ("Desactivated"));
        break;
    default:
        my_putstr("Unknown option. Retry with -h.\n");
    }
    return (0);
}

int error_handling(int argument)
{
    char buff[300];

    if (MAX_ID < argument || argument < 1) {
        read(open("./usages/errors.txt", O_RDONLY), buff, 300);
        my_printf(buff, argument, MAX_ID);
        return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (error_handling(0));
    if (av[1][0] == '-')
        return (usages(av[1]));
    if (error_handling(my_getnbr(av[1])))
        return (84);
    manage_windows(head_initialize(av));
    return (0);
}