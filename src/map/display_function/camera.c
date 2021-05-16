/*
** EPITECH PROJECT, 2021
** camera
** File description:
** desc
*/

#include "my_map.h"

void cam_in_tile(map_t *map, int i, int j, sfVector2f point)
{
    if (in_tile(map->tiles[i * map->size.x + j], point))
        map->camera = (sfVector2i){j, i};
}

void find_camera_pos(map_t *map, sfVector2u w_size)
{
    sfVector2f point;

    if (map->camera.x != -1 && map->camera.y != -1)
        return;
    point.x = w_size.x / 2 + map->origin.x;
    point.y = w_size.y / 2 + map->origin.y;
    for (int i = 0; i < map->size.y; i++) {
        for (int j = 0; j < map->size.x; j++) {
            cam_in_tile(map, i, j, point);
        }
    }
}

void cam_pos(map_t *map, int i, int j, sfVector2u w_size)
{
    sfVector2f point;

    point.x = w_size.x / 2 + map->origin.x;
    point.y = w_size.y / 2 + map->origin.y;
    if (in_tile(map->tiles[i * map->size.x + j], point)) {
        map->camera.x = j;
        map->camera.y = i;
    }
}