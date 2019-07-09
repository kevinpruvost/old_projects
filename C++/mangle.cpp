#include <stdio.h>
#include <iostream>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;

char *string_to_char(string str)
{
	char *cstr = new char[str.size() + 1];

	strcpy(cstr, str.c_str());
    return (cstr);
}

int isvowel(char c)
{
    char vowels[10] = {'a', 'A', 'e', 'E', 'o', 'O', 'i', 'I', 'u', 'U'};

    for (int i = 0; i < 10; i++) {
        if (c == vowels[i])
            return (1);
    }
    return (0);
}

void mangled(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (isalpha(str[i]) != 0)
            str[i] += (str[i] == 'z' || str[i] == 'Z') ? -25 : 1;
        if (islower(str[i]) != 0 && isvowel(str[i]) != 0)
            str[i] -= 32;
    }
}

int main(void)
{
    string strm;
    char *tomangle;

    cout << "Enter a string to mangle : ";
    getline(cin, strm);
    tomangle = string_to_char(strm);
    cout << endl;

    mangled(tomangle);
    cout << "Mangled string : " << tomangle << endl;
}