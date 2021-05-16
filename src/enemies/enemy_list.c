/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_listc
*/

#include "my_enemy.h"
#include <stdlib.h>

enemy_list_t *enemy_list_init(void)
{
    enemy_list_t *list = malloc(sizeof(*list));

    if (!list)
        return (NULL);
    list->first = NULL;
    return (list);
}

void enemy_list_destroy(enemy_list_t *list)
{
    enemy_node_t *ptr;
    enemy_node_t *node_to_free;

    if (!list && !list->first)
        return;
    ptr = list->first;
    while (ptr) {
        node_to_free = ptr;
        ptr = ptr->next;
        enemy_destroy(node_to_free->enemy);
        free(node_to_free);
    }
    free(list);
}

int enemy_list_insert_beginning(enemy_list_t *list, enemy_t *enemy)
{
    enemy_node_t *new_node;

    if (!list)
        return (-1);
    new_node = malloc(sizeof(*new_node));
    if (!new_node)
        return (-1);
    new_node->enemy = enemy;
    new_node->next = list->first;
    list->first = new_node;
    return (0);
}