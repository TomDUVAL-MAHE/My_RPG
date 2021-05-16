/*
** EPITECH PROJECT, 2021
** arrow creation
** File description:
** for my_rpg
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "arrow.h"
#include "my.h"

int choose_lvl_arrow(char *path)
{
    if (my_strcmp(path, "bow1") == 0)
        return (1);
    if (my_strcmp(path, "bow2") == 0)
        return (2);
    if (my_strcmp(path, "bow3") == 0)
        return (3);
    return (0);
}

void choose_direction(arrow_t *arrow, orientation direction)
{
    arrow->direction = direction;
    if (arrow->direction == 0)
        arrow->texture = sfTexture_createFromFile\
        ("assets/arrow/arrow_top.png", NULL);
    if (arrow->direction == 3)
        arrow->texture = sfTexture_createFromFile\
        ("assets/arrow/arrow_right.png", NULL);
    if (arrow->direction == 1)
        arrow->texture = sfTexture_createFromFile\
        ("assets/arrow/arrow_bottom.png", NULL);
    if (arrow->direction == 2)
        arrow->texture = sfTexture_createFromFile\
        ("assets/arrow/arrow_left.png", NULL);
}

void choose_power(arrow_t *arrow, int lvl)
{
    if (lvl == 1) {
        arrow->power.lvl = lvl;
        arrow->power.speed = 20;
        arrow->power.damage = 1;
    }
    if (lvl == 2) {
        arrow->power.lvl = lvl;
        arrow->power.speed = 20;
        arrow->power.damage = 2;
    }
    if (lvl == 3) {
        arrow->power.lvl = lvl;
        arrow->power.speed = 50;
        arrow->power.damage = 3;
    }
}

void choose_hitbox(arrow_t *arrow)
{
    if (arrow->direction == 0 || arrow->direction == 1)
        arrow->hitbox = (sfFloatRect) {arrow->pos.x, arrow->pos.y, 5, 34};
    if (arrow->direction == 2 || arrow->direction == 3)
        arrow->hitbox = (sfFloatRect) {arrow->pos.x, arrow->pos.y, 34, 5};
}

arrow_t *arrow_creation(orientation direction, int x, int y, int lvl)
{
    arrow_t *arrow = malloc(sizeof(*arrow));

    if (!arrow)
        return (NULL);
    choose_direction(arrow, direction);
    choose_power(arrow, lvl);
    arrow->sprite = sfSprite_create();
    sfSprite_setTexture(arrow->sprite, arrow->texture, sfTrue);
    arrow->count = 100;
    arrow->pos.x = x;
    arrow->pos.y = y;
    choose_hitbox(arrow);
    sfSprite_setPosition(arrow->sprite, arrow->pos);
    return (arrow);
}
