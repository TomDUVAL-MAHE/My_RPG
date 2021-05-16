/*
** EPITECH PROJECT, 2021
** game_scene_pause_init
** File description:
** desc
*/

#include "my_game.h"

void game_scene_init_button_two_two(button_t *button, \
sfVector2f pos)
{
    sfText_setPosition(button->text, (sfVector2f){pos.x + 50, pos.y + 25});
    button_set_font(button, "assets/fonts/arial.ttf");
    button_set_string(button, "Save");
    button_set_text_color(button, sfBlack);
    button_set_text_size(button, 32);
    button_set_action(button, &save_gestion);
    button_set_status(button, ACTIVE);
}

button_t *game_scene_init_button_two(my_game_t *rpg)
{
    sfVector2f size = {400.0 / 1920 * rpg->window.size.x, 100.0 / 1080 * \
        rpg->window.size.y};
    sfVector2f pos = {rpg->window.size.x / 2.0 - size.x / 2, 600.0 / 1080 * \
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
    game_scene_init_button_two_two(button, pos);
    return (button);
}

void game_scene_init_button_three_three(button_t *button, \
sfVector2f pos)
{
    sfText_setPosition(button->text, (sfVector2f){pos.x + 50, pos.y + 25});
    button_set_font(button, "assets/fonts/arial.ttf");
    button_set_string(button, "Exit");
    button_set_text_color(button, sfBlack);
    button_set_text_size(button, 32);
    button_set_action(button, &go_to_main_menu_scene);
    button_set_status(button, ACTIVE);
}

button_t *game_scene_init_button_three(my_game_t *rpg)
{
    sfVector2f size = {400.0 / 1920 * rpg->window.size.x, 100.0 / 1080 * \
        rpg->window.size.y};
    sfVector2f pos = {rpg->window.size.x / 2.0 - size.x / 2, 750.0 / 1080 * \
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
    game_scene_init_button_three_three(button, pos);
    return (button);
}

menus_t *game_scene_pause_menu_init(my_game_t *rpg)
{
    menus_t *pause_menu = malloc(sizeof(*pause_menu));

    if (!pause_menu)
        return NULL;
    pause_menu->displayed = false;
    pause_menu->nb_text = 0;
    pause_menu->text = NULL;
    pause_menu->nb_btns = 4;
    pause_menu->btns = malloc(sizeof(*pause_menu->btns) * pause_menu->nb_btns);
    if (!pause_menu->nb_btns)
        return (destroy_a_menu(pause_menu));
    pause_menu->btns[0] = game_scene_init_button_zero(rpg);
    pause_menu->btns[1] = game_scene_init_button_one(rpg);
    pause_menu->btns[2] = game_scene_init_button_two(rpg);
    pause_menu->btns[3] = game_scene_init_button_three(rpg);
    return (pause_menu);
}