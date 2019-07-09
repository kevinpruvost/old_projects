/*
** EPITECH PROJECT, 2019
** menger.c
** File description:
** cpool day 01 project
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "menger.h"

void display_menger_line(int line[3])
{
    for (int i = 0; i < 3; i++) {
        if (line[i] < 100)
            printf("0");
        if (line[i] < 10)
            printf("0");
        printf("%d", line[i]);
        (i != 2) ? (printf(" ")) : (printf("\n"));
    }
}

void set_line(int line[3], int a, int b, int c)
{
    line[0] = a;
    line[1] = b;
    line[2] = c;    
}

int menger(int x, int y)
{
    int line[3] = {0, 0, 0};

    if (x < 3 || x % 3 != 0 || y <= 0 || x <= y / 3)
        return (84);
    x /= 3;
    set_line(line, x, x, x);
    display_menger_line(line);
    for (int x_a = x; x_a != 1;) {
        x_a /= 3;
        set_line(line, x_a, x_a, x_a);
        display_menger_line(line);
    }
    return (0);
}