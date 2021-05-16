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

void save_pnj_two(FILE *save, pnj_node_t *ptr)
{
    fwrite(text_convert_int_to_char((int)ptr->pnj->start.x), \
    my_strlen(text_convert_int_to_char((int)ptr->pnj->start.x)), \
    1, save);
    fwrite(";", 1, 1, save);
    fwrite(text_convert_int_to_char((int)ptr->pnj->start.y), \
    my_strlen(text_convert_int_to_char((int)ptr->pnj->start.y)), \
    1, save);
    fwrite(";", 1, 1, save);
    fwrite(text_convert_int_to_char((int)ptr->pnj->end.x), \
    my_strlen(text_convert_int_to_char((int)ptr->pnj->end.x)), \
    1, save);
    fwrite(";", 1, 1, save);
    fwrite(text_convert_int_to_char((int)ptr->pnj->end.y), \
    my_strlen(text_convert_int_to_char((int)ptr->pnj->end.y)), \
    1, save);
}

void save_pnj_three(FILE *save, pnj_node_t *ptr)
{
    fwrite(";", 1, 1, save);
    fwrite(text_convert_int_to_char((int)(ptr->pnj->e_type)), \
    my_strlen(text_convert_int_to_char((int)(ptr->pnj->e_type))), \
    1, save);
    fwrite(";", 1, 1, save);
    fwrite(text_convert_int_to_char((int)ptr->pnj->is_quest), \
    my_strlen(text_convert_int_to_char((int)ptr->pnj->is_quest)), \
    1, save);
    fwrite(";", 1, 1, save);
    fwrite(text_convert_int_to_char((int)ptr->pnj->actual_dialog), \
    my_strlen(text_convert_int_to_char((int)ptr->pnj->actual_dialog)), \
    1, save);
    fwrite(";", 1, 1, save);
}

void save_pnj(my_game_t *rpg, char *save_name)
{
    FILE *save = return_file_descriptor(save_name, "saves/pnj/pnj");
    pnj_node_t *ptr;

    if (!rpg->game->pnj_list->first) {
        fwrite("A", 1, 1, save);
        fclose(save);
        return;
    }
    ptr = rpg->game->pnj_list->first;
    while (ptr) {
        save_pnj_two(save, ptr);
        save_pnj_three(save, ptr);
        for (int i = 0; i < ptr->pnj->max_dialog; i++) {
            fwrite(ptr->pnj->dialog_list[i], my_strlen\
            (ptr->pnj->dialog_list[i]), 1, save);
            fwrite(";", 1, 1, save);
        }
        fwrite("\n", 1, 1, save);
        ptr = ptr->next;
    }
    fclose(save);
}