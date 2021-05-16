/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** scene_display
*/

#include "my_game.h"

void weather_engine_start_rain(my_game_t *rpg)
{
    int cloud_number = rand() % 15 + 30;

    rpg->weather_engine.cloud_number = cloud_number;
    framebuffer_fill_all_pixel(&(rpg->weather_engine.framebuffer), \
    (sfColor){2, 13, 25, 50});
    rpg->weather_engine.actual_weather = RAIN;
    rpg->weather_engine.clouds = malloc(sizeof(cloud_t) * (cloud_number + 1));
    for (int i = 0; i < cloud_number; i++) {
        weather_setup_cloud_one(rpg, i, 150, 10);
    }
    rpg->weather_engine.snow_animation_counter = 0;
    rpg->weather_engine.snow_animation_snow = \
    malloc(sizeof(sfVector2i) * 10000);
}

void weather_update_rain_draw_rain(my_game_t *rpg, int i)
{
    framebuffer_put_pixel(&(rpg->weather_engine.framebuffer), \
    (sfVector2f){rpg->weather_engine.snow_animation_snow[i].x, \
        rpg->weather_engine.snow_animation_snow[i].y}, \
    (sfColor){7, 74, 242, 255});
    framebuffer_put_pixel(&(rpg->weather_engine.framebuffer), \
    (sfVector2f){rpg->weather_engine.snow_animation_snow[i].x + 1, \
        rpg->weather_engine.snow_animation_snow[i].y}, \
    (sfColor){7, 74, 242, 255});
    framebuffer_put_pixel(&(rpg->weather_engine.framebuffer), \
    (sfVector2f){rpg->weather_engine.snow_animation_snow[i].x, \
        rpg->weather_engine.snow_animation_snow[i].y + 1}, \
    (sfColor){7, 74, 242, 255});
    framebuffer_put_pixel(&(rpg->weather_engine.framebuffer), \
    (sfVector2f){rpg->weather_engine.snow_animation_snow[i].x + 1, \
        rpg->weather_engine.snow_animation_snow[i].y + 1}, \
    (sfColor){7, 74, 242, 255});
    rpg->weather_engine.snow_animation_snow[i].y += (1 * \
    (rpg->elapsed_microsecond / 20000) * (rand() % 5));
}

void weather_update_rain(my_game_t *rpg)
{
    framebuffer_fill_all_pixel(&(rpg->weather_engine.framebuffer), \
    (sfColor){2, 13, 25, 50});
    for (int i = 0; i < rpg->weather_engine.cloud_number; i++) {
        weather_engine_move_cloud(rpg, i, 150, 10);
    }
    if (rpg->weather_engine.snow_animation_counter < 1000) {
        rpg->weather_engine.snow_animation_snow\
        [rpg->weather_engine.snow_animation_counter] = \
        (sfVector2i){rand() % (rpg->window.size.x - 1), 0};
        rpg->weather_engine.snow_animation_counter += 1;
    }
    for (int i = 0; i < rpg->weather_engine.snow_animation_counter; i++) {
        weather_update_rain_draw_rain(rpg, i);
        if (rpg->weather_engine.snow_animation_snow[i].y > \
            rpg->window.size.y - 5)
            rpg->weather_engine.snow_animation_snow[i].y = 0;
    }
    framebuffer_display(&(rpg->weather_engine.framebuffer), \
    rpg->window.window);
}