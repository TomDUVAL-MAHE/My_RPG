/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** game_events
*/

#include "my_game.h"
#include "my_quest.h"

void quest_list_delete(my_game_t *rpg, int id)
{
    quest_t *save = rpg->quest_list.first;

    while (save->next && save->next->content.id != id) {
        save = save->next;
    }
    if (!save->next)
        return;
    quest_delete(save, rpg);
}

void quest_list_swap(my_game_t *rpg, quest_t *limit, quest_t *prev)
{
    quest_t *new = create_a_quest(prev->next->content);

    quest_delete(prev, rpg);
    if (limit->next == NULL) {
        quest_list_add_quest_end(rpg, new->content);
        return;
    }
    limit->next->prev = new;
    new->next = limit->next;
    limit->next = new;
    new->prev = limit;
}

void quest_list_sort_type_to_end(my_game_t *rpg)
{
    quest_t *save = rpg->quest_list.end;
    quest_t *limit = save;

    while (save && save->content.state == ENDED) {
        limit = save;
        save = save->prev;
    }
    if (!save)
        return;
    save = rpg->quest_list.first;
    while (save->next) {
        if (save->next->content.id == limit->content.id)
            break;
        if (save->next->content.state == ENDED) {
            quest_list_swap(rpg, limit, save);
        } else
            save = save->next;
    }
}

void quest_list_change_state(my_game_t *rpg, int id, int state)
{
    quest_t *save = rpg->quest_list.first;

    while (save->next && save->next->content.id != id) {
        save = save->next;
    }
    if (!save->next)
        return;
    save->next->content.state = state;
}

int quest_list_return_state_by_id(my_game_t *rpg, int id)
{
    quest_t *save = rpg->quest_list.first;

    while (save->next && save->next->content.id != id) {
        save = save->next;
    }
    if (!save->next)
        return (-1);
    return (save->next->content.state);
}