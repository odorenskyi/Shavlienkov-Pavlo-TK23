#include <iostream>
#include "ModulesShavlienkov.h"

using namespace std;

int main()
{
    system("chcp 1251 & cls");

    writeAuthorInfo();
    writeFileInfo();
    writeCalculations(1, 2, 3, 500);

    return 0;
}
