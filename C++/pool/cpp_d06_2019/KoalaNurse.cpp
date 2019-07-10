#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include "KoalaDoctor.hpp"
#include "SickKoalaList.hpp"

using namespace std;

int main(void)
{
    srandom(time(NULL));
    KoalaNurse nurse1(0);
    KoalaNurse nurse2(1);
    SickKoala koala1("Javier");
    SickKoala koala2("El Pueblo");
    SickKoalaList sklist(&koala1);
    SickKoalaList sklist2(&koala2);
    KoalaDoctor doc("Alain");

    sklist.append(&sklist2);
    sklist.dump();
}