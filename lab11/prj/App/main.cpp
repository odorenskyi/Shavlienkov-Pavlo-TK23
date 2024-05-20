#include <iostream>
#include <fstream>

#include "ModulesShavlienkov.h"
#include "ModulesSytenkova.h"
#include "ModulesMakodzeba.h"

using namespace std;

int main() {
    system("chcp 1251 & cls");

    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "|              ���������� ��� ���� ����� \"�������: ���� ��������\"             |" << endl;
    cout << "|          ����������: �������� �����, ��������� �������, ��������� �����     |" << endl;
    cout << "|   �������� �����, ��������� �������, ��������� ����� � �� ����� �������.  |" << endl;
    cout << "|                                   2024 ��                                    |" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;

    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "|                       ������ ������� ��� ���� �����:                         |" << endl;
    cout << "|                          1 - ������� ��� �������� � �������                 |" << endl;
    cout << "|                          2 - ������� ��� �������� � ����                    |" << endl;
    cout << "|                          3 - ������ �������� �� ������                       |" << endl;
    cout << "|                          4 - ������� ��� ��������                            |" << endl;
    cout << "|                          5 - �������� ��� ��� ��������                       |" << endl;
    cout << "|                          6 - ��������� ��������                               |" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;

    ifstream database("database.txt");
    ofstream temp("temp.txt");

    temp << database.rdbuf();
    database.close();
    temp.close();

    while (true) {
        int command;
        cout << "������ �������: ";
        cin >> command;

        switch (command) {
            case 1:
                getStudents(1);
                break;
            case 2: {
                string path;
                cout << "������ ���� �� �����: ";
                cin >> path;
                getStudents(2, path);
                break;
            }
            case 3: {
                Student student;
                cout << "�������: ";
                cin >> student.last_name;
                cout << "��'�: ";
                cin >> student.first_name;
                cout << "��-�������: ";
                cin >> student.middle_name;
                cout << "���� ����������: ";
                cin >> student.date_of_birth;
                cout << "̳��� ���������� (������ ������ ��������� _): ";
                cin >> student.place_of_birth;
                cout << "������������: ";
                cin >> student.citizenship;
                cout << "ѳ������ ����: ";
                cin >> student.marital_status;
                cout << "̳��� ���������� (������ ������ ��������� _): ";
                cin >> student.place_of_residence;
                cout << "���������: ";
                cin >> student.faculty;
                cout << "������������ (������ ������ ��������� _): ";
                cin >> student.specialty;
                cout << "������������ (������ ������ ��������� _): ";
                cin >> student.specialization;

                addStudent(student);
                break;
            }
            case 4: {
                string last_name;
                cout << "������ ������� ��������: ";
                cin >> last_name;
                getStudentData(last_name);
                break;
            }
            case 5: {
                string last_name;
                cout << "������ ������� ��������: ";
                cin >> last_name;
                deleteStudentData(last_name);
                break;
            }
            case 6: {
                exitProgram();
                return 0;
            }
            default:
                cout << "���� ������� �� ����" << endl;
        }
    }

    return 0;
}
