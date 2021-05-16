/*
** EPITECH PROJECT, 2020
** proto.h
** File description:
** prototypes of all the function
*/

#ifndef __WEATHER_ENGINE
#define __WEATHER_ENGINE

//--INCLUDE--------------------------------------------

#include <SFML/Graphics.h>
#include "framebuffer.h"

//--DEFINE---------------------------------------------

#define SUN 0
#define SNOW 2
#define RAIN 3
#define ANIMATION 10
#define NONE -1

//--STRUCTURES-----------------------------------------

typedef struct my_game_s my_game_t;

typedef struct cloud_s {
    int type;
    sfVector2i speed;
    sfVector2i pos;
    sfVector2i dir;
    int size;
} cloud_t;

typedef struct my_weather_s {
    framebuffer_t framebuffer;
    int actual_weather;
    int actual_animation;
    int blind_animation_current_size;
    sfVector2i *snow_animation_snow;
    int snow_animation_counter;
    cloud_t *clouds;
    int cloud_number;
} my_weather_t;

//--PROTOTYPE------------------------------------------

//WEATHER_SNOW.C//

void weather_engine_start_snow(my_game_t *rpg);
void weather_update_snow_draw(my_game_t *rpg, int i);
void weather_update_snow(my_game_t *rpg);

//WEARHER_CLOUD.C//

void weather_engine_draw_cloud_one(my_game_t *rpg, sfVector2i pos, \
int scale, int type);
void weather_setup_cloud_one(my_game_t *rpg, int i, int type, int s);
void weather_engine_detect_dir_cloud(my_game_t *rpg, int i, int type, int s);
void weather_engine_move_cloud(my_game_t *rpg, int i, int type, int s);

//WEATHER_RAIN.C//

void weather_engine_start_rain(my_game_t *rpg);
void weather_update_rain_draw_rain(my_game_t *rpg, int i);
void weather_update_rain(my_game_t *rpg);

//WEATHER_SUN.C//

void weather_engine_start_sun(my_game_t *rpg);
void weather_update_sun(my_game_t *rpg);

//WEATHER_BLIND.C//

void weather_engine_start_blind(my_game_t *rpg);
void weather_animation_blind_draw_circel(my_game_t *rpg, sfVector2i player_pos);
void weather_animation_blind(my_game_t *rpg);
void weather_update_blind(my_game_t *rpg);

//WEATHER_ENGINE_UPDATE.C//

void weather_update(my_game_t *rpg);

//WEATHER_ENGINE_SETUP.C//

my_weather_t weather_engine_setup(my_game_t *rpg);

#endif