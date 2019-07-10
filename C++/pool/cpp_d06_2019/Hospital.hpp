#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "SickKoalaList.hpp"
#include "KoalaDoctorList.hpp"
#include "KoalaNurseList.hpp"
#include <cstring>
#include <string>

class Hospital {
    private:
        KoalaDoctorList *doctors = NULL;
        SickKoalaList *patients = NULL;
        KoalaNurseList *nurses = NULL;
        bool work = false;
    public:
        void hospital_begin() {
            std::cout << "[HOSPITAL] ";
        }
        void addDoctor(KoalaDoctorList *doctor) {
            this->hospital_begin();
            std::cout << "Doctor " << doctor->getName() << " just arrived!\n";
            doctor->timeCheck();

            if (this->doctors == NULL) {
                this->doctors = doctor;
            } else {
                this->doctors->append(doctor);
            }
        }
        void addSick(SickKoalaList *sick) {
            this->hospital_begin();
            std::cout << "Patient " << sick->getName() << " just arrived!\n";

            if (this->patients == NULL) {
                this->patients = sick;
            } else {
                this->patients->append(sick);
            }
        }
        void addNurse(KoalaNurseList *nurse) {
            this->hospital_begin();
            std::cout << "Nurse " << nurse->getID() << " just arrived!\n";
            nurse->timeCheck();

            if (this->nurses == NULL) {
                this->nurses = nurse;
            } else {
                this->nurses->append(nurse);
            }
        }
        void run() {
            this->work = true;
            this->hospital_begin();
            std::cout << "Work starting with:\n";
            this->doctors->dump();
            this->nurses->dump();
            this->patients->dump();

            KoalaNurseList *nurses = this->nurses;
            KoalaDoctorList *doctors = this->doctors;
            std::string med;
            while (this->patients != NULL)
            {
                doctors->koala->diagnose(this->patients->koala);
                med = nurses->koala->readReport(this->patients->koala->getName() + ".report");
                nurses->koala->giveDrug(med, this->patients->koala);

                doctors = doctors->getNext();
                nurses = nurses->getNext();
                if (nurses == NULL)
                    nurses = this->nurses;
                if (doctors == NULL)
                    doctors = this->doctors;
                this->patients = this->patients->remove(this->patients);
            }

            while (this->nurses != NULL) {
                this->nurses->timeCheck();
                this->nurses = this->nurses->remove(this->nurses);
            }
            while (this->doctors != NULL) {
                this->doctors->timeCheck();
                this->doctors = this->doctors->remove(this->doctors);
            }
        }
};

#endif