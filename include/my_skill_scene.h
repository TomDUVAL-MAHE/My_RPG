/*
** EPITECH PROJECT, 2021
** my_skill_scene
** File description:
** desc
*/

#ifndef MY_SKILL_SCENE_H_
#define MY_SKILL_SCENE_H_

//--INCLUDE--------------------------------------------

#include <SFML/Graphics.h>
#include "my_text.h"

//--DEFINE---------------------------------------------

//--STRUCTURES-----------------------------------------

typedef struct skill_scene {
    sfRectangleShape **picture_list;
    int remaining_point;
    text_t text;
    sfVector2u window_size;
    int *is_active;
} skill_scene_t;

//--PROTOTYPE------------------------------------------

//SKILL_SCENE_BUTTON_SETUP.C//

void skill_scene_setup_info_button(skill_scene_t *skill_scene);
void skill_scene_setup_skills_button(skill_scene_t *skill_scene);

//SKILL_SCENE_DISPLAY.C//

void skill_scene_picture_display(skill_scene_t *skill_scene, \
sfRenderWindow *window);
void skill_scene_display_text(skill_scene_t *skill_scene, \
sfRenderWindow *window);
void skill_scene_display(skill_scene_t *skill_scene, sfRenderWindow *window);

//SKILL_SCENE_EVENT.C//

void skill_scene_detect_button(skill_scene_t *skill_scene, \
sfVector2i mouse_pos, inventory_scene_t *inventory_scene);
void skill_scene_event_gestion(skill_scene_t *skill_scene, \
sfVector2i mouse_pos, inventory_scene_t *inventory_scene);

//SKILL_SCENE_PIPE_SETUP.C//
void skill_scene_setup_pipe(skill_scene_t *skill_scene);
void skill_scene_setup_picture(skill_scene_t *skill_scene);

//SKILL_SCENE_SETUP.C//
void skill_scene_setup_is_active(skill_scene_t *skill_scene);
void skill_scene_setup_text(skill_scene_t *skill_scene);
void skill_scene_update_text(skill_scene_t *skill_scene);
skill_scene_t skill_scene_setup(sfRenderWindow *window);

//SKILL_SCENE_TEXT_SETUP.C//
void skill_scene_setup_info_text(skill_scene_t *skill_scene);
void skill_scene_setup_skills_text(skill_scene_t *skill_scene);

//SKILL_SCENE_UNLOCK_ABILITIES.C//

void skill_scene_get_axe(skill_scene_t *skill_scene, \
inventory_scene_t *inventory_scene);
void skill_scene_get_pickaxe(skill_scene_t *skill_scene, \
inventory_scene_t *inventory_scene);
void skill_scene_get_ring(skill_scene_t *skill_scene, \
inventory_scene_t *inventory_scene);
void skill_scene_get_bow(skill_scene_t *skill_scene, \
inventory_scene_t *inventory_scene);

#endif /* !MY_SKILL_SCENE_H_ */