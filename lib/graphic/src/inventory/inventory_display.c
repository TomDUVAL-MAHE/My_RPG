/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory.h"

void inventory_change_display(inventory_t *inventory, bool is_display)
{
    inventory->is_display = is_display;
}

void inventory_display_two(inventory_t *inventory, int i, \
sfRenderWindow *window)
{
    for (int j = 0; j < inventory->cases_number.x; j++) {
        if (inventory->cases[i][j].is_display == false) {
            sfRenderWindow_drawRectangleShape(window, \
            inventory->empty_cases[i][j], NULL);
        } else {
            inventory_case_display(&(inventory->cases[i][j]), \
            window);
        }
    }
}

void inventory_display(inventory_t *inventory, \
sfRenderWindow *window)
{
    if (inventory->is_display == false)
        return;
    sfRenderWindow_drawRectangleShape(window, inventory->background, NULL);
    for (int i = 0; i < inventory->cases_number.y; i++) {
        inventory_display_two(inventory, i, window);
    }
}

void inventory_display_info(inventory_t *inventory, \
sfRenderWindow *window, sfVector2i mouse_pos)
{
    if (inventory->is_display == false)
        return;
    for (int i = 0; i < inventory->cases_number.y; i++) {
        for (int j = 0; j < inventory->cases_number.x; j++) {
            inventory_case_display_info(&(inventory->cases[i][j]), \
            window, mouse_pos);
        }
    }
}

void inventory_destroy(inventory_t *inventory)
{
    sfRectangleShape_destroy(inventory->background);
    for (int i = 0; i < inventory->cases_number.y; i++) {
        for (int j = 0; j < inventory->cases_number.x; j++) {
            sfRectangleShape_destroy(inventory->empty_cases[i][j]);
            sfRectangleShape_destroy(inventory->cases[i][j].sprite);
        }
        free(inventory->empty_cases[i]);
        free(inventory->cases[i]);
    }
    free(inventory->empty_cases);
    free(inventory->cases);
}