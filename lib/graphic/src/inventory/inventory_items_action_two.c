/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory.h"

char *item_return_name(item_t *items, sfTexture *texture)
{
    for (int i = 0; i < items[0].item_nbr; i++) {
        if (texture == items[i].texture)
            return (items[i].name);
    }
    return ("EMPTY");
}