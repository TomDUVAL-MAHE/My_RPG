/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** game_events
*/

#include "my_game.h"
#include "my_quest.h"

void quest_scene_update_three(quest_t *save, quest_scene_t *quest_scene, \
int *count, sfVector2f size)
{
    if (save->content.state == IN_PROGRESS) {
        text_change_fill_color(&(quest_scene->quest_view[*count].\
        title), sfWhite);
        text_change_fill_color(&(quest_scene->quest_view[*count].\
        description), sfWhite);
    }
    text_change_pos(&(quest_scene->quest_view[*count].title), \
    (sfVector2f){quest_scene->quest_view[*count].pos.x + \
        (size.x * 0.5) - ((my_strlen(save->content.name) / 2) * \
        (int)(size.y * 0.10)), quest_scene->quest_view[*count].pos.y + \
        size.y * 0.2});
    text_change_pos(&(quest_scene->quest_view[*count].description), \
    (sfVector2f){quest_scene->quest_view[*count].pos.x + \
        (size.x * 0.5) - ((my_strlen(save->content.description) / 2) * \
        (int)(size.y * 0.075)), \
        quest_scene->quest_view[*count].pos.y + size.y * 0.55});
    quest_scene->quest_view[*count].is_full = true;
    *count += 1;
}

void quest_scene_update_two(quest_t *save, quest_scene_t *quest_scene, \
int *count, sfVector2f size)
{
    if (save->content.state != NOT_ACTIVE) {
        sfRectangleShape_setFillColor\
        (quest_scene->quest_view[*count].background, sfWhite);
        sfRectangleShape_setTexture\
        (quest_scene->quest_view[*count].background, \
        sfTexture_createFromFile("empty.png", NULL), true);
        text_change_buffer(&(quest_scene->quest_view[*count].title), \
        save->content.name);
        text_change_buffer(&(quest_scene->quest_view[*count].description), \
        save->content.description);
        if (save->content.state == ENDED) {
            text_change_fill_color(&(quest_scene->quest_view[*count].\
            title), sfGreen);
            text_change_fill_color(&(quest_scene->quest_view[*count].\
            description), sfGreen);
        }
        quest_scene_update_three(save, quest_scene, count, size);
    }
}