/*
** EPITECH PROJECT, 2021
** world_edit
** File description:
** desc
*/

#include "my_game.h"
#include "my_world_edit.h"

map_t *init_world_edit_map(void)
{
    map_t *map = map_create();

    map_set_size(map, (sfVector2i){100, 100});
    map->camera = (sfVector2i){10, 10};
    map->origin = (sfVector2f){-100, -100};
    map_set_tiles(map, 130);
    map_set_origin(map, (sfVector2f){-100, -100});
    return (map);
}

void we_draw_build(my_game_t *rpg, map_t *map)
{
    int i = 0;
    int j = 0;

    i = (map->camera.y - 15 > 0) ? map->camera.y - 15 : 0;
    for (; i < map->camera.y + 15 && i < map->size.y; i++) {
        for (; j < map->camera.x + 15 && j < map->size.x; j++) {
            draw_build(rpg->window.window, map, i, j);
        }
        j = (map->camera.x - 15 > 0) ? map->camera.x - 15 : 0;
    }
}

void start_world_edit(my_game_t *rpg, map_t *map, world_edit_t *world_edit)
{
    sfVector2u w_size = sfRenderWindow_getSize(rpg->window.window);

    if (map == NULL || world_edit == NULL) {
        my_putstr("fail to load world_edit\n");
        rpg->scene = MAIN_MENU;
    }
    world_edit_set_size(world_edit, (sfVector2f){400, w_size.y});
    world_edit_set_position(world_edit, (sfVector2f){w_size.x - 400, 0});
    world_edit_set_color(world_edit, (sfColor){30, 30, 30, 255});

}

void world_edit(my_game_t *rpg)
{
    world_edit_t *world_edit = world_edit_create(rpg->window.window);
    map_t *map = init_world_edit_map();

    start_world_edit(rpg, map, world_edit);
    while (rpg->scene == WORLD_EDIT) {
        world_edit_event(rpg, map, world_edit);
        if (world_edit->preview == false) {
            sfRenderWindow_clear(rpg->window.window, sfBlack);
            map_display(rpg->window.window, map);
            we_draw_build(rpg, map);
            world_edit_display(rpg->window.window, world_edit, map);
            sfRenderWindow_display(rpg->window.window);
        }
    }
    map_destroy(map);
    world_edit_destroy(world_edit);
    scene_manager(rpg);
}