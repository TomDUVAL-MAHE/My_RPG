/*
** EPITECH PROJECT, 2021
** my_player
** File description:
** desc
*/

#ifndef MY_PLAYER_H_
#define MY_PLAYER_H_

//--INCLUDE--------------------------------------------

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "my_stats.h"
#include "arrow.h"
//--DEFINE---------------------------------------------

//--CREATION--
//Texture path
#define PLAYER_HAT_PATH "assets/characters/player/hats/hat2.png"
#define PLAYER_ARMOR_PATH "assets/characters/player/armors/armor0.png"
#define PLAYER_LEGS_PATH "assets/characters/player/legs/legs0.png"
#define PLAYER_WEAPON_PATH "assets/characters/player/weapons/weapon1.png"
#define PLAYER_MAN_BODY_PATH "assets/characters/player/man.png"
//player texture and sprite tab
#define PLAYER_TAB_BODY 0
#define PLAYER_TAB_HAT 1
#define PLAYER_TAB_ARMOR 2
#define PLAYER_TAB_LEGS 3
#define PLAYER_TAB_WEAPON 4
//hitbox
#define PLAYER_HITBOX_WIDTH 85
#define PLAYER_HITBOX_HEIGHT 100
//--ATTACK--
#define PLAYER_MELE_ATTACK_COOLDOWN 6000000
#define PLAYER_BOW_ATTACK_COOLDOWN 13000000
#define PLAYER_CROSSBOW_ATTACK_COOLDOWN 8000000
#define PLAYER_REINIT_ATTACK_RECT ((sfFloatRect){0, 0, 0, 0})
#define PLAYER_BASIC_ATTACK_Y_RECT ((sfFloatRect){player->hitbox.left, \
player->hitbox.top, PLAYER_HITBOX_WIDTH, 30})
#define PLAYER_BASIC_ATTACK_X_RECT ((sfFloatRect){player->hitbox.left, \
player->hitbox.top, 40, PLAYER_HITBOX_HEIGHT})
#define PLAYER_LONG_ATTACK_Y_RECT ((sfFloatRect){player->hitbox.left, \
player->hitbox.top, PLAYER_HITBOX_WIDTH, 90})
#define PLAYER_LONG_ATTACK_X_RECT ((sfFloatRect){player->hitbox.left, \
player->hitbox.top, 140, PLAYER_HITBOX_HEIGHT})
//--ANIMATION--
//animation value
#define PLAYER_ANIMATION_COOLDOWN 100000
#define PLAYER_ANIMATION_RECT_WIDTH 64
#define PLAYER_ANIMATION_RECT_HEIGHT 64
#define PLAYER_ANIMATION_RECT_X_OFFSET 64
#define PLAYER_ANIMATION_RECT_Y_OFFSET 64
#define PLAYER_ANIMATION_RECT_LONG_WIDTH 192
#define PLAYER_ANIMATION_RECT_LONG_HEIGHT 100
#define PLAYER_ANIMATION_RECT_LONG_X_OFFSET 100
#define PLAYER_ANIMATION_RECT_LONG_Y_OFFSET 192
//Walk Animation
#define PLAYER_WALK_MOVE_RECT 64
#define PLAYER_WALK_UP_RECT ((sfIntRect){0, 516, 64, 64})
#define PLAYER_WALK_DOWN_RECT ((sfIntRect){0, 646, 64, 64})
#define PLAYER_WALK_LEFT_RECT ((sfIntRect){0, 580, 64, 64})
#define PLAYER_WALK_RIGHT_RECT ((sfIntRect){0, 708, 64, 64})
#define PLAYER_WALK_MAX_RECT 520
//Attack Animation
#define PLAYER_ATTACK_BASIC_RECT ((sfIntRect){0, 775, 64, 64})
#define PLAYER_ATTACK_LONG_RECT ((sfIntRect){0, 1400, 192, 100})
#define PLAYER_ATTACK_BOW_RECT ((sfIntRect){0, 1032, 64, 64})
#define PLAYER_ATTACK_CROSSBOW_RECT ((sfIntRect){0, 264, 64, 64})
#define PLAYER_ATTACK_BASIC_MAX_LEFT 320
#define PLAYER_ATTACK_LONG_MAX_LEFT 960
#define PLAYER_ATTACK_BOW_MAX_LEFT 768
#define PLAYER_ATTACK_CROSSBOW_MAX_LEFT 448
//Die animation
#define PLAYER_DIE_RECT ((sfIntRect){0, 1287, 64, 64})
#define PLAYER_DIE_MAX_LEFT 576
//sprite pos
#define PLAYER_SPRITE_BASIC_POS_X player->hitbox.left + \
player->hitbox.width / 2 - 128 / 2
#define PLAYER_SPRITE_BASIC_POS_Y player->hitbox.top + \
player->hitbox.height / 2 - 128/ 2
#define PLAYER_SPRITE_LONG_POS_X player->hitbox.left + \
player->hitbox.width / 2 - PLAYER_ANIMATION_RECT_LONG_WIDTH
#define PLAYER_SPRITE_LONG_POS_Y player->hitbox.top + \
player->hitbox.height / 2 - PLAYER_ANIMATION_RECT_LONG_HEIGHT + 6

//--STRUCTURES-----------------------------------------

typedef struct my_game_s my_game_t;

typedef struct enemy_list_s enemy_list_t;

typedef struct pnj_list_s pnj_list_t;

typedef struct enemy_s enemy_t;

typedef enum {
    SWORD,
    LONG_SWORD,
    BOW,
    CROSSBOW,
    AXE,
    PICKAXE,
    INVOCATION
} weapon_type;

typedef struct player_s {
    bool move_up;
    bool move_down;
    bool move_left;
    bool move_right;
    bool is_walking;
    bool is_attacking;
    bool is_dying;
    bool dead;
    bool destroyed;
    int anim_cooldown;
    arrow_t *arrow;
    orientation orientation;
    sfIntRect anim_rect;
    sfFloatRect hitbox;
    sfFloatRect attack_hitbox;
    weapon_type weapon_type;
    sfTexture **textures;
    sfSprite **sprites;
    stats_t stats;
    int zone;
} player_t;

//--PROTOTYPE------------------------------------------

//player_init.c//
sfTexture **player_textures_init(void);
sfSprite **player_sprites_init(player_t *player);
void player_sprites_inits(player_t *player, sfSprite **sprites);
player_t *player_create(my_game_t *rpg);
void player_destroy(player_t *player);

//player_moves.c//
sfVector2i return_actual_tile(my_game_t *rpg, sfVector2f pos);
sfVector2i return_actual_tiles(my_game_t *rpg, sfVector2f pos, int i);
void player_move_x(my_game_t *rpg, player_t *player, sfVector2f move);
void player_move_y(my_game_t *rpg, player_t *player, sfVector2f move);
void move_all_pnj(my_game_t *rpg, sfVector2f move, \
pnj_list_t *pnj_list, bool force);
void move_all_enemy(my_game_t *rpg, sfVector2f move, \
enemy_list_t *enemy_list, bool force);
sfVector2f player_get_move(my_game_t *rpg, player_t* player);
bool is_player_moving(player_t *player);
void player_move(my_game_t *rpg, player_t *player);
sfVector2i return_actual_tile(my_game_t *rpg, sfVector2f pos);

//player_attack//
void player_crossbow_attack(player_t *player);
void player_bow_attack(player_t *player);
void player_long_sword_attack(player_t *player, my_game_t *rpg);
void player_basic_attack(player_t *player, my_game_t *rpg);
void player_attack(player_t *player, my_game_t *rpg);

//player_orientation.c//
void player_chose_orientation(player_t *player, sfVector2f move);
void player_orientate(player_t *player);

//player_display.c//
void player_reset_attack_animation(player_t *player);
void player_get_attack_anim_specifities(player_t *player, int *max_width);
void player_walk_animation(my_game_t *rpg, player_t *player);
void player_set_sprite_pose(player_t *player, float x, float y);
void player_display(my_game_t *rpg, player_t *player);

//player_interaction.c
void player_interaction(my_game_t *rpg);

//player_attack_detect_entities.c
void player_is_killing_enemy(enemy_t *enemy, player_t *player, my_game_t *rpg);
void player_hit_ennemy(player_t *player, enemy_list_t *e_list, my_game_t *rpg);
void player_cut_tree(my_game_t *rpg, sfFloatRect hitbox);
void player_cut_rock(my_game_t *rpg, sfFloatRect hitbox);


#endif /* !MY_PLAYER_H_ */
