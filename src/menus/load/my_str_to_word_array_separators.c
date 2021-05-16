/*
** EPITECH PROJECT, 2021
** env_parsing.c
** File description:
** all function for parsing env
*/

#include "my.h"
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_game.h"

char *copy_str_without_adjacents_separators(char *str, char *separators)
{
    int str_size = my_strlen(str);
    char *new_str = malloc(sizeof(char) * (str_size + 2));
    int count = 0;
    int start = 0;

    for (int i = 0; my_strchr(str[i], separators) == true; i++)
        start++;
    for (int i = start; i < str_size; i++) {
        if (my_strchr(str[i], separators) == false) {
            new_str[count] = str[i];
            count++;
        } else {
            count = copy_one(str, (sfVector2i){i, count}, separators, new_str);
        }
    }
    new_str[count] = '\0';
    new_str[count + 1] = '\0';
    return (new_str);
}

int get_separators_occurence(char *str, char *separators)
{
    int str_size = my_strlen(str);
    int count = 0;

    for (int i = 0; i < str_size; i++) {
        if (my_strchr(str[i], separators) == true)
            count++;
    }
    return (count + 1);
}

void replace_all_separators_by_endfile(char *str, char *separators)
{
    int str_size = my_strlen(str);

    for (int i = 0; i < str_size; i++) {
        if (my_strchr(str[i], separators) == true)
            str[i] = '\0';
    }
}

void fill_new_buff_with_str(char *str, char **new_buff)
{
    int count = 0;

    while (my_strlen(str) != 0) {
        new_buff[count] = my_strdup(str);
        count += 1;
        str += my_strlen(str) + 1;
    }
    new_buff[count] = "\0";
}

char **my_str_to_word_array_separators(char *buffer, char *separators)
{
    char **new_buff = NULL;
    char *str = NULL;
    int separators_occurence = 0;

    if (separators == NULL)
        separators = "";
    if (buffer == NULL)
        buffer = "";
    str = copy_str_without_adjacents_separators(buffer, separators);
    separators_occurence = get_separators_occurence(str, separators);
    new_buff = malloc(sizeof(char *) * (separators_occurence + 1));
    replace_all_separators_by_endfile(str, separators);
    fill_new_buff_with_str(str, new_buff);
    free(str);
    return (new_buff);
}