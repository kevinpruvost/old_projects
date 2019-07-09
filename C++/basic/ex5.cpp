//Line count
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string name;

    cout << "Rentre un nom\n";
    cin >> name;
    fstream file(name);

    char *c = new char[255];
    cout << "\n\n\n";
    file.seekg(0, ios_base::end);
    while (file.getline(c, 255, '\n'))
        cout << c << "\n";
    file.close();
}