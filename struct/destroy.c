/*
** EPITECH PROJECT, 2020
** destroy.c
** File description:
** destroy
*/

#include "../include/screensaver.h"

void head_destroy(sv_head_t *head)
{
    sfTexture_destroy(head->texture);
    sfSprite_destroy(head->sprite);
    free(head->option);
    free(head);
    return;
}

void main_destroy(sv_head_t *head, framebuffer_t
*framebuffer, sfRenderWindow *window)
{
    fb_destroy(framebuffer);
    head_destroy(head);
    sfRenderWindow_destroy(window);
    return;
}