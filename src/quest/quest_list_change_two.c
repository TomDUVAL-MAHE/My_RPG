/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** game_events
*/

#include "my_game.h"
#include "my_quest.h"

void quest_list_add_quest_end(my_game_t *rpg, quest_content_t content)
{
    quest_t *save = rpg->quest_list.end;
    quest_t *new = create_a_quest(content);

    save->next = new;
    new->prev = save;
    new->next = NULL;
    rpg->quest_list.end = new;
}

void quest_delete(quest_t *prev, my_game_t *rpg)
{
    quest_t *save = prev->next;

    prev->next = save->next;
    if (save->next)
        save->next->prev = prev;
    if (prev->next == NULL)
        rpg->quest_list.end = prev;
    free(save);
}