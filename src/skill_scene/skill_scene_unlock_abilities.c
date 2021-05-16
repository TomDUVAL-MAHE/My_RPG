/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_game.h"
#include "my_inventory_scene.h"

void skill_scene_get_axe(skill_scene_t *skill_scene, \
inventory_scene_t *inventory_scene)
{
    if (skill_scene->remaining_point < 1 || \
        skill_scene->is_active[0] == 1)
        return;
    skill_scene->remaining_point -= 1;
    inventory_scene_unlock_axe(inventory_scene);
    sfRectangleShape_setTexture(skill_scene->picture_list[8], \
    sfTexture_createFromFile("assets/skill/axe1.png", NULL), true);
    sfRectangleShape_setTexture(skill_scene->picture_list[5], \
    sfTexture_createFromFile("assets/skill/pipe1.png", NULL), true);
    skill_scene->is_active[0] = 1;
    skill_scene_update_text(skill_scene);
}

void skill_scene_get_pickaxe(skill_scene_t *skill_scene, \
inventory_scene_t *inventory_scene)
{
    if (skill_scene->remaining_point < 2 || \
        skill_scene->is_active[0] == 0 || skill_scene->is_active[1] == 1)
        return;
    skill_scene->remaining_point -= 2;
    inventory_scene_unlock_pickaxe(inventory_scene);
    sfRectangleShape_setTexture(skill_scene->picture_list[10], \
    sfTexture_createFromFile("assets/skill/pickaxe1.png", NULL), true);
    skill_scene->is_active[1] = 1;
    skill_scene_update_text(skill_scene);
}

void skill_scene_get_ring(skill_scene_t *skill_scene, \
inventory_scene_t *inventory_scene)
{
    if (skill_scene->remaining_point < 1 || skill_scene->is_active[2] == 1)
        return;
    skill_scene->remaining_point -= 1;
    inventory_scene_unlock_ring(inventory_scene);
    sfRectangleShape_setTexture(skill_scene->picture_list[9], \
    sfTexture_createFromFile("assets/skill/ring1.png", NULL), true);
    sfRectangleShape_setTexture(skill_scene->picture_list[6], \
    sfTexture_createFromFile("assets/skill/pipe1.png", NULL), true);
    skill_scene->is_active[2] = 1;
    skill_scene_update_text(skill_scene);
}

void skill_scene_get_bow(skill_scene_t *skill_scene, \
inventory_scene_t *inventory_scene)
{
    if (skill_scene->remaining_point < 2 || \
        skill_scene->is_active[2] == 0 || skill_scene->is_active[3] == 1)
        return;
    skill_scene->remaining_point -= 2;
    inventory_scene_unlock_bow(inventory_scene);
    sfRectangleShape_setTexture(skill_scene->picture_list[11], \
    sfTexture_createFromFile("assets/skill/bow1.png", NULL), true);
    skill_scene->is_active[3] = 1;
    skill_scene_update_text(skill_scene);
}