/*
** EPITECH PROJECT, 2021
** we_new_button
** File description:
** desc
*/

#include "my_world_edit.h"
#include "my.h"

we_button_t *we_new_button(sfIntRect size, char *str, int tsize)
{
    we_button_t *button = we_button_create();

    we_button_set_font(button, "assets/fonts/arial.ttf");
    we_button_set_position(button, (sfVector2f){size.left, size.top});
    we_button_set_size(button, (sfVector2f){size.width, size.height});
    we_button_set_color(button, (sfColor){50, 50, 50, 255});
    we_button_set_string(button, str);
    we_button_set_text_color(button, sfWhite);
    we_button_set_text_size(button, tsize);
    return (button);
}