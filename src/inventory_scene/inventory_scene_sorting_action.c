/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_inventory_scene.h"

void sorting_action_two(inventory_scene_t *inventory_scene)
{
    if (inventory_scene->actual_sort == 2) {
        sfRectangleShape_setTexture(inventory_scene->sorting_button, \
        sfTexture_createFromFile("assets/inventory/sorting_four.png", NULL), \
        true);
        inventory_scene->actual_sort += 1;
        inventory_sort_list(inventory_scene->inventory_one, \
        inventory_scene->items, inventory_scene->inventory_list_one, "HEALTH");
        return;
    }
    if (inventory_scene->actual_sort == 3) {
        sfRectangleShape_setTexture(inventory_scene->sorting_button, \
        sfTexture_createFromFile("assets/inventory/sorting_five.png", NULL), \
        true);
        inventory_scene->actual_sort += 1;
        inventory_sort_list(inventory_scene->inventory_one, \
        inventory_scene->items, inventory_scene->inventory_list_one, "TYPE");
        return;
    }
}

void sorting_action_three(inventory_scene_t *inventory_scene)
{
    if (inventory_scene->actual_sort == 4)
        inventory_scene->actual_sort = 0;
}

void sorting_action(inventory_scene_t *inventory_scene)
{
    sorting_action_three(inventory_scene);
    if (inventory_scene->actual_sort == 0) {
        sfRectangleShape_setTexture(inventory_scene->sorting_button, \
        sfTexture_createFromFile("assets/inventory/sorting_two.png", NULL), \
        true);
        inventory_scene->actual_sort += 1;
        inventory_sort_list(inventory_scene->inventory_one, \
        inventory_scene->items, inventory_scene->inventory_list_one, "NAME");
        return;
    }
    if (inventory_scene->actual_sort == 1) {
        sfRectangleShape_setTexture(inventory_scene->sorting_button, \
        sfTexture_createFromFile("assets/inventory/sorting_three.png", NULL), \
        true);
        inventory_scene->actual_sort += 1;
        inventory_sort_list(inventory_scene->inventory_one, \
        inventory_scene->items, inventory_scene->inventory_list_one, "ATTACK");
        return;
    }
    return (sorting_action_two(inventory_scene));
}