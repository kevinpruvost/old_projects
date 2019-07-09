#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

int get_file_size(ifstream *file)
{
    int size = 0;

    (*file).seekg(0, ios_base::end);
    size = (*file).tellg();
    (*file).seekg(0, ios_base::beg);
    return (size);
}

int main(void)
{
    char *content;
    ifstream file;
    string filename;

    cout << "Entrez le nom du fichier à lire : ";
    cin >> filename;
    cout << endl;

    file.exceptions(ifstream::failbit | ifstream::badbit);
    try
    {
        file.open(filename);
    }
    catch (ifstream::failure &e)
    {
        cerr << "Bug, le fichier ne peut pas être lu.\n";
        return (84);
    }
    int file_size = get_file_size(&file);

    content = new char[file_size + 1];
    file.read(content, file_size);
    printf("%s\n", content);
    file.close();
    return (0);
}