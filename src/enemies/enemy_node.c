/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** enemy_node
*/

#include "my_enemy.h"
#include <stdlib.h>

void enemy_list_destroy_a_node(enemy_node_t *node)
{
    if (!node)
        return;
    enemy_destroy(node->enemy);
    free(node);
}

bool enemy_list_destroy_two(enemy_node_t *ptr, enemy_node_t *node, \
enemy_list_t *list)
{
    if (ptr == node) {
        list->first = ptr->next;
        enemy_list_destroy_a_node(ptr);
        return (true);
    }
    return (false);
}

void enemy_list_destroy_a_selected_node_in_list(enemy_list_t *list, \
enemy_node_t *node)
{
    enemy_node_t *ptr;
    enemy_node_t *node_to_free;

    if (!list || !node)
        return;
    ptr = list->first;
    if (!ptr || enemy_list_destroy_two(ptr, node, list) == true)
        return;
    while (ptr->next) {
        if (ptr->next == node) {
            node_to_free = ptr->next;
            ptr->next = node_to_free->next;
            enemy_list_destroy_a_node(node_to_free);
            node = NULL;
            node_to_free = NULL;
            break;
        }
        ptr = ptr->next;
    }
}
