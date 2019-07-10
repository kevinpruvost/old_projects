#ifndef SICKKOALA_H
#define SICKKOALA_H

#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

class SickKoala {
    private :
        int id;
        std::string name;
    public:
        void cout_mr_name() {
            std::cout << "Mr." << this->name << ": ";
        }
        SickKoala(std::string name) {
            this->name = name;
        }
        ~SickKoala() {
            (this)->cout_mr_name();
            std::cout << "Kreooogg!! I'm cuuuured!\n";
        }
        std::string getName() {
            return this->name;
        }
        void poke() {
            (this)->cout_mr_name();
            std::cout << "Gooeeeeerrk!!\n";
        }
        bool takeDrug(std::string drug) {
            if (boost::iequals(drug, "mars")) {
                (this)->cout_mr_name();
                std::cout << "Mars, and it kreogs!\n";
                return (true);
            }
            if (drug.compare("Buronzand") == 0) {
                (this)->cout_mr_name();
                std::cout << "And you'll sleep right away!\n";
                return (true);
            }
            (this)->cout_mr_name();
            std::cout << "Goerkreog!\n";
            return (false);
        }
        void overDrive(std::string quote) {
            quote.replace(quote.find("Kreog!"), 6, "1337!");
            (this)->cout_mr_name();
            std::cout << quote << std::endl;
        }
};

#endif