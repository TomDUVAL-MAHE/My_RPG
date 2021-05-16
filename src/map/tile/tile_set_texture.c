/*
** EPITECH PROJECT, 2021
** tile_set_texture
** File description:
** desc
*/

#include "my_map.h"

void tile_set_texture(tile_t *tile, sfTexture **ground)
{
    sfConvexShape_setTexture(tile->shape, ground[tile->ground], sfTrue);
}