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

void my_array_free(char **array)
{
    for (; *array[0] != '\0'; array++) {
        free(*array);
    }
}

int my_array_get_size(char **array)
{
    int count = 0;

    for (char **str = array; *str[0] != '\0'; str++)
        count++;
    return (count);
}

int quest_fill(my_game_t *rpg, char **buffer_list)
{
    char **quest_information = NULL;

    for (int i = 0; buffer_list[i][0] != '\0'; i++) {
        quest_information = my_str_to_word_array_separators\
        (buffer_list[i], ";");
        if (my_array_get_size(quest_information) != 4) {
            my_array_free(quest_information);
            write(2, "Invalid Quest File.\n", 20);
            return (-1);
        }
        quest_list_add_quest_end(rpg, (quest_content_t){quest_information[0], \
            my_getnbr(quest_information[1]), quest_information[2], \
            my_getnbr(quest_information[3])});
        my_array_free(quest_information);
    }
    return (0);
}

int quest_upload(my_game_t *rpg, char *path)
{
    char *buffer = load_file_in_mem(path);
    char **buffer_list = NULL;

    if (buffer == NULL)
        return (-1);
    buffer_list = my_str_to_word_array_separators(buffer, "\n");
    if (quest_fill(rpg, buffer_list) == -1) {
        my_array_free(buffer_list);
        return (-1);
    }
    my_array_free(buffer_list);
    return (0);
}

int load_quest(my_game_t *rpg, char *save_name)
{
    char *path = malloc(sizeof(char) * (my_strlen("saves/quest/quest") + \
    my_strlen(save_name) + 1));

    path[0] = '\0';
    my_strcat(path, "saves/quest/quest");
    my_strcat(path, save_name);
    if (quest_upload(rpg, path) == -1)
        return (-1);
    return (0);
}