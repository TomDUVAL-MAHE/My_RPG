/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** inventory_scene_update_stats_two
*/

#include "my_inventory_scene.h"

void player_update_weapon_type(player_t *player, \
inventory_scene_t *inventory_scene)
{
    if (my_strcmp(inventory_scene->inventory_list_two[4][0], "BOW1") == 0)
        player->weapon_type = BOW;
    if (my_strcmp(inventory_scene->inventory_list_two[4][0], "BOW2") == 0)
        player->weapon_type = BOW;
    if (my_strcmp(inventory_scene->inventory_list_two[4][0], "BOW3") == 0)
        player->weapon_type = CROSSBOW;
    if (my_strcmp(inventory_scene->inventory_list_two[4][0], "AXE") == 0)
        player->weapon_type = AXE;
    if (my_strcmp(inventory_scene->inventory_list_two[4][0], "PICKAXE") == 0)
        player->weapon_type = PICKAXE;
    if (my_strcmp(inventory_scene->inventory_list_two[4][0], "WEAPON1") == 0)
        player->weapon_type = LONG_SWORD;
    if (my_strcmp(inventory_scene->inventory_list_two[4][0], "WEAPON2") == 0)
        player->weapon_type = LONG_SWORD;
    if (my_strcmp(inventory_scene->inventory_list_two[4][0], "WEAPON3") == 0)
        player->weapon_type = LONG_SWORD;
}