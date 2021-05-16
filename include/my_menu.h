/*
** EPITECH PROJECT, 2021
** my_menu
** File description:
** desc
*/

#ifndef MY_MENU_H_
#define MY_MENU_H_

//--INCLUDE--------------------------------------------

#include "my_text.h"
#include "my_button.h"

//--DEFINE---------------------------------------------

//--STRUCTURES-----------------------------------------

typedef struct menus_s {
    bool displayed;
    int nb_btns;
    int nb_text;
    int nb_inventory;
    button_t **btns;
    text_t *text;
} menus_t;

//--PROTOTYPE------------------------------------------

//MENU_STRUCT.C//

menus_t *destroy_a_menu(menus_t *menu);
void draw_a_menu(sfRenderWindow *window, menus_t *menu);

#endif /* !MY_MENU_H_ */