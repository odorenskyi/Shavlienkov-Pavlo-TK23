#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <sstream>

#include "../ModulesShavlienkov.h"

using namespace std;

int main()
{

    system("chcp 65001 & cls");

    int st = string(__FILE__).find("\\lab12\\prj");

    if(st == -1) {

        ofstream output("../../TestSuite/TestResults.txt");

        for(int i = 0; i < 100; i++) {
            Beep(900, 100);
            Sleep(100);

            output << "Встановлені вимоги порядку виконання лабораторної роботи порушено!";

            output.close();
        }

    } else {

        ifstream input("../../TestSuite/TestSuite.txt");
        ofstream output("../../TestSuite/TestResults.txt");

        int testCase = 1;

        string line;

        while (getline(input, line)) {
            stringstream ss(line);
            double a, b;

            ss >> a;
            ss.ignore(1, '|');
            ss >> b;

            try {
                ClassLab12_Shavlienkov obj(a, b);

                output << "TEST CASE " << testCase << endl;
                output<< "A: " << obj.getA() << endl;
                output << "B: " << obj.getB() << endl;
                output << "AREA: " << obj.getArea() << endl;
                output << "STATUS: " << "PASSED" << endl << endl;

            } catch (const invalid_argument& e) {
                output << "TEST CASE " << testCase << endl;
                output<< "A: " << a << endl;
                output << "B: " << b << endl;
                output << "STATUS: " << e.what() << endl << endl;
            }

            testCase += 1;

        }

        input.close();
        output.close();

    }

    return 0;
}
