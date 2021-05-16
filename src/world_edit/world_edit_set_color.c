/*
** EPITECH PROJECT, 2021
** world_edit_set_color
** File description:
** desc
*/

#include "my_world_edit.h"

void world_edit_set_color(world_edit_t *menu, sfColor color)
{
    menu->color = color;
    sfRectangleShape_setFillColor(menu->shape, color);
}