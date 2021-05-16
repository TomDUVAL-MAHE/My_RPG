/*
** EPITECH PROJECT, 2021
** RPG-TESTS
** File description:
** button_set_action
*/

#include "my_button.h"

void button_set_action(button_t *button, void (*action)(my_game_t *rpg))
{
    button->action = action;
}