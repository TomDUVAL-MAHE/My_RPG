/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_inventory_scene.h"

void inventory_scene_setup_attack_bar(inventory_scene_t *inventory_scene)
{
    inventory_scene->attack_bar = sfRectangleShape_create();
    sfRectangleShape_setFillColor(inventory_scene->attack_bar, \
    (sfColor){198, 110, 3, 255});
    sfRectangleShape_setOutlineColor(inventory_scene->attack_bar, \
    (sfColor){198, 110, 3, 255});
    sfRectangleShape_setOutlineThickness(inventory_scene->attack_bar, 2);
    sfRectangleShape_setSize(inventory_scene->attack_bar, (sfVector2f)\
    {inventory_scene->window_size.x * 0.23, inventory_scene->window_size.y \
        * 0.04});
    sfRectangleShape_setPosition(inventory_scene->attack_bar, (sfVector2f)\
    {inventory_scene->window_size.x * 0.06, inventory_scene->window_size.y * \
        0.69 + inventory_scene->window_size.y * 0.03});
}

void inventory_scene_setup_health_bar(inventory_scene_t *inventory_scene)
{
    sfRectangleShape_setPosition(inventory_scene->health_bar[0], (sfVector2f)\
    {inventory_scene->window_size.x * 0.06, inventory_scene->window_size.y * \
        0.75 + inventory_scene->window_size.y * 0.03});
    inventory_scene->health_bar[1] = sfRectangleShape_create();
    sfRectangleShape_setFillColor(inventory_scene->health_bar[1], sfRed);
    sfRectangleShape_setSize(inventory_scene->health_bar[1], (sfVector2f)\
    {inventory_scene->window_size.x * 0.23, inventory_scene->window_size.y * \
        0.04});
    sfRectangleShape_setPosition(inventory_scene->health_bar[1], (sfVector2f)\
    {inventory_scene->window_size.x * 0.06, inventory_scene->window_size.y * \
        0.75 + inventory_scene->window_size.y * 0.03});
    inventory_scene_setup_attack_bar(inventory_scene);
    inventory_scene_setup_four(inventory_scene);
}

void inventory_scene_setup_level_bar(inventory_scene_t *inventory_scene)
{
    sfRectangleShape_setPosition(inventory_scene->level_bar[0], (sfVector2f)\
    {inventory_scene->window_size.x * 0.06, inventory_scene->window_size.y * \
        0.75 + inventory_scene->window_size.y * 0.09});
    inventory_scene->level_bar[1] = sfRectangleShape_create();
    sfRectangleShape_setFillColor(inventory_scene->level_bar[1], sfCyan);
    sfRectangleShape_setSize(inventory_scene->level_bar[1], (sfVector2f)\
    {inventory_scene->window_size.x * 0.23, inventory_scene->window_size.y * \
        0.04});
    sfRectangleShape_setPosition(inventory_scene->level_bar[1], (sfVector2f)\
    {inventory_scene->window_size.x * 0.06, inventory_scene->window_size.y * \
        0.75 + inventory_scene->window_size.y * 0.09});
    inventory_scene_setup_five(inventory_scene);
}