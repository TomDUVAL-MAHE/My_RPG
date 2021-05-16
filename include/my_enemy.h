/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** my_enemy
*/

#ifndef __MY_ENEMY
#define __MY_ENEMY
//-----NEEDED-INCLUDES-------
#include "my_player.h"
#include "my_game_scene.h"
#include "arrow.h"
//-----MACROS----------------
//--CREATION--
//hitbox
#define ENEMY_HITBOX_WIDTH 85
#define ENEMY_HITBOX_HEIGHT 100
//--ATTACK--
#define ENEMY_MELE_ATTACK_COOLDOWN 6000000
#define ENEMY_BOW_ATTACK_COOLDOWN 13000000
#define ENEMY_CROSSBOW_ATTACK_COOLDOWN 8000000
#define ENEMY_REINIT_ATTACK_RECT ((sfFloatRect){0, 0, 0, 0})
#define ENEMY_BASIC_ATTACK_Y_RECT ((sfFloatRect){enemy->hitbox.left, \
enemy->hitbox.top, ENEMY_HITBOX_WIDTH, 30})
#define ENEMY_BASIC_ATTACK_X_RECT ((sfFloatRect){enemy->hitbox.left, \
enemy->hitbox.top, 40, ENEMY_HITBOX_HEIGHT})
#define ENEMY_LONG_ATTACK_Y_RECT ((sfFloatRect){enemy->hitbox.left, \
enemy->hitbox.top, ENEMY_HITBOX_WIDTH, 90})
#define ENEMY_LONG_ATTACK_X_RECT ((sfFloatRect){enemy->hitbox.left, \
enemy->hitbox.top, 140, ENEMY_HITBOX_HEIGHT})
//--ANIMATION--
//animation value
#define ENEMY_ANIMATION_COOLDOWN 100000
#define ENEMY_ANIMATION_RECT_WIDTH 64
#define ENEMY_ANIMATION_RECT_HEIGHT 64
#define ENEMY_ANIMATION_RECT_X_OFFSET 64
#define ENEMY_ANIMATION_RECT_Y_OFFSET 64
#define ENEMY_ANIMATION_RECT_LONG_WIDTH 192
#define ENEMY_ANIMATION_RECT_LONG_HEIGHT 100
#define ENEMY_ANIMATION_RECT_LONG_X_OFFSET 100
#define ENEMY_ANIMATION_RECT_LONG_Y_OFFSET 192
//Walk Animation
#define ENEMY_WALK_MOVE_RECT 64
#define ENEMY_WALK_UP_RECT ((sfIntRect){0, 516, 64, 64})
#define ENEMY_WALK_DOWN_RECT ((sfIntRect){0, 646, 64, 64})
#define ENEMY_WALK_LEFT_RECT ((sfIntRect){0, 580, 64, 64})
#define ENEMY_WALK_RIGHT_RECT ((sfIntRect){0, 708, 64, 64})
#define ENEMY_WALK_MAX_RECT 520
//Attack Animation
#define ENEMY_ATTACK_BASIC_RECT ((sfIntRect){0, 775, 64, 64})
#define ENEMY_ATTACK_LONG_RECT ((sfIntRect){0, 1400, 192, 100})
#define ENEMY_ATTACK_BOW_RECT ((sfIntRect){0, 1032, 64, 64})
#define ENEMY_ATTACK_CROSSBOW_RECT ((sfIntRect){0, 264, 64, 64})
#define ENEMY_ATTACK_INVOC_RECT ((sfIntRect){0, 7, 64, 64})
#define ENEMY_ATTACK_BASIC_MAX_LEFT 320
#define ENEMY_ATTACK_LONG_MAX_LEFT 960
#define ENEMY_ATTACK_BOW_MAX_LEFT 768
#define ENEMY_ATTACK_CROSSBOW_MAX_LEFT 448
//Die animation
#define ENEMY_DIE_RECT ((sfIntRect){0, 1287, 64, 64})
#define ENEMY_DIE_MAX_LEFT 576
//sprite pos
#define ENEMY_SPRITE_BASIC_POS_X enemy->hitbox.left + \
enemy->hitbox.width / 2 - 128 / 2
#define ENEMY_SPRITE_BASIC_POS_Y enemy->hitbox.top + \
enemy->hitbox.height / 2 - 128/ 2
#define ENEMY_SPRITE_LONG_POS_X enemy->hitbox.left + \
enemy->hitbox.width / 2 - ENEMY_ANIMATION_RECT_LONG_WIDTH
#define ENEMY_SPRITE_LONG_POS_Y enemy->hitbox.top + \
enemy->hitbox.height / 2 - ENEMY_ANIMATION_RECT_LONG_HEIGHT + 6
#define ENEMY_PTR_SPRITE_BASIC_POS_X ptr->enemy->hitbox.left + \
ptr->enemy->hitbox.width / 2 - 128 / 2
#define ENEMY_PTR_SPRITE_BASIC_POS_Y ptr->enemy->hitbox.top + \
ptr->enemy->hitbox.height / 2 - 128/ 2
#define ENEMY_PTR_SPRITE_LONG_POS_X ptr->enemy->hitbox.left + \
ptr->enemy->hitbox.width / 2 - 192
#define ENEMY_PTR_SPRITE_LONG_POS_Y ptr->enemy->hitbox.top + \
ptr->enemy->hitbox.height / 2 - 100 + 6

//-----STRUCTURES------------
typedef struct my_game_s my_game_t;

typedef enum enemy_type {
    BOSS,
    ORC_LONGSWORD,
    ORC_SCYTHE,
    ORC_SPEAR,
    WOLF
} enemy_type;

typedef struct enemy_s
{
    bool move_up;
    bool move_down;
    bool move_left;
    bool move_right;
    bool is_walking;
    bool is_attacking;
    bool is_dying;
    bool destroyed;
    int anim_cooldown;
    sfVector2i tile;
    enemy_type type;
    orientation orientation;
    sfIntRect anim_rect;
    sfFloatRect hitbox;
    sfFloatRect attack_hitbox;
    weapon_type weapon_type;
    sfTexture *texture;
    sfSprite *sprite;
    stats_t stats;
} enemy_t;

typedef struct enemy_node_s
{
    enemy_t *enemy;
    struct enemy_node_s *next;
}enemy_node_t;

typedef struct enemy_list_s
{
    enemy_node_t *first;
}enemy_list_t;

//-----PROTOTYPES------------
//enemy_init.c
enemy_t *enemy_create(enemy_type e_type, int lvl, sfVector2i pos);
void enemy_destroy(enemy_t *enemy);
int create_new_enemy(enemy_list_t *enemy_list, enemy_type e_type, \
int lvl, sfVector2i pos);

//enemy_init_enemy_type.c
char *get_path_and_weapon_type_from_enemy_type(enemy_type e_type);

//enemy_init_weapon_type.c
void setup_enemy_caracteristique_from_type(enemy_t *enemy, \
enemy_type type, int lvl);

//enemy_list.c
enemy_list_t *enemy_list_init(void);
void enemy_list_destroy(enemy_list_t *list);
int enemy_list_insert_beginning(enemy_list_t *list, enemy_t *enemy);

//enemy_node.c
void enemy_list_destroy_a_node(enemy_node_t *node);
void enemy_list_destroy_a_selected_node_in_list(enemy_list_t *list, \
enemy_node_t *node);

//enemy_display.c
void enemy_attack_animation(my_game_t *rpg, enemy_t *enemy);
void enemies_display(my_game_t *rpg, enemy_list_t *enemy_list, int i, int j);

//enemy_orientation.c//
void define_enemy_orientation(sfVector2f move, enemy_t *enemy);
void enemy_chose_orientation(enemy_t *enemy, sfVector2f move);
void enemy_orientate(enemy_t *enemy);

//enemy_move.h
bool enemy_move_two(enemy_t *enemy, my_game_t *rpg, sfVector2f move, \
bool force);
void enemy_move(enemy_t *enemy, sfVector2f move, my_game_t *rpg, bool force);

//enemy_attack.c
void enemy_is_killing_player(player_t *player);
void enemy_basic_attack(enemy_t *enemy, player_t *player);
void enemy_long_sword_attack(enemy_t *enemy, player_t *player);
void enemy_bow_attack(enemy_t *enemy);
void enemy_crossbow_attack(enemy_t *enemy);
void enemy_attack(enemy_t *enemy, player_t *player);

//enemy_ia.c
void enemy_ia_management(my_game_t *rpg, enemy_list_t *e_list);

//enemy_give_item.c
void enemy_give_item(my_game_t *rpg, int level);

#endif // __MY_ENEMY 