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

void save_map(map_t *map, char *save_name)
{
    FILE *file = return_file_descriptor(save_name, "saves/maps/map");
    char *number = NULL;

    if (file == NULL)
        return;
    write_map_pos(file, map->size);
    write_map_origin(file, map->origin);
    write_map_camera(file, map->camera);
    for (int i = 0; i < map->size.x * map->size.y; i++) {
        number = int_to_str(map->tiles[i].ground);
        fwrite(number, my_strlen(number), 1, file);
        fwrite(",", 1, 1, file);
        free(number);
        number = int_to_str(map->tiles[i].building);
        fwrite(number, my_strlen(number), 1, file);
        fwrite(";", 1, 1, file);
        free(number);
    }
    fclose(file);
}