#include <iostream>
#include <fstream>
#include <string>
#include <limits>

#include "ModulesShavlienkov.h"
#include "ModulesSytenkova.h"
#include "ModulesMakodzeba.h"

using namespace std;

void getInput(const string& prompt, string& input) {
    cout << prompt;
    getline(cin, input);
    while (input.empty()) {
        cout << "Поле не може бути порожнім. " << endl;
        cout << prompt;
        getline(cin, input);
    }
}

int main() {
    system("chcp 1251 & cls");

    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "|              Застосунок для бази даних \"Деканат: облік студентів\"             |" << endl;
    cout << "|          Розробники: Шавлєнков Павло, Ситенкова Вероніка, Макодзеба Павло     |" << endl;
    cout << "|   Шавлєнков Павло, Ситенкова Вероніка, Макодзеба Павло © Усі права захищені.  |" << endl;
    cout << "|                                   2024 рік                                    |" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;

    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "|                       Основні команди для бази даних:                         |" << endl;
    cout << "|                         1 - вивести всіх студентів в консоль                  |" << endl;
    cout << "|                         2 - вивести всіх студентів в файл                     |" << endl;
    cout << "|                         3 - додати студента до реєстру                        |" << endl;
    cout << "|                         4 - вивести дані студента                             |" << endl;
    cout << "|                         5 - видалити дані про студента                        |" << endl;
    cout << "|                         6 - завершити програму                                |" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;

    ifstream database("database.txt");
    ofstream temp("temp.txt");

    temp << database.rdbuf();
    database.close();
    temp.close();

    while (true) {
        string command;
        cout << "Введіть команду: ";
        cin >> command;

        if (command == "1") {
            getStudents(1);
        } else if (command == "2") {
            string path;
            cout << "Введіть шлях до файлу: ";
            cin >> path;

            getStudents(2, path);
        } else if (command == "3") {
            Student student;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            getInput("Прізвище: ", student.last_name);
            getInput("Ім'я: ", student.first_name);
            getInput("По-батькові: ", student.middle_name);
            getInput("Дата народження: ", student.date_of_birth);
            getInput("Місце народження (замість пробіла поставити _): ", student.place_of_birth);
            getInput("Громадянство: ", student.citizenship);
            getInput("Сімейний стан: ", student.marital_status);
            getInput("Місце проживання (замість пробіла поставити _): ", student.place_of_residence);
            getInput("Факультет: ", student.faculty);
            getInput("Спеціальність (замість пробіла поставити _): ", student.specialty);
            getInput("Спеціалізація (замість пробіла поставити _): ", student.specialization);

            addStudent(student);
        } else if (command == "4") {
            string last_name;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            getInput("Введіть прізвище студента: ", last_name);

            getStudentData(last_name);
        } else if (command == "5") {
            string last_name;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            getInput("Введіть прізвище студента: ", last_name);

            deleteStudentData(last_name);
        } else if (command == "6") {
            exitProgram();

            break;
        } else {
            cout << "Такої команди не існує" << endl;
            break;
        }
    }

    return 0;
}
