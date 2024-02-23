#include <iostream>
#include "ModulesShavlienkov.h"

using namespace std;

string printCopyright() {
    return "Шавлєнков Павло © Усі права захищені.";
}

bool logicalExpression(char a, char b) {
    bool v = a + 1 < b;

    return v;
}

float printNumbersInDecAndHex(int x, int y, int z) {
    cout << "У десятковій системі: " << dec << x << endl;
    cout << "У десятковій системі: " << dec << y << endl;
    cout << "У десятковій системі: " << dec << z << endl;

    cout << "\n";

    cout << "У шістнадцятковій системі: " << hex << x << endl;
    cout << "У шістнадцятковій системі: " << hex << y << endl;
    cout << "У шістнадцятковій системі: " << hex << z << endl;

    return s_calculation(x, y, z);
}

int main()
{
    system("chcp 65001 & cls");

    int x, y, z;
    char a, b;

    cout << "Введіть значення x: ";
    cin >> x;
    cout << "Введіть значення y: ";
    cin >> y;
    cout << "Введіть значення z: ";
    cin >> z;
    cout << "Введіть значення a: ";
    cin >> a;
    cout << "Введіть значення b: ";
    cin >> b;

    cout << printCopyright() << endl;
    cout << logicalExpression(a, b) << endl;

    cout << "\n";

    cout << printNumbersInDecAndHex(x, y, z) << endl;

    return 0;
}
