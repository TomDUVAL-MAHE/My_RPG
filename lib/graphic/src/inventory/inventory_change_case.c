/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory.h"

sfVector2i inventory_cursor_is_in_case(inventory_t *inventory, \
sfVector2i mouse_pos)
{
    sfVector2i r = {0, 0};

    for (int i = 0; i < inventory->cases_number.y; i++) {
        r = inventory_cursor_is_in_cases(inventory, mouse_pos, i);
        if (r.x != -1)
            return (r);
    }
    return ((sfVector2i){-1, -1});
}

void inventory_detect_case_two(inventory_t *inventory, \
sfVector2i pos, inventory_scene_t *inventory_scene)
{
    sfTexture *texture_save = inventory->cases[pos.y][pos.x].texture;
    char *buffer_save = inventory->cases[pos.y][pos.x].info.text.buffer;

    inventory->is_movement = true;
    inventory_copy_case(inventory, pos);
    inventory->movement_texture = texture_save;
    inventory_scene->movement_texture = texture_save;
    inventory->movement_buffer = buffer_save;
    inventory->movement_pos = pos;
}

bool inventory_check_type(inventory_t *inventory, sfVector2i pos, \
item_t *items)
{
    if (inventory->is_movement == false)
        return (true);
    if (inventory->cases[pos.y][pos.x].type_limit == -1)
        return (true);
    if (item_return_type(items, item_return_name(items, \
        inventory->movement_texture)) == \
        inventory->cases[pos.y][pos.x].type_limit)
        return (true);
    return (false);
}

void inventory_detect_case_three(inventory_t *inventory, sfVector2i pos, \
inventory_scene_t *inventory_scene)
{
    inventory->is_movement = true;
    inventory->movement_pos = pos;
    inventory->movement_texture = inventory->cases[pos.y][pos.x].texture;
    inventory->movement_buffer = inventory->cases[pos.y][pos.x].\
    info.text.buffer;
    inventory_scene->movement_texture = inventory->cases[pos.y][pos.x].texture;
    inventory_unfill_case(inventory, inventory->movement_pos);
}

bool inventory_detect_case(inventory_t *inventory, sfVector2i mouse_pos, \
item_t *items, inventory_scene_t *inventory_scene)
{
    sfVector2i pos = inventory_cursor_is_in_case(inventory, mouse_pos);

    if (inventory->is_display == false || pos.x == -1)
        return (false);
    if (inventory_check_type(inventory, pos, items) == false)
        return (false);
    if (inventory->is_movement == true && !inventory->cases[pos.y]\
    [pos.x].is_display) {
        inventory_copy_case(inventory, pos);
        inventory->is_movement = false;
        return (true);
    } else if (inventory->is_movement == true) {
        inventory_detect_case_two(inventory, pos, inventory_scene);
        return (true);
    } else if (inventory->cases[pos.y][pos.x].is_display) {
        inventory_detect_case_three(inventory, pos, inventory_scene);
        return (true);
    } else
        inventory->is_movement = false;
    return (false);
}