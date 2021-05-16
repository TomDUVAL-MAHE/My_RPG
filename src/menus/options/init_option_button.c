/*
** EPITECH PROJECT, 2021
** init_option_button
** File description:
** desc
*/

#include "option.h"
#include "my_game.h"

void option_button_one(my_game_t *rpg)
{
    sfVector2i s = rpg->window.size;
    sfVector2f size = {400.0 / 1920 * s.x, 100.0 / 1080 * s.y};
    sfVector2f pos = {s.x / 2 - size.x / 2, 300.0 / 1080 * s.y};

    rpg->option->sound = true;
    rpg->option->menu->btns[0] = button_init();
    button_set_position(rpg->option->menu->btns[0], pos);
    button_set_size(rpg->option->menu->btns[0], size);
    button_set_color(rpg->option->menu->btns[0], sfWhite, ACTIVE);
    button_set_texture(rpg->option->menu->btns[0], \
    "assets/buttons/button_menu_option.png", ACTIVE);
    button_set_texture(rpg->option->menu->btns[0], \
    "assets/buttons/button_menu_option.png", HOVER);
    button_set_texture(rpg->option->menu->btns[0], \
    "assets/buttons/button_menu_option.png", CLICK);
    button_set_font(rpg->option->menu->btns[0], "assets/fonts/arial.ttf");
    button_set_string(rpg->option->menu->btns[0], "Sound");
    button_set_text_color(rpg->option->menu->btns[0], sfBlack);
    button_set_text_size(rpg->option->menu->btns[0], 32);
    button_set_action(rpg->option->menu->btns[0], &update_sound);
    button_set_status(rpg->option->menu->btns[0], ACTIVE);
}

void option_button_two(my_game_t *rpg)
{
    sfVector2i s = rpg->window.size;
    sfVector2f size = {400.0 / 1920 * s.x, 100.0 / 1080 * s.y};
    sfVector2f pos = {s.x / 2 - size.x / 2, 450.0 / 1080 * s.y};

    rpg->option->music = true;
    rpg->option->menu->btns[1] = button_init();
    button_set_position(rpg->option->menu->btns[1], pos);
    button_set_size(rpg->option->menu->btns[1], size);
    button_set_color(rpg->option->menu->btns[1], sfWhite, ACTIVE);
    button_set_font(rpg->option->menu->btns[1], "assets/fonts/arial.ttf");
    button_set_texture(rpg->option->menu->btns[1], \
    "assets/buttons/button_menu_option.png", ACTIVE);
    button_set_texture(rpg->option->menu->btns[1], \
    "assets/buttons/button_menu_option.png", HOVER);
    button_set_texture(rpg->option->menu->btns[1], \
    "assets/buttons/button_menu_option.png", CLICK);
    button_set_string(rpg->option->menu->btns[1], "Music");
    button_set_text_color(rpg->option->menu->btns[1], sfBlack);
    button_set_text_size(rpg->option->menu->btns[1], 32);
    button_set_action(rpg->option->menu->btns[1], &update_music);
    button_set_status(rpg->option->menu->btns[1], ACTIVE);
}

void back_to_pause(my_game_t *rpg)
{
    rpg->option->menu->displayed = false;
    rpg->main_menu.main_part.displayed = true;
}

void option_button_four(my_game_t *rpg)
{
    sfVector2i s = rpg->window.size;
    sfVector2f size = {400.0 / 1920 * s.x, 100.0 / 1080 * s.y};
    sfVector2f pos = {s.x / 2 - size.x / 2, 600.0 / 1080 * s.y};

    rpg->option->music = true;
    rpg->option->menu->btns[2] = button_init();
    button_set_position(rpg->option->menu->btns[2], pos);
    button_set_size(rpg->option->menu->btns[2], size);
    button_set_color(rpg->option->menu->btns[2], sfWhite, ACTIVE);
    button_set_texture(rpg->option->menu->btns[2], \
    "assets/buttons/button_menu_option.png", ACTIVE);
    button_set_texture(rpg->option->menu->btns[2], \
    "assets/buttons/button_menu_option.png", HOVER);
    button_set_texture(rpg->option->menu->btns[2], \
    "assets/buttons/button_menu_option.png", CLICK);
    button_set_font(rpg->option->menu->btns[2], "assets/fonts/arial.ttf");
    button_set_string(rpg->option->menu->btns[2], "Back");
    button_set_text_color(rpg->option->menu->btns[2], sfBlack);
    button_set_text_size(rpg->option->menu->btns[2], 32);
    button_set_action(rpg->option->menu->btns[2], &back_to_pause);
    button_set_status(rpg->option->menu->btns[2], ACTIVE);
}
