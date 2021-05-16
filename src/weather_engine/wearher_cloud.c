/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** scene_display
*/

#include "my_game.h"

void weather_engine_draw_cloud_two(my_game_t *rpg, sfVector2i *cloud_pos, \
sfVector2i pos, vector_i a)
{
    for (int j = 0; j < cloud_pos[a.x / a.y].y; j++) {
        if (pos.x + cloud_pos[a.x / a.y].x + j > 0 && pos.x + \
            cloud_pos[a.x / a.y].x + j < rpg->window.size.x)
            framebuffer_put_pixel(&(rpg->weather_engine.framebuffer), \
            (sfVector2f){pos.x + cloud_pos[a.x / a.y].x + j, pos.y + a.x}, \
            (sfColor){0, 0, 0, a.z});
    }
}

void weather_engine_draw_cloud_one(my_game_t *rpg, sfVector2i pos, \
int scale, int type)
{
    sfVector2i cloud_pos[] = {(sfVector2i){9 * scale, 3 * scale},  \
        (sfVector2i){8 * scale, 5 * scale}, (sfVector2i){7 * scale, 8 * \
            scale}, (sfVector2i){6 * scale, 10 * scale}, (sfVector2i){4 * \
            scale, 12 * scale}, (sfVector2i){1 * scale, 17 * scale}, \
        (sfVector2i){0 * scale, 19 * scale}, (sfVector2i){0 * scale, 20 \
            * scale}, (sfVector2i){1 * scale, 19 * scale}, (sfVector2i){2 * \
            scale, 17 * scale}};

    for (int i = 0; i < 10 * scale; i++) {
        weather_engine_draw_cloud_two(rpg, cloud_pos, pos, \
        (vector_i){i, scale, type});
    }
}

void weather_setup_cloud_one(my_game_t *rpg, int i, int type, int s)
{
    int scale = rand() % 15 + s;
    int r = rand() % 2;

    if (r) {}
    rpg->weather_engine.clouds[i].type = rand() % 75 + type;
    rpg->weather_engine.clouds[i].size = scale;
    rpg->weather_engine.clouds[i].speed = (sfVector2i){rand() % 10 + 2, \
        rand() % 1};
    rpg->weather_engine.clouds[i].dir = (sfVector2i){rand() % 2, rand() % 2};
    if (rpg->weather_engine.clouds[i].dir.x == 1)
        rpg->weather_engine.clouds[i].pos = (sfVector2i){rpg->window.size.x + \
            scale * 22 - 1, rand() % (rpg->window.size.y - scale * 11)};
    if (rpg->weather_engine.clouds[i].dir.x == 0)
        rpg->weather_engine.clouds[i].pos = (sfVector2i){0 - scale * 22 + 1, \
            rand() % (rpg->window.size.y - scale * 11)};
}

void weather_engine_detect_dir_cloud(my_game_t *rpg, int i, int type, int s)
{
    if (rpg->weather_engine.clouds[i].dir.x == 0 && \
        rpg->weather_engine.clouds[i].pos.x + \
        rpg->weather_engine.clouds[i].speed.x >= rpg->window.size.x)
        weather_setup_cloud_one(rpg, i, type, s);
    if (rpg->weather_engine.clouds[i].dir.x == 1 && \
        rpg->weather_engine.clouds[i].pos.x - \
        rpg->weather_engine.clouds[i].speed.x <= 0 - \
        rpg->weather_engine.clouds[i].size * 22)
        weather_setup_cloud_one(rpg, i, type, s);
}

void weather_engine_move_cloud(my_game_t *rpg, int i, int type, int s)
{
    weather_engine_detect_dir_cloud(rpg, i, type, s);
    if (rpg->weather_engine.clouds[i].dir.x == 0)
        rpg->weather_engine.clouds[i].pos.x += \
        rpg->weather_engine.clouds[i].speed.x * \
        rpg->elapsed_microsecond / 100000;
    else
        rpg->weather_engine.clouds[i].pos.x -= \
        rpg->weather_engine.clouds[i].speed.x * \
        rpg->elapsed_microsecond / 100000;
    weather_engine_draw_cloud_one(rpg, \
    rpg->weather_engine.clouds[i].pos, \
    rpg->weather_engine.clouds[i].size, \
    rpg->weather_engine.clouds[i].type);
}