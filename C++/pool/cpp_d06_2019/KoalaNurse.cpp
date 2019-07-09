#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include "KoalaNurse.hpp"

using namespace std;

int main(void)
{
    KoalaNurse nurse1(0);
    KoalaNurse nurse2(1);
    SickKoala koala1("Javier");

    koala1.overDrive("Kreog! How's it going ?");
}