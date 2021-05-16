/*
** EPITECH PROJECT, 2021
** rpg_temp
** File description:
** game_scene_pause_init
*/

#include "my_game_scene.h"
#include "my_game.h"
#include "save.h"
#include <stdlib.h>

void game_scene_init_button_zero_zero(button_t *button, \
sfVector2f pos)
{
    sfText_setPosition(button->text, (sfVector2f){pos.x + 50, pos.y + 25});
    button_set_font(button, "assets/fonts/arial.ttf");
    button_set_string(button, "Resume");
    button_set_text_color(button, sfBlack);
    button_set_text_size(button, 32);
    button_set_action(button, &pause_game);
    button_set_status(button, ACTIVE);
}

button_t *game_scene_init_button_zero(my_game_t *rpg)
{
    sfVector2f size = {400.0 / 1920 * rpg->window.size.x, 100.0 / 1080 * \
        rpg->window.size.y};
    sfVector2f pos = {rpg->window.size.x / 2.0 - size.x / 2, 300.0 / 1080 * \
        rpg->window.size.y};
    button_t *button = button_init();

    if (!button)
        return NULL;
    button_set_position(button, pos);
    button_set_size(button, size);
    button_set_color(button, (sfColor){255, 255, 255, 255}, ACTIVE);
    button_set_texture(button, "assets/buttons/button_menu_option.png", ACTIVE);
    button_set_texture(button, "assets/buttons/button_menu_option_hover.png", \
    HOVER);
    button_set_texture(button, "assets/buttons/button_menu_option_click.png", \
    CLICK);
    game_scene_init_button_zero_zero(button, pos);
    return (button);
}

void game_scene_init_button_one_one(button_t *button, \
sfVector2f pos)
{
    sfText_setPosition(button->text, (sfVector2f){pos.x + 50, pos.y + 25});
    button_set_font(button, "assets/fonts/arial.ttf");
    button_set_string(button, "Option");
    button_set_text_color(button, sfBlack);
    button_set_text_size(button, 32);
    button_set_action(button, &show_option);
    button_set_status(button, ACTIVE);
}

button_t *game_scene_init_button_one(my_game_t *rpg)
{
    sfVector2f size = {400.0 / 1920 * rpg->window.size.x, 100.0 / 1080 * \
        rpg->window.size.y};
    sfVector2f pos = {rpg->window.size.x / 2.0 - size.x / 2, 450.0 / 1080 * \
        rpg->window.size.y};
    button_t *button = button_init();

    if (!button)
        return NULL;
    button_set_position(button, pos);
    button_set_size(button, size);
    button_set_color(button, (sfColor){255, 255, 255, 255}, ACTIVE);
    button_set_texture(button, "assets/buttons/button_menu_option.png", \
    ACTIVE);
    button_set_texture(button, "assets/buttons/button_menu_option_hover.png", \
    HOVER);
    button_set_texture(button, "assets/buttons/button_menu_option_click.png", \
    CLICK);
    game_scene_init_button_one_one(button, pos);
    return (button);
}