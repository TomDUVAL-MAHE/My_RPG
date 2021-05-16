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

char *load_file_in_mem(char *path)
{
    char *buffer = readfile(path);

    return (buffer);
}

bool my_strchr(char letter, char *list)
{
    int list_len = my_strlen(list);

    for (int i = 0; i < list_len; i++) {
        if (letter == list[i])
            return (true);
    }
    return (false);
}

int copy_one(char *str, sfVector2i s, char *separators, char *new_str)
{
    if (my_strchr(str[s.x + 1], separators) == false) {
        new_str[s.y] = str[s.x];
        s.y += 1;
    }
    return (s.y);
}