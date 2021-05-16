/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** game_events
*/

#include "my_game.h"
#include "my_quest.h"
#include "my_pnj.h"

void quest_end_move(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, MOVE_QUEST) == IN_PROGRESS) {
        quest_list_change_state(rpg, MOVE_QUEST, ENDED);
        quest_list_change_state(rpg, GO_TO_VILLAGE_QUEST, IN_PROGRESS);
    }
}

void quest_end_gtv(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, GO_TO_VILLAGE_QUEST) == \
    IN_PROGRESS) {
        if (is_in_zone(rpg->game->player->hitbox, VILLAGE_ZONE, rpg)) {
            quest_list_change_state(rpg, GO_TO_VILLAGE_QUEST, ENDED);
            quest_list_change_state(rpg, TALK_TO_MAYOR_QUEST, IN_PROGRESS);
        }
    }
}

void quest_end_talk_to_mayor(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, TALK_TO_MAYOR_QUEST) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, TALK_TO_MAYOR_QUEST, ENDED);
        quest_list_change_state(rpg, TALK_TO_BLACKSMITH_QUEST, IN_PROGRESS);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 1);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 0);
    }
}

void quest_end_talk_to_blacksmith(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, TALK_TO_BLACKSMITH_QUEST) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, TALK_TO_BLACKSMITH_QUEST, ENDED);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 0);
        inventory_add_item_to_list(rpg->inventory_scene.inventory_one, \
        rpg->inventory_scene.items, \
        rpg->inventory_scene.inventory_list_one, "ARMOR1");
        quest_list_change_state(rpg, GO_TO_PEERAGE_QUEST, IN_PROGRESS);
        quest_list_change_state(rpg, EQUIP_JACKET_QUEST, IN_PROGRESS);
    }
}

void quest_end_gtp(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, GO_TO_PEERAGE_QUEST) == \
    IN_PROGRESS) {
        if (is_in_zone(rpg->game->player->hitbox, PEERAGE_ZONE, rpg)) {
            quest_list_change_state(rpg, GO_TO_PEERAGE_QUEST, ENDED);
            quest_list_change_state(rpg, END_FIGHT_ONE_QUEST, IN_PROGRESS);
        }
    }
}