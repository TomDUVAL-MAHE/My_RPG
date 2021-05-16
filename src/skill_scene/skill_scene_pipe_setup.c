/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_game.h"

void skill_scene_setup_pipe(skill_scene_t *skill_scene)
{
    skill_scene->picture_list[3] = picture_setup(sfTexture_createFromFile\
    ("assets/skill/pipe2.png", NULL), (sfVector2f)\
    {skill_scene->window_size.x * 0.135, skill_scene->window_size.y * 0.47}, \
    (sfVector2f){skill_scene->window_size.x * 0.25, \
        skill_scene->window_size.y * 0.10});
    skill_scene->picture_list[4] = picture_setup(sfTexture_createFromFile\
    ("assets/skill/pipe3.png", NULL), (sfVector2f)\
    {skill_scene->window_size.x * 0.135, skill_scene->window_size.y * 0.56}, \
    (sfVector2f){skill_scene->window_size.x * 0.25, \
        skill_scene->window_size.y * 0.10});
    skill_scene->picture_list[5] = picture_setup(sfTexture_createFromFile\
    ("assets/skill/pipe0.png", NULL), (sfVector2f)\
    {skill_scene->window_size.x * 0.40, skill_scene->window_size.y * 0.46}, \
    (sfVector2f){skill_scene->window_size.x * 0.25, \
        skill_scene->window_size.y * 0.05});
    skill_scene->picture_list[6] = picture_setup(sfTexture_createFromFile\
    ("assets/skill/pipe0.png", NULL), (sfVector2f)\
    {skill_scene->window_size.x * 0.40, skill_scene->window_size.y * 0.62}, \
    (sfVector2f){skill_scene->window_size.x * 0.25, \
        skill_scene->window_size.y * 0.05});
}

void skill_scene_setup_picture(skill_scene_t *skill_scene)
{
    skill_scene->picture_list = malloc(sizeof(sfRectangleShape *) * 20);
    skill_scene->picture_list[0] = picture_setup(sfTexture_createFromFile\
    ("assets/inventory/back.png", NULL), (sfVector2f){0, 0}, \
    (sfVector2f){skill_scene->window_size.x, skill_scene->window_size.y});
    skill_scene->picture_list[1] = picture_setup(sfTexture_createFromFile\
    ("assets/skill/inventory.png", NULL), (sfVector2f)\
    {skill_scene->window_size.x * 0.06, skill_scene->window_size.y * 0.04}, \
    (sfVector2f){skill_scene->window_size.x * 0.417, \
        skill_scene->window_size.y * 0.13});
    skill_scene->picture_list[2] = picture_setup(sfTexture_createFromFile\
    ("assets/skill/skills.png", NULL), (sfVector2f)\
    {skill_scene->window_size.x * 0.52, skill_scene->window_size.y * 0.04}, \
    (sfVector2f){skill_scene->window_size.x * 0.417, \
        skill_scene->window_size.y * 0.13});
    skill_scene_setup_skills_button(skill_scene);
    skill_scene_setup_skills_text(skill_scene);
    skill_scene_setup_pipe(skill_scene);
}