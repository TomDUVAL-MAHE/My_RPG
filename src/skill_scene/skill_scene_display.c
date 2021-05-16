/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_game.h"

void skill_scene_picture_display(skill_scene_t *skill_scene, \
sfRenderWindow *window)
{
    for (int i = 0; i < 17; i++) {
        sfRenderWindow_drawRectangleShape(window, \
        skill_scene->picture_list[i], NULL);
    }
}

void skill_scene_display_text(skill_scene_t *skill_scene, \
sfRenderWindow *window)
{
    text_display(&(skill_scene->text), window);
}

void skill_scene_display(skill_scene_t *skill_scene, sfRenderWindow *window)
{
    skill_scene_picture_display(skill_scene, window);
    skill_scene_display_text(skill_scene, window);
}