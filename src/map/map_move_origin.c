/*
** EPITECH PROJECT, 2021
** map_move_origin.c
** File description:
** desc
*/

#include "my_map.h"

void map_move_origin(map_t *map, sfVector2f move)
{
    int i = (map->camera.y - 20 > 0) ? map->camera.y - 20 : 0;
    int j = (map->camera.x - 20 > 0) ? map->camera.x - 20 : 0;

    if (move.x == 0 && move.y == 0)
        return;
    map->origin.x += move.x;
    map->origin.y += move.y;
    for (; i < map->camera.y + 20 && i < map->size.y; i++) {
        for (; j < map->camera.x + 20 && j < map->size.x; j++) {
            sfConvexShape_setOrigin(\
            map->tiles[i * map->size.x + j].shape, map->origin);
        }
        j = (map->camera.x - 20 > 0) ? map->camera.x - 20 : 0;
    }
}