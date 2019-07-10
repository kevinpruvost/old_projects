#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "SickKoalaList.hpp"
#include "KoalaDoctorList.hpp"
#include "KoalaNurseList.hpp"
#include <cstring>

class Hospital {
    private:
        SickKoala *koala;
        SickKoalaList *next = NULL;
    public:
        void hospital_begin() {
            std::cout << "[HOSPITAL] ";
        }
        void addDoctor(KoalaDoctor *doctor) {
            this->hospital_begin();
            std::cout << "Doctor " << doctor->getName() << " just arrived!\n";
        }
        void addSick(SickKoala *sick) {
            this->hospital_begin();
            std::cout << "Patient " << sick->getName() << " just arrived!\n";
        }
        void addNurse(KoalaNurse *nurse) {
            this->hospital_begin();
            std::cout << "Nurse " << nurse->getID() << " just arrived!\n";
        }
        void run() {
            this->hospital_begin();
            std::cout << "Work starting with:\n";
        }
};

#endif