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

void save_quest(my_game_t *rpg, char *save_name)
{
    FILE *save = return_file_descriptor(save_name, "saves/quest/quest");
    quest_t *quest = rpg->quest_list.first;

    quest = quest->next;
    while (quest != NULL) {
        fwrite(quest->content.name, my_strlen(quest->content.name), 1, save);
        fwrite(";", 1, 1, save);
        fwrite(text_convert_int_to_char(quest->content.id), \
        my_strlen(text_convert_int_to_char(quest->content.id)), 1, save);
        fwrite(";", 1, 1, save);
        fwrite(quest->content.description, \
        my_strlen(quest->content.description), 1, save);
        fwrite(";", 1, 1, save);
        fwrite(text_convert_int_to_char(quest->content.state), \
        my_strlen(text_convert_int_to_char(quest->content.state)), 1, save);
        fwrite(";", 1, 1, save);
        fwrite("\n", 1, 1, save);
        quest = quest->next;
    }
    fclose(save);
}