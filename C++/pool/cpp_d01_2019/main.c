/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** cpool day 01 project
*/

#include <stdio.h>
#include <stdlib.h>
#include "menger.h"

int main(int ac, char **av)
{
    int x = 0;
    int y = 0;

    if (ac != 3) {
        return (84);
    } else {
        x = atoi(av[1]);
        y = atoi(av[2]);
        menger(x, y);
    }
    return (0);
}