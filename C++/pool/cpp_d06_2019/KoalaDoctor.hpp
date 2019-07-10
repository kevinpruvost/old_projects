#ifndef KOALADOCTOR_H
#define KOALADOCTOR_H

#include "KoalaNurse.hpp"
#include <iostream>
#include <fstream>
#include <ostream>

class KoalaDoctor {
    private :
        int id;
        bool work = false;
        std::string name;
    public:
        void show_name(){
            std::cout << "Dr." << this->name << ": ";
        }
        KoalaDoctor(std::string name) {
            this->name = name;
            (this)->show_name();
            std::cout << "I'm Dr." << this->name << "! How do you kreog?\n";
        }
        ~KoalaDoctor() {
        }
        void write_report(std::string name) {
            std::string filename = name + ".report";
            std::string meds[5] = {"mars", "Buronzand", "Viagra", "Extasy", "Eucalyptus leaf"};
            std::ofstream file(filename);
            file << meds[random() % 5];
            file.close();
        }
        void diagnose(SickKoala *patient) {
            (this)->show_name();
            std::cout << "So what's goerking you Mr." << (*patient).getName() << "?\n";
            (*patient).poke();
            (this)->write_report((*patient).getName());
        }
        void timeCheck() {
            (this->work) ? (this->work = false) : (this->work = true);
            if (this->work)
                std::cout << "Dr." << this->id << ": Time to get to work!\n";
            else
                std::cout << "Dr." << this->id << ": Time to go home to my eucalyptus forest!\n";
        }
};

#endif