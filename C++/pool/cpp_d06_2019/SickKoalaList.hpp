#ifndef SICKKOALALIST_H
#define SICKKOALALIST_H

#include "SickKoala.hpp"
#include <cstring>

class SickKoalaList {
    private:
        SickKoalaList *next = NULL;
    public:
        SickKoala *koala;
        SickKoalaList(SickKoala *koala) {
            this->koala = koala;
        }
        std::string getName() {
            if (this->koala != NULL)
                return this->koala->getName();
            return (NULL);
        }
        bool isEnd() {
            if (this->next == NULL)
                return (true);
            else
                return (false);
        }
        bool check_presence(SickKoalaList *to_check) {
            SickKoalaList *node = this;

            while (node != NULL) {
                if (node == to_check)
                    return (true);
                node = node->next;
            }
            return (false);
        }
        void append(SickKoalaList *next) {
            SickKoalaList *node = this;

            if (this->check_presence(next) == true)
                return;
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
        SickKoalaList *remove(SickKoalaList *to_remove) {
            SickKoalaList *node = this;
            SickKoalaList *buff = to_remove;

            if (to_remove == NULL)
                return (this);
            if (this == to_remove)
            {
                to_remove = to_remove->next;
                buff->next = NULL;
                return (to_remove);
            }
            else
            {
                while (node->next != to_remove && node->next != NULL)
                    node = node->next;
                if (node->next == to_remove)
                    node->next = to_remove->next;
            }
            return (NULL);
        }
        SickKoalaList *removeFromName(std::string name) {
            SickKoala *to_remove_koala = (this)->getFromName(name);
            SickKoalaList *to_remove = this;

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
        SickKoala *getContent() {
            return this->koala;
        }
        SickKoalaList *getNext() {
            return this->next;
        }
        void dump() {
            SickKoalaList *node = this;

            std::cout << "Patients: ";
            while (node != NULL)
            {
                if (node->koala != NULL && node->koala->getName().empty() == false)
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