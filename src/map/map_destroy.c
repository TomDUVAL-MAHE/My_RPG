/*
** EPITECH PROJECT, 2021
** map_destroy
** File description:
** desc
*/

#include "my_map.h"

void tile_destroy(tile_t *tiles, int size)
{
    for (int i = 0; i < size; i++) {
        if (tiles[i].shape != NULL)
            sfConvexShape_destroy(tiles[i].shape);
        if (tiles[i].vector != NULL)
            free(tiles[i].vector);
    }
    if (tiles != NULL)
        free(tiles);
}

void textures_destroy(textures_t *textures)
{
    for (int i = 0; i < textures[0].nb_texture; i++) {
        if (textures[0].texture[i] != NULL)
            sfTexture_destroy(textures[0].texture[i]);
    }
    if (textures[0].texture != NULL)
        free(textures[0].texture);
    for (int i = 0; i < textures[1].nb_texture; i++) {
        if (textures[1].texture[i] != NULL)
            sfTexture_destroy(textures[1].texture[i]);
    }
    if (textures[1].texture != NULL)
        free(textures[1].texture);
    if (textures != NULL)
        free(textures);
}

void map_destroy(map_t *map)
{
    if (map->name != NULL)
        free(map->name);
    if (map->tiles != NULL)
        tile_destroy(map->tiles, map->size.x * map->size.y);
    if (map->textures != NULL)
        textures_destroy(map->textures);
    if (map->clock != NULL)
        sfClock_destroy(map->clock);
    if (map != NULL)
        free(map);
}