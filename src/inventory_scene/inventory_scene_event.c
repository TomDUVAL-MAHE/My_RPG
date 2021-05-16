/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_inventory_scene.h"

void inventory_scene_event_gestion(inventory_scene_t *inventory_scene, \
sfVector2i mouse_pos, stats_t *stats, player_t *player)
{
    inventory_scene_detect_button(inventory_scene, mouse_pos, player);
    if (inventory_detect_case(inventory_scene->inventory_one, mouse_pos, \
    inventory_scene->items, inventory_scene) == true) {
        inventory_scene->inventory_two->is_movement = false;
        update_stats(inventory_scene, stats, player);
    }
    inventory_scene_echange_inventory_one(inventory_scene);
    if (inventory_detect_case(inventory_scene->inventory_two, mouse_pos, \
    inventory_scene->items, inventory_scene) == true) {
        inventory_scene->inventory_one->is_movement = false;
        update_stats(inventory_scene, stats, player);
    }
    inventory_scene_echange_inventory_two(inventory_scene);
}
