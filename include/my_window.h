/*
** EPITECH PROJECT, 2021
** my_window
** File description:
** desc
*/

#ifndef MY_WINDOW_H_
#define MY_WINDOW_H_

//--INCLUDE--------------------------------------------

#include <SFML/Graphics.h>

//--DEFINE---------------------------------------------

//--STRUCTURES-----------------------------------------

typedef struct my_window_s{
    sfVector2i size;
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
} my_window_t;

//--PROTOTYPE------------------------------------------

void init_rpg_window(my_window_t *window, int width, int height);

#endif /* !MY_WINDOW_H_ */