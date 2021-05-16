/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** main_menu_play_part_buttons.c
*/

#include "my_game.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include "my_world_edit.h"

char *load_file_in_mem_without_error(char *path)
{
    char *buffer = readfile(path);

    return (buffer);
}

void clear_a_save(char *save_name)
{
    char *path = malloc(sizeof(char) * (my_strlen("saves/global/") + \
    my_strlen(save_name) + 1));
    FILE *save = NULL;

    path[0] = '\0';
    my_strcat(path, "saves/global/");
    my_strcat(path, save_name);
    save = fopen(path, "w+");
    fclose(save);
}

int load_map(my_game_t *rpg, char *save_name)
{
    char *path = malloc(sizeof(char) * (my_strlen("saves/maps/map") + \
    my_strlen(save_name) + 1));

    path[0] = '\0';
    my_strcat(path, "saves/maps/map");
    my_strcat(path, save_name);
    if (load_a_file(rpg->game->map, path) == 0) {
        load_the_map(rpg->game->map, path);
    } else
        return (-1);
    return (0);
}

int load_a_save_call(my_game_t *rpg, char *save_name)
{
    if (load_player(rpg, save_name) == -1)
        return (-1);
    if (load_inventory(rpg, save_name) == -1)
        return (-1);
    if (load_quest(rpg, save_name) == -1)
        return (-1);
    if (load_skills(rpg, save_name) == -1)
        return (-1);
    if (load_stats(rpg, save_name) == -1)
        return (-1);
    if (load_enemy(rpg, save_name) == -1)
        return (-1);
    if (load_pnj(rpg, save_name) == -1)
        return (-1);
    if (load_map(rpg, save_name) == -1)
        return (-1);
    return (0);
}

int load_a_save(my_game_t *rpg, char *save_name)
{
    char *path = malloc(sizeof(char) * (my_strlen("saves/global/") + \
    my_strlen(save_name) + 1));

    rpg->game = game_scene_init(rpg);
    rpg->weather_engine = weather_engine_setup(rpg);
    rpg->inventory_scene = inventory_scene_setup\
    (rpg->window.window, rpg->game->player);
    rpg->skill_scene = skill_scene_setup(rpg->window.window);
    quest_all_setup(rpg);
    path[0] = '\0';
    my_strcat(path, "saves/global/");
    my_strcat(path, save_name);
    if (load_file_in_mem_without_error(path) == NULL) {
        if (create_new_save(save_name, rpg) == -1) {
            return (-1);
        }
    }
    free(path);
    rpg->save_name = my_strdup(save_name);
    return (load_a_save_call(rpg, save_name));
}