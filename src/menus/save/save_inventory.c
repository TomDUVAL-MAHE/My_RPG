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
#include "my_quest.h"

void save_inventory(my_game_t *rpg, char *save_name)
{
    char *path = malloc(sizeof(char) * (my_strlen\
    ("saves/inventory/inventory_one") + my_strlen(save_name) + 1));

    path[0] = '\0';
    my_strcat(path, "saves/inventory/inventory_one");
    my_strcat(path, save_name);
    inventory_save_list(rpg->inventory_scene.inventory_one, \
    rpg->inventory_scene.inventory_list_one, path, \
    rpg->inventory_scene.items);
    path[0] = '\0';
    my_strcat(path, "saves/inventory/inventory_two");
    my_strcat(path, save_name);
    inventory_save_list(rpg->inventory_scene.inventory_two, \
    rpg->inventory_scene.inventory_list_two, path, \
    rpg->inventory_scene.items);
    free(path);
}