/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_display
*/

#include "my_game.h"
#include "my_pnj.h"

void pnj_setup_window_view(my_game_t *rpg)
{
    sfRenderWindow_clear(rpg->window.window, sfBlack);
    game_scene_display_entities(rpg);
    weather_update(rpg);
    quest_display_shortcut(rpg->quest_list, rpg->window);
    life_bar_display(rpg->life_bar, rpg->window.window, rpg);
    level_bar_display(rpg->level_bar, rpg->window.window, rpg);
}

int chose_dialog(pnj_t *pnj)
{
    if (!pnj->is_quest)
        return (rand() % pnj->max_dialog);
    return (pnj->actual_dialog);
}

void change_dialog(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '\\')
            str[i] = '\n';
    }
}

void pnj_tell(pnj_t *pnj, my_window_t window, my_game_t *rpg)
{
    int stop = 0;
    int choice = chose_dialog(pnj);

    define_orientation_with_intersect(pnj->hitbox, \
    rpg->game->player->hitbox, pnj);
    pnj_setup_window_view(rpg);
    change_dialog(pnj->dialog_list[choice]);
    draw_dialog(window, pnj->dialog_list[choice]);
    while (stop == 0) {
        pnj_tell_end(window, rpg, &stop);
    }
    for (int i = 0; i < my_strlen(pnj->dialog_list[choice]); i++) {
        if (pnj->dialog_list[choice][i] == '\n')
            pnj->dialog_list[choice][i] = '\\';
    }
}

void check_men(pnj_type e_type, char **path)
{
    if (e_type == HUMAN_BASIC_ONE)
        *path = "assets/pnj/men1.png";
    if (e_type == HUMAN_BASIC_TWO) {
        *path = "assets/pnj/men2.png";
    }
    if (e_type == HUMAN_BASIC_THREE)
        *path = "assets/pnj/men3.png";
}