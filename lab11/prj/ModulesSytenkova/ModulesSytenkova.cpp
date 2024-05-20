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
            throw runtime_error("���� ���� ����� �� ��������!");
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
                cout << "�������: " << elements[0] << endl;
                cout << "��'�: " << elements[1] << endl;
                cout << "��-�������: " << elements[2] << endl;
                cout << "̳��� ����������: " << elements[3] << endl;
                cout << "���� ����������: " << elements[4] << endl;
                cout << "������������: " << elements[5] << endl;
                cout << "ѳ������ ����: " << elements[6] << endl;
                cout << "̳��� ����������: " << elements[7] << endl;
                cout << "���������: " << elements[8] << endl;
                cout << "������������: " << elements[9] << endl;
                cout << "������������: " << elements[10] << endl;
                found = true;
            }

            cout << "-----------------" << endl;
        }
        file.close();

        if (!found) {
            throw runtime_error("������� ������� � ��� �����!");
        }
    } catch (const runtime_error& e) {
        cerr << "�������: " << e.what() << endl;
    }
}

void deleteStudentData(string last_name = "") {
    try {
        ifstream file("temp.txt");
        if (!file.is_open()) {
            throw runtime_error("���� ���� ����� �� ��������!");
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
            throw runtime_error("������� ������� � ��� �����!");
        } else {
            cout << "��� �������� ��������!" << endl;
        }

        temp_file.close();

        remove("temp.txt");
        rename("temp_tmp.txt", "temp.txt");
    } catch (const runtime_error& e) {
        cerr << "�������: " << e.what() << endl;
    }
}
