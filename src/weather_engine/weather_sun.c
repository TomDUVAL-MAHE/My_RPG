/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** scene_display
*/

#include "my_game.h"

void weather_engine_start_sun(my_game_t *rpg)
{
    int cloud_number = rand() % 15 + 1;

    rpg->weather_engine.cloud_number = cloud_number;
    framebuffer_fill_all_pixel(&(rpg->weather_engine.framebuffer), \
    (sfColor){0, 0, 0, 0});
    rpg->weather_engine.actual_weather = SUN;
    rpg->weather_engine.clouds = malloc(sizeof(cloud_t) * (cloud_number + 1));
    for (int i = 0; i < cloud_number; i++) {
        weather_setup_cloud_one(rpg, i, 75, 5);
    }
}

void weather_update_sun(my_game_t *rpg)
{
    framebuffer_fill_all_pixel(&(rpg->weather_engine.\
    framebuffer), (sfColor){0, 0, 0, 0});
    rpg->weather_engine.actual_weather = SUN;
    for (int i = 0; i < rpg->weather_engine.cloud_number; i++) {
        weather_engine_move_cloud(rpg, i, 75, 5);
    }
    framebuffer_display(&(rpg->weather_engine.framebuffer), \
    rpg->window.window);
}