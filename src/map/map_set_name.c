/*
** EPITECH PROJECT, 2021
** map_set_name
** File description:
** desc
*/

#include "my_map.h"

int name_len(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

void map_set_name(map_t *map, char *name)
{
    int len = 0;
    int i = 0;

    if (name == NULL)
        return;
    len = name_len(name);
    map->name = malloc(sizeof(char) * (len + 1));
    while (name[i]) {
        map->name[i] = name[i];
        i++;
    }
    map->name[i] = '\0';
}