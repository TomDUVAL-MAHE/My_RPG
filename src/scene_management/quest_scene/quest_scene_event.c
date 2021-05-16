/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** scene_display
*/

#include "my_game.h"

void quest_scene_key(my_game_t *rpg, sfEvent event)
{
    if (event.key.code == sfKeyI || event.key.code == sfKeyEscape) {
        go_to_game_scene(rpg);
    }
    if (event.key.code == sfKeyE) {
        go_to_inventory_scene(rpg);
    }
    if (event.key.code == sfKeyA) {
        rpg->quest_scene.actual_slide += 3;
        quest_scene_update(&(rpg->quest_scene), rpg->quest_list, rpg);
    }
}

void quest_scene_wheel(my_game_t *rpg, sfEvent event)
{
    if (event.mouseWheelScroll.delta < 0) {
        rpg->quest_scene.actual_slide += 3;
        quest_scene_update(&(rpg->quest_scene), rpg->quest_list, rpg);
    }
    if (event.mouseWheelScroll.delta > 0) {
        rpg->quest_scene.actual_slide -= 3;
        if (rpg->quest_scene.actual_slide < 0)
            rpg->quest_scene.actual_slide = 0;
        quest_scene_update(&(rpg->quest_scene), rpg->quest_list, rpg);
    }
}

void quest_scene_event(my_game_t *rpg, sfEvent event)
{
    while (sfRenderWindow_pollEvent(rpg->window.window, &(event))) {
        if (event.type == sfEvtClosed)
            rpg->scene = EXIT;
        if (event.type == sfEvtKeyPressed) {
            quest_scene_key(rpg, event);
        }
        if (event.type == sfEvtMouseWheelScrolled) {
            quest_scene_wheel(rpg, event);
        }
    }
}