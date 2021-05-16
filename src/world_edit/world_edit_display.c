/*
** EPITECH PROJECT, 2021
** world_edit_display.c
** File description:
** desc
*/

#include "my_world_edit.h"

void world_edit_menu(sfRenderWindow *window, world_edit_t *world_edit, \
map_t *map)
{
    sfText *text = sfText_create();
    sfVector2f pos = {world_edit->pos.x + 150, world_edit->pos.y + 10};

    sfText_setFillColor(text, sfRed);
    if (map->name == NULL)
        sfText_setString(text, "NULL");
    else
        sfText_setString(text, map->name);
    sfText_setPosition(text, pos);
    sfText_setFont(text, world_edit->buttons[0]->font);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
}

void we_display_action(world_edit_t *world_edit, int i)
{
    if (world_edit->buttons[i]->status == CLICK) {
        world_edit->menu = i;
        world_edit->texture_selected = 0;
        we_button_set_color(world_edit->buttons[i], \
        (sfColor){100, 100, 100, 255});
    } else if (world_edit->buttons[i]->status == HOVER) {
        we_button_set_color(world_edit->buttons[i], (sfColor){75, 75, 75, 255});
    } else {
        we_button_set_color(world_edit->buttons[i], (sfColor){50, 50, 50, 255});
    }
}

void world_edit_display_button(world_edit_t *world_edit, \
sfRenderWindow *window, int i)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        world_edit->status = CLICK;
    } else {
        world_edit->status = ACTIVE;
    }
    we_button_display(window, world_edit->buttons[i]);
    we_button_is_click(world_edit->buttons[i], window, sfMouseLeft);
    we_display_action(world_edit, i);
}

void world_edit_display(sfRenderWindow *window, world_edit_t *world_edit, \
map_t *map)
{
    void (*button_ptr[])(sfRenderWindow *window, \
    world_edit_t *world_edit, map_t *map) = {\
        &world_edit_menu, \
        &world_edit_texture, \
        &world_edit_sprite, \
        &world_edit_save, \
        &world_edit_load};

    tile_hover_and_click(map, world_edit, window);
    draw_hover_and_click(window, map, world_edit);
    if (world_edit->menu == 0)
        sfRectangleShape_setSize(world_edit->shape, \
        (sfVector2f){world_edit->size.x, 100});
    else
        sfRectangleShape_setSize(world_edit->shape, world_edit->size);
    sfRenderWindow_drawRectangleShape(window, world_edit->shape, NULL);
    button_ptr[world_edit->menu](window, world_edit, map);
    for (int i = 0; i < world_edit->nb_button; i++) {
        world_edit_display_button(world_edit, window, i);
    }
}