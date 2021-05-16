/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** game_events
*/

#include "my_game.h"
#include "my_quest.h"
#include "my_pnj.h"

void quest_end_fight_one(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, END_FIGHT_ONE_QUEST) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, END_FIGHT_ONE_QUEST, ENDED);
        quest_list_change_state(rpg, TALK_BACK_TO_BLACKSMITH_QUEST, \
        IN_PROGRESS);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 0);
    }
}

void quest_end_go_back_blacksmith(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, TALK_BACK_TO_BLACKSMITH_QUEST) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, TALK_BACK_TO_BLACKSMITH_QUEST, ENDED);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 0);
        inventory_add_item_to_list(rpg->inventory_scene.inventory_one, \
        rpg->inventory_scene.items, \
        rpg->inventory_scene.inventory_list_one, "AXE");
        quest_list_change_state(rpg, TALK_TO_MAGICIAN_QUEST, IN_PROGRESS);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 2);
    }
}

void quest_end_talk_magician(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, TALK_TO_MAGICIAN_QUEST) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, TALK_TO_MAGICIAN_QUEST, ENDED);
        quest_list_change_state(rpg, GO_TO_ICELAND_QUEST, IN_PROGRESS);
        quest_list_change_state(rpg, UNLOCK_PASSAGE_QUEST, IN_PROGRESS);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 2);
    }
}

void quest_end_gti(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, GO_TO_ICELAND_QUEST) == \
    IN_PROGRESS) {
        if (is_in_zone(rpg->game->player->hitbox, ICELAND_ZONE, rpg)) {
            quest_list_change_state(rpg, GO_TO_ICELAND_QUEST, ENDED);
            quest_list_change_state(rpg, END_FIGHT_TWO_QUEST, IN_PROGRESS);
        }
    }
}

void quest_end_unlock_passage(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, UNLOCK_PASSAGE_QUEST) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, UNLOCK_PASSAGE_QUEST, ENDED);
    }
}