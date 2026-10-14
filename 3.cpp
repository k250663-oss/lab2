
#include<iostream>
#include<string>
using namespace std;

void addItem(string*& arr, int& size, int& capacity, string item) {
    if(size == capacity) {
        int newCapacity = capacity * 2;
        string* temp = new string[newCapacity];

        cout << "Resizing: " << capacity
             << " -> " << newCapacity << endl;

        for(int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
        capacity = newCapacity;
    }

    arr[size] = item;
    size++;
}

int main() {
    int capacity = 3;
    int size = 0;

    string* items = new string[capacity];

    for(int i = 0; i < 7; i++) {
        string item;
        cout << "Enter item: ";
        cin >> item;

        addItem(items, size, capacity, item);
    }

    cout << "\nShopping cart:\n";
    for(int i = 0; i < size; i++) {
        cout << items[i] << endl;
    }

    delete[] items;

    return 0;
}
