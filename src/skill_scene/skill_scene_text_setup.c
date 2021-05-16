/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_game.h"

void skill_scene_setup_info_text(skill_scene_t *skill_scene)
{
    skill_scene->picture_list[15] = picture_setup(sfTexture_createFromFile\
    ("assets/skill/bow_text.png", NULL), (sfVector2f)\
    {skill_scene->window_size.x * 0.625, skill_scene->window_size.y * 0.76}, \
    (sfVector2f){skill_scene->window_size.x * 0.11, \
        skill_scene->window_size.y * 0.13});
    skill_scene->picture_list[16] = picture_setup(sfTexture_createFromFile\
    ("assets/skill/point.png", NULL), (sfVector2f)\
    {skill_scene->window_size.x * 0.755, skill_scene->window_size.y * 0.45}, \
    (sfVector2f){skill_scene->window_size.x * 0.21, \
        skill_scene->window_size.y * 0.23});
}

void skill_scene_setup_skills_text(skill_scene_t *skill_scene)
{
    skill_scene->picture_list[12] = picture_setup(sfTexture_createFromFile\
    ("assets/skill/axe_text.png", NULL), (sfVector2f)\
    {skill_scene->window_size.x * 0.345, skill_scene->window_size.y * 0.24}, \
    (sfVector2f){skill_scene->window_size.x * 0.11, \
        skill_scene->window_size.y * 0.13});
    skill_scene->picture_list[13] = picture_setup(sfTexture_createFromFile\
    ("assets/skill/ring_text.png", NULL), (sfVector2f)\
    {skill_scene->window_size.x * 0.345, skill_scene->window_size.y * 0.76}, \
    (sfVector2f){skill_scene->window_size.x * 0.11, \
        skill_scene->window_size.y * 0.13});
    skill_scene->picture_list[14] = picture_setup(sfTexture_createFromFile\
    ("assets/skill/pickaxe_text.png", NULL), (sfVector2f)\
    {skill_scene->window_size.x * 0.625, skill_scene->window_size.y * 0.24}, \
    (sfVector2f){skill_scene->window_size.x * 0.11, \
        skill_scene->window_size.y * 0.13});
    skill_scene_setup_info_text(skill_scene);
}
