/*
** EPITECH PROJECT, 2021
** main
** File description:
** desc
*/

#include "my_inventory_scene.h"

void inventory_scene_update_attack_bar(inventory_scene_t *inventory_scene, \
int attack)
{
    char *buffer = malloc(sizeof(char) * 1000);

    buffer[0] = '\0';
    my_strcat(buffer, "ATTACK : ");
    my_strcat(buffer, text_convert_int_to_char(attack));
    text_change_buffer(&(inventory_scene->text[2]), buffer);
}

void inventory_scene_update_health_bar(inventory_scene_t *inventory_scene, \
int actual_health, int max_health)
{
    sfVector2f size = sfRectangleShape_getSize(inventory_scene->health_bar[0]);
    float act = actual_health;
    float max = max_health;
    float change = act / max;
    char *buffer = malloc(sizeof(char) * 1000);

    sfRectangleShape_setSize(inventory_scene->health_bar[1], (sfVector2f)\
    {size.x * change, size.y});
    buffer[0] = '\0';
    my_strcat(buffer, "PV : ");
    my_strcat(buffer, text_convert_int_to_char(actual_health));
    my_strcat(buffer, " / ");
    my_strcat(buffer, text_convert_int_to_char(max_health));
    text_change_buffer(&(inventory_scene->text[0]), buffer);
}

void inventory_scene_update_level_bar(inventory_scene_t *inventory_scene, \
int actual_xp, int max_xp, int next_level)
{
    sfVector2f size = sfRectangleShape_getSize(inventory_scene->level_bar[0]);
    float act = actual_xp;
    float max = max_xp;
    float change = act / max;
    char *buffer = malloc(sizeof(char) * 1000);

    sfRectangleShape_setSize(inventory_scene->level_bar[1], (sfVector2f)\
    {size.x * change, size.y});
    buffer[0] = '\0';
    my_strcat(buffer, "LVL : ");
    my_strcat(buffer, text_convert_int_to_char(next_level));
    my_strcat(buffer, " -> ");
    my_strcat(buffer, text_convert_int_to_char(actual_xp));
    my_strcat(buffer, " / ");
    my_strcat(buffer, text_convert_int_to_char(max_xp));
    my_strcat(buffer, " XP");
    text_change_buffer(&(inventory_scene->text[1]), buffer);
}