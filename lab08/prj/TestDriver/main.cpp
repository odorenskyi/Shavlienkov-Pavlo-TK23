#include <iostream>
#include "ModulesShavlienkov.h"

using namespace std;

int main()
{
    system("chcp 65001 & cls");

    int x, y, z;

    cout << "Введіть число x: ";
    cin >> x;
    cout << "Введіть число y: ";
    cin >> y;
    cout << "Введіть число z: ";
    cin >> z;

    cout << "S = ";
    cout << s_calculation(x, y, z) << endl;
    return 0;
}
