/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** game_events
*/

#include "my_game.h"
#include "my_quest.h"

void quest_scene_update_empty(int count, quest_scene_t *quest_scene)
{
    while (count < 6) {
        sfRectangleShape_setTexture(quest_scene->quest_view[count].background, \
        sfTexture_createFromFile("empty.png", NULL), true);
        sfRectangleShape_setFillColor(quest_scene->quest_view[count].\
        background, (sfColor){114, 114, 114, 150});
        quest_scene->quest_view[count].is_full = false;
        count++;
    }
}

void quest_scene_update_four(int *count, quest_t *save)
{
    *count += 1;
    if (save->content.state == NOT_ACTIVE)
        *count -= 1;
}

void quest_scene_update(quest_scene_t *quest_scene, \
quest_list_t quest_list, my_game_t *rpg)
{
    quest_t *save = quest_list.first;
    sfVector2f size = (sfVector2f){rpg->window.size.x * 0.2675, \
        rpg->window.size.y * 0.2};
    int count = 0;

    quest_list_sort_type_to_end(rpg);
    while (save && count < quest_scene->actual_slide) {
        quest_scene_update_four(&count, save);
        save = save->next;
    }
    if (!save) {
        quest_scene->actual_slide -= quest_scene->actual_slide - count;
        quest_scene->actual_slide -= quest_scene->actual_slide % 3;
        return;
    }
    count = 0;
    while (save && count < 6) {
        quest_scene_update_two(save, quest_scene, &count, size);
        save = save->next;
    }
    quest_scene_update_empty(count, quest_scene);
}

void quest_scene_display(quest_scene_t *quest_scene, my_window_t window)
{
    sfRenderWindow_drawRectangleShape(window.window, \
    quest_scene->background, NULL);
    sfRenderWindow_drawRectangleShape(window.window, quest_scene->title, NULL);
    for (int i = 0; i < 6; i++) {
        sfRenderWindow_drawRectangleShape(window.window, \
        quest_scene->quest_view[i].background, NULL);
        if (quest_scene->quest_view[i].is_full == true) {
            text_display(&(quest_scene->quest_view[i].title), window.window);
            text_display(&(quest_scene->quest_view[i].description), \
            window.window);
        }
    }
}

void quest_all_setup(my_game_t *rpg)
{
    quest_list_setup(rpg);
    rpg->quest_scene = quest_scene_setup(rpg);
}