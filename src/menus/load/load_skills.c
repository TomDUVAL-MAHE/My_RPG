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

void load_skills_update(my_game_t *rpg)
{
    int save = rpg->skill_scene.remaining_point;

    rpg->skill_scene.remaining_point = 100;
    if (rpg->skill_scene.is_active[0] == 1) {
        rpg->skill_scene.is_active[0] = 0;
        skill_scene_get_axe(&(rpg->skill_scene), &(rpg->inventory_scene));
    }
    if (rpg->skill_scene.is_active[1] == 1) {
        rpg->skill_scene.is_active[1] = 0;
        skill_scene_get_pickaxe(&(rpg->skill_scene), &(rpg->inventory_scene));
    }
    if (rpg->skill_scene.is_active[2] == 1) {
        rpg->skill_scene.is_active[2] = 0;
        skill_scene_get_ring(&(rpg->skill_scene), &(rpg->inventory_scene));
    }
    if (rpg->skill_scene.is_active[3] == 1) {
        rpg->skill_scene.is_active[3] = 0;
        skill_scene_get_bow(&(rpg->skill_scene), &(rpg->inventory_scene));
    }
    rpg->skill_scene.remaining_point = save;
}

void skill_upload_update(my_game_t *rpg, char *buffer)
{
    rpg->skill_scene.is_active[0] = buffer[0] - 48;
    rpg->skill_scene.is_active[1] = buffer[1] - 48;
    rpg->skill_scene.is_active[2] = buffer[2] - 48;
    rpg->skill_scene.is_active[3] = buffer[3] - 48;
}

int skill_upload(my_game_t *rpg, char *path)
{
    char *buffer = load_file_in_mem(path);

    if (buffer == NULL)
        return (-1);
    if (my_strlen(buffer) <= 5) {
        write(2, "Invalid Skill Save.\n", 20);
        return (-1);
    }
    skill_upload_update(rpg, buffer);
    rpg->skill_scene.remaining_point = my_getnbr(buffer + 4);
    for (int i = 0; i < 4; i++) {
        if (rpg->skill_scene.is_active[i] != 0 && \
        rpg->skill_scene.is_active[i] != 1) {
            write(2, "Invalid Skill Save.\n", 20);
            free(buffer);
            return (-1);
        }
    }
    free(buffer);
    return (0);
}

int load_skills(my_game_t *rpg, char *save_name)
{
    char *path = malloc(sizeof(char) * (my_strlen("saves/skills/skill") + \
    my_strlen(save_name) + 1));

    path[0] = '\0';
    my_strcat(path, "saves/skills/skill");
    my_strcat(path, save_name);
    if (skill_upload(rpg, path) == -1)
        return (-1);
    load_skills_update(rpg);
    skill_scene_update_text(&(rpg->skill_scene));
    return (0);
}