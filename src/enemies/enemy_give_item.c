/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_give_item
*/

#include "my_enemy.h"
#include "my_game.h"

void enemy_give_item_lvl_one(my_game_t *rpg)
{
    int r = rand() % 4;
    char ***inv_tab = rpg->inventory_scene.inventory_list_one;
    inventory_t *rpg_inv = rpg->inventory_scene.inventory_one;
    item_t *item = rpg->inventory_scene.items;

    if (r == 0)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "ARMOR1");
    if (r == 1)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "SHOES1");
    if (r == 2)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "HAT1");
    if (r == 3)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "WEAPON1");
}

void enemy_give_item_lvl_two(my_game_t *rpg)
{
    int r = rand() % 7;
    char ***inv_tab = rpg->inventory_scene.inventory_list_one;
    inventory_t *rpg_inv = rpg->inventory_scene.inventory_one;
    item_t *item = rpg->inventory_scene.items;

    if (r == 0)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "ARMOR2");
    if (r == 1)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "SHOES2");
    if (r == 2)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "HAT2");
    if (r == 3)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "WEAPON2");
    if (r == 4)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "NECK1");
    if (r == 5)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "NECK2");
    if (r == 6)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "NECK3");
}

void enemy_give_item_lvl_three_two(my_game_t *rpg, int r)
{
    char ***inv_tab = rpg->inventory_scene.inventory_list_one;
    inventory_t *rpg_inv = rpg->inventory_scene.inventory_one;
    item_t *item = rpg->inventory_scene.items;

    if (r == 6)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "NECK3");
    if (r == 7)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "BOW1");
    if (r == 8)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "BOW2");
    if (r == 9)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "BOW3");
}

void enemy_give_item_lvl_three(my_game_t *rpg)
{
    int r = rand() % 7;
    char ***inv_tab = rpg->inventory_scene.inventory_list_one;
    inventory_t *rpg_inv = rpg->inventory_scene.inventory_one;
    item_t *item = rpg->inventory_scene.items;

    r = rand() % 10;
    if (r == 0)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "ARMOR3");
    if (r == 1)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "SHOES3");
    if (r == 2)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "HAT3");
    if (r == 3)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "WEAPON3");
    if (r == 4)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "NECK1");
    if (r == 5)
        inventory_add_item_to_list(rpg_inv, item, inv_tab, "NECK2");
    enemy_give_item_lvl_three_two(rpg, r);
}

void enemy_give_item(my_game_t *rpg, int level)
{
    if (level == 1)
        enemy_give_item_lvl_one(rpg);
    if (level == 2)
        enemy_give_item_lvl_two(rpg);
    if (level == 3)
        enemy_give_item_lvl_three(rpg);
}