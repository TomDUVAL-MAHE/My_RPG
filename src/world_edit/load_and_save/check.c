/*
** EPITECH PROJECT, 2021
** check
** File description:
** desc
*/

#include "my_world_edit.h"
#include "my.h"

int check_size_valide(char *line)
{
    int i = 0;

    for (; line[i] && is_num(line[i]); i++);
    if (line[i] && line[i] == ',')
        i++;
    else
        return (1);
    for (; line[i] && is_num(line[i]); i++);
    if (line[i])
        return (1);
    return (0);
}

int check_camera_valide(char *line)
{
    int i = 0;

    for (; line[i] && is_num(line[i]); i++);
    if (line[i] && line[i] == ',')
        i++;
    else
        return (1);
    for (; line[i] && is_num(line[i]); i++);
    if (line[i])
        return (1);
    return (0);
}

int check_origin_valide(char *line)
{
    int i = 0;

    for (int j = i; line[i]; i++) {
        if (i == j && line[i] == '-')
            i++;
        else if (!is_num(line[i]))
            break;
    }
    if (line[i] && line[i] == ',')
        i++;
    else
        return (1);
    for (int j = i; line[i]; i++) {
        if (i == j && line[i] == '-')
            i++;
        else if (!is_num(line[i]))
            break;
    }
    if (line[i])
        return (1);
    return (0);
}

int check_tiles_valide(map_t *map, char *line)
{
    int i = 0;
    int j = 0;

    for (; line[i]; j++) {
        while (line[i] && is_num(line[i]))
            i++;
        if (line[i] != ',')
            return (1);
        i++;
        while (line[i] && is_num(line[i]))
            i++;
        if (line[i] != ';')
            return (1);
        i++;
    }
    if (j != map->size.x * map->size.y) {
        return (1);
    }
    return (0);
}

void load_map_size(map_t *map, char *line)
{
    int i = 0;

    map->size.x = my_getnbr(line);
    while (line[i]) {
        if (line[i] == ',')
            break;
        i++;
    }
    i++;
    map->size.y = my_getnbr(line + i);
}