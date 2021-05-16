/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** scene_display
*/

#include "my_game.h"

void quest_scene_manager(my_game_t *rpg)
{
    quest_scene_update(&(rpg->quest_scene), rpg->quest_list, rpg);
    while (rpg->scene == QUEST) {
        get_time(rpg);
        sfRenderWindow_clear(rpg->window.window, sfBlack);
        quest_scene_event(rpg, rpg->window.event);
        if (rpg->scene != QUEST)
            break;
        quest_scene_display(&(rpg->quest_scene), rpg->window);
        sfRenderWindow_display(rpg->window.window);
    }
    scene_manager(rpg);
}