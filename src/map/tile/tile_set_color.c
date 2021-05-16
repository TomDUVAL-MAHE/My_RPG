/*
** EPITECH PROJECT, 2021
** tile_set_color
** File description:
** desc
*/

#include "my_map.h"

void tile_set_color(tile_t *tile, sfColor color)
{
    sfConvexShape_setFillColor(tile->shape, color);
}