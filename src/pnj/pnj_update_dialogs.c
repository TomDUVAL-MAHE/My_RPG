/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_display
*/

#include "my_game.h"
#include "my_pnj.h"

void pnj_go_to_nex_dialogs(pnj_list_t *pnj_list, int nbr)
{
    pnj_node_t *ptr;
    int count = 0;

    if (!pnj_list)
        return;
    ptr = pnj_list->first;
    while (ptr) {
        if (nbr == count)
            ptr->pnj->actual_dialog += 1;
        count++;
        ptr = ptr->next;
    }
}

void pnj_go_to_new_co(pnj_list_t *pnj_list, int nbr, sfVector2f pos)
{
    pnj_node_t *ptr;
    int count = 0;

    if (!pnj_list)
        return;
    ptr = pnj_list->first;
    while (ptr) {
        if (nbr == count) {
            ptr->pnj->start = pos;
            ptr->pnj->end = (sfVector2f){pos.x + 50, pos.y + 50};
            ptr->pnj->hitbox.left = pos.x;
            ptr->pnj->hitbox.top = pos.y;
        }
        count++;
        ptr = ptr->next;
    }
}