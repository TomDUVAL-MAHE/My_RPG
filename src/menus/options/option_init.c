/*
** EPITECH PROJECT, 2021
** option_init.c
** File description:
** desc
*/

#include "my_game.h"

void update_sound(my_game_t *rpg)
{
    if (rpg->option->sound == true)
        rpg->option->sound = false;
    else
        rpg->option->sound = true;
}

void update_music(my_game_t *rpg)
{
    if (rpg->option->music == true)
        rpg->option->music = false;
    else
        rpg->option->music = true;
}

void show_option(my_game_t *rpg)
{
    menus_t *pause_m = rpg->option->menu;

    if (rpg->game)
        rpg->game->pause_menu->displayed = false;
    rpg->main_menu.main_part.displayed = false;
    pause_m->displayed = (pause_m->displayed ? false : true);
    if (pause_m->displayed) {
        rpg->elapsed_microsecond = 0;
    } else {
        get_time(rpg);
        rpg->last_time = rpg->actual_time;
        rpg->elapsed_microsecond = 0;
    }
}

void option_init(my_game_t *rpg)
{
    rpg->option = malloc(sizeof(option_t));
    if (rpg->option == NULL)
        return;
    rpg->option->menu = malloc(sizeof(menus_t));
    if (rpg->option->menu == NULL)
        return;
    rpg->option->menu->nb_btns = 3;
    rpg->option->menu->displayed = false;
    rpg->option->menu->nb_text = 0;
    rpg->option->menu->text = NULL;
    rpg->option->menu->btns = malloc(sizeof(button_t *) * 3);
    option_button_one(rpg);
    option_button_two(rpg);
    option_button_four(rpg);
}