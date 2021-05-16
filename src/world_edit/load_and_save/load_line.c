/*
** EPITECH PROJECT, 2021
** load_line.c
** File description:
** desc
*/

#include "my_world_edit.h"
#include "my.h"

void load_map_origin(map_t *map, char *line)
{
    int i = 0;

    map->origin.x = my_getnbr(line);
    while (line[i]) {
        if (line[i] == ',')
            break;
        i++;
    }
    i++;
    map->origin.y = my_getnbr(line + i);
}

void load_map_camera(map_t *map, char *line)
{
    int i = 0;

    map->camera.x = my_getnbr(line);
    while (line[i]) {
        if (line[i] == ',')
            break;
        i++;
    }
    i++;
    map->camera.y = my_getnbr(line + i);
}

char *load_map_one_tile(map_t *map, char *line, int i, int j)
{
    int index = i * map->size.x + j;
    int ground = 0;
    int build = 0;

    index = i * map->size.x + j;
    ground = my_getnbr(line);
    while (*line != ',')
        line++;
    line++;
    build = my_getnbr(line);
    while (*line != ';')
        line++;
    line++;
    map->tiles[index] = tile_set(ground, build, 130);
    map->tiles[index].pos = iso_projection(j, i, 0, 130);
    tile_set_position(&map->tiles[index], map->tiles[index].pos);
    tile_set_texture(&map->tiles[index], map->textures[0].texture);
    tile_set_origin(&map->tiles[i * map->size.x + j], map->origin);
    return (line);
}

void load_map_tiles(map_t *map, char *line)
{
    tile_destroy(map->tiles, map->size.x * map->size.y);
    map->tiles = malloc(sizeof(tile_t) * (map->size.x * map->size.y));
    for (int i = 0; i < map->size.y; i++) {
        for (int j = 0; j < map->size.x; j++) {
            line = load_map_one_tile(map, line, i, j);
        }
    }
}

void select_load_map(map_t *map, char *line, int nb_line)
{
    switch (nb_line) {
    case 1:
        load_map_size(map, line);
        break;
    case 2:
        load_map_origin(map, line);
        break;
    case 3:
        load_map_camera(map, line);
        break;
    case 4:
        load_map_tiles(map, line);
        break;
    }
}