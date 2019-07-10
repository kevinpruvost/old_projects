#ifndef KOALANURSELIST_H
#define KOALANURSELIST_H

#include "KoalaNurse.hpp"
#include <cstring>

class KoalaNurseList {
    private:
        KoalaNurseList *next = NULL;
    public:
        KoalaNurse *koala;
        KoalaNurseList(KoalaNurse *koala) {
            this->koala = koala;
        }
        int getID() {
            if (this->koala != NULL)
                return this->koala->getID();
            return (-1);
        }
        void timeCheck() {
            if (this->koala != NULL)
                this->koala->timeCheck();
        }
        bool isEnd() {
            if (this->next != NULL)
                return (false);
            else
                return (true);
        }
        bool check_presence(KoalaNurseList *to_check) {
            KoalaNurseList *node = this;

            while (node != NULL) {
                if (node == to_check)
                    return (true);
                node = node->next;
            }
            return (false);
        }
        void append(KoalaNurseList *next) {
            KoalaNurseList *node = this;

            if (this->check_presence(next) == true)
                return;
            while (node->next != NULL) {
                node = node->next;
            }
            node->next = next;
        }
        KoalaNurse *getFromID(int id) {
            KoalaNurseList *node = this;

            while (node->koala->getID() != id && node->next != NULL)
                node = node->next;
            if (node->koala->getID() == id)
                return (node->koala);
            return (NULL);
        }
        KoalaNurseList *remove(KoalaNurseList *to_remove) {
            KoalaNurseList *node = this;
            KoalaNurseList *buff = to_remove;

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
        KoalaNurseList *removeFromID(int id) {
            KoalaNurse *to_remove_koala = (this)->getFromID(id);
            KoalaNurseList *to_remove = this;

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
        KoalaNurseList *getNext() {
            return this->next;
        }
        void dump() {
            KoalaNurseList *node = this;

            std::cout << "Nurses: ";
            while (node != NULL)
            {
                if (node->koala != NULL)
                    std::cout << node->koala->getID();
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