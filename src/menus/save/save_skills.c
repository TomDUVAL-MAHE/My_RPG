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

void save_skills(my_game_t *rpg, char *save_name)
{
    FILE *save = return_file_descriptor(save_name, \
    "saves/skills/skill");

    fwrite(text_convert_int_to_char(rpg->skill_scene.is_active[0]), \
    my_strlen(text_convert_int_to_char(rpg->skill_scene.is_active[0])), \
    1, save);
    fwrite(text_convert_int_to_char(rpg->skill_scene.is_active[1]), \
    my_strlen(text_convert_int_to_char(rpg->skill_scene.is_active[1])), \
    1, save);
    fwrite(text_convert_int_to_char(rpg->skill_scene.is_active[2]), \
    my_strlen(text_convert_int_to_char(rpg->skill_scene.is_active[2])), \
    1, save);
    fwrite(text_convert_int_to_char(rpg->skill_scene.is_active[3]), \
    my_strlen(text_convert_int_to_char(rpg->skill_scene.is_active[3])), \
    1, save);
    fwrite(text_convert_int_to_char(rpg->skill_scene.remaining_point), \
    my_strlen(text_convert_int_to_char(rpg->skill_scene.remaining_point)), \
    1, save);
    fwrite("A", 1, 1, save);
    fclose(save);
}