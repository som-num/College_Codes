#include <iostream>
#include <unordered_map>
using namespace std;

void example1() {
    int n;
    cout<<"Example 1\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    unordered_map<string, int> hashTable;
    cout << "Enter the elements (key value pairs): ";
    for (int i = 0; i < n; i++) {
        string key;
        int value;
        cin >> key >> value;
        hashTable[key] = value;
    }

    string key;
    cout << "Enter the key to search: ";
    cin >> key;

    if (hashTable.count(key) > 0) {
        cout << "Value found: " << hashTable[key] << endl;
    } else {
        cout << "Value not found" << endl;
    }
}

void example2() {
    int n;
    cout<<"Example 2\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    unordered_map<int, string> hashTable;
    cout << "Enter the elements (key value pairs): ";
    for (int i = 0; i < n; i++) {
        int key;
        string value;
        cin >> key >> value;
        hashTable[key] = value;
    }

    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    if (hashTable.count(key) > 0) {
        cout << "Value found: " << hashTable[key] << endl;
    } else {
        cout << "Value not found" << endl;
    }
}

int main(){
    system("clear");
    example1();
    cout<<"\n\n";
    example2();
}