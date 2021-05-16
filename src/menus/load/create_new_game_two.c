/*
** EPITECH PROJECT, 2021
** create
** File description:
** create_new_game_two
*/

#include "my_game.h"
#include "cut_scene.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int create_new_save_quest(char *save_name)
{
    char *path = malloc(sizeof(char) * (100 + my_strlen(save_name) + 1));
    FILE *global_new_save = NULL;
    char *global_save = load_file_in_mem("saves/global/new");

    global_save = load_file_in_mem("saves/quest/questnew");
    if (global_save == NULL)
        return (-1);
    path[0] = '\0';
    my_strcat(path, "saves/quest/quest");
    my_strcat(path, save_name);
    global_new_save = fopen(path, "w+");
    fwrite(global_save, my_strlen(global_save), 1, global_new_save);
    fclose(global_new_save);
    free(global_save);
    free(path);
    return (0);
}

int create_new_save_map(char *save_name)
{
    char *path = malloc(sizeof(char) * (100 + my_strlen(save_name) + 1));
    FILE *global_new_save = NULL;
    char *global_save = NULL;

    global_save = load_file_in_mem("saves/maps/mapnew");
    if (global_save == NULL)
        return (-1);
    path[0] = '\0';
    my_strcat(path, "saves/maps/map");
    my_strcat(path, save_name);
    global_new_save = fopen(path, "w+");
    fwrite(global_save, my_strlen(global_save), 1, global_new_save);
    fclose(global_new_save);
    free(global_save);
    free(path);
    return (0);
}

int create_new_save_enemy(char *save_name)
{
    char *path = malloc(sizeof(char) * (100 + my_strlen(save_name) + 1));
    FILE *global_new_save = NULL;
    char *global_save = NULL;

    global_save = load_file_in_mem("saves/enemy/enemynew");
    if (global_save == NULL)
        return (-1);
    path[0] = '\0';
    my_strcat(path, "saves/enemy/enemy");
    my_strcat(path, save_name);
    global_new_save = fopen(path, "w+");
    fwrite(global_save, my_strlen(global_save), 1, global_new_save);
    fclose(global_new_save);
    free(global_save);
    free(path);
    return (0);
}

int create_new_save_pnj(char *save_name)
{
    char *path = malloc(sizeof(char) * (100 + my_strlen(save_name) + 1));
    FILE *global_new_save = NULL;
    char *global_save = NULL;

    global_save = load_file_in_mem("saves/pnj/pnjnew");
    if (global_save == NULL)
        return (-1);
    path[0] = '\0';
    my_strcat(path, "saves/pnj/pnj");
    my_strcat(path, save_name);
    global_new_save = fopen(path, "w+");
    fwrite(global_save, my_strlen(global_save), 1, global_new_save);
    fclose(global_new_save);
    free(global_save);
    free(path);
    return (0);
}

int create_new_save_player(char *save_name)
{
    char *path = malloc(sizeof(char) * (100 + my_strlen(save_name) + 1));
    FILE *global_new_save = NULL;
    char *global_save = NULL;

    global_save = load_file_in_mem("saves/player/playernew");
    if (global_save == NULL)
        return (-1);
    path[0] = '\0';
    my_strcat(path, "saves/player/player");
    my_strcat(path, save_name);
    global_new_save = fopen(path, "w+");
    fwrite(global_save, my_strlen(global_save), 1, global_new_save);
    fclose(global_new_save);
    free(global_save);
    free(path);
    return (0);
}