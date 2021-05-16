/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** scene_display
*/

#include "my_game.h"

void weather_update(my_game_t *rpg)
{
    if (rpg->weather_engine.actual_weather == RAIN)
        weather_update_rain(rpg);
    if (rpg->weather_engine.actual_weather == SUN)
        weather_update_sun(rpg);
    if (rpg->weather_engine.actual_weather == SNOW)
        weather_update_snow(rpg);
}