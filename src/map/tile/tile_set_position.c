/*
** EPITECH PROJECT, 2021
** tile_set_position
** File description:
** desc
*/

#include "my_map.h"

void tile_set_position(tile_t *tile, sfVector2f pos)
{
    sfConvexShape_setPosition(tile->shape, pos);
}