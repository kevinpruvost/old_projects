#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include "KoalaDoctor.hpp"

using namespace std;

int main(void)
{
    srandom(time(NULL));
    KoalaNurse nurse1(0);
    KoalaNurse nurse2(1);
    SickKoala koala1("Javier");
    KoalaDoctor doc("Alain");

    doc.diagnose(&koala1);
}