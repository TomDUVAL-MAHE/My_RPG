/*
** EPITECH PROJECT, 2021
** go_to_a_scene
** File description:
** desc
*/

#include "my_game.h"

void go_to_inventory_scene(my_game_t *rpg)
{
    go_to_a_scene(rpg, INVENTORY);
}

void go_to_world_edit_scene(my_game_t *rpg)
{
    go_to_a_scene(rpg, WORLD_EDIT);
}

void go_to_quest_scene(my_game_t *rpg)
{
    go_to_a_scene(rpg, QUEST);
}