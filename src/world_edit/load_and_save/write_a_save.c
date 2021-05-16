/*
** EPITECH PROJECT, 2021
** write_a_save
** File description:
** desc
*/

#include "my_world_edit.h"
#include "my.h"
#include "my_map.h"
#include <unistd.h>

FILE *open_a_file(save_t *save, char *dir)
{
    FILE *file = NULL;
    int len = my_strlen(dir) + my_strlen(save->save_name) + 1;
    char *path = malloc(sizeof(char) * (len + 1));

    my_strcpy(path, dir);
    my_strcat(path, "/\0");
    my_strcat(path, save->save_name);
    file = fopen(path, "w+");
    free(path);
    if (file == NULL) {
        write(2, "path not found\n", 15);
        return (NULL);
    }
    return (file);
}

void write_map_pos(FILE *file, sfVector2i pos)
{
    char *number = NULL;

    number = int_to_str(pos.x);
    fwrite(number, my_strlen(number), 1, file);
    free(number);
    fwrite(",", 1, 1, file);
    number = int_to_str(pos.y);
    fwrite(number, my_strlen(number), 1, file);
    free(number);
    fwrite("\n", 1, 1, file);
}

void write_map_origin(FILE *file, sfVector2f origin)
{
    char *number = NULL;

    number = int_to_str(origin.x);
    fwrite(number, my_strlen(number), 1, file);
    free(number);
    fwrite(",", 1, 1, file);
    number = int_to_str(origin.y);
    fwrite(number, my_strlen(number), 1, file);
    free(number);
    fwrite("\n", 1, 1, file);
}

void write_map_camera(FILE *file, sfVector2i camera)
{
    char *number = NULL;

    number = int_to_str(camera.x);
    fwrite(number, my_strlen(number), 1, file);
    free(number);
    fwrite(",", 1, 1, file);
    number = int_to_str(camera.y);
    fwrite(number, my_strlen(number), 1, file);
    free(number);
    fwrite("\n", 1, 1, file);
}

void write_map_save(save_t *save, map_t *map)
{
    FILE *file = open_a_file(save, "maps");
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