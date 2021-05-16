/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** main_menu_play_part_buttons.c
*/

#include "my_game.h"

void save_three_launch(my_game_t *rpg)
{
    if (load_a_save(rpg, "3") == 0)
        go_to_game_scene(rpg);
    else
        go_to_a_scene(rpg, EXIT);
}

button_t *init_play_part_button_zero(my_game_t *rpg)
{
    sfVector2f size = {400.0 / 1920 * rpg->window.size.x, \
        100.0 / 1080 * rpg->window.size.y};
    sfVector2f pos = {rpg->window.size.x / 2 - size.x / 2, \
        300.0 / 1080 * rpg->window.size.y};
    button_t *button = button_init();

    button_set_position(button, pos);
    button_set_size(button, size);
    button_set_color(button, sfWhite, ACTIVE);
    button_set_texture(button, BUTTON_SAVE_PATH, ACTIVE);
    button_set_texture(button, BUTTON_SAVE_HOVER_PATH, HOVER);
    button_set_texture(button, BUTTON_SAVE_CLICK_PATH, CLICK);
    sfText_setPosition(button->text, (sfVector2f){pos.x + 50, pos.y + 25});
    button_set_font(button, "assets/fonts/arial.ttf");
    button_set_string(button, "Save 1");
    button_set_text_color(button, sfBlack);
    button_set_text_size(button, 32);
    button_set_action(button, &save_one_launch);
    button_set_status(button, ACTIVE);
    return (button);
}

button_t *init_play_part_button_one(my_game_t *rpg)
{
    sfVector2f size = {400.0 / 1920 * rpg->window.size.x, \
        100.0 / 1080 * rpg->window.size.y};
    sfVector2f pos = {rpg->window.size.x / 2 - size.x / 2, \
        450.0 / 1080 * rpg->window.size.y};
    button_t *button = button_init();

    button_set_position(button, pos);
    button_set_size(button, size);
    button_set_color(button, sfWhite, ACTIVE);
    button_set_texture(button, BUTTON_SAVE_PATH, ACTIVE);
    button_set_texture(button, BUTTON_SAVE_HOVER_PATH, HOVER);
    button_set_texture(button, BUTTON_SAVE_CLICK_PATH, CLICK);
    sfText_setPosition(button->text, (sfVector2f){pos.x + 50, pos.y + 25});
    button_set_font(button, "assets/fonts/arial.ttf");
    button_set_string(button, "Save 2");
    button_set_text_color(button, sfBlack);
    button_set_text_size(button, 32);
    button_set_action(button, &save_two_launch);
    button_set_status(button, ACTIVE);
    return (button);
}

button_t *init_play_part_button_two(my_game_t *rpg)
{
    sfVector2f size = {400.0 / 1920 * rpg->window.size.x, \
        100.0 / 1080 * rpg->window.size.y};
    sfVector2f pos = {rpg->window.size.x / 2 - size.x / 2, \
        600.0 / 1080 * rpg->window.size.y};
    button_t *button = button_init();

    button_set_position(button, pos);
    button_set_size(button, size);
    button_set_color(button, sfWhite, ACTIVE);
    button_set_texture(button, BUTTON_SAVE_PATH, ACTIVE);
    button_set_texture(button, BUTTON_SAVE_HOVER_PATH, HOVER);
    button_set_texture(button, BUTTON_SAVE_CLICK_PATH, CLICK);
    sfText_setPosition(button->text, (sfVector2f){pos.x + 50, pos.y + 25});
    button_set_font(button, "assets/fonts/arial.ttf");
    button_set_string(button, "Save 3");
    button_set_text_color(button, sfBlack);
    button_set_text_size(button, 32);
    button_set_action(button, &save_three_launch);
    button_set_status(button, ACTIVE);
    return (button);
}

button_t *init_play_part_button_three(my_game_t *rpg)
{
    sfVector2f size = {400.0 / 1920 * rpg->window.size.x, \
        100.0 / 1080 * rpg->window.size.y};
    sfVector2f pos = {rpg->window.size.x / 2 - size.x / 2, \
        750.0 / 1080 * rpg->window.size.y};
    button_t *button = button_init();

    button_set_position(button, pos);
    button_set_size(button, size);
    button_set_color(button, sfWhite, ACTIVE);
    button_set_texture(button, BUTTON_SAVE_PATH, ACTIVE);
    button_set_texture(button, BUTTON_SAVE_HOVER_PATH, HOVER);
    button_set_texture(button, BUTTON_SAVE_CLICK_PATH, CLICK);
    sfText_setPosition(button->text, (sfVector2f){pos.x + 50, pos.y + 25});
    button_set_font(button, "assets/fonts/arial.ttf");
    button_set_string(button, "Return");
    button_set_text_color(button, sfBlack);
    button_set_text_size(button, 32);
    button_set_action(button, &show_main_part);
    button_set_status(button, ACTIVE);
    return (button);
}
