/*
** EPITECH PROJECT, 2021
** world_edit_event
** File description:
** desc
*/

#include "my_world_edit.h"
#include "my_game.h"

void event_move_map(map_t *map, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyW)
            map->move.y = -15;
        if (event.key.code == sfKeyS)
            map->move.y = 15;
        if (event.key.code == sfKeyA)
            map->move.x = -15;
        if (event.key.code == sfKeyD)
            map->move.x = 15;
    }
    if (event.type == sfEvtKeyReleased) {
        if (event.key.code == sfKeyW)
            map->move.y = 0;
        if (event.key.code == sfKeyS)
            map->move.y = 0;
        if (event.key.code == sfKeyA)
            map->move.x = 0;
        if (event.key.code == sfKeyD)
            map->move.x = 0;
    }
}

void preview_event(my_game_t *rpg, world_edit_t *world_edit, map_t *map, \
sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyM) {
        if (world_edit->preview == false) {
            world_edit->preview = true;
            sfRenderWindow_clear(rpg->window.window, sfBlack);
            set_tile_preview(map, 17, (sfVector2f){-1920 / 2, 0});
            draw_preview(rpg->window.window, map);
            sfRenderWindow_display(rpg->window.window);
        }
    }
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyM) {
        if (world_edit->preview == true) {
            world_edit->preview = false;
            set_tile_preview(map, 130, map->origin);
        }
    }
}

void texture_scroll_event(sfEvent event, world_edit_t *world_edit, map_t *map)
{
    if ((world_edit->menu == TEXTURE || world_edit->menu == SPRITE) && \
    event.type == sfEvtMouseWheelScrolled) {
        if (event.mouseWheelScroll.delta > 0 && world_edit->scroll_texture > 0)
            world_edit->scroll_texture -= 4;
        if (event.mouseWheelScroll.delta < 0 && world_edit->scroll_texture + 4 \
            < map->textures[world_edit->menu - 1].nb_texture)
            world_edit->scroll_texture += 4;
    }
}

void world_edit_event(my_game_t *rpg, map_t *map, world_edit_t *world_edit)
{
    sfEvent event = rpg->window.event;

    while (sfRenderWindow_pollEvent(rpg->window.window, &event)) {
        if (event.type == sfEvtClosed) {
            rpg->scene = EXIT;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            rpg->scene = MAIN_MENU;
        }
        event_move_map(map, event);
        if (event.type == sfEvtMouseButtonPressed && \
            event.mouseButton.button == sfMouseLeft)
            map->status = CLICK;
        if (event.type == sfEvtMouseButtonReleased && \
            event.mouseButton.button == sfMouseLeft)
            map->status = ACTIVE;
        texture_scroll_event(event, world_edit, map);
        preview_event(rpg, world_edit, map, event);
    }
}