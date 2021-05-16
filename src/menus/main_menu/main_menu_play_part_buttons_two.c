/*
** EPITECH PROJECT, 2021
** RPG-TESTS
** File description:
** main_menu_play_part_buttons_two.c
*/

#include "my_game.h"

void clear_save_two(my_game_t *rpg)
{
    clear_a_save("2");
    rpg->mouse_pressed = rpg->mouse_pressed;
}

void clear_save_three(my_game_t *rpg)
{
    clear_a_save("3");
    rpg->mouse_pressed = rpg->mouse_pressed;
}

button_t *init_play_part_button_four(my_game_t *rpg)
{
    sfVector2f size = {100.0 / 1920 * rpg->window.size.x, \
        100.0 / 1080 * rpg->window.size.y};
    sfVector2f pos = {rpg->window.size.x / 2 + 250.0 / 1920 * \
        rpg->window.size.x, 300.0 / 1080 * rpg->window.size.y};
    button_t *button = button_init();

    button_set_position(button, pos);
    button_set_size(button, size);
    button_set_color(button, sfWhite, ACTIVE);
    button_set_texture(button, BUTTON_SAVE_PATH, ACTIVE);
    button_set_texture(button, BUTTON_SAVE_HOVER_PATH, HOVER);
    button_set_texture(button, BUTTON_SAVE_CLICK_PATH, CLICK);
    sfText_setPosition(button->text, (sfVector2f){pos.x + 50, pos.y + 25});
    button_set_font(button, "assets/fonts/arial.ttf");
    button_set_string(button, "X");
    button_set_text_color(button, sfBlack);
    button_set_text_size(button, 32);
    button_set_action(button, &clear_save_one);
    button_set_status(button, ACTIVE);
    return (button);
}

button_t *init_play_part_button_five(my_game_t *rpg)
{
    sfVector2f size = {100.0 / 1920 * rpg->window.size.x, \
        100.0 / 1080 * rpg->window.size.y};
    sfVector2f pos = {rpg->window.size.x / 2 + 250.0 / 1920 * \
        rpg->window.size.x, 450.0 / 1080 * rpg->window.size.y};
    button_t *button = button_init();

    button_set_position(button, pos);
    button_set_size(button, size);
    button_set_color(button, sfWhite, ACTIVE);
    button_set_texture(button, BUTTON_SAVE_PATH, ACTIVE);
    button_set_texture(button, BUTTON_SAVE_HOVER_PATH, HOVER);
    button_set_texture(button, BUTTON_SAVE_CLICK_PATH, CLICK);
    sfText_setPosition(button->text, (sfVector2f){pos.x + 50, pos.y + 25});
    button_set_font(button, "assets/fonts/arial.ttf");
    button_set_string(button, "X");
    button_set_text_color(button, sfBlack);
    button_set_text_size(button, 32);
    button_set_action(button, &clear_save_two);
    button_set_status(button, ACTIVE);
    return (button);
}

button_t *init_play_part_button_six(my_game_t *rpg)
{
    sfVector2f size = {100.0 / 1920 * rpg->window.size.x, \
        100.0 / 1080 * rpg->window.size.y};
    sfVector2f pos = {rpg->window.size.x / 2 + 250.0 / 1920 * \
        rpg->window.size.x, 600.0 / 1080 * rpg->window.size.y};
    button_t *button = button_init();

    button_set_position(button, pos);
    button_set_size(button, size);
    button_set_color(button, sfWhite, ACTIVE);
    button_set_texture(button, BUTTON_SAVE_PATH, ACTIVE);
    button_set_texture(button, BUTTON_SAVE_HOVER_PATH, HOVER);
    button_set_texture(button, BUTTON_SAVE_CLICK_PATH, CLICK);
    sfText_setPosition(button->text, (sfVector2f){pos.x + 50, pos.y + 25});
    button_set_font(button, "assets/fonts/arial.ttf");
    button_set_string(button, "X");
    button_set_text_color(button, sfBlack);
    button_set_text_size(button, 32);
    button_set_action(button, &clear_save_three);
    button_set_status(button, ACTIVE);
    return (button);
}
