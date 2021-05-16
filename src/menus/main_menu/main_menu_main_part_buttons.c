/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** main_menu_main_part_buttons.c
*/

#include "my_game.h"
#include "option.h"

button_t *init_main_part_button_zero(my_game_t *rpg)
{
    sfVector2f size = {400.0 / 1920 * rpg->window.size.x, \
        100.0 / 1080 * rpg->window.size.y};
    sfVector2f pos = {rpg->window.size.x / 2.0 - size.x / 2, \
        300.0 / 1080 * rpg->window.size.y};
    button_t *button = button_init();

    button_set_position(button, pos);
    button_set_size(button, size);
    button_set_color(button, (sfColor){255, 255, 255, 255}, ACTIVE);
    button_set_texture(button, "assets/buttons/button_menu.png", ACTIVE);
    button_set_texture(button, "assets/buttons/button_menu_hover.png", HOVER);
    button_set_texture(button, "assets/buttons/button_menu_click.png", CLICK);
    button_set_font(button, "assets/fonts/arial.ttf");
    button_set_string(button, "Play");
    button_set_text_color(button, sfBlack);
    button_set_text_size(button, 32);
    sfText_setPosition(button->text, (sfVector2f){pos.x + 50, pos.y + 25});
    button_set_action(button, &show_play_part);
    button_set_status(button, ACTIVE);
    return (button);
}

button_t *init_main_part_button_one(my_game_t *rpg)
{
    sfVector2f size = {400.0 / 1920 * rpg->window.size.x, \
        100.0 / 1080 * rpg->window.size.y};
    sfVector2f pos = {rpg->window.size.x / 2.0 - size.x / 2, \
        450.0 / 1080 * rpg->window.size.y};
    button_t *button = button_init();

    button_set_position(button, pos);
    button_set_size(button, size);
    button_set_color(button, (sfColor){255, 255, 255, 255}, ACTIVE);
    button_set_texture(button, "assets/buttons/button_menu.png", ACTIVE);
    button_set_texture(button, "assets/buttons/button_menu_hover.png", HOVER);
    button_set_texture(button, "assets/buttons/button_menu_click.png", CLICK);
    button_set_font(button, "assets/fonts/arial.ttf");
    button_set_string(button, "Options");
    button_set_text_color(button, sfBlack);
    button_set_text_size(button, 32);
    sfText_setPosition(button->text, (sfVector2f){pos.x + 50, pos.y + 25});
    button_set_action(button, &show_option);
    button_set_status(button, ACTIVE);
    return (button);
}

button_t *init_main_part_button_two(my_game_t *rpg)
{
    sfVector2f size = {400.0 / 1920 * rpg->window.size.x, \
        100.0 / 1080 * rpg->window.size.y};
    sfVector2f pos = {rpg->window.size.x / 2.0 - size.x / 2, \
        600.0 / 1080 * rpg->window.size.y};
    button_t *button = button_init();

    button_set_position(button, pos);
    button_set_size(button, size);
    button_set_color(button, (sfColor){255, 255, 255, 255}, ACTIVE);
    button_set_texture(button, "assets/buttons/button_menu.png", ACTIVE);
    button_set_texture(button, "assets/buttons/button_menu_hover.png", HOVER);
    button_set_texture(button, "assets/buttons/button_menu_click.png", CLICK);
    button_set_font(button, "assets/fonts/arial.ttf");
    button_set_string(button, "World Edit");
    button_set_text_color(button, sfBlack);
    button_set_text_size(button, 32);
    sfText_setPosition(button->text, (sfVector2f){pos.x + 50, pos.y + 25});
    button_set_action(button, &go_to_world_edit_scene);
    button_set_status(button, ACTIVE);
    return (button);
}

button_t *init_main_part_button_three(my_game_t *rpg)
{
    sfVector2f size = {400.0 / 1920 * rpg->window.size.x, \
        100.0 / 1080 * rpg->window.size.y};
    sfVector2f pos = {rpg->window.size.x / 2.0 - size.x / 2, \
        750.0 / 1080 * rpg->window.size.y};
    button_t *button = button_init();

    button_set_position(button, pos);
    button_set_size(button, size);
    button_set_color(button, (sfColor){255, 255, 255, 255}, ACTIVE);
    button_set_texture(button, "assets/buttons/button_menu.png", ACTIVE);
    button_set_texture(button, "assets/buttons/button_menu_hover.png", HOVER);
    button_set_texture(button, "assets/buttons/button_menu_click.png", CLICK);
    button_set_font(button, "assets/fonts/arial.ttf");
    button_set_string(button, "Exit");
    button_set_text_color(button, sfBlack);
    button_set_text_size(button, 32);
    sfText_setPosition(button->text, (sfVector2f){pos.x + 50, pos.y + 25});
    button_set_action(button, &make_exit);
    button_set_status(button, ACTIVE);
    return (button);
}