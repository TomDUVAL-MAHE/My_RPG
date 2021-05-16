/*
** EPITECH PROJECT, 2021
** my_game
** File description:
** desc
*/

#ifndef SAVE_H_
#define SAVE_H_

#include "my_game.h"

void save_gestion(my_game_t *rpg);
FILE *return_file_descriptor(char *save_name, char *first_path);
void save_stats(my_game_t *rpg, char *save_name);
void save_skills(my_game_t *rpg, char *save_name);
void save_quest(my_game_t *rpg, char *save_name);
void save_player(my_game_t *rpg, char *save_name);
void save_map(map_t *map, char *save_name);
void save_inventory(my_game_t *rpg, char *save_name);
void save_enemy(my_game_t *rpg, char *save_name);
void save_pnj(my_game_t *rpg, char *save_name);

#endif