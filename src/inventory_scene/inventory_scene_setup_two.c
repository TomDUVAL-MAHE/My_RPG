/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_inventory_scene.h"

void inventory_scene_setup_three(inventory_scene_t *inventory_scene)
{
    inventory_scene->health_bar = malloc(sizeof(sfRectangleShape *) * 2);
    inventory_scene->health_bar[0] = sfRectangleShape_create();
    sfRectangleShape_setFillColor(inventory_scene->health_bar[0], \
    (sfColor){0, 0, 0, 0});
    sfRectangleShape_setOutlineColor(inventory_scene->health_bar[0], sfRed);
    sfRectangleShape_setOutlineThickness(inventory_scene->health_bar[0], 2);
    sfRectangleShape_setSize(inventory_scene->health_bar[0], (sfVector2f)\
    {inventory_scene->window_size.x * 0.23, inventory_scene->window_size.y * \
        0.04});
    inventory_scene_setup_health_bar(inventory_scene);
    inventory_scene->movement_texture = NULL;
}

inventory_scene_t inventory_scene_setup(sfRenderWindow *window, \
player_t *player)
{
    inventory_scene_t inventory_scene;

    inventory_scene.items = items_get_list();
    if (inventory_scene.items == NULL)
        return (inventory_scene);
    inventory_scene.window_size = sfRenderWindow_getSize(window);
    inventory_scene.inventory_list_one = create_inventory_list(\
    (sfVector2i){5, 5}, inventory_scene.items);
    inventory_scene.inventory_one = inventory_scene_create_inv_one\
    (window, inventory_scene.window_size, inventory_scene.items, \
    inventory_scene.inventory_list_one);
    inventory_scene.inventory_list_two = create_inventory_list(\
    (sfVector2i){1, 5}, inventory_scene.items);
    inventory_scene.inventory_two = inventory_scene_create_inv_two\
    (window, inventory_scene.window_size, inventory_scene.items, \
    inventory_scene.inventory_list_one);
    inventory_scene.picture_list = inventory_scene_picture_list_setup\
    (inventory_scene.window_size);
    inventory_scene_setup_two(&inventory_scene);
    update_stats(&inventory_scene, &(player->stats), player);
    return (inventory_scene);
}

void inventory_scene_setup_arrow_button(inventory_scene_t *inventory_scene)
{
    inventory_scene->arrow_button = malloc(sizeof(sfRectangleShape *) * 3);
    inventory_scene->arrow_button[0] = picture_setup(sfTexture_createFromFile\
    ("assets/inventory/arrow0.png", NULL), (sfVector2f)\
    {inventory_scene->window_size.x * 0.03, inventory_scene->window_size.y * \
        0.5}, (sfVector2f){inventory_scene->window_size.x * 0.05, \
        inventory_scene->window_size.y * 0.1});
    inventory_scene->arrow_button[1] = picture_setup(sfTexture_createFromFile\
    ("assets/inventory/arrow1.png", NULL), (sfVector2f)\
    {inventory_scene->window_size.x * 0.275, inventory_scene->window_size.y * \
        0.5}, (sfVector2f){inventory_scene->window_size.x * 0.05, \
        inventory_scene->window_size.y * 0.1});
    inventory_scene->scene = 0;
}

void inventory_scene_setup_two(inventory_scene_t *inventory_scene)
{
    inventory_scene_setup_case_limit(inventory_scene);
    inventory_scene->actual_sort = 0;
    inventory_scene->sorting_button = sfRectangleShape_create();
    sfRectangleShape_setSize(inventory_scene->sorting_button, (sfVector2f)\
    {inventory_scene->window_size.x * 0.17, \
        inventory_scene->window_size.y * 0.09});
    sfRectangleShape_setPosition(inventory_scene->sorting_button, \
    (sfVector2f){inventory_scene->window_size.x * 0.39 + \
        inventory_scene->window_size.x * 0.015, inventory_scene->window_size.y \
        * 0.49 + inventory_scene->window_size.y * 0.03});
    sfRectangleShape_setTexture(inventory_scene->sorting_button, \
    sfTexture_createFromFile("assets/inventory/sorting_one.png", NULL), true);
    inventory_scene_setup_three(inventory_scene);
    inventory_scene->dir = 0;
    inventory_scene_setup_arrow_button(inventory_scene);
}