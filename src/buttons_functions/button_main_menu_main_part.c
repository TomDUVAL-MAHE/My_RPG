/*
** EPITECH PROJECT, 2021
** RPG-TESTS
** File description:
** button_main_menu_main_part
*/

#include "my_game.h"

void show_play_part(my_game_t *rpg)
{
    rpg->main_menu.main_part.displayed = false;
    rpg->main_menu.play_part.displayed = true;
}