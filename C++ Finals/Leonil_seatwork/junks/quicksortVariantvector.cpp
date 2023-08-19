#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class quickSort{
    private:
    int partition(vector<int>& arr, int low, int high)
    {
        // Selecting the first element as pivot
        int pivot = arr[low];
        
        // Initialize the low and high index
        int lowIndex = low +1;
        int highIndex = high;

        // loop until low and high index meet
        while(true)
        {
            // moves the low index to the right until finding value greater than pivot
            while(lowIndex <= highIndex && arr[lowIndex] < pivot)
            {
                lowIndex++;
            }

            //moves the high index to the left until finding value less than the pivot
            while(lowIndex <= highIndex && arr[highIndex] > pivot)
            {
                highIndex--;
            }

            
            if(lowIndex > highIndex)
            {
                break;                
            }
            // swaps value of the low and high index if low index is still less than high index after the loop
                swap(arr[lowIndex], arr[highIndex]);
                lowIndex++;
                highIndex--;

        }

        // swap the pivot and value of high index
        swap(arr[low], arr[highIndex]);
        return highIndex;

    }

    // swap function to exchange values
    void swap(int& num1, int& num2)
    {
        int temp = num1;
        num1= num2;
        num2 = temp;
    }

    public:

    void quicksort(vector<int>& arr, int low, int high)
    {
        //checks if there are at least 2 elements in the array
        if(low < high)
        {

            //sets the pivot index
            int pivotIndex = partition(arr,low,high);

            //sort subarrary of less value than pivot to the left
            quicksort(arr, low, pivotIndex - 1);

            //sort subarray of greater value than pivot to the right
            quicksort(arr,pivotIndex + 1, high);
        }
    }
};

class dataArray
{
    private:
    vector<int> data;
    public:
    
    // Add data to the dataset
        void addData(int num)
        {
        data.push_back(num);
        printDataArray();
        }

        void addData(string num)
        {
        int newNum = stoi(num);
        data.push_back(newNum);
        cout<<"Added string: \n";
        printDataArray();
        }

    // Remove data from the dataset
    void removeData(int num)
    {
        auto it = find(data.begin(), data.end(), num);
        if (it != data.end()){
            data.erase(it);
            cout<< "Value " << num << " removed from the dataset." << endl;
        }
        else {
            cout << "Value not found in the dataset." << endl;
        }
        printDataArray();
    }

    // Sort the dataset in ascending order 
    void ascending()
    {
        quickSort sorter;
        sorter.quicksort(data, 0,data.size() -1 );
        printDataArray();

    }

    // Sort the dataset in descending order
    void descending()
    {
        quickSort sorter;
        sorter.quicksort(data, 0, data.size() - 1);
        // reverse(data.begin(), data.end());
        for (int i = 0; i < data.size() / 2; i++) {
        swap(data[i], data[data.size() - 1 - i]);
    }

        printDataArray();
    }

    // Truncate the dataset, removing all data
    void truncateData(){

        data.clear();
        cout << "Truncated Successfully" << endl;
        printDataArray();
        }

    void debig(){
        cout<<"hatdog"<<endl;
    }
    // Print the current state of the dataset
    void printDataArray()
    {
        cout << "Dataset: ";
        for ( auto value : data) {
            cout << value << " ";
        }
        cout << endl;

    }

    void menu(){
        char choice;
        do
        {
            system("clear");
            printDataArray();
            cout<<"1) Add data \n";
            cout<<"2) Remove data\n";
            cout<<"3) Sort Ascending\n";
            cout<<"4) Sort Descending\n";
            cout<<"5) Truncate data\n";
            cout<<"Quit? y/n\n";
            cin >> choice;

            switch (choice)
            {
            case '1':
                system("clear");
                printDataArray();
                int num;
                cout<<"Input Data: ";
                cin>>num;
                addData(num);
                break;

            case '2':
            system("clear");
                printDataArray();
                int num1;
                cout<<"Remove Data: ";
                cin >> num1;
                removeData(num1);
                break;
            
            case '3':
            system("clear");
                printDataArray();
                ascending();
                break;

            case '4':
            system("clear");
                printDataArray();
                descending();
                break;
            
            case '5':
                printDataArray();
                truncateData();
                break;
            
            default:
                break;
            }
        }while(choice != 'y');
    }
};




int main(){
    dataArray dataset;
    dataset.menu();
    
}