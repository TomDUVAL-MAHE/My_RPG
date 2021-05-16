/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** game_events
*/

#include "my_game.h"
#include "my_quest.h"
#include "my_pnj.h"

void quest_end_unlock_passage_two(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, UNLOCK_PASSAGE_TWO_QUEST) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, UNLOCK_PASSAGE_TWO_QUEST, ENDED);
    }
}

void quest_end_fight_three(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, END_FIGHT_THREE_QUEST) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, END_FIGHT_THREE_QUEST, ENDED);
        quest_list_change_state(rpg, TALK_BACK_TO_ARCHER_QUEST, IN_PROGRESS);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 3);
    }
}

void quest_end_go_back_archer(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, TALK_BACK_TO_ARCHER_QUEST) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, TALK_BACK_TO_ARCHER_QUEST, ENDED);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 3);
        inventory_add_item_to_list(rpg->inventory_scene.inventory_one, \
        rpg->inventory_scene.items, \
        rpg->inventory_scene.inventory_list_one, "BOW1");
        quest_list_change_state(rpg, TALK_BACK_TO_MAYOR_QUEST, IN_PROGRESS);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 1);
    }
}

void quest_end_talk_back_mayor(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, TALK_BACK_TO_MAYOR_QUEST) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, TALK_BACK_TO_MAYOR_QUEST, ENDED);
        quest_list_change_state(rpg, GO_TO_BEACH_QUEST, IN_PROGRESS);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 1);
    }
}

void quest_end_gtb(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, GO_TO_BEACH_QUEST) == \
    IN_PROGRESS) {
        if (is_in_zone(rpg->game->player->hitbox, BEACH_ZONE, rpg)) {
            quest_list_change_state(rpg, GO_TO_BEACH_QUEST, ENDED);
            quest_list_change_state(rpg, THE_END_QUEST, IN_PROGRESS);
            quest_end_the_end(rpg);
        }
    }
}