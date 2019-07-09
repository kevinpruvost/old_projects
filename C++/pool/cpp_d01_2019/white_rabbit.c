/*
** EPITECH PROJECT, 2019
** white_rabbit.c
** File description:
** white rabbit project
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int follow_the_white_rabbit(void)
{
    int direct[4][9] = {{4, 5, 6, 17, 18, 19, 20, 21, 28},
    {13, 34, 35, 36, -1, -1, -1, -1, -1},
    {10, 15, 23, -1, -1, -1, -1, -1, -1},
    {8, 16, 24, 26, 32, -1, -1, -1, -1}};
    int sum = 0;

    for (int d = random()%37+1; d != 37 && d != 1; d = random()%37+1) {
        sum += d;
        for (int i = 0; i < 20; i++) {
            (d == direct[0][i]) ? (write(1, "left\n", 5)) : (0);
            (d == direct[1][i]) ? (write(1, "right\n", 6)) : (0);
            (d == direct[2][i]) ? (write(1, "forward\n", 8)) : (0);
            (d == direct[3][i]) ? (write(1, "backward\n", 9)) : (0);
        }
        if (sum == 397 || sum == 421)
            break;
    }
    write(1, "RABBIT!!!\n", 10);
    return (0);
}