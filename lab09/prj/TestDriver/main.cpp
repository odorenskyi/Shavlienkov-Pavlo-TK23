#include <iostream>
#include "ModulesShavlienkov.h"

using namespace std;

int main()
{
    system("chcp 65001 & cls");

    float speed;

    cout << "Введіть швидкість вітру: ";
    cin >> speed;

    printInfoTornado(speed);

    float temps[6];

    for(int i = 0; i < 6; i++) {
        float temp;
        cout << "Введіть температуру: ";
        cin >> temp;
        temps[i] = temp;
    }

    avgTemp(temps);

    int N;

    cout << "Введіть число: ";
    cin >> N;

    countBits(N);

    system("pause");

    return 0;
}
