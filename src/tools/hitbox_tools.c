/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** hitbox_tools
*/

#include <SFML/Graphics.h>
#include "my.h"
#include <stdio.h>

void show_a_hitbox(sfRenderWindow *window, sfFloatRect hitbox)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setOutlineColor(rect, sfRed);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(255, 0, 0, 55));
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setPosition(rect, (sfVector2f) {hitbox.left, hitbox.top});
    sfRectangleShape_setSize(rect, (sfVector2f) {hitbox.width, hitbox.height});
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

void show_sprite_outline(sfRenderWindow *window, sfSprite *sprite)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfFloatRect size = sfSprite_getGlobalBounds(sprite);

    sfRectangleShape_setOutlineColor(rect, sfGreen);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(0, 255, 0, 55));
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setPosition(rect, (sfVector2f) {size.left, size.top});
    sfRectangleShape_setSize(rect, (sfVector2f) {size.width, size.height});
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_destroy(rect);
}