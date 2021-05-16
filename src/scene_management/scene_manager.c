/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** scene_manager
*/

#include "my_game.h"

void scene_manager(my_game_t *rpg)
{
    switch (rpg->scene) {
    case EXIT:
        destroy_rpg(rpg);
        return;
    case MAIN_MENU:
        main_menu_scene_display(rpg);
        break;
    case GAME:
        game_scene_display(rpg);
        break;
    case INVENTORY:
        q_inventory_scene_display(rpg);
        break;
    case QUEST:
        quest_scene_manager(rpg);
        break;
    case WORLD_EDIT:
        world_edit(rpg);
        break;
    }
}