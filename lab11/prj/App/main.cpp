#include <iostream>
#include <fstream>

#include "ModulesShavlienkov.h"
#include "ModulesSytenkova.h"
#include "ModulesMakodzeba.h"

using namespace std;

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
    cout << "|                          1 - вивести всіх студентів в консоль                 |" << endl;
    cout << "|                          2 - вивести всіх студентів в файл                    |" << endl;
    cout << "|                          3 - додати студента до реєстру                       |" << endl;
    cout << "|                          4 - вивести дані студента                            |" << endl;
    cout << "|                          5 - видалити дані про студента                       |" << endl;
    cout << "|                          6 - завершити програму                               |" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;

    ifstream database("database.txt");
    ofstream temp("temp.txt");

    temp << database.rdbuf();
    database.close();
    temp.close();

    while (true) {
        int command;
        cout << "Введіть команду: ";
        cin >> command;

        switch (command) {
            case 1:
                getStudents(1);
                break;
            case 2: {
                string path;
                cout << "Введіть шлях до файлу: ";
                cin >> path;
                getStudents(2, path);
                break;
            }
            case 3: {
                Student student;
                cout << "Прізвище: ";
                cin >> student.last_name;
                cout << "Ім'я: ";
                cin >> student.first_name;
                cout << "По-батькові: ";
                cin >> student.middle_name;
                cout << "Дата народження: ";
                cin >> student.date_of_birth;
                cout << "Місце народження (замість пробіла поставити _): ";
                cin >> student.place_of_birth;
                cout << "Громадянство: ";
                cin >> student.citizenship;
                cout << "Сімейний стан: ";
                cin >> student.marital_status;
                cout << "Місце проживання (замість пробіла поставити _): ";
                cin >> student.place_of_residence;
                cout << "Факультет: ";
                cin >> student.faculty;
                cout << "Спеціальність (замість пробіла поставити _): ";
                cin >> student.specialty;
                cout << "Спеціалізація (замість пробіла поставити _): ";
                cin >> student.specialization;

                addStudent(student);
                break;
            }
            case 4: {
                string last_name;
                cout << "Введіть прізвище студента: ";
                cin >> last_name;
                getStudentData(last_name);
                break;
            }
            case 5: {
                string last_name;
                cout << "Введіть прізвище студента: ";
                cin >> last_name;
                deleteStudentData(last_name);
                break;
            }
            case 6: {
                exitProgram();
                return 0;
            }
            default:
                cout << "Такої команди не існує" << endl;
        }
    }

    return 0;
}
