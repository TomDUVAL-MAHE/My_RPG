/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_inventory_scene.h"
#include "my_skill_scene.h"

void skill_scene_setup_info_button(skill_scene_t *skill_scene)
{
    skill_scene->picture_list[10] = picture_setup(sfTexture_createFromFile\
    ("assets/skill/pickaxe0.png", NULL), (sfVector2f)\
    {skill_scene->window_size.x * 0.625, skill_scene->window_size.y * 0.39}, \
    (sfVector2f){skill_scene->window_size.x * 0.11, \
        skill_scene->window_size.y * 0.13});
    skill_scene->picture_list[11] = picture_setup(sfTexture_createFromFile\
    ("assets/skill/bow0.png", NULL), (sfVector2f)\
    {skill_scene->window_size.x * 0.625, skill_scene->window_size.y * 0.61}, \
    (sfVector2f){skill_scene->window_size.x * 0.11, \
        skill_scene->window_size.y * 0.13});
}

void skill_scene_setup_skills_button(skill_scene_t *skill_scene)
{
    skill_scene->picture_list[7] = picture_setup(sfTexture_createFromFile\
    ("assets/skill/man1.png", NULL), (sfVector2f)\
    {skill_scene->window_size.x * 0.06, skill_scene->window_size.y * 0.50}, \
    (sfVector2f){skill_scene->window_size.x * 0.11, \
        skill_scene->window_size.y * 0.13});
    skill_scene->picture_list[8] = picture_setup(sfTexture_createFromFile\
    ("assets/skill/axe0.png", NULL), (sfVector2f)\
    {skill_scene->window_size.x * 0.345, skill_scene->window_size.y * 0.39}, \
    (sfVector2f){skill_scene->window_size.x * 0.11, \
        skill_scene->window_size.y * 0.13});
    skill_scene->picture_list[9] = picture_setup(sfTexture_createFromFile\
    ("assets/skill/ring0.png", NULL), (sfVector2f)\
    {skill_scene->window_size.x * 0.345, skill_scene->window_size.y * 0.61}, \
    (sfVector2f){skill_scene->window_size.x * 0.11, \
        skill_scene->window_size.y * 0.13});
    skill_scene_setup_info_button(skill_scene);
}