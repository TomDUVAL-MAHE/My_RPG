/*
** EPITECH PROJECT, 2021
** world_edit_set_size
** File description:
** desc
*/

#include "my_world_edit.h"

void world_edit_set_size(world_edit_t *menu, sfVector2f size)
{
    menu->size = size;
    sfRectangleShape_setSize(menu->shape, size);
}