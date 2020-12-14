// Lab10.1(Rekurs).cpp 
// Михайлов Олександр
// Пошук та заміна символів у літерному рядку
// Варіант 24

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

int Count(char* str, int i)
{
    if (sizeof(str) < 3)
        return 0;
    if (str[i + 1] != 0)
        if (str[i - 1] == 'a' && str[i] == 'b' && str[i + 1] == 'c')
            return 1 + Count(str, i + 1);
        else
            return Count(str, i + 1);
    else
        return 0;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    fstream f;

    f.open("t.txt");

    if (!f.is_open())
    {
        cout << "Файл не відкрито!" << endl;
        return 0;
    }

    char tchar[100];

    while (!f.eof())
    {
        f.getline(tchar, sizeof(tchar));
    }

    if (Count(tchar, 1) == 1) {
        cout << endl << "String contained " << Count(tchar, 1) << " group of 'abc'." << endl;
    }
    else {
        cout << endl << "String contained " << Count(tchar, 1) << " groups of 'abc'." << endl;
    }

    f.close();

    return 0;
}
