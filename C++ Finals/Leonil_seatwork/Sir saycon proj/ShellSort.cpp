#include <iostream>
#include <string>
using namespace std;

void shellSort(string arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            string temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void example1() {
    int n;
    cout<<"Example 1\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    string arr[n];
    cout << "Enter the string elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    shellSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void example2() {
    int n;
    cout<<"Example 2\n";
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the int elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    shellSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main(){
    system("clear");
    example1();
    cout<<"\n\n";
    example2();
}