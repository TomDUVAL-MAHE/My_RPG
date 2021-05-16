/*
** EPITECH PROJECT, 2021
** world_edit_hover_and_click
** File description:
** desc
*/

#include "my_world_edit.h"

void check_tile(map_t *map, world_edit_t *menu, sfVector2f p, sfVector2i index)
{
    int i = index.y;
    int j = index.x;

    if (in_tile(map->tiles[i * map->size.x + j], p)) {
        if (map->status == CLICK)
            menu->tile_selected = index;
        menu->tile_hover = index;
    }
}

void tile_hover_and_click(map_t *map, world_edit_t *menu, \
sfRenderWindow *window)
{
    int i = (map->camera.y - 15 > 0) ? map->camera.y - 15 : 0;
    int j = (map->camera.x - 15 > 0) ? map->camera.x - 15 : 0;
    sfVector2i point = sfMouse_getPositionRenderWindow(window);
    sfVector2f p = {point.x + map->origin.x, point.y + map->origin.y};
    sfVector2u w_size = sfRenderWindow_getSize(window);

    if (point.x > w_size.x - menu->size.x)
        return;
    for (; i < map->camera.y + 15 && i < map->size.y; i++) {
        for (; j < map->camera.x + 15 && j < map->size.x; j++) {
            check_tile(map, menu, p, (sfVector2i){j, i});
        }
        j = (map->camera.x - 15 > 0) ? map->camera.x - 15 : 0;
    }
}

void draw_hover_and_click(sfRenderWindow *window, map_t *map, \
world_edit_t *menu)
{
    int index = menu->tile_hover.y * map->size.x + menu->tile_hover.x;

    sfConvexShape_setOutlineThickness(map->tiles[index].shape, 3);
    sfRenderWindow_drawConvexShape(window, map->tiles[index].shape, NULL);
    index = menu->tile_selected.y * map->size.x + menu->tile_selected.x;
    sfConvexShape_setOutlineThickness(map->tiles[index].shape, 3);
    sfRenderWindow_drawConvexShape(window, map->tiles[index].shape, NULL);
}