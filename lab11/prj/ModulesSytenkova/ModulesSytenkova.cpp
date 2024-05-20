#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>

#include "struct_type_project_8.h"

using namespace std;

void getStudentData(string last_name = "") {
    try {
        ifstream file("temp.txt");
        if (!file.is_open()) {
            throw runtime_error("Файл бази даних не знайдено!");
        }

        string line;
        bool found = false;

        cout << "-----------------" << endl;

        while (getline(file, line)) {
            vector<string> elements;
            stringstream ss(line);
            string item;
            while (ss >> item) {
                elements.push_back(item);
            }
            if (!elements.empty() && elements[0] == last_name) {
                cout << "Прізвище: " << elements[0] << endl;
                cout << "Ім'я: " << elements[1] << endl;
                cout << "По-батькові: " << elements[2] << endl;
                cout << "Місце народження: " << elements[3] << endl;
                cout << "Дата народження: " << elements[4] << endl;
                cout << "Громадянство: " << elements[5] << endl;
                cout << "Сімейний стан: " << elements[6] << endl;
                cout << "Місце проживання: " << elements[7] << endl;
                cout << "Факультет: " << elements[8] << endl;
                cout << "Спеціальність: " << elements[9] << endl;
                cout << "Спеціалізація: " << elements[10] << endl;
                found = true;
            }

            cout << "-----------------" << endl;
        }
        file.close();

        if (!found) {
            throw runtime_error("Студент відсутній у базі даних!");
        }
    } catch (const runtime_error& e) {
        cerr << "Помилка: " << e.what() << endl;
    }
}

void deleteStudentData(string last_name = "") {
    try {
        ifstream file("temp.txt");
        if (!file.is_open()) {
            throw runtime_error("Файл бази даних не знайдено!");
        }

        string line;
        ofstream temp_file("temp_tmp.txt");
        bool found = false;

        while (getline(file, line)) {
            vector<string> elements;
            stringstream ss(line);
            string item;
            while (ss >> item) {
                elements.push_back(item);
            }
            if (!elements.empty() && elements[0] == last_name) {
                found = true;
            } else {
                temp_file << line << endl;
            }
        }

        file.close();

        if (!found) {
            throw runtime_error("Студент відсутній у базі даних!");
        } else {
            cout << "Дані студента видалено!" << endl;
        }

        temp_file.close();

        remove("temp.txt");
        rename("temp_tmp.txt", "temp.txt");
    } catch (const runtime_error& e) {
        cerr << "Помилка: " << e.what() << endl;
    }
}
