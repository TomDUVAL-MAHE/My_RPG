/*
** EPITECH PROJECT, 2021
** map_set_origin
** File description:
** desc
*/

#include "my_map.h"

void map_set_origin(map_t *map, sfVector2f origin)
{
    map->origin = origin;
    for (int i = 0; i < map->size.x * map->size.y; i++) {
        sfConvexShape_setOrigin(map->tiles[i].shape, origin);
    }
}