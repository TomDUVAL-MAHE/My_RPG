/*
** EPITECH PROJECT, 2021
** create
** File description:
** create_new_game_one
*/

#include "my_game.h"
#include "cut_scene.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int create_new_save_global(char *save_name)
{
    char *path = malloc(sizeof(char) * (100 + my_strlen(save_name) + 1));
    FILE *global_new_save = NULL;
    char *global_save = load_file_in_mem("saves/global/new");

    if (global_save == NULL)
        return (-1);
    path[0] = '\0';
    my_strcat(path, "saves/global/");
    my_strcat(path, save_name);
    global_new_save = fopen(path, "w+");
    fwrite(global_save, my_strlen(global_save), 1, global_new_save);
    fclose(global_new_save);
    free(global_save);
    free(path);
    return (0);
}

int create_new_save_inventory(char *save_name)
{
    char *path = malloc(sizeof(char) * (100 + my_strlen(save_name) + 1));
    FILE *global_new_save = NULL;
    char *global_save = load_file_in_mem("saves/global/new");

    global_save = load_file_in_mem("saves/inventory/inventory_onenew");
    if (global_save == NULL)
        return (-1);
    path[0] = '\0';
    my_strcat(path, "saves/inventory/inventory_one");
    my_strcat(path, save_name);
    global_new_save = fopen(path, "w+");
    fwrite(global_save, my_strlen(global_save), 1, global_new_save);
    fclose(global_new_save);
    free(global_save);
    free(path);
    return (0);
}

int create_new_save_inventory_two(char *save_name)
{
    char *path = malloc(sizeof(char) * (100 + my_strlen(save_name) + 1));
    FILE *global_new_save = NULL;
    char *global_save = load_file_in_mem("saves/global/new");

    global_save = load_file_in_mem("saves/inventory/inventory_twonew");
    if (global_save == NULL)
        return (-1);
    path[0] = '\0';
    my_strcat(path, "saves/inventory/inventory_two");
    my_strcat(path, save_name);
    global_new_save = fopen(path, "w+");
    fwrite(global_save, my_strlen(global_save), 1, global_new_save);
    fclose(global_new_save);
    free(global_save);
    free(path);
    return (0);
}

int create_new_save_stats(char *save_name)
{
    char *path = malloc(sizeof(char) * (100 + my_strlen(save_name) + 1));
    FILE *global_new_save = NULL;
    char *global_save = NULL;

    global_save = load_file_in_mem("saves/stats/statsnew");
    if (global_save == NULL)
        return (-1);
    path[0] = '\0';
    my_strcat(path, "saves/stats/stats");
    my_strcat(path, save_name);
    global_new_save = fopen(path, "w+");
    fwrite(global_save, my_strlen(global_save), 1, global_new_save);
    fclose(global_new_save);
    free(global_save);
    free(path);
    return (0);
}

int create_new_save_skill(char *save_name)
{
    char *path = malloc(sizeof(char) * (100 + my_strlen(save_name) + 1));
    FILE *global_new_save = NULL;
    char *global_save = load_file_in_mem("saves/global/new");

    global_save = load_file_in_mem("saves/skills/skillnew");
    if (global_save == NULL)
        return (-1);
    path[0] = '\0';
    my_strcat(path, "saves/skills/skill");
    my_strcat(path, save_name);
    global_new_save = fopen(path, "w+");
    fwrite(global_save, my_strlen(global_save), 1, global_new_save);
    fclose(global_new_save);
    free(global_save);
    free(path);
    return (0);
}