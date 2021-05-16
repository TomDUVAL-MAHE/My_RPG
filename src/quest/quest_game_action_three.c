/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** game_events
*/

#include "my_game.h"
#include "my_quest.h"
#include "my_pnj.h"

void quest_end_equip_jacket(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, EQUIP_JACKET_QUEST) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, EQUIP_JACKET_QUEST, ENDED);
    }
}

void quest_end_fight_two(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, END_FIGHT_TWO_QUEST) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, END_FIGHT_TWO_QUEST, ENDED);
        quest_list_change_state(rpg, TALK_BACK_TO_MAGICIAN_QUEST, IN_PROGRESS);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 2);
    }
}

void quest_end_go_back_magician(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, TALK_BACK_TO_MAGICIAN_QUEST) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, TALK_BACK_TO_MAGICIAN_QUEST, ENDED);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 2);
        inventory_add_item_to_list(rpg->inventory_scene.inventory_one, \
        rpg->inventory_scene.items, \
        rpg->inventory_scene.inventory_list_one, "NECK3");
        inventory_add_item_to_list(rpg->inventory_scene.inventory_one, \
        rpg->inventory_scene.items, \
        rpg->inventory_scene.inventory_list_one, "NECK2");
        inventory_add_item_to_list(rpg->inventory_scene.inventory_one, \
        rpg->inventory_scene.items, \
        rpg->inventory_scene.inventory_list_one, "NECK1");
        quest_list_change_state(rpg, TALK_TO_ARCHER_QUEST, IN_PROGRESS);
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 3);
    }
}

void quest_end_talk_archer(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, TALK_TO_ARCHER_QUEST) == \
    IN_PROGRESS) {
        quest_list_change_state(rpg, TALK_TO_ARCHER_QUEST, ENDED);
        quest_list_change_state(rpg, GO_TO_MOUNTAIN_QUEST, IN_PROGRESS);
        quest_list_change_state(rpg, UNLOCK_PASSAGE_TWO_QUEST, IN_PROGRESS);
        inventory_add_item_to_list(rpg->inventory_scene.inventory_one, \
        rpg->inventory_scene.items, \
        rpg->inventory_scene.inventory_list_one, "PICKAXE");
        pnj_go_to_nex_dialogs(rpg->game->pnj_list, 3);
    }
}

void quest_end_gtm(my_game_t *rpg)
{
    if (quest_list_return_state_by_id(rpg, GO_TO_MOUNTAIN_QUEST) == \
    IN_PROGRESS) {
        if (is_in_zone(rpg->game->player->hitbox, MOUTAIN_ZONE, rpg)) {
            quest_list_change_state(rpg, GO_TO_MOUNTAIN_QUEST, ENDED);
            quest_list_change_state(rpg, END_FIGHT_THREE_QUEST, IN_PROGRESS);
        }
    }
}