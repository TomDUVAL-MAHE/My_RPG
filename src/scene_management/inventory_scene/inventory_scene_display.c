/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** scene_display
*/

#include "my_game.h"
#include "my_inventory_scene.h"

void q_inventory_scene_display(my_game_t *rpg)
{
    update_stats(&(rpg->inventory_scene), &(rpg->game->player->stats), \
    rpg->game->player);
    while (rpg->scene == INVENTORY) {
        get_time(rpg);
        sfRenderWindow_clear(rpg->window.window, sfBlack);
        inventory_scene_events(rpg, &(rpg->inventory_scene), \
        rpg->window.event, &(rpg->skill_scene));
        if (rpg->scene != INVENTORY)
            break;
        if (rpg->inventory_scene.scene == 0)
            inventory_scene_display(&(rpg->inventory_scene), \
            rpg->window.window);
        else
            skill_scene_display(&(rpg->skill_scene), rpg->window.window);
        sfRenderWindow_display(rpg->window.window);
    }
    scene_manager(rpg);
}