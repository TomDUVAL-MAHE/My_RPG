/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_game.h"

void skill_scene_setup_is_active(skill_scene_t *skill_scene)
{
    skill_scene->is_active = malloc(sizeof(int) * 5);
    skill_scene->is_active[0] = 0;
    skill_scene->is_active[1] = 0;
    skill_scene->is_active[2] = 0;
    skill_scene->is_active[3] = 0;
}

void skill_scene_setup_text(skill_scene_t *skill_scene)
{
    skill_scene->text = text_create((sfVector2f)\
    {skill_scene->window_size.x * 0.935, skill_scene->window_size.y * 0.56}\
    , "X", sfFont_createFromFile("assets/fonts/arial.ttf"), true);
    text_change_fill_color(&(skill_scene->text), sfWhite);
    text_change_char_size(&(skill_scene->text), \
    skill_scene->window_size.y * 0.05);
}

void skill_scene_update_text(skill_scene_t *skill_scene)
{
    text_change_buffer(&(skill_scene->text), \
    text_convert_int_to_char(skill_scene->remaining_point));
}

skill_scene_t skill_scene_setup(sfRenderWindow *window)
{
    skill_scene_t skill_scene;

    skill_scene.window_size = sfRenderWindow_getSize(window);
    skill_scene_setup_is_active(&skill_scene);
    skill_scene_setup_picture(&skill_scene);
    skill_scene_setup_text(&skill_scene);
    skill_scene.remaining_point = 9;
    skill_scene_update_text(&skill_scene);
    return (skill_scene);
}