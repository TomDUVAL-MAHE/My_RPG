/*
** EPITECH PROJECT, 2021
** map_set_tiles
** File description:
** desc
*/

#include "my_map.h"
#include <time.h>
#include "my.h"

void tile_set_origin(tile_t *tile, sfVector2f origin)
{
    sfConvexShape_setOrigin(tile->shape, origin);
}

void map_set_tiles(map_t *map, int zoom)
{
    int index = 0;
    int var = 0;

    srand(time(NULL));
    map->tiles = malloc(sizeof(tile_t) * (map->size.x * map->size.y));
    for (int i = 0; i < map->size.y; i++) {
        for (int j = 0; j < map->size.x; j++) {
            var = (rand() % 4) + 1;
            var = (rand() % 10 == 0) ? (rand() % 4) + 4 : var;
            index = i * map->size.x + j;
            map->tiles[index] = tile_set(var, 0, zoom);
            map->tiles[index].pos = iso_projection(j, i, 0, zoom);
            tile_set_position(&map->tiles[index], map->tiles[index].pos);
            tile_set_texture(&map->tiles[index], map->textures[0].texture);
            tile_set_origin(&map->tiles[i * map->size.x + j], map->origin);
        }
    }
}