/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** game_events
*/

#include "my_game.h"
#include "my_quest.h"

void quest_display_shortcut_loop(sfVector2f actual_pos, int *count, \
my_window_t window, quest_t *save)
{
    sfVector2f size = (sfVector2f){window.size.x * 0.3, window.size.y * 0.1};

    sfRectangleShape_setSize(save->background, size);
    sfRectangleShape_setPosition(save->background, actual_pos);
    sfRenderWindow_drawRectangleShape(window.window, \
    save->background, NULL);
    text_change_pos(&(save->title), (sfVector2f)\
    {actual_pos.x + (size.x * 0.5) - ((my_strlen(save->content.name) \
        / 2) * (int)(size.y * 0.15)), actual_pos.y + size.y * 0.2});
    text_change_char_size(&(save->title), (int)(size.y * 0.3));
    text_display(&(save->title), window.window);
    text_change_pos(&(save->description), (sfVector2f){actual_pos.x + \
        (size.x * 0.5) - ((my_strlen(save->content.description) / 2) * \
        (int)(size.y * 0.10)), actual_pos.y + size.y * 0.55});
    text_change_char_size(&(save->description), (int)(size.y * 0.2));
    text_display(&(save->description), window.window);
    *count += 1;
}

void quest_display_shortcut(quest_list_t quest_list, my_window_t window)
{
    quest_t *save = quest_list.first;
    sfVector2f actual_pos = (sfVector2f){window.size.x * 0.7, 0};
    sfVector2f size = (sfVector2f){window.size.x * 0.3, window.size.y * 0.1};
    int count = 0;

    while (save != NULL && count < 2) {
        if (save->content.state == IN_PROGRESS) {
            quest_display_shortcut_loop\
            (actual_pos, &count, window, save);
            actual_pos.y += size.y;
        }
        save = save->next;
    }
}

void quest_scene_setup_emplacement_two(quest_scene_t *quest_scene, \
int i, my_game_t *rpg, sfVector2f actual_pos)
{
    sfVector2f size = (sfVector2f){rpg->window.size.x * 0.2675, \
        rpg->window.size.y * 0.2};

    text_change_char_size(&(quest_scene->quest_view[i].title), \
    (int)(size.y * 0.2));
    quest_scene->quest_view[i].description = text_create((sfVector2f)\
    {actual_pos.x, actual_pos.y + size.y * 0.55}, "NONE", \
    sfFont_createFromFile("assets/fonts/arial.ttf"), true);
    text_change_char_size(&(quest_scene->quest_view[i].description), \
    (int)(size.y * 0.15));
}

void quest_scene_setup_emplacement(my_game_t *rpg, quest_scene_t *quest_scene)
{
    sfVector2f actual_pos = (sfVector2f){rpg->window.size.x * 0.05, \
        rpg->window.size.y * 0.3};
    sfVector2f size = (sfVector2f){rpg->window.size.x * 0.2675, \
        rpg->window.size.y * 0.2};

    for (int i = 0; i < 6; i++) {
        quest_scene->quest_view[i].pos = actual_pos;
        quest_scene->quest_view[i].background = sfRectangleShape_create();
        sfRectangleShape_setPosition(quest_scene->quest_view[i].background, \
        actual_pos);
        sfRectangleShape_setSize(quest_scene->quest_view[i].background, size);
        quest_scene->quest_view[i].title = text_create((sfVector2f)\
        {actual_pos.x, actual_pos.y + size.y * 0.2}, "NONE", \
        sfFont_createFromFile("assets/fonts/arial.ttf"), true);
        quest_scene_setup_emplacement_two(quest_scene, i, rpg, actual_pos);
        actual_pos.x += size.x + rpg->window.size.x * 0.05;
        if (i == 2)
            actual_pos = (sfVector2f)\
            {rpg->window.size.x * 0.05, rpg->window.size.y * 0.6};
    }
}

quest_scene_t quest_scene_setup(my_game_t *rpg)
{
    quest_scene_t quest_scene;

    quest_scene.all_quest_number = 6;
    quest_scene.quest_view = malloc(sizeof(quest_view_t) * 7);
    quest_scene.background = sfRectangleShape_create();
    sfRectangleShape_setPosition(quest_scene.background, \
    (sfVector2f){0, 0});
    sfRectangleShape_setSize(quest_scene.background, (sfVector2f)\
    {rpg->window.size.x, rpg->window.size.y});
    sfRectangleShape_setTexture(quest_scene.background, \
    sfTexture_createFromFile("assets/quest/back.png", NULL), true);
    quest_scene_setup_emplacement(rpg, &quest_scene);
    quest_scene.actual_slide = 0;
    quest_scene.title = sfRectangleShape_create();
    sfRectangleShape_setPosition(quest_scene.title, \
    (sfVector2f){rpg->window.size.x * 0.32, rpg->window.size.y * 0.05});
    sfRectangleShape_setSize(quest_scene.title, (sfVector2f)\
    {rpg->window.size.x * 0.4, rpg->window.size.y * 0.2});
    sfRectangleShape_setTexture(quest_scene.title, \
    sfTexture_createFromFile("assets/quest/title.png", NULL), true);
    return (quest_scene);
}