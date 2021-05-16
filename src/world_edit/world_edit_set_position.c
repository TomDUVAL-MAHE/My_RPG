/*
** EPITECH PROJECT, 2021
** world_edit_set_position
** File description:
** desc
*/

#include "my_world_edit.h"

void world_edit_set_position(world_edit_t *menu, sfVector2f pos)
{
    menu->pos = pos;
    sfRectangleShape_setPosition(menu->shape, pos);
}