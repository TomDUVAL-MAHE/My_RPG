/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_listc
*/

#include "my_pnj.h"
#include <stdlib.h>

pnj_list_t *pnj_list_init(void)
{
    pnj_list_t *list = malloc(sizeof(*list));

    if (!list)
        return (NULL);
    list->first = NULL;
    return (list);
}

void pnj_list_destroy(pnj_list_t *list)
{
    pnj_node_t *ptr;
    pnj_node_t *node_to_free;

    if (!list)
        return;
    ptr = list->first;
    while (ptr) {
        node_to_free = ptr;
        ptr = ptr->next;
        pnj_destroy(node_to_free->pnj);
        free(node_to_free);
    }
    free(list);
}

int pnj_list_insert_beginning(pnj_list_t *list, pnj_t *pnj)
{
    pnj_node_t *new_node;

    if (!list)
        return (-1);
    new_node = malloc(sizeof(*new_node));
    if (!new_node)
        return (-1);
    new_node->pnj = pnj;
    new_node->next = list->first;
    list->first = new_node;
    return (0);
}