#include <iostream>
#include <Windows.h>
#include "ModulesShavlienkov.h"

using namespace std;

int main()
{
    system("chcp 65001 & cls");

    while (true) {
        char symbol;
        cout << "Введіть символ(z, r, s, t, q, Q): ";
        cin >> symbol;

        if (symbol == 'q' || symbol == 'Q') {
            break;
        }

        switch (symbol) {
            case 'z':
                int x, y, z;

                cout << "Введіть число x: ";
                cin >> x;
                cout << "Введіть число y: ";
                cin >> y;
                cout << "Введіть число z: ";
                cin >> z;

                cout << s_calculation(x, y, z) << endl;

                break;

            case 'r':
                float speed;

                cout << "Введіть швидкість вітру: ";
                cin >> speed;

                printInfoTornado(speed);

                break;

            case 's':
                float temps[6];

                for(int i = 0; i < 6; i++) {
                   float temp;
                   cout << "Введіть температуру: ";
                   cin >> temp;
                   temps[i] = temp;
                }

                avgTemp(temps);

                break;

            case 't':
                int N;

                cout << "Введіть число: ";
                cin >> N;

                countBits(N);

                break;

            default:
                Beep(523, 1000);

                break;
        }

    }

    return 0;
}
