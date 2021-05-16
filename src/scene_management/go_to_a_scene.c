/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** go_to_a_scene
*/

#include "my_game.h"

void go_to_a_scene(my_game_t *rpg, scene_id scene)
{
    rpg->scene = scene;
}

void go_to_game_scene(my_game_t *rpg)
{
    go_to_a_scene(rpg, GAME);
}

void go_to_main_menu_scene(my_game_t *rpg)
{
    rpg->main_menu.main_part.displayed = true;
    rpg->main_menu.play_part.displayed = false;
    go_to_a_scene(rpg, MAIN_MENU);
}