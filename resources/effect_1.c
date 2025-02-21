/*
** EPITECH PROJECT, 2020
** effect_1.c
** File description:
** 
*/

#include "../include/screensaver.h"

framebuffer_t *effect_1(framebuffer_t *framebuffer, option_t *option)
{
    fb_restart(framebuffer, 0.985);
    fml_draw_circle(framebuffer, (sfVector2i){500 - option->c_frame *
    (10 * option->seed), 500 - option->c_frame * (10 * option->seed)},
    100, (sfColor){option->seed / 2, option->seed, option->seed * 2, 255});
    if (option->c_frame % 480 == 0 && RANDOM_SEED == 1) {
        srand(time(NULL));
        option->seed = rand() / 100000;
    }
    return (framebuffer);
}