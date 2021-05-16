/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_node
*/

#include "my_pnj.h"
#include <stdlib.h>

void pnj_list_destroy_a_node(pnj_node_t *node)
{
    if (!node)
        return;
    pnj_destroy(node->pnj);
    free(node);
}

void pnj_list_destroy_a_selected_node_in_list(pnj_list_t *list, \
pnj_node_t *node)
{
    pnj_node_t *ptr;
    pnj_node_t *node_to_free;

    if (!list || !node)
        return;
    ptr = list->first;
    if (!ptr)
        return;
    if (ptr == node) {
        list->first = ptr->next;
        pnj_list_destroy_a_node(ptr);
    }
    while (ptr) {
        if (ptr->next == node) {
            node_to_free = ptr->next;
            ptr->next = node_to_free->next;
            pnj_list_destroy_a_node(node_to_free);
            break;
        }
        ptr = ptr->next;
    }
}
