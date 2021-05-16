/*
** EPITECH PROJECT, 2021
** arrow.h
** File description:
** for my_rpg
*/

#ifndef _ARROW_H_
#define _ARROW_H_

typedef struct player_s player_t;

typedef struct my_game_s my_game_t;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} orientation;

typedef struct pos_s{
    int x;
    int y;
}pos_t;

typedef struct power_s{
    int lvl;
    int speed;
    int damage;
}power_t;

typedef struct hit_s{
    int type;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    sfIntRect rect;
    sfVector2f pos;
}hit_t;

typedef struct arrow_s{
    sfSprite *sprite;
    sfTexture *texture;
    sfFloatRect hitbox;
    sfVector2f pos;
    power_t power;
    orientation direction;
    int count;
    sfClock *clock;
}arrow_t;

//_______arrow_creation.c_______//
arrow_t *arrow_creation(orientation direction, int x, int y, int lvl);
int choose_lvl_arrow(char *path);
//void choose_power(arrow_t *arrow, int lvl);
//void choose_direction(arrow_t *arrow, direction_t direction);


//_______arrow_destroy.c_______//
void destroy_arrow(player_t *player);


//_______arrow_managment.c_______//
void arrow_display(my_game_t *rpg, player_t *player);
//void manage_arrow(player_t *player);
//void manage_arrow(arrow_t *arrow);


//_______arrow_hit.c_______//
void hit(void);
//void create_hit(void);
//void choose_hit(void);
//void manage_hit(void);
//void destroy_hit(void);


#endif
