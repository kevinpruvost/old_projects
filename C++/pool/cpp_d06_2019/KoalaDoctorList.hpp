#ifndef KOALADOCTORLIST_H
#define KOALADOCTORLIST_H

#include "KoalaDoctor.hpp"
#include <cstring>

class KoalaDoctorList {
    private:
        KoalaDoctor *koala;
        KoalaDoctorList *next = NULL;
    public:
        KoalaDoctorList(KoalaDoctor *koala) {
            this->koala = koala;
        }
        bool isEnd() {
            if (this->next != NULL)
                return (false);
            else
                return (true);
        }
        void append(KoalaDoctorList *next) {
            KoalaDoctorList *node = this;

            while (node->next != NULL) {
                node = node->next;
            }
            node->next = next;
        }
        KoalaDoctor *getFromName(std::string name) {
            KoalaDoctorList *node = this;

            while (node->koala->getName() != name && node->next != NULL)
                node = node->next;
            if (node->koala->getName() == name)
                return (node->koala);
            return (NULL);
        }
        KoalaDoctorList *remove(KoalaDoctorList *to_remove) {
            KoalaDoctorList *node = this;

            if (to_remove == NULL)
                return (this);
            if (this == to_remove)
            {
                to_remove = to_remove->next;
                return (to_remove);
            }
            else
            {
                while (node->next != to_remove && node->next != NULL)
                    node = node->next;
                if (node->next == to_remove)
                    node->next = to_remove->next;
            }
        }
        KoalaDoctorList *removeFromID(std::string name) {
            KoalaDoctor *to_remove_koala = (this)->getFromName(name);
            KoalaDoctorList *to_remove = this;

            if (to_remove_koala == NULL)
                return (this);
            else {
                while (to_remove->koala != to_remove_koala && to_remove != NULL)
                    to_remove = to_remove->next;
                if (to_remove == NULL)
                    return (this);
                else
                    return ((this)->remove(to_remove));
            }
        }
        void dump() {
            KoalaDoctorList *node = this;

            std::cout << "Nurses: ";
            while (node != NULL)
            {
                if (node->koala != NULL)
                    std::cout << node->koala->getName();
                else
                    std::cout << "[NULL]";
                if (node->next != NULL)
                    std::cout << ", ";
                else
                    std::cout << ".\n";
                node = node->next;
            }
        }
};

#endif