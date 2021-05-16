/*
** EPITECH PROJECT, 2021
** world_edit_preview
** File description:
** desc
*/

#include "my_world_edit.h"

void draw_convex_shape_preview(sfRenderWindow *window, map_t *map, int i, int j)
{
    sfConvexShape *convex = map->tiles[i * map->size.x + j].shape;

    sfConvexShape_setTexture(convex, map->textures[0].texture[map->tiles\
    [map->size.x * i + j].ground], sfTrue);
    sfConvexShape_setOutlineThickness(convex, 0);
    sfConvexShape_setOutlineColor(convex, sfBlack);
    sfRenderWindow_drawConvexShape(window, convex, NULL);
}

void select_build_preview(sfRectangleShape *shape, int building, sfVector2f pos)
{
    if (building >= 1 && building <= 3) {
        pos.x -= 150 / 8;
        pos.y -= 200 / 8;
        sfRectangleShape_setSize(shape, (sfVector2f){400 / 8, 250 / 8});
    }
    if (building >= 4) {
        pos.x -= 50 / 8;
        pos.y -= 50 / 8;
        sfRectangleShape_setSize(shape, (sfVector2f){100 / 8, 100 / 8});
    }
    sfRectangleShape_setPosition(shape, pos);
}

void draw_build_preview(sfRenderWindow *window, map_t *map, int i, int j)
{
    sfRectangleShape *shape = NULL;
    int id = i * map->size.x + j;

    if (map->tiles[id].building <= 0)
        return;
    if (map->tiles[id].building == 99)
        return;
    shape = sfRectangleShape_create();
    sfRectangleShape_setTexture(shape, map->textures[1].texture[map->tiles\
    [id].building], sfTrue);
    select_build_preview(shape, map->tiles[id].building, map->tiles[id].pos);
    sfRectangleShape_setOrigin(shape, (sfVector2f){-1920 / 2, 0});
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRectangleShape_destroy(shape);
}

void draw_preview(sfRenderWindow *window, map_t *map)
{
    sfVector2u w_size = sfRenderWindow_getSize(window);

    if (sfClock_getElapsedTime(map->clock).microseconds > 10000) {
        map_move_origin(map, map->move);
        sfClock_restart(map->clock);
    }
    find_camera_pos(map, w_size);
    for (int i = 0; i < map->size.y; i++) {
        for (int j = 0; j < map->size.x; j++) {
            draw_convex_shape_preview(window, map, i, j);
        }
    }
    for (int i = 0; i < map->size.y; i++) {
        for (int j = 0; j < map->size.x; j++) {
            draw_build_preview(window, map, i, j);
        }
    }
}

void set_tile_preview(map_t *map, int zoom, sfVector2f origin)
{
    int index = 0;

    for (int i = 0; i < map->size.y; i++) {
        for (int j = 0; j < map->size.x; j++) {
            index = i * map->size.x + j;
            sfConvexShape_destroy(map->tiles[index].shape);
            free(map->tiles[index].vector);
            map->tiles[index] = tile_set\
            (map->tiles[index].ground, map->tiles[index].building, zoom);
            map->tiles[index].pos = iso_projection(j, i, 0, zoom);
            tile_set_position(&map->tiles[index], map->tiles[index].pos);
            tile_set_texture(&map->tiles[index], map->textures[0].texture);
            tile_set_origin(&map->tiles[i * map->size.x + j], origin);
        }
    }
}