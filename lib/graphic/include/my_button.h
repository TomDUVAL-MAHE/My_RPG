/*
** EPITECH PROJECT, 2021
** my_button
** File description:
** desc
*/

#ifndef MY_BUTTON_H_
#define MY_BUTTON_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct my_game_s my_game_t;

typedef enum {
    INACTIVE,
    ACTIVE,
    HOVER,
    CLICK
} button_status;

typedef struct button_s {
    int text_size;
    char *str;
    int status;
    sfIntRect size;
    sfColor *color;
    sfTexture **texture;
    sfRectangleShape *shape;
    sfColor text_color;
    sfText *text;
    sfFont *font;
    void (*action)(my_game_t *my_game);
} button_t;

button_t *button_init(void);
void button_display(sfRenderWindow *window, button_t *button);
void button_set_string(button_t *button, char *str);
void button_set_font(button_t *button, char *font);
void button_set_position(button_t *button, sfVector2f pos);
void button_set_size(button_t *button, sfVector2f size);
void button_set_color(button_t *button, sfColor color, button_status status);
void button_set_text_color(button_t *button, sfColor color);
void button_set_text_size(button_t *button, int size);
bool button_is_hover(button_t *button, sfVector2i pos);
bool button_is_click(button_t *button, sfVector2i pos);
void button_destroy(button_t *button);
void button_set_texture(button_t *button, char *filename, button_status status);
button_t new_button(sfIntRect size, char *str, int tsize);
void button_set_action(button_t *button, void (*action)(my_game_t *rpg));
void button_launch_action(button_t *button, my_game_t *rpg);
void button_set_status(button_t *button, button_status status);

#endif /* !MY_BUTTON_H_ */