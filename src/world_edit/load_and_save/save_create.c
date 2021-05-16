/*
** EPITECH PROJECT, 2021
** save_create
** File description:
** desc
*/

#include "my_world_edit.h"

save_t *save_create(void)
{
    save_t *save = malloc(sizeof(save_t));

    save->save_name = NULL;
    save->text = sfText_create();
    save->shape = sfRectangleShape_create();
    save->font = sfFont_createFromFile("assets/fonts/arial.ttf");
    return (save);
}