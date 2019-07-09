#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void temp_find(float temperature[2], char *str)
{
    char *deg = new char[50];
    char *unit = new char[50];
    string units;
    int mode = 0;

    for (int i = 0, j = 0; str[i] != 0; i++) {
        if (mode == 0 && str[i] == ' ')
            mode = 1;
        if (mode == 1 && str[i] != ' ')
            mode = 2;
        if (mode == 2 && isalpha(str[i]) == 0)
            break;
        (mode == 0) ? (deg[j++] = str[i]) : (0);
        (mode == 1) ? (j = 0) : (0);
        (mode == 2) ? (unit[j++] = str[i]) : (0);
    }
    temperature[0] = -84;
    temperature[1] = -84;
    units = unit;
    if (units.compare("Fahreneit") == 0)
        temperature[1] = 1;
    else if (units.compare("Celsius") == 0)
        temperature[1] = 2;
    else
        return;
    for (int i = 0; deg[i] != 0; i++)
        if (isdigit(deg[i]) == 0 && deg[i] != '.' && deg[i] != ',' && deg[i] != '-')
            return;
    temperature[0] = atof(deg);
}

int main(int ac, char **av)
{
    float temperature[2] = {0, 0};

    if (ac != 2) {
        return (84);
    } else {
        temp_find(temperature, av[1]);
        if (temperature[0] == -84 || temperature[1] == -84)
            return (84);
        if (temperature[1] == 2)
            temperature[0] = temperature[0] * 9 / 5 + 32;
        else
            temperature[0] = (temperature[0] - 32) / 9 * 5;
        printf("\t%.3f\t", temperature[0]);
        if (temperature[1] == 2)
            printf("Fahreneit\n");
        else
            printf("Celsius\n");
    }
}