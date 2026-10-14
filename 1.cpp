
#include<iostream>
using namespace std;

int main() {
    int shelf[6] = {102, 0, 305, 0, 401, 908};

    cout << "Before compacting: ";
    for(int i = 0; i < 6; i++) {
        cout << shelf[i] << " ";
    }

    int j = 0;

    for(int i = 0; i < 6; i++) {
        if(shelf[i] != 0) {
            shelf[j] = shelf[i];
            j++;
        }
    }

    while(j < 6) {
        shelf[j] = 0;
        j++;
    }

    cout << "\nAfter compacting: ";
    for(int i = 0; i < 6; i++) {
        cout << shelf[i] << " ";
    }

    return 0;
}
