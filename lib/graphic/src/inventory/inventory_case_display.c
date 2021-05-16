/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory_case.h"

void inventory_case_display(inventory_case_t *cases, sfRenderWindow *window)
{
    if (cases->is_display == true) {
        sfRenderWindow_drawRectangleShape(window, cases->sprite, NULL);
    }
}

void inventory_case_display_info(inventory_case_t *cases, sfRenderWindow \
*window, sfVector2i mouse_pos)
{
    if (cases->is_display == true) {
        if (mouse_pos.x >= cases->pos.x && mouse_pos.x <= cases->pos.x + \
            cases->size.x && mouse_pos.y >= cases->pos.y && mouse_pos.y <= \
            cases->pos.y + cases->size.y)
            textbox_display(&(cases->info), window);
    }
}