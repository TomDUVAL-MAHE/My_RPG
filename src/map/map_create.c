/*
** EPITECH PROJECT, 2021
** map_create
** File description:
** desc
*/

#include "my_map.h"
#include "my.h"

map_t *map_create(void)
{
    map_t *map = malloc(sizeof(map_t));

    map->name = NULL;
    map->origin = (sfVector2f){0, 0};
    map->size = (sfVector2i){0, 0};
    map->tiles = NULL;
    map->textures = texture_create();
    if (map->textures == NULL) {
        return (NULL);
    }
    map->camera = (sfVector2i){-1, -1};
    map->move = (sfVector2f){0, 0};
    map->status = 0;
    map->clock = sfClock_create();
    return (map);
}