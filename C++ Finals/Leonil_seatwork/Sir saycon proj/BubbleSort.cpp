#include <iostream>
#include <string>
using namespace std;

void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void example1(){
    int n;
    cout<<"Example 1 \n";
    cout << "Enter the number of elements: ";
    cin >> n;

    string arr[n];
    cout << "Enter the string elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void example2(){
    int n;
    cout<<"Example2 \n";
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the int elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    system("clear");
    example1();
    cout<<"\n\n";
    example2();     
    return 0;
}
