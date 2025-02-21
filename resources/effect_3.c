/*
** EPITECH PROJECT, 2020
** effect_3.c
** File description:
** 
*/

#include "../include/screensaver.h"

void fml_put_pixel_addition(framebuffer_t *framebuffer,
unsigned int x, unsigned int y, sfColor color);

void effect_3_curved_line(framebuffer_t *framebuffer,
option_t *option, int i, int j)
{
    float tan_percentage = 1;
    float tan_multiplier = 180;
    double y;

    for (float k = -1.2; k < 1.2; k += 0.00333) {
        y = tan(k / tan_percentage) *
        tan_multiplier + i + j + option->c_frame * 2 + 600;
        fml_put_pixel_addition(framebuffer, k * 300 +
        HEIGHT_WINDOW / 2, y, (sfColor){0, i, 255, 255});
        fml_put_pixel_addition(framebuffer, k * 300 +
        HEIGHT_WINDOW / 2, -y, (sfColor){0, i, 255, 255});
    }
}

framebuffer_t *effect_3(framebuffer_t *framebuffer, option_t *option)
{
    for (int j = 0; j < 10; j += 1)
        for (int i = 0; i < LENGTH_WINDOW * 2; i += 200)
            effect_3_curved_line(framebuffer, option, i, j);
    return (framebuffer);
}