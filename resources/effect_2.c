/*
** EPITECH PROJECT, 2020
** effect_2.c
** File description:
** Effect that does a 3D rotate with simple 2D effect
*/

#include "../include/screensaver.h"

void fml_put_pixel_addition(framebuffer_t *framebuffer,
unsigned int x, unsigned int y, sfColor color)
{
    unsigned long coords;

    if (x > framebuffer->width)
        x -= (x / framebuffer->width) * framebuffer->width;
    if (y > framebuffer->height)
        y -= (y / framebuffer->height) * framebuffer->height;
    coords = (x + (y * framebuffer->width)) * 4;
    framebuffer->pixels[coords] += color.r;
    framebuffer->pixels[1 + coords] += color.g;
    framebuffer->pixels[2 + coords] += color.b;
    framebuffer->pixels[3 + coords] += color.a;
}

void effect_2_curved_line(framebuffer_t *framebuffer,
option_t *option, int i, int j)
{
    float tan_percentage = 1;
    float tan_multiplier = 210;
    double y;

    for (float k = -1.18; k < 1.18; k += 0.00333) {
        y = tan(k / tan_percentage) *
        tan_multiplier + i + j + option->c_frame * 2 + 600;
        fml_put_pixel_addition(framebuffer, k * 300 +
        HEIGHT_WINDOW / 2, y, (sfColor){0, i, 255, 255});
        fml_put_pixel_addition(framebuffer, k * 300 +
        HEIGHT_WINDOW / 2, -y, (sfColor){0, i, 255, 255});
    }
}

framebuffer_t *effect_2(framebuffer_t *framebuffer, option_t *option)
{
    fb_recolor(framebuffer, (sfColor){0, 138, 245, 255});

    for (int j = 0; j < 75 - 65 * LOW_DETAIL; j += 1)
        for (int i = 0; i < LENGTH_WINDOW * 2; i += 130)
            effect_2_curved_line(framebuffer, option, i, j);
    return (framebuffer);
}