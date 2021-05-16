/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "framebuffer.h"
#include <math.h>

framebuffer_t framebuffer_create(sfVector2f size, sfVector2f pos, \
bool is_display)
{
    framebuffer_t framebuffer;

    framebuffer.pixels = malloc(size.x * size.y * 32 / 8);
    framebuffer.size = size;
    framebuffer.pos = pos;
    framebuffer.is_display = is_display;
    framebuffer.texture = sfTexture_create(size.x, size.y);
    framebuffer.sprite = sfSprite_create();
    sfSprite_setPosition(framebuffer.sprite, pos);
    sfSprite_setTexture(framebuffer.sprite, framebuffer.texture, sfTrue);
    return (framebuffer);
}

void framebuffer_display(framebuffer_t *framebuffer, sfRenderWindow *window)
{
    if (framebuffer->is_display == true) {
        sfTexture_updateFromPixels(framebuffer->texture, framebuffer->pixels, \
        framebuffer->size.x, framebuffer->size.y, 0, 0);
        sfRenderWindow_drawSprite(window, framebuffer->sprite, NULL);
    }
}

void framebuffer_put_pixel(framebuffer_t *framebuffer, sfVector2f pos, \
sfColor color)
{
    framebuffer->pixels[(int) (framebuffer->size.x * pos.y + pos.x) * 4] \
    = color.r;
    framebuffer->pixels[(int) (framebuffer->size.x * pos.y + pos.x) * 4 + 1] \
    = color.g;
    framebuffer->pixels[(int) (framebuffer->size.x * pos.y + pos.x) * 4 + 2] \
    = color.b;
    framebuffer->pixels[(int) (framebuffer->size.x * pos.y + pos.x) * 4 + 3] \
    = color.a;
}

void framebuffer_fill_all_pixel(framebuffer_t *framebuffer, sfColor color)
{
    for (int i = 0; i < framebuffer->size.y; i++) {
        for (int j = 0; j < framebuffer->size.x; j++)
            framebuffer_put_pixel(framebuffer, (sfVector2f){j, i}, color);
    }
}