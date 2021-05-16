/*
** EPITECH PROJECT, 2021
** RPG-TESTS
** File description:
** events.c
*/

#include "my_game.h"

void detect_key(my_game_t *rpg, sfEvent event)
{
    if (event.key.code == sfKeyEscape)
        sfRenderWindow_close(rpg->window.window);
}