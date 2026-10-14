
#include<iostream>
using namespace std;

int main() {
    int sizes[3] = {2, 4, 6};
    int** seats = new int*[3];

    for(int i = 0; i < 3; i++) {
        seats[i] = new int[sizes[i]];

        for(int j = 0; j < sizes[i]; j++) {
            seats[i][j] = 0;
        }
    }

    int row, seat;

    while(true) {
        cout << "\nEnter row (0=First, 1=Business, 2=Economy)";
        cout << " or -1 to exit: ";
        cin >> row;

        if(row == -1) {
            break;
        }

        if(row < 0 || row > 2) {
            cout << "Invalid row!\n";
            continue;
        }

        cout << "Enter seat number: ";
        cin >> seat;

        if(seat < 0 || seat >= sizes[row]) {
            if(row == 0) {
                cout << "Error: First Class has only 2 seat slots!\n";
            }
            else if(row == 1) {
                cout << "Error: Business Class has only 4 seat slots!\n";
            }
            else {
                cout << "Error: Economy Class has only 6 seat slots!\n";
            }
            continue;
        }

        if(seats[row][seat] == 1) {
            cout << "Seat already reserved!\n";
        }
        else {
            seats[row][seat] = 1;
            cout << "Seat reserved successfully!\n";
        }
    }

    for(int i = 0; i < 3; i++) {
        delete[] seats[i];
    }
    delete[] seats;

    return 0;
}
