/*
** EPITECH PROJECT, 2021
** option
** File description:
** desc
*/

#ifndef OPTION_H_
#define OPTION_H_

#include "my_button.h"
#include "my_menu.h"

typedef struct option_s {
    bool sound;
    bool music;
    sfVector2u size;
    menus_t *menu;
} option_t;

void option_init(my_game_t *rpg);
void show_option(my_game_t *rpg);
void game_scene_option_menu_event(my_game_t *rpg, sfEvent event);
void update_music(my_game_t *rpg);
void update_sound(my_game_t *rpg);
void option_button_one(my_game_t *rpg);
void option_button_two(my_game_t *rpg);
void option_button_four(my_game_t *rpg);

#endif /* !OPTION_H_ */