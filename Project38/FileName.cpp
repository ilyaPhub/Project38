#include <iostream>
#include <string>

using namespace std;

class ArraySizeException {
public:
    const char* what() const {
        return "����� ������� ���� ������� 4x4!";
    }
};

class ArrayDataException {
    string message;
public:
    ArrayDataException(int row, int col, const string& value) {
        message = "��������� ��� � ������� (" + to_string(row) + ", " + to_string(col) + "): \"" + value + "\"";
    }
    const char* what() const {
        return message.c_str();
    }
};

class ArrayValueCalculator {
public:
    static int doCalc(const string array[4][4]) {
        int sum = 0;

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                try {
                    sum += stoi(array[i][j]); 
                }
                catch (invalid_argument&) {
                    throw ArrayDataException(i, j, array[i][j]);
                }
            }
        }

        return sum;
    }
};

int main() {
    try {
        string array[4][4] = {
            {"1", "2", "3", "4"},
            {"5", "6", "7", "8"},
            {"9", "10", "11", "12"},
            {"13", "14", "15", "16"}
        };

        int result = ArrayValueCalculator::doCalc(array);
        cout << "��������� ����������: " << result << endl;

    }
    catch (const ArraySizeException& e) {
        cerr << "������� ������ ������: " << e.what() << endl;
    }
    catch (const ArrayDataException& e) {
        cerr << "������� ����� ������: " << e.what() << endl;
    }

    return 0;
}
