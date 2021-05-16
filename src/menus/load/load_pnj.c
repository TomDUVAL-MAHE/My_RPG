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

void pnj_set_dialog(pnj_t *pnj, char **dialogs, bool is_quest, int actual)
{
    char **new_dialogs = malloc(sizeof(char *) * \
    (my_array_get_size(dialogs) + 1));

    for (int i = 0; i < my_array_get_size(dialogs); i++) {
        new_dialogs[i] = my_strdup(dialogs[i]);
    }
    new_dialogs[my_array_get_size(dialogs)] = '\0';
    pnj->is_quest = is_quest;
    pnj->dialog_list = new_dialogs;
    pnj->max_dialog = my_array_get_size(dialogs);
    pnj->actual_dialog = actual;
}

int pnj_fill(my_game_t *rpg, char **buffer_list)
{
    char **pnj_information = NULL;

    for (int i = my_array_get_size(buffer_list) - 1; i >= 0; i--) {
        pnj_information = my_str_to_word_array_separators(buffer_list[i], ";");
        if (my_array_get_size(pnj_information) < 8) {
            my_array_free(pnj_information);
            write(2, "Invalid Pnj Save.\n", 20);
            return (-1);
        }
        create_new_pnj(rpg->game->pnj_list, my_getnbr(pnj_information[4]), \
        (sfVector2i){my_getnbr(pnj_information[0]), \
            my_getnbr(pnj_information[1])}, (sfVector2i)\
        {my_getnbr(pnj_information[2]), my_getnbr(pnj_information[3])});
        pnj_set_dialog(rpg->game->pnj_list->first->pnj, \
        pnj_information + 7, my_getnbr(pnj_information[5]), \
        my_getnbr(pnj_information[6]));
        my_array_free(pnj_information);
    }
    return (0);
}

int pnj_upload(my_game_t *rpg, char *path)
{
    char *buffer = load_file_in_mem(path);
    char **buffer_list = NULL;

    if (buffer == NULL)
        return (-1);
    buffer_list = my_str_to_word_array_separators(buffer, "\n");
    if (buffer_list[0][0] == 'A') {
        my_array_free(buffer_list);
        return (0);
    }
    if (pnj_fill(rpg, buffer_list) == -1) {
        my_array_free(buffer_list);
        return (-1);
    }
    my_array_free(buffer_list);
    return (0);
}

int load_pnj(my_game_t *rpg, char *save_name)
{
    char *path = malloc(sizeof(char) * (my_strlen("saves/pnj/pnj") + \
    my_strlen(save_name) + 1));

    path[0] = '\0';
    my_strcat(path, "saves/pnj/pnj");
    my_strcat(path, save_name);
    if (pnj_upload(rpg, path) == -1)
        return (-1);
    return (0);
}