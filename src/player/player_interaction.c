/*
** EPITECH PROJECT, 10021
** RPG
** File description:
** player_moves
*/

#include "my_game.h"

pnj_t *player_interact_with_pnj(player_t *player, pnj_list_t *pnj_list, \
int *count)
{
    pnj_node_t *ptr;

    if (!pnj_list) {
        return (false);
    }
    ptr = pnj_list->first;
    while (ptr) {
        if (sfFloatRect_intersects(&(player->hitbox), \
            &(ptr->pnj->hitbox), NULL) == true)
            return (ptr->pnj);
        ptr = ptr->next;
        *count += 1;
    }
    return (NULL);
}

void player_interactions(my_game_t *rpg, int count, pnj_t *pnj)
{
    if (count == 0 && pnj->actual_dialog == 3)
        quest_end_go_back_blacksmith(rpg);
    if (count == 0 && pnj->actual_dialog == 6)
        quest_end_fight(rpg);
    if (count == 2 && pnj->actual_dialog == 1)
        quest_end_talk_magician(rpg);
    if (count == 2 && pnj->actual_dialog == 3)
        quest_end_go_back_magician(rpg);
    if (count == 3 && pnj->actual_dialog == 1)
        quest_end_talk_archer(rpg);
    if (count == 3 && pnj->actual_dialog == 3)
        quest_end_go_back_archer(rpg);
}

void player_interaction(my_game_t *rpg)
{
    int count = 0;
    pnj_t *pnj = player_interact_with_pnj(rpg->game->player, \
    rpg->game->pnj_list, &count);

    if (pnj == NULL)
        return;
    pnj_tell(pnj, rpg->window, rpg);
    if (count == 1 && pnj->actual_dialog == 0)
        quest_end_talk_to_mayor(rpg);
    if (count == 1 && pnj->actual_dialog == 2)
        quest_end_talk_back_mayor(rpg);
    if (count == 1 && pnj->actual_dialog == 4)
        quest_end_the_choice(rpg);
    else if (count == 1 && pnj->actual_dialog == 5)
        quest_end_escape(rpg);
    if (count == 0 && pnj->actual_dialog == 1)
        quest_end_talk_to_blacksmith(rpg);
    player_interactions(rpg, count, pnj);
}