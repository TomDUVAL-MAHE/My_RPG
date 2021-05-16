/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include "my_inventory.h"
#include <unistd.h>

int item_get_nbr(char *buffer)
{
    int nbr = 0;

    if (buffer == NULL) {
        return (-1);
    }
    for (int i = 0; i < my_strlen(buffer); i++) {
        if (buffer[i] == '\n')
            nbr += 1;
    }
    return (nbr);
}

void transform_item_buffer(char *buffer)
{
    int size = my_strlen(buffer);

    for (int i = 0; i < size; i++) {
        if (buffer[i] == ';' || buffer[i] == '\n')
            buffer[i] = '\0';
    }
}

void items_get_list_two(item_t *items, char *buffer, int item_number)
{
    for (int i = 0; i < item_number; i++) {
        items[0].item_nbr = item_number - 1;
        items[i].name = my_strdup(buffer);
        buffer += my_strlen(buffer) + 1;
        items[i].description = my_strdup(buffer);
        buffer += my_strlen(buffer) + 1;
        items[i].texture = sfTexture_createFromFile(buffer, NULL);
        buffer += my_strlen(buffer) + 1;
        items[i].health_modificator = my_getnbr(buffer);
        buffer += my_strlen(buffer) + 1;
        items[i].attack_modificator = my_getnbr(buffer);
        buffer += my_strlen(buffer) + 1;
        items[i].type = my_getnbr(buffer);
        buffer += my_strlen(buffer) + 1;
    }
}

bool item_file_valid_configuration(char *buffer)
{
    int count = 0;

    for (int i = 0; i < my_strlen(buffer) - 1; i++) {
        if (buffer[i] == '\n' && count == 5) {
            count = 0;
        } else if (buffer[i] == '\n')
            return (false);
        if (buffer[i] == ';')
            count++;
    }
    return (true);
}

item_t *items_get_list(void)
{
    char *buffer = get_file_buffer("saves/inventory/items_list.txt");
    int item_number = item_get_nbr(buffer);
    item_t *items = malloc(sizeof(item_t) * item_number);

    if (item_number == -1 || !item_file_valid_configuration(buffer)) {
        write(2, "Configuration File Not Valid\n", 30);
        return (NULL);
    }
    transform_item_buffer(buffer);
    items_get_list_two(items, buffer, item_number);
    return (items);
}