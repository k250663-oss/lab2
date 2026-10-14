
#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;

    cout << "Enter number of passengers: ";
    cin >> n;

    if(n <= 0) {
        cout << "Invalid number of passengers";
        return 0;
    }

    string* names = new string[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter passenger name: ";
        cin >> ws;
        getline(cin, names[i]);
    }

    cout << "\nReverse boarding sequence:\n";

    for(int i = n - 1; i >= 0; i--) {
        cout << names[i] << endl;
    }

    delete[] names;
    names = nullptr;

    return 0;
}
