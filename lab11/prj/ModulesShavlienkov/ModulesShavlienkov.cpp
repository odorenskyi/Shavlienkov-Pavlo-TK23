#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>

#include "struct_type_project_8.h"

using namespace std;

void getStudents(int status, string path = "") {
    try {
        if (status == 1) {
            ifstream file("temp.txt");
            string content;

            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    content += line + "\n";
                }
            } else {
                throw runtime_error("Файл бази даних не знайдено!");
            }

            istringstream iss(content);
            string line;
            vector<string> labels = {
                "Прізвище", "Ім'я", "По-батькові", "Дата народження",
                "Місце народження", "Громадянство", "Сімейний стан",
                "Місце проживання", "Факультет", "Спеціальність", "Спеціалізація"
            };

            cout << "-----------------" << endl;

            while (getline(iss, line, '\n')) {
                istringstream lineStream(line);
                string word;
                int labelIndex = 0;

                while (lineStream >> word) {
                    cout << labels[labelIndex] << ": " << word << endl;
                    ++labelIndex;
                    if (labelIndex >= labels.size()) {
                        labelIndex = 0;
                    }
                }

                cout << "-----------------" << endl;
            }

        } else if (status == 2 && !path.empty()) {
            ifstream file("temp.txt");
            string content;

            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    content += line + "\n";
                }
            } else {
                throw runtime_error("Файл бази даних не знайдено!");
            }

            ofstream output(path);
            istringstream iss(content);
            string line;
            vector<string> labels = {
                "Прізвище", "Ім'я", "По-батькові", "Дата народження",
                "Місце народження", "Громадянство", "Сімейний стан",
                "Місце проживання", "Факультет", "Спеціальність", "Спеціалізація"
            };

            output << "-----------------" << endl;

            while (getline(iss, line, '\n')) {
                istringstream lineStream(line);
                string word;
                int labelIndex = 0;

                while (lineStream >> word) {
                    output << labels[labelIndex] << ": " << word << endl;
                    ++labelIndex;
                    if (labelIndex >= labels.size()) {
                        labelIndex = 0;
                    }
                }

                output << "-----------------" << endl;
            }
        }
    } catch (const exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }
}

void addStudent(Student student) {
    ofstream output("temp.txt", ios_base::app);
    output << student.last_name << " " << student.first_name << " " << student.middle_name << " "
           << student.place_of_birth << " " << student.date_of_birth << " " << student.citizenship << " "
           << student.marital_status << " " << student.place_of_residence << " " << student.faculty << " "
           << student.specialty << " " << student.specialization << "\n";
    output.close();

    cout << "Дані студента успішно записані" << endl;
}
