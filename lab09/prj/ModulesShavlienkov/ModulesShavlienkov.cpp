#include <cmath>
#include <iostream>

using namespace std;

float s_calculation(int x, int y, int z) {
    float S = pow(z + y + z, 2.0) - sqrt(fabs((2.0 * M_PI * sqrt((1.0/2.0) * z)) / (y + (4.0 * (pow(x, 3.0) + cos(z)))) ));
    return S;
}

void printInfoTornado(float speed) {
    if(64 <= speed && 116 >= speed) {
        cout << "Категорія торнадо за шкалою Фудзіти: " << "F0" << endl << "Частота виникнення: 38,9%" << endl;
    } else if(117 <= speed && 180 >= speed) {
        cout << "Категорія торнадо за шкалою Фудзіти: " << "F1" << endl << "Частота виникнення: 35,6%" << endl;
    } else if(181 <= speed && 253 >= speed) {
        cout << "Категорія торнадо за шкалою Фудзіти: " << "F2" << endl << "Частота виникнення: 19,4%" << endl;
    } else if(254 <= speed && 332 >= speed) {
        cout << "Категорія торнадо за шкалою Фудзіти: " << "F3" << endl << "Частота виникнення: 4,9%" << endl;
    } else if(333 <= speed && 418 >= speed) {
        cout << "Категорія торнадо за шкалою Фудзіти: " << "F4" << endl << "Частота виникнення: 1,1%" << endl;
    } else if(419 <= speed && 512 >= speed) {
        cout << "Категорія торнадо за шкалою Фудзіти: " << "F5" << endl << "Частота виникнення: меньше 0,1%" << endl;
    } else {
        cout << "Не входить у діапазон" << endl;
    }
}

void avgTemp(float arr[]) {

    float sum_temp = 0;

    for(int i = 0; i < 6; i++) {
        sum_temp += arr[i];
    }

    cout << "Цельсії: " << (sum_temp / 6) << " °C" << endl;
    cout << "Фаренгейти: " << ((sum_temp / 6) * (9 / 5)) + 32 << " °F" << endl;
}

void countBits(int N) {

    int counter = 0;

    if((N & 1) == 0) {

        while (N > 0) {
            int bit = N % 2;
            counter += (bit == 0) ? 1 : 0;
            N /= 2;
        }

        cout << "Кількість двійкових нулів дорівнює: " << counter << endl;

    } else {

        while (N > 0) {
            int bit = N % 2;
            counter += (bit != 0) ? 1 : 0;
            N /= 2;
        }

        cout << "Кількість двійкових одиниць дорівнює: " << counter << endl;
    }
}



