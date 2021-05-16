/*
** EPITECH PROJECT, 2021
** RPG-TESTS
** File description:
** window.c
*/

#include "my_window.h"

void init_rpg_window(my_window_t *window, int width, int height)
{
    sfVideoMode mode = {width, height, 32};

    window->size.x = width;
    window->size.y = height;
    window->mode = mode;
    window->window = \
    sfRenderWindow_create(mode, "window", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window->window, 60);
}