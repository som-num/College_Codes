#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}
int linearSearch(string arr[], int n, string key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

void example1() {
    int n;
    cout<<"Example1\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    string arr[n];
    cout << "Enter the string elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string key;
    cout << "Enter the element to search: ";
    cin >> key;

    int index = linearSearch(arr, n, key);
    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }
}

void example2() {
    int n;
    cout<<"Example2\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the int elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int index = linearSearch(arr, n, key);
    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }
    }

int main(){
    system("clear");
    example1();
    cout<<"\n\n";
    example2();
}