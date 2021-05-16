/*
** EPITECH PROJECT, 2021
** my_item
** File description:
** desc
*/

#ifndef MY_ITEM_H_
#define MY_ITEM_H_

#include <SFML/Graphics.h>

typedef struct items {
    char *name;
    char *description;
    sfTexture *texture;
    int item_nbr;
    int type;
    int attack_modificator;
    int health_modificator;
} item_t;

//INVENTORY_ITEMS_ACTION_TWO.C//

char *item_return_name(item_t *items, sfTexture *texture);

//INVENTORY_ITEMS.C//

int item_get_nbr(char *buffer);
void transform_item_buffer(char *buffer);
void items_get_list_two(item_t *items, char *buffer, int item_number);
bool item_file_valid_configuration(char *buffer);
item_t *items_get_list(void);

//INVENTORY_ITEMS_ACTION.C//

sfTexture *item_return_texture(item_t *items, char *item_name);
char *item_return_info(item_t *items, char *item_name);
int item_return_health(item_t *items, char *item_name);
int item_return_attack(item_t *items, char *item_name);
int item_return_type(item_t *items, char *item_name);

#endif /* !MY_ITEM_H_ */
