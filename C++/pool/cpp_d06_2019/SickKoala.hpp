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

class SickKoalaList {
    private:
        SickKoala *koala;
        SickKoalaList *next = NULL;
    public:
        SickKoalaList(SickKoala *koala) {
            this->koala = koala;
        }
        bool isEnd() {
            if (this->next == NULL)
                return (true);
            else
                return (false);
        }
        void append(SickKoalaList *next) {
            SickKoalaList *node = this;

            while (node->next != NULL) {
                node = node->next;
            }
            node->next = next;
        }
        SickKoala *getFromName(std::string name) {
            SickKoalaList *node = this;

            while (node->koala->getName().compare(name) != 0 && node->next != NULL)
                node = node->next;
            if (node->koala->getName().compare(name) == 0)
                return (node->koala);
            return (NULL);
        }
};

#endif