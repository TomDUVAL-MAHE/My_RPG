/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_game.h"

void inventory_scene_echange_inventory_one(inventory_scene_t *inventory_scene)
{
    if (my_strcmp(item_return_name(inventory_scene->items, \
    inventory_scene->movement_texture), "EMPTY") != 0) {
        inventory_scene->inventory_two->movement_texture = \
        inventory_scene->movement_texture;
        inventory_scene->inventory_two->movement_pos = (sfVector2i){0, 0};
        inventory_scene->inventory_two->movement_buffer = \
        item_return_info(inventory_scene->items, item_return_name\
        (inventory_scene->items, inventory_scene->movement_texture));
        inventory_scene->inventory_two->is_movement = true;
        inventory_scene->movement_texture = NULL;
    }
}

void inventory_scene_echange_inventory_two(inventory_scene_t *inventory_scene)
{
    if (my_strcmp(item_return_name(inventory_scene->items, \
    inventory_scene->movement_texture), "EMPTY") != 0) {
        inventory_scene->inventory_one->movement_texture = \
        inventory_scene->movement_texture;
        inventory_scene->inventory_one->movement_pos = (sfVector2i){0, 0};
        inventory_scene->inventory_one->movement_buffer = \
        item_return_info(inventory_scene->items, item_return_name\
        (inventory_scene->items, inventory_scene->movement_texture));
        inventory_scene->inventory_one->is_movement = true;
        inventory_scene->movement_texture = NULL;
    }
}