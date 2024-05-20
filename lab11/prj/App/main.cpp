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
        cout << "���� �� ���� ���� �������. " << endl;
        cout << prompt;
        getline(cin, input);
    }
}

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
    cout << "|                         1 - ������� ��� �������� � �������                  |" << endl;
    cout << "|                         2 - ������� ��� �������� � ����                     |" << endl;
    cout << "|                         3 - ������ �������� �� ������                        |" << endl;
    cout << "|                         4 - ������� ��� ��������                             |" << endl;
    cout << "|                         5 - �������� ��� ��� ��������                        |" << endl;
    cout << "|                         6 - ��������� ��������                                |" << endl;
    cout << "---------------------------------------------------------------------------------" << endl;

    ifstream database("database.txt");
    ofstream temp("temp.txt");

    temp << database.rdbuf();
    database.close();
    temp.close();

    while (true) {
        string command;
        cout << "������ �������: ";
        cin >> command;

        if (command == "1") {
            getStudents(1);
        } else if (command == "2") {
            string path;
            cout << "������ ���� �� �����: ";
            cin >> path;

            getStudents(2, path);
        } else if (command == "3") {
            Student student;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            getInput("�������: ", student.last_name);
            getInput("��'�: ", student.first_name);
            getInput("��-�������: ", student.middle_name);
            getInput("���� ����������: ", student.date_of_birth);
            getInput("̳��� ���������� (������ ������ ��������� _): ", student.place_of_birth);
            getInput("������������: ", student.citizenship);
            getInput("ѳ������ ����: ", student.marital_status);
            getInput("̳��� ���������� (������ ������ ��������� _): ", student.place_of_residence);
            getInput("���������: ", student.faculty);
            getInput("������������ (������ ������ ��������� _): ", student.specialty);
            getInput("������������ (������ ������ ��������� _): ", student.specialization);

            addStudent(student);
        } else if (command == "4") {
            string last_name;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            getInput("������ ������� ��������: ", last_name);

            getStudentData(last_name);
        } else if (command == "5") {
            string last_name;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            getInput("������ ������� ��������: ", last_name);

            deleteStudentData(last_name);
        } else if (command == "6") {
            exitProgram();

            break;
        } else {
            cout << "���� ������� �� ����" << endl;
            break;
        }
    }

    return 0;
}
