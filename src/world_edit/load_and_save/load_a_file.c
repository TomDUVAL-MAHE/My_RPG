/*
** EPITECH PROJECT, 2021
** load_a_file
** File description:
** desc
*/

#include "my_map.h"
#include <stdio.h>
#include "my.h"
#include "my_world_edit.h"

int is_num(char a)
{
    if (a >= '0' && a <= '9')
        return (1);
    return (0);
}

char *read_line(FILE *file)
{
    char *line = NULL;
    size_t size = 0;
    int len = 0;

    len = getline(&line, &size, file);
    if (len < 0) {
        free(line);
        return (NULL);
    }
    if (line[len - 1] == '\n')
        line[len - 1] = '\0';
    return (line);
}

int check_line(map_t *map, char *line, int nb_line)
{
    int res = 1;

    switch (nb_line) {
    case 1:
        res = check_size_valide(line);
        if (res == 0) {
            load_map_size(map, line);
        }
        break;
    case 2:
        res = check_origin_valide(line);
        break;
    case 3:
        res = check_camera_valide(line);
        break;
    case 4:
        res = check_tiles_valide(map, line);
        break;
    }
    return (res);
}

void load_the_map(map_t *map, char *pathname)
{
    FILE *file = fopen(pathname, "r+");
    char *line = read_line(file);
    int nb_line = 1;

    while (line) {
        select_load_map(map, line, nb_line);
        free(line);
        line = read_line(file);
        nb_line++;
    }
    free(line);
    map_set_origin(map, map->origin);
    fclose(file);
}

int load_a_file(map_t *map, char *pathname)
{
    FILE *file = fopen(pathname, "r+");
    char *line = NULL;
    int nb_line = 1;

    if (file == NULL)
        return (1);
    line = read_line(file);
    while (line) {
        if (check_line(map, line, nb_line)) {
            free(line);
            return (1);
        }
        free(line);
        line = read_line(file);
        nb_line++;
    }
    free(line);
    fclose(file);
    return (0);
}