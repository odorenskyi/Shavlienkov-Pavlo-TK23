#ifndef MODULESSHAVLIENKOV_H_INCLUDED
#define MODULESSHAVLIENKOV_H_INCLUDED

#include "../App/struct_type_project_8.h"
#include <string>

using namespace std;

void getStudents(int, string = "");
void addStudent(Student);
void getStudentData(string last_name = "");
void deleteStudentData(string last_name = "");
void exitProgram();

#endif // MODULESSHAVLIENKOV_H_INCLUDED
