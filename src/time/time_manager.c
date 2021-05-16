/*
** EPITECH PROJECT, 2021
** RPG-TESTS
** File description:
** time_manager
*/

#include "my_game.h"

void get_time(my_game_t *rpg)
{
    rpg->last_time = rpg->actual_time;
    rpg->actual_time = sfClock_getElapsedTime(rpg->main_clock);
    rpg->elapsed_microsecond = \
    sfTime_asMicroseconds(rpg->actual_time)\
    - sfTime_asMicroseconds(rpg->last_time);
}