/*
** EPITECH PROJECT, 2021
** load_create
** File description:
** desc
*/

#include "my_map.h"
#include "my_world_edit.h"

load_t *load_create(world_edit_t *world_edit)
{
    load_t *load = malloc(sizeof(load_t));

    load->directory = NULL;
    load->dir = NULL;
    load->path = NULL;
    load->pos = (sfVector2f){world_edit->pos.x + 10, world_edit->pos.y + 100};
    load->res = 0;
    load->is_load = false;
    return (load);
}