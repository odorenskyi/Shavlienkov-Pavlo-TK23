#include <cmath>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <sstream>

using namespace std;

float s_calculation(int x, int y, int z) {
    float S = pow(z + y + z, 2.0) - sqrt(fabs((2.0 * M_PI * sqrt((1.0/2.0) * z)) / (y + (4.0 * (pow(x, 3.0) + cos(z)))) ));
    return S;
}

void printInfoTornado(float speed) {
    if(64 <= speed && 116 >= speed) {
        cout << "�������� ������� �� ������ ������: " << "F0" << endl << "������� ����������: 38,9%" << endl;
    } else if(117 <= speed && 180 >= speed) {
        cout << "�������� ������� �� ������ ������: " << "F1" << endl << "������� ����������: 35,6%" << endl;
    } else if(181 <= speed && 253 >= speed) {
        cout << "�������� ������� �� ������ ������: " << "F2" << endl << "������� ����������: 19,4%" << endl;
    } else if(254 <= speed && 332 >= speed) {
        cout << "�������� ������� �� ������ ������: " << "F3" << endl << "������� ����������: 4,9%" << endl;
    } else if(333 <= speed && 418 >= speed) {
        cout << "�������� ������� �� ������ ������: " << "F4" << endl << "������� ����������: 1,1%" << endl;
    } else if(419 <= speed && 512 >= speed) {
        cout << "�������� ������� �� ������ ������: " << "F5" << endl << "������� ����������: ������ 0,1%" << endl;
    } else {
        cout << "�� ������� � �������" << endl;
    }
}

void avgTemp(float arr[]) {

    float sum_temp = 0;

    for(int i = 0; i < 6; i++) {
        sum_temp += arr[i];
    }

    cout << "�����: " << (sum_temp / 6) << " �C" << endl;
    cout << "����������: " << ((sum_temp / 6) * (9 / 5)) + 32 << " �F" << endl;
}

void countBits(int N) {

    int counter = 0;

    if((N & 1) == 0) {

        while (N > 0) {
            int bit = N % 2;
            counter += (bit == 0) ? 1 : 0;
            N /= 2;
        }

        cout << "ʳ������ �������� ���� �������: " << counter << endl;

    } else {

        while (N > 0) {
            int bit = N % 2;
            counter += (bit != 0) ? 1 : 0;
            N /= 2;
        }

        cout << "ʳ������ �������� ������� �������: " << counter << endl;
    }

}

void writeAuthorInfo() {
    try {
        string inputFilename = "input.txt";
        ifstream file(inputFilename);

        if (!file.is_open()) {
            throw runtime_error("�� ������� ������� ����.");
        }

        char c;

        int couter = 0;

        while (file.get(c)) {
            if ((c >= '�' && c <= '�') || c == '�' || c == '�' || c == '�' || c == '�') {
                couter++;
            }
        }

        file.close();

        string inputFilename2 = "input2.txt";
        ifstream file2(inputFilename2);
        string content;

        if (file2.is_open()) {
            string line2;

            while (getline(file2, line2)) {
                content += line2;
            }

            file2.close();
        } else {
            throw runtime_error("�� ������� ������� ����.");
        }

        string text = "���� ����� �� ������ ���� �� ����\n"
                      "��� � �� ������ ����� ����!\n"
                      "³� ���� ������� �� ������\n"
                      "���� ���� �� ���� �������.\n"
                      "���� ������� �������� � ������,\n"
                      "�, ����, ��� �� ��� �������,\n"
                      "� ���� - ����� ����� � �������,\n"
                      "� ����� ����� ��������� �����.\n";

        string line3;

        istringstream iss(text);

        bool found = false;

        while (getline(iss, line3)) {
            if (line3 == content) {
                found = true;
                break;
            }
        }

        string authorInfoFilename = "author_info.txt";

        ofstream outFile(authorInfoFilename);

        if (outFile.is_open()) {
            outFile << "�����: ����� ��������\n"
                       "��������/����������: ����\n"
                       "̳���: �������������\n"
                       "�����: ������\n"
                       "г� ��������: 2024\n";
            outFile << couter << "\n";

            if (found) {
                outFile << "��������";
            } else {
                outFile << "�� ��������";
            }

            outFile.close();
            cout << "��������� ���������� ���� �������� � ���� '" << authorInfoFilename << "'." << endl;
        } else {
            throw runtime_error("��������� ������� ���� ��� ������.");
        }

    } catch (const exception& e) {
        cout << "�������: " << e.what() << endl;
    }
}

void writeFileInfo() {
    try {
        ofstream file("input3.txt", ios_base::out | ios_base::app);

        if (!file.is_open()) {
            throw runtime_error("�� ������� ������� ���� ��� ������!");
        }

        file.seekp(0, ios_base::end);
        streampos fileSize = file.tellp();

        time_t currentTime = time(nullptr);
        tm* localTime = localtime(&currentTime);

        char buffer[80];
        strftime(buffer, sizeof(buffer), "%c", localTime);

        file << "\n";
        file << "��'�� ����� (� ������): " << fileSize << endl;
        file << "���� � ��� ��������: " << buffer << endl;

        file.close();

        cout << "���������� ������ �� �����!" << endl;
    } catch (const exception& e) {
        cout << "�������: " << e.what() << endl;
    }
}

void writeCalculations(int x, int y, int z, int b) {
    try {
        ofstream file("output.txt");

        if (!file.is_open()) {
            throw runtime_error("�� ������� ������� ���� ��� ������!");
        }

        string binary = "";

        while (b != 0) {

            if ((b % 2) == 0) {
                binary += "0";
            } else {
                binary += "1";
            }

            b = b / 2;
        }

        int left = 0;
        int right = binary.length() - 1;

        while (left < right) {

            char temp = binary[left];
            binary[left] = binary[right];
            binary[right] = temp;

            ++left;
            --right;
        }

        file << s_calculation(x, y, z) << "\n";
        file << binary;

        cout << "���������� ������ �� �����";

    } catch (const exception& e) {
        cout << "�������: " << e.what() << endl;
    }
}
