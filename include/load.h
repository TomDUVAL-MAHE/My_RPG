/*
** EPITECH PROJECT, 2021
** my_game
** File description:
** desc
*/

#ifndef LOAD_H_
#define LOAD_H_

#include "my_game.h"

int load_a_save(my_game_t *rpg, char *save_name);
int create_new_save(char *save_name, my_game_t *rpg);
char *load_file_in_mem(char *path);
int load_inventory(my_game_t *rpg, char *save_name);
int load_quest(my_game_t *rpg, char *save_name);
int load_skills(my_game_t *rpg, char *save_name);
int load_stats(my_game_t *rpg, char *save_name);
void clear_a_save(char *save_name);
char **my_str_to_word_array_separators(char *buffer, char *separators);
void my_array_free(char **array);
int my_array_get_size(char **array);
int load_player(my_game_t *rpg, char *save_name);
int load_enemy(my_game_t *rpg, char *save_name);
int load_pnj(my_game_t *rpg, char *save_name);

#endif