//number to english txt
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

string num_to_text[] = { 
    "", "one", "two", "three", "four", "five", 
    "six", "seven", "eight", "nine", "ten", 
    "eleven", "twelve", "thirteen", "fourteen", 
    "fifteen", "sixteen", "seventeen", "eighteen", 
    "nineteen" };

string tens_to_text[] = { "", "", "twenty", "thirty", 
    "forty", "fifty", "sixty", "seventy", "eighty", 
    "ninety" };

string power_to_text[] = { "", "thousand", "million", "billion" };

string hundred = "hundred";

string conversion(string name, int number)
{
    char *nb = new char[15];
    sprintf(nb, "%d", number);
    name.clear();
    for (int i = 0, grandeur = strlen(nb) - 1; grandeur >= 0; grandeur--, i++) {
        int cmp = grandeur / 3;

        cout << "grandeur = " << grandeur << " et cmp = " << cmp << endl;
        if (nb[i] == '0')
            continue;
        if ((grandeur - cmp * 3) % 2 == 0 && grandeur - cmp * 3 > 0)
        {
            name += num_to_text[nb[i] - 48] + " ";
            name += hundred + " ";
        } else if (grandeur - cmp * 3 > 0) {
            if (nb[i] - 48 == 1) {
                i++, grandeur--;
                name += num_to_text[nb[i] - 48 + 10] + " ";
                if (grandeur >= 3) {
                    name += power_to_text[cmp] + " ";
                }
            } else {
                name += tens_to_text[nb[i] - 48] + " ";
            }
        } else {
            name += num_to_text[nb[i] - 48] + " ";
            if (grandeur >= 3) {
                name += power_to_text[cmp] + " ";
            }
        }
    }
    return (name);
}

int main()
{
    string name;
    int number;

    cout << "Enter the number : ";
    cin >> number;
    cout << endl;

    name = conversion(name, number);
    cout << number << " = " << name << endl;
    return (0);
}