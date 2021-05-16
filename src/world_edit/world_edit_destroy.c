/*
** EPITECH PROJECT, 2021
** world_edit_destroy
** File description:
** desc
*/

#include "my_world_edit.h"

void world_edit_destroy(world_edit_t *menu)
{
    if (menu->shape != NULL)
        sfRectangleShape_destroy(menu->shape);
    for (int i = 0; i < menu->nb_button; i++) {
        if (menu->buttons[i] != NULL)
            we_button_destroy(menu->buttons[i]);
    }
    if (menu->buttons != NULL)
        free(menu->buttons);
    if (menu != NULL)
        free(menu);
}