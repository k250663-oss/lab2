
#include<iostream>
using namespace std;

class SafeCommandCenter {
private:
    int* commands;
    int size;

public:
    SafeCommandCenter() {
        size = 5;
        commands = new int[size];

        for(int i = 0; i < size; i++) {
            commands[i] = 0;
        }
    }

    void safeWrite(int index, int value) {
        if(index < 0 || index >= size) {
            cout << "CRITICAL ERROR: Invalid index!\n";
            cout << "Rover Emergency Braking Triggered!\n";
            return;
        }

        if(value < 0 || value > 100) {
            cout << "CRITICAL ERROR: Invalid speed!\n";
            cout << "Rover Emergency Braking Triggered!\n";
            return;
        }

        commands[index] = value;
        cout << "Command saved successfully.\n";
    }

    void display() {
        for(int i = 0; i < size; i++) {
            cout << commands[i] << " ";
        }
        cout << endl;
    }

    ~SafeCommandCenter() {
        delete[] commands;
    }
};

int main() {
    SafeCommandCenter rover;

    rover.safeWrite(0, 50);
    rover.safeWrite(2, 80);
    rover.safeWrite(5, 60);
    rover.safeWrite(1, -10);

    cout << "Commands: ";
    rover.display();

    return 0;
}
