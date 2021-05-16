/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory.h"

void inventory_unfill_case(inventory_t *inventory, sfVector2i pos)
{
    inventory_case_change_display(&(inventory->cases[pos.y][pos.x]), false);
}

void inventory_copy_case(inventory_t *inventory, sfVector2i pos2)
{
    inventory_case_change_display(&(inventory->cases[pos2.y][pos2.x]), true);
    inventory_case_change_texture(&(inventory->cases[pos2.y][pos2.x]), \
    inventory->movement_texture);
    inventory_case_info_text_change_buffer(&(inventory->cases[pos2.y]\
    [pos2.x]), inventory->movement_buffer);
}

void inventory_switch_case(inventory_t *inventory, sfVector2i pos1, \
sfVector2i pos2)
{
    sfTexture *texture = inventory->cases[pos1.y][pos1.x].texture;
    char *info = inventory->cases[pos1.y][pos1.x].info.text.buffer;
    bool is_display = inventory->cases[pos1.y][pos1.x].is_display;

    inventory_case_change_display(&(inventory->cases[pos1.y][pos1.x]), \
    inventory->cases[pos2.y][pos2.x].is_display);
    inventory_case_change_texture(&(inventory->cases[pos1.y][pos1.x]), \
    inventory->cases[pos2.y][pos2.x].texture);
    inventory_case_info_text_change_buffer(&(inventory->cases[pos1.y]\
    [pos1.x]), inventory->cases[pos2.y][pos2.x].info.text.buffer);
    inventory_case_change_display(&(inventory->cases[pos2.y][pos2.x]), \
    is_display);
    inventory_case_change_texture(&(inventory->cases[pos2.y][pos2.x]), \
    texture);
    inventory_case_info_text_change_buffer(&(inventory->cases[pos2.y]\
    [pos2.x]), info);
}