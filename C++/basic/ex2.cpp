#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    int number = rand() % 8; 
    int guess = -1;
    int trycount = 0;

    while (trycount < 8) {
        cout << "Please enter a guess: ";
        cin >> guess;
        if (guess < number)
            cout << "Too low" << endl;
        if (guess > number)
            cout << "Too high" << endl;
        if (guess == number)
            cout << "You guessed the number";
        else
            cout << "Sorry, the number was: " << number;
        trycount++;
    }
    return (0);
}