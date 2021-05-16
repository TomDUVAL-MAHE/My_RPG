/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_inventory_scene.h"

void inventory_scene_unlock_bow(inventory_scene_t *inventory_scene)
{
    inventory_scene->items[4].type = 8;
    inventory_scene->items[5].type = 8;
    inventory_scene->items[6].type = 8;
}

void inventory_scene_unlock_axe(inventory_scene_t *inventory_scene)
{
    inventory_scene->items[3].type = 8;
}

void inventory_scene_unlock_pickaxe(inventory_scene_t *inventory_scene)
{
    inventory_scene->items[13].type = 8;
}

void inventory_scene_unlock_ring(inventory_scene_t *inventory_scene)
{
    inventory_scene->items[10].type = 6;
    inventory_scene->items[11].type = 6;
    inventory_scene->items[12].type = 6;
}