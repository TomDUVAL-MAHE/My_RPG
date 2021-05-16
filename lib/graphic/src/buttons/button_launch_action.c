/*
** EPITECH PROJECT, 2021
** RPG-TESTS
** File description:
** button_launch_action
*/

#include "my_button.h"

void button_launch_action(button_t *button, my_game_t *rpg)
{
    if (button->action)
        button->action(rpg);
}