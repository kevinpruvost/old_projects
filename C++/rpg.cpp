#include <iostream>

using namespace std;

class character {
    private :
        int level = 1;
        int starting_point = 0;
        int xp = 0;
    public :
        int get_level() {
            return this->level;
        }
        int get_xp() {
            return this->xp;
        }
        int give_xp(int to_add) {
            this->xp += to_add;
            if (this->xp >= 100)
            return this->xp;
        }
        int win_fight(character ennemy) {
            this->xp += ennemy.level * 5;
        }
        void show_xp() {
            std::cout << "Ce personnage a " << this->xp << "xp.\n";
        }
}