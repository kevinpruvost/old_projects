#ifndef KOALANURSE_H
#define KOALANURSE_H

#include "SickKoala.hpp"
#include <iostream>
#include <fstream>

class KoalaNurse {
    private :
        int id;
        bool work = false;
    public:
        KoalaNurse(int assign_id) {
            this->id = assign_id;
        }
        ~KoalaNurse() {
            std::cout << "Nurse " << this->id << ": Finally some rest!\n";
        }
        int getID() {
            return this->id;
        }
        void giveDrug(std::string drug, SickKoala *koala) {
            (*koala).takeDrug(drug);
        }
        std::string readReport(std::string report) {
            std::ifstream file(report.c_str(), std::ios::in);
            std::string	drug;
            std::size_t	pos;

            if (file) {
                if (!getline(file, drug))
                    return (report);
                pos = report.find(".report", 0);
                if (pos != std::string::npos && pos + 7 == report.length())
                    report.replace(report.length() - 7, 7, "\0");
                else
                    return (report);
                std::cout << "Nurse " << this->id << ": Kreog! Mr." << report << " needs a "
                << drug << "!" << std::endl;
                return (drug);
                } else
                    return (report);
            return drug;
        }
        void timeCheck() {
            (this->work) ? (this->work = false) : (this->work = true);
            if (this->work)
                std::cout << "Nurse " << this->id << ": Time to get to work!\n";
            else
                std::cout << "Nurse " << this->id << ": Time to go home to my eucalyptus forest!\n";
        }
};

#endif