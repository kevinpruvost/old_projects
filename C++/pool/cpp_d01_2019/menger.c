/*
** EPITECH PROJECT, 2019
** menger.c
** File description:
** menger exercise, find every empty squares [size, x, y]
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "menger.h"

void display_menger_line(int line[3])
{
    for (int i = 0; i < 3; i++)
    {
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

int menger_complete(int line[3], int x, int y)
{
    int x1 = 1;
    int x2 = 1;
}

int menger(double x, double y, double a, double b, int n)
{
    int size;
    int line[3] = {0, 0, 0};

    if (n > 0)
    {
        size = (x + 2 * a / 3) - (x + a / 3);
        set_line(line, size, y + b / 3, x + a / 3);
        display_menger_line(line);
        menger(x, y, a / 3, b / 3, n - 1);
        menger(x + a / 3, y, a / 3, b / 3, n - 1);
        menger(x + 2 * a / 3, y, a / 3, b / 3, n - 1);
        menger(x, y + b / 3, a / 3, b / 3, n - 1);
        menger(x + 2 * a / 3, y + b / 3, a / 3, b / 3, n - 1);
        menger(x, y + 2 * b / 3, a / 3, b / 3, n - 1);
        menger(x + a / 3, y + 2 * b / 3, a / 3, b / 3, n - 1);
        menger(x + 2 * a / 3, y + 2 * b / 3, a / 3, b / 3, n - 1);
    }
    return (0);
}