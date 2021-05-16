/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** game_events
*/

#include "my_game.h"
#include "my_quest.h"

quest_t *create_a_quest(quest_content_t content)
{
    quest_t *quest = malloc(sizeof(quest_t) * 1);
    quest->content.name = my_strdup(content.name);
    quest->content.id = content.id;
    quest->content.description = my_strdup(content.description);
    quest->content.state = content.state;
    quest->background = sfRectangleShape_create();
    sfRectangleShape_setTexture(quest->background, \
    sfTexture_createFromFile("empty.png", NULL), true);
    quest->title = text_create((sfVector2f){0, 0}, content.name, \
    sfFont_createFromFile("assets/fonts/arial.ttf"), true);
    quest->description = text_create((sfVector2f){0, 0}, \
    content.description, sfFont_createFromFile("assets/fonts/arial.ttf"), true);
    return (quest);
}

void quest_list_setup(my_game_t *rpg)
{
    rpg->quest_list.first = create_a_quest((quest_content_t)\
    {"EMPTY", TEST_QUEST, "EMPTY", NOT_ACTIVE});
    rpg->quest_list.first->next = NULL;
    rpg->quest_list.first->prev = NULL;
    rpg->quest_list.end = rpg->quest_list.first;
}