#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void exitProgram() {
    ifstream temp("temp.txt");
    ofstream database("database.txt");
    database << temp.rdbuf();
    temp.close();
    database.close();
    remove("temp.txt");
}
