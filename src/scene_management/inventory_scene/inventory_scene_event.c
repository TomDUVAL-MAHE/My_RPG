/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** scene_display
*/

#include "my_game.h"
#include "my_inventory_scene.h"

void inventory_scene_key(my_game_t *rpg, sfEvent event)
{
    if (event.key.code == sfKeyE || event.key.code == sfKeyEscape) {
        go_to_game_scene(rpg);
    }
    if (event.key.code == sfKeyI) {
        go_to_quest_scene(rpg);
    }
}

void inventory_scene_events(my_game_t *rpg, \
inventory_scene_t *inventory_scene, sfEvent event, skill_scene_t *skill_scene)
{
    while (sfRenderWindow_pollEvent(rpg->window.window, &(event))) {
        if (event.type == sfEvtClosed)
            rpg->scene = EXIT;
        if (event.type == sfEvtKeyPressed)
            inventory_scene_key(rpg, event);
        if (event.type == sfEvtJoystickButtonPressed && \
            event.joystickButton.button == 2)
            go_to_game_scene(rpg);
        if (event.type == sfEvtMouseButtonPressed && \
        inventory_scene->scene == 0) {
            inventory_scene_event_gestion(inventory_scene, \
            sfMouse_getPositionRenderWindow(rpg->window.window), \
            &(rpg->game->player->stats), rpg->game->player);
        } else if (event.type == sfEvtMouseButtonPressed && \
        inventory_scene->scene == 1) {
            skill_scene_event_gestion(skill_scene, \
            sfMouse_getPositionRenderWindow(rpg->window.window), \
            inventory_scene);
        }
    }
}