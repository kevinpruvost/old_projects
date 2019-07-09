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

int my_cat(string filename)
{
    char *content;
    ifstream file;
    int file_size = 0;

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
    file_size = get_file_size(&file);

    content = new char[file_size + 1];
    file.read(content, file_size);
    printf("%s", content);
    file.close();
    return (0);
}

int main(int ac, char **av)
{
    string filename;

    if (ac < 2)
        return (84);
    else {
        for (int i = 1; i < ac; i++) {
            filename = av[i];
            my_cat(filename);
        }
    }
    return (0);
}