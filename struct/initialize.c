/*
** EPITECH PROJECT, 2020
** initialize.c
** File description:
** initialize structures
*/

#include "../include/screensaver.h"

option_t *option_initialize(void)
{
    option_t *option = malloc(sizeof(sv_head_t));

    option->c_frame = 0;
    option->clock = sfClock_create();
    srand(time(NULL));
    option->seed = rand() / 100000;
    option->c_frame_mode = 1;
    return (option);
}

sv_head_t *head_initialize(char **av)
{
    sv_head_t *head = malloc(sizeof(sv_head_t));

    head->id = my_getnbr(av[1]);
    head->texture = sfTexture_create(HEIGHT_WINDOW, LENGTH_WINDOW);
    head->sprite = sfSprite_create();
    sfSprite_setTexture(head->sprite, head->texture, sfTrue);
    head->option = option_initialize();
    return (head);
}