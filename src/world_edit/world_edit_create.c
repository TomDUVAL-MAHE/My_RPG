/*
** EPITECH PROJECT, 2021
** world_edit_create
** File description:
** desc
*/

#include "my_world_edit.h"
#include "my_button.h"

void init_world_edit_buttons(world_edit_t *world_edit)
{
    world_edit->buttons[0] = we_new_button((sfIntRect)\
    {world_edit->pos.x + 10, world_edit->pos.y + 10, 120, 40}, "MENU", 32);
    world_edit->buttons[1] = we_new_button((sfIntRect)\
    {world_edit->pos.x + 10, world_edit->pos.y + 60, 75, 20}, "Texture", 16);
    world_edit->buttons[2] = we_new_button((sfIntRect)\
    {world_edit->pos.x + 95, world_edit->pos.y + 60, 60, 20}, "Sprite", 16);
    world_edit->buttons[3] = we_new_button((sfIntRect)\
    {world_edit->pos.x + 165, world_edit->pos.y + 60, 60, 20}, "Save", 16);
    world_edit->buttons[4] = we_new_button((sfIntRect)\
    {world_edit->pos.x + 235, world_edit->pos.y + 60, 60, 20}, "Load", 16);
}

world_edit_t *world_edit_create(sfRenderWindow *window)
{
    world_edit_t *world_edit = malloc(sizeof(world_edit_t));
    sfVector2u w_size = sfRenderWindow_getSize(window);

    world_edit->tile_hover = (sfVector2i){0, 0};
    world_edit->tile_selected = (sfVector2i){0, 0};
    world_edit->texture_selected = 0;
    world_edit->menu = MENU;
    world_edit->pos = (sfVector2f){w_size.x - 400, 0};
    world_edit->size = (sfVector2f){400, w_size.y};
    world_edit->color = sfBlack;
    world_edit->nb_button = 5;
    world_edit->shape = sfRectangleShape_create();
    world_edit->buttons = malloc(sizeof(we_button_t *) * world_edit->nb_button);
    init_world_edit_buttons(world_edit);
    world_edit->save = save_create();
    world_edit->load = load_create(world_edit);
    world_edit->scroll_texture = 0;
    world_edit->preview = false;
    return (world_edit);
}