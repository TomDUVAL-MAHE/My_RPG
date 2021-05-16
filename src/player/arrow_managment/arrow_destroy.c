/*
** EPITECH PROJECT, 2021
** destroy_arrow
** File description:
** for my_rpg
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "arrow.h"
#include "my_player.h"

void destroy_arrow(player_t *player)
{
    if (!player->arrow)
        return;
    sfTexture_destroy(player->arrow->texture);
    sfSprite_destroy(player->arrow->sprite);
    player->arrow = NULL;
}
