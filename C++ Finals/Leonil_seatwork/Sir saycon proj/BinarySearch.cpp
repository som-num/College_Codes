#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void example1() {
    int n;
    cout<<"Example 1\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements (in sorted order): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int index = binarySearch(arr, 0, n - 1, key);
    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }
}
int binarySearch(string arr[], int low, int high, string key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void example2() {
    int n;
    cout<<"Example 2\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    string arr[n];
    cout << "Enter the elements (in sorted order): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string key;
    cout << "Enter the element to search: ";
    cin >> key;

    int index = binarySearch(arr, 0, n - 1, key);
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