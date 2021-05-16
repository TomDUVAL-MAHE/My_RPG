/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory.h"

sfTexture *item_return_texture(item_t *items, char *item_name)
{
    for (int i = 0; i < items[0].item_nbr; i++) {
        if (my_strcmp(item_name, items[i].name) == 0) {
            return (items[i].texture);
        }
    }
    return (NULL);
}

char *item_return_info(item_t *items, char *item_name)
{
    for (int i = 0; i < items[0].item_nbr; i++) {
        if (my_strcmp(item_name, items[i].name) == 0) {
            return (items[i].description);
        }
    }
    return (NULL);
}

int item_return_health(item_t *items, char *item_name)
{
    for (int i = 0; i < items[0].item_nbr; i++) {
        if (my_strcmp(item_name, items[i].name) == 0) {
            return (items[i].health_modificator);
        }
    }
    return (0);
}

int item_return_attack(item_t *items, char *item_name)
{
    for (int i = 0; i < items[0].item_nbr; i++) {
        if (my_strcmp(item_name, items[i].name) == 0) {
            return (items[i].attack_modificator);
        }
    }
    return (0);
}

int item_return_type(item_t *items, char *item_name)
{
    for (int i = 0; i < items[0].item_nbr; i++) {
        if (my_strcmp(item_name, items[i].name) == 0) {
            return (items[i].type);
        }
    }
    return (0);
}