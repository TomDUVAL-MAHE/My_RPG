/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_inventory_scene.h"

bool button_is_touch(sfVector2f pos, sfVector2f size, sfVector2i mouse_pos)
{
    if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + size.x && mouse_pos.y \
        >= pos.y && mouse_pos.y <= pos.y + size.y)
        return (true);
    return (false);
}

void inventory_scene_change_man_dir(inventory_scene_t *inventory_scene, \
int dir, player_t *player)
{
    inventory_scene->dir += dir;
    if (inventory_scene->dir == -1)
        inventory_scene->dir = 3;
    if (inventory_scene->dir == 4)
        inventory_scene->dir = 0;
    inventory_update_list(inventory_scene->inventory_two, \
    inventory_scene->items, inventory_scene->inventory_list_two);
    update_picture(inventory_scene, true, player);
}

void inventory_scene_change_scene(inventory_scene_t *inventory_scene, \
int scene)
{
    inventory_scene->scene = scene;
}

void inventory_scene_delete_item(inventory_scene_t *inventory_scene)
{
    inventory_scene->movement_texture = NULL;
    inventory_scene->inventory_one->is_movement = false;
    inventory_scene->inventory_two->is_movement = false;
}

void inventory_scene_detect_button(inventory_scene_t *inventory_scene, \
sfVector2i mouse_pos, player_t *player)
{
    if (button_is_touch(sfRectangleShape_getPosition\
        (inventory_scene->sorting_button), sfRectangleShape_getSize\
        (inventory_scene->sorting_button), mouse_pos) == true)
        sorting_action(inventory_scene);
    if (button_is_touch(sfRectangleShape_getPosition\
        (inventory_scene->arrow_button[0]), sfRectangleShape_getSize\
        (inventory_scene->arrow_button[0]), mouse_pos) == true)
        inventory_scene_change_man_dir(inventory_scene, 1, player);
    if (button_is_touch(sfRectangleShape_getPosition\
        (inventory_scene->arrow_button[1]), sfRectangleShape_getSize\
        (inventory_scene->arrow_button[1]), mouse_pos) == true)
        inventory_scene_change_man_dir(inventory_scene, -1, player);
    if (button_is_touch(sfRectangleShape_getPosition\
        (inventory_scene->picture_list[3]), sfRectangleShape_getSize\
        (inventory_scene->picture_list[3]), mouse_pos) == true)
        inventory_scene_change_scene(inventory_scene, 1);
    if (button_is_touch(sfRectangleShape_getPosition\
        (inventory_scene->picture_list[8]), sfRectangleShape_getSize\
        (inventory_scene->picture_list[8]), mouse_pos) == true)
        inventory_scene_delete_item(inventory_scene);
}