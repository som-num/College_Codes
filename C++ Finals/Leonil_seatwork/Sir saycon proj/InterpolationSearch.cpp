#include <iostream>
#include <string>
using namespace std;

int interpolationSearch(const int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key)
                return low;
            return -1;
        }

        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == key)
            return pos;

        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

void example1() {
    int n;
    cout << "Example 1\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the integer elements (in sorted order): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    int index = interpolationSearch(arr, n, key);
    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }
}

int interpolationSearch(const string arr[], int n, const string& key) {
    int low = 0;
    int high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key)
                return low;
            return -1;
        }

        int pos = low + ((key.compare(arr[low])) * (high - low)) / (arr[high].compare(arr[low]));

        if (arr[pos] == key)
            return pos;

        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

void example2() {
    int n;
    cout << "Example 2\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    string arr[n];
    cout << "Enter the string elements (in sorted order): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string key;
    cout << "Enter the element to search: ";
    cin >> key;

    int index = interpolationSearch(arr, n, key);
    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }
}

int main() {
    system("clear");
    example1();
    cout << "\n\n";
    example2();

    return 0;
}
