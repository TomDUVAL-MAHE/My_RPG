/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_game.h"

int main(void)
{
    my_game_t rpg;

    if (init_rpg(&rpg) == -1)
        return (84);
    scene_manager(&rpg);
}