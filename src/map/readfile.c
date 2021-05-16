/*
** EPITECH PROJECT, 2021
** readfile
** File description:
** desc
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "my.h"

char *readline(FILE *file)
{
    char *line = NULL;
    int len = 0;
    size_t size = 0;

    len = getline(&line, &size, file);
    if (len <= 0) {
        free(line);
        return (NULL);
    }
    return (line);
}

char *fill_buf(char *buf, char *tmp, char *line, int len)
{
    buf = malloc(sizeof(char) * (len + 1));
    if (buf == NULL)
        return (NULL);
    if (tmp != NULL) {
        my_strcpy(buf, tmp);
        my_strcat(buf, line);
    } else {
        my_strcpy(buf, line);
    }
    buf[len] = '\0';
    return (buf);
}

char *fill_tmp(int len, char *tmp, char *buf)
{
    len = my_strlen(buf);
    tmp = malloc(sizeof(char) * (len + 1));
    my_strcpy(tmp, buf);
    tmp[len] = '\0';
    free(buf);
    return (tmp);
}

int count_len(char *line, char *tmp)
{
    int len = 0;

    len = my_strlen(line);
    if (tmp != NULL) {
        len += my_strlen(tmp);
    }
    return (len);
}

char *readfile(char *pathname)
{
    char *buf = NULL;
    char *line = NULL;
    char *tmp = NULL;
    int len = 0;
    FILE *file = fopen(pathname, "r+");

    if (file == NULL)
        return (NULL);
    for (line = readline(file); line; line = readline(file)) {
        if (buf != NULL)
            tmp = fill_tmp(len, tmp, buf);
        len = count_len(line, tmp);
        buf = fill_buf(buf, tmp, line, len);
        free(line);
        free(tmp);
    }
    fclose(file);
    return (buf);
}