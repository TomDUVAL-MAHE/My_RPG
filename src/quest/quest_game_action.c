/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** game_events
*/

#include "my_game.h"
#include "my_quest.h"
#include "my_pnj.h"

void quest_end_the_end(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, THE_END_QUEST) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, THE_END_QUEST, ENDED);
        quest_list_change_state(rpg, THE_CHOICE_QUEST, IN_PROGRESS);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 1);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 2);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 3);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 0);
        pnj_go_to_new_co(rpg->game->pnj_list, 1, (sfVector2f){800, 800});
        pnj_go_to_new_co(rpg->game->pnj_list, 2, (sfVector2f){900, 800});
        pnj_go_to_new_co(rpg->game->pnj_list, 3, (sfVector2f){1000, 800});
        pnj_go_to_new_co(rpg->game->pnj_list, 0, (sfVector2f){1100, 800});
    }
}

void quest_end_the_choice(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, THE_CHOICE_QUEST) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, THE_CHOICE_QUEST, ENDED);
        quest_list_change_state(rpg, ESCAPE, IN_PROGRESS);
        quest_list_change_state(rpg, FIGHT, IN_PROGRESS);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 1);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 0);
    }
}

void quest_end_escape(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, ESCAPE) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, ESCAPE, ENDED);
        my_putstr("Unfortunately the monster killed all the inhabitants");
        go_to_main_menu_scene(rpg);
    }
}

void quest_end_fight(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, FIGHT) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, FIGHT, ENDED);
        pnj_go_to_new_co(rpg->game->pnj_list, 1, (sfVector2f){-1000, -1000});
        pnj_go_to_new_co(rpg->game->pnj_list, 2, (sfVector2f){-1500, -1000});
        pnj_go_to_new_co(rpg->game->pnj_list, 3, (sfVector2f){-2000, -1000});
        pnj_go_to_new_co(rpg->game->pnj_list, 0, (sfVector2f){-2500, -1000});
        create_new_enemy(rpg->game->enemy_list, BOSS, 4, \
        (sfVector2i){1500, 800});
        weather_engine_start_rain(rpg);
    }
}

void quest_end_fights(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, FIGHT) == \
    ENDED) {
        my_putstr\
        ("Congratulations you have killed the monster. You can go home");
        go_to_main_menu_scene(rpg);
    }
}