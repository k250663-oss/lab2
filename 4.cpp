
#include<iostream>
using namespace std;

void addNewStudent(int**& currentGrades, int& currentN) {
    int** temp = new int*[currentN + 1];

    for(int i = 0; i < currentN + 1; i++) {
        temp[i] = new int[3];
    }

    cout << "Old memory address: "
         << currentGrades << endl;

    for(int i = 0; i < currentN; i++) {
        for(int j = 0; j < 3; j++) {
            temp[i][j] = currentGrades[i][j];
        }
    }

    cout << "Enter grades for new student:\n";
    for(int j = 0; j < 3; j++) {
        cin >> temp[currentN][j];
    }

    for(int i = 0; i < currentN; i++) {
        delete[] currentGrades[i];
    }
    delete[] currentGrades;

    currentGrades = temp;
    currentN++;

    cout << "New memory address: "
         << currentGrades << endl;
    cout << "Student added successfully!\n";
}

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    if(n <= 0) {
        cout << "Invalid number of students";
        return 0;
    }

    int** grades = new int*[n];

    for(int i = 0; i < n; i++) {
        grades[i] = new int[3];

        cout << "Enter 3 grades for student "
             << i + 1 << ": ";

        for(int j = 0; j < 3; j++) {
            cin >> grades[i][j];
        }
    }

    addNewStudent(grades, n);

    cout << "\nUpdated grade table:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cout << grades[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < n; i++) {
        delete[] grades[i];
    }
    delete[] grades;

    return 0;
}
