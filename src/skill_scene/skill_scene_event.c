/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_game.h"

void skill_scene_detect_button(skill_scene_t *skill_scene, \
sfVector2i mouse_pos, inventory_scene_t *inventory_scene)
{
    if (button_is_touch(sfRectangleShape_getPosition\
        (skill_scene->picture_list[1]), sfRectangleShape_getSize\
        (skill_scene->picture_list[1]), mouse_pos) == true)
        inventory_scene_change_scene(inventory_scene, 0);
    if (button_is_touch(sfRectangleShape_getPosition\
        (skill_scene->picture_list[8]), sfRectangleShape_getSize\
        (skill_scene->picture_list[8]), mouse_pos) == true)
        skill_scene_get_axe(skill_scene, inventory_scene);
    if (button_is_touch(sfRectangleShape_getPosition\
        (skill_scene->picture_list[10]), sfRectangleShape_getSize\
        (skill_scene->picture_list[10]), mouse_pos) == true)
        skill_scene_get_pickaxe(skill_scene, inventory_scene);
    if (button_is_touch(sfRectangleShape_getPosition\
        (skill_scene->picture_list[9]), sfRectangleShape_getSize\
        (skill_scene->picture_list[9]), mouse_pos) == true)
        skill_scene_get_ring(skill_scene, inventory_scene);
    if (button_is_touch(sfRectangleShape_getPosition\
        (skill_scene->picture_list[11]), sfRectangleShape_getSize\
        (skill_scene->picture_list[11]), mouse_pos) == true)
        skill_scene_get_bow(skill_scene, inventory_scene);
}

void skill_scene_event_gestion(skill_scene_t *skill_scene, \
sfVector2i mouse_pos, inventory_scene_t *inventory_scene)
{
    skill_scene_detect_button(skill_scene, mouse_pos, inventory_scene);
}