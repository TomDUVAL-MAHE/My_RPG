/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** scene_display
*/

#include "my_game.h"

my_weather_t weather_engine_setup(my_game_t *rpg)
{
    my_weather_t weather_engine;

    weather_engine.framebuffer = framebuffer_create((sfVector2f)\
    {rpg->window.size.x, rpg->window.size.y}, (sfVector2f){0, 0}, true);
    weather_engine.actual_weather = NONE;
    weather_engine.actual_animation = NONE;
    return (weather_engine);
}