/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** function button
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int modif_number(char const *str, int count, int number, int is_neg)
{
    int j_count = 0;

    for (j_count = count; str[j_count] <= '9' &&
    str[j_count] >= '0'; j_count++) {
        number = number * 10 + str[j_count]-'0';
        if (number < 0 && (number != -2147483648 || is_neg % 2 != 1))
            return (0);
    }
    return (number);
}

char *get_file_buffer(char *path)
{
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int size = 0;
    ssize_t line_size;
    FILE *fp = fopen(path, "r");
    char *buffer;
    int file_description = open(path, O_RDONLY);

    if (!fp) {
        return (NULL);
    }
    line_size = getline(&line_buf, &line_buf_size, fp);
    while (line_size >= 0) {
        size += line_size;
        line_size = getline(&line_buf, &line_buf_size, fp);
    }
    buffer = malloc(size + 1);
    read(file_description, buffer, size);
    close(file_description);
    buffer[size] = '\0';
    return (buffer);
}