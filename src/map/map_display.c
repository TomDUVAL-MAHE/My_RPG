/*
** EPITECH PROJECT, 2021
** map_display
** File description:
** desc
*/

#include "my_map.h"

int in_window(map_t *map, int i, sfVector2u w_size)
{
    int res = 0;

    if (map->tiles[i].pos.x - map->origin.x - map->tiles[i].vector[3].x >= 0)
        res++;
    if (map->tiles[i].pos.x - map->origin.x <= w_size.x)
        res++;
    if (map->tiles[i].pos.y - map->origin.y + map->tiles[i].vector[2].y >= 0)
        res++;
    if (map->tiles[i].pos.y - map->origin.y <= w_size.y)
        res++;
    if (res == 4)
        return (1);
    return (0);
}

void draw_convex_shape(sfRenderWindow *window, map_t *map, int i, int j)
{
    sfConvexShape *convex = map->tiles[i * map->size.x + j].shape;

    sfConvexShape_setTexture(convex, map->textures[0].texture[map->tiles\
    [map->size.x * i + j].ground], sfTrue);
    sfConvexShape_setOutlineThickness(convex, 1);
    sfConvexShape_setOutlineColor(convex, (sfColor){100, 70, 36, 255});
    sfRenderWindow_drawConvexShape(window, convex, NULL);
}

void select_build(sfRectangleShape *shape, int building, sfVector2f pos)
{
    if (building >= 1 && building <= 3) {
        pos.x -= 150;
        pos.y -= 200;
        sfRectangleShape_setSize(shape, (sfVector2f){400, 250});
    }
    if (building >= 4) {
        pos.x -= 50;
        pos.y -= 50;
        sfRectangleShape_setSize(shape, (sfVector2f){100, 100});
    }
    sfRectangleShape_setPosition(shape, pos);
}

void draw_build(sfRenderWindow *window, map_t *map, int i, int j)
{
    sfRectangleShape *shape = NULL;

    if (map->tiles[i * map->size.x + j].building <= 0)
        return;
    if (map->tiles[i * map->size.x + j].building == 99)
        return;
    shape = sfRectangleShape_create();
    sfRectangleShape_setTexture(shape, map->textures[1].texture[map->tiles\
    [i * map->size.x + j].building], sfTrue);
    select_build(shape, map->tiles[i * map->size.x + j].building, \
    map->tiles[i * map->size.x + j].pos);
    sfRectangleShape_setOrigin(shape, map->origin);
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
    sfRectangleShape_destroy(shape);
}

void map_display(sfRenderWindow *window, map_t *map)
{
    sfVector2u w_size = sfRenderWindow_getSize(window);
    int i = (map->camera.y - 15 > 0) ? map->camera.y - 15 : 0;
    int j = (map->camera.x - 15 > 0) ? map->camera.x - 15 : 0;

    if (sfClock_getElapsedTime(map->clock).microseconds > 10000) {
        map_move_origin(map, map->move);
        sfClock_restart(map->clock);
    }
    find_camera_pos(map, w_size);
    for (; i < map->camera.y + 15 && i < map->size.y; i++) {
        for (; j < map->camera.x + 15 && j < map->size.x; j++) {
            cam_pos(map, i, j, w_size);
            draw_convex_shape(window, map, i, j);
        }
        j = (map->camera.x - 15 > 0) ? map->camera.x - 15 : 0;
    }
}