#include <iostream>
#include <vector>
#include <variant>
#include <limits>
#include <algorithm>

using namespace std;

class quickSort{
    private:
    void partition(vector<variant<int, string>>& arr, int low, int high, vector<variant<int, string>>& less, vector<variant<int, string>>& greater) {
        variant<int, string> pivot = arr[low];

        for (int i = low + 1; i <= high; i++) {
            if (arr[i] < pivot) {
                less.push_back(arr[i]);
            }
            else {
                greater.push_back(arr[i]);
            }
        }
    }
        
    vector<variant<int, string>> sortedLess;
    vector<variant<int, string>> sortedGreater;
public:
    void quicksort(vector<variant<int, string>>& arr, vector<variant<int, string>>& sortedArr) {
        if (arr.size() <= 1) {
            sortedArr = arr;
            return;
        }

        variant<int, string> pivot = arr[0];
        vector<variant<int, string>> less;
        vector<variant<int, string>> greater;
        
        partition(arr, 1, arr.size() - 1, less, greater);
        

        
        quicksort(less, sortedLess);

    

        
        quicksort(greater, sortedGreater);

        sortedArr.insert(sortedArr.end(), sortedLess.begin(), sortedLess.end());
        sortedArr.push_back(pivot);
        sortedArr.insert(sortedArr.end(), sortedGreater.begin(), sortedGreater.end());
    }

    void printSortedLess(){
         cout << "Less than pivot sub-array: ";
        for( auto& element: sortedLess)
        {
            if(holds_alternative<int>(element)){
                cout << get<int>(element)<< " ";
            }
            else if(holds_alternative<string>(element)){
                cout<<get<string>(element)<<" ";
            }
        }
        cout << endl;
    }

    void printSortedGreater(){
        cout << "Greater than pivot sub-array: ";
        for( auto& element: sortedGreater)
        {
            if(holds_alternative<int>(element)){
                cout << get<int>(element)<< " ";
            }
            else if(holds_alternative<string>(element)){
                cout<<get<string>(element)<<" ";
            }
        }
        cout << endl;

    }
};


class dataArray
{
    private:
    vector<variant<int,string>> data;
    vector<variant<int,string>> sortedArr;
    public:
    
    // Add data to the dataset
        void addData(variant<int,string>& num)
        {
        data.push_back(num);
        printDataArray();
        }


    // Remove data from the dataset
    void removeData(variant<int,string>& element)
    {
        auto it = find(data.begin(), data.end(), element);
        if (it != data.end()){
            data.erase(it);
            // cout<< "Value " << element << " removed from the dataset." << endl;
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
        sorter.quicksort(data,sortedArr);
        sorter.printSortedLess();    
        sorter.printSortedGreater();    
        printDataArray();

    }

    // Sort the dataset in descending order
    void descending()
    {
        quickSort sorter;
        sorter.quicksort(data,sortedArr);
        // reverse(data.begin(), data.end());
        for (int i = 0; i < data.size() / 2; i++) {
        swap(data[i], data[data.size() - 1 - i]);
    }

        printDataArray();
    }

    // Truncate the dataset, removing all data
    void truncateData(){

        data.clear();
        cout << "Truncated Successfully" << endl;class quickSort{
    private:
    int partition(vector<variant<int, string>>& arr, int low, int high)
    {
        // Selecting the first element as pivot
        variant<int,string> pivot = arr[low];
        
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
    void swap(variant<int,string>& num1, variant<int, string>& num2)
    {
        variant<int,string> temp = num1;
        num1= num2;
        num2 = temp;
    }

    public:

    void quicksort(vector<variant<int,string>>& arr, int low, int high)
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
        printDataArray();
        }

    void debig(){
        cout<<"hatdog"<<endl;
    }
    // Print the current state of the dataset
    void printDataArray()
    {
        cout << "Dataset: ";
        for( auto& element: data)
        {
            if(holds_alternative<int>(element)){
                cout << get<int>(element)<< " ";
            }
            else if(holds_alternative<string>(element)){
                cout<<get<string>(element)<<" ";
            }
        }
        cout << endl;

    }
    void printSortedDataArray()
    {
        cout << "Dataset: ";
        for( auto& element: sortedArr)
        {
            if(holds_alternative<int>(element)){
                cout << get<int>(element)<< " ";
            }
            else if(holds_alternative<string>(element)){
                cout<<get<string>(element)<<" ";
            }
        }
        cout << endl;

    }

    void menu(){
        char choice;
        string input,input1;
        variant<int,string> num,num1;
        
        do
        {
            // system("clear");
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
                cout<<"Input Data: ";
                cin >> input;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                try
                {
                    num = stoi(input);
                }
                catch(const invalid_argument&)
                {
                    num=input;
                }
                
                addData(num);
                break;

            case '2':
            system("clear");
                printDataArray();
                cout<<"Remove Data: ";
                cin >> input1;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                try
                {
                    num1=stoi(input1);
                }
                catch(const invalid_argument&)
                {
                    num1=input1;
                }
                
                removeData(num1);
                break;
            
            case '3':
            system("clear");
                printDataArray();
                ascending();
                printSortedDataArray();
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