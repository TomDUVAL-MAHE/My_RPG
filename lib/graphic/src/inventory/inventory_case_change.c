/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory_case.h"

void inventory_case_info_change_dir(inventory_case_t *cases, int dir)
{
    sfVector2f pos = {cases->pos.x, cases->pos.y};

    if (dir == 0)
        pos.y -= (cases->size.y / 10);
    if (dir == 1) {
        pos.y -= (cases->size.y / 10);
        pos.x += cases->size.x * 0.9;
    }
    if (dir == 2)
        pos.y += (cases->size.y * 1.2);
    if (dir == 3) {
        pos.y += (cases->size.y * 1.2);
        pos.x += cases->size.x * 0.9;
    }
    cases->info.pos = pos;
    sfRectangleShape_setPosition(cases->info.background, pos);
}

void inventory_case_info_change_size(inventory_case_t *cases, sfVector2f size)
{
    cases->info.size = size;
    sfRectangleShape_setSize(cases->info.background, size);
}

void inventory_case_info_change_texture(inventory_case_t *cases, \
sfTexture *texture)
{
    cases->info.texture = texture;
    sfRectangleShape_setTexture(cases->info.background, texture, true);
}

void inventory_case_info_text_change_size(inventory_case_t *cases, int size)
{
    sfVector2f new_size = {(my_strlen(cases->info.text.buffer) * size) * \
        1.2, size * 1.2};

    inventory_case_info_change_size(cases, new_size);
    text_change_char_size(&(cases->info.text), size);
}

void inventory_case_info_text_change_buffer(inventory_case_t *cases, \
char *buffer)
{
    sfVector2f new_size = {((my_strlen(buffer) / 2) * \
        cases->info.text.char_size) + 10, cases->info.text.char_size * 1.6};

    inventory_case_info_change_size(cases, new_size);
    text_change_buffer(&(cases->info.text), buffer);
}