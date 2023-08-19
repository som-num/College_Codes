#include <iostream>
#include <vector>
#include <variant>
#include <limits>
#include <algorithm>

using namespace std;

class quickSort
{
private:
    int partition(vector<variant<int, string>> &arr, int low, int high)
    {
        variant<int, string> pivot = arr[low];
        int lowIndex = low + 1;
        int highIndex = high;

        while (true)
        {

            while (lowIndex <= highIndex && arr[lowIndex] < pivot)
                lowIndex++;

            while (lowIndex <= highIndex && arr[highIndex] > pivot)
                highIndex--;

            if (lowIndex > highIndex)
                break;

            swap(arr[lowIndex], arr[highIndex], arr, lowIndex, highIndex, low);
            lowIndex++;
            highIndex--;
        }

        swap(arr[low], arr[highIndex], arr, lowIndex, highIndex, low);
        // cout << "Sorting Dataset: ";
        //     for (int i = 0; i < arr.size(); i++)
        //     {
        //         if (holds_alternative<int>(arr[i]))
        //         {
        //             if (lowIndex > highIndex && (i==lowIndex || i == highIndex))
        //                 cout << "\033[1;31m" << get<int>(arr[i]) << "\033[0m ";
        //             else
        //                 cout << get<int>(arr[i]) << " ";
        //         }
        //         else if (holds_alternative<string>(arr[i]))
        //         {
        //             if (lowIndex > highIndex && (i==lowIndex || i == highIndex))
        //                 cout << "\033[1;31m" << get<string>(arr[i]) << "\033[0m ";
        //             else
        //                 cout << get<string>(arr[i]) << " ";
        //         }
        //     }
        //     cout << "\t\t";
        //     cout << " low index: " << lowIndex << "  high index: " << highIndex << endl;

        return highIndex;
    }

    void swap(variant<int, string> &num1, variant<int, string> &num2, vector<variant<int, string>> &arr, int lowIndex, int highIndex, int low)
    {
        variant<int, string> temp = num1;
        num1 = num2;
        num2 = temp;

        // Print the dataset with swapped elements highlighted
        cout << "Sorting Dataset: ";
        for (int i = 0; i < arr.size(); i++)
        {
            if (holds_alternative<int>(arr[i]))
            {
                if (i == lowIndex || i == highIndex)
                    cout << "\033[1;31m" << get<int>(arr[i]) << "\033[0m ";
                else
                    cout << get<int>(arr[i]) << " ";
            }
            else if (holds_alternative<string>(arr[i]))
            {
                if (i == lowIndex || i == highIndex)
                    cout << "\033[1;31m" << get<string>(arr[i]) << "\033[0m ";
                else
                    cout << get<string>(arr[i]) << " ";
            }
        }
        cout << "\t\t";
        cout << " low index: " << lowIndex << "  high index: " << highIndex << " Pivot Index: " << low << endl;
    }

public:
    void quicksort(vector<variant<int, string>> &arr, int low, int high)
    {
        if (low < high)
        {
            int pivotIndex = partition(arr, low, high);
            quicksort(arr, low, pivotIndex - 1);
            quicksort(arr, pivotIndex + 1, high);
        }
    }
};

class quickSortdescending
{
private:
    int partition(vector<variant<int, string>> &arr, int low, int high)
    {
        variant<int, string> pivot = arr[low];
        int lowIndex = low + 1;
        int highIndex = high;

        while (true)
        {

            while (lowIndex <= highIndex && arr[lowIndex] > pivot)
                lowIndex++;

            while (lowIndex <= highIndex && arr[highIndex] < pivot)
                highIndex--;

            if (lowIndex > highIndex)
                break;

            swap(arr[lowIndex], arr[highIndex], arr, lowIndex, highIndex, low);
            lowIndex++;
            highIndex--;
        }

        swap(arr[low], arr[highIndex], arr, lowIndex, highIndex, low);
        // cout << "Sorting Dataset: ";
        //     for (int i = 0; i < arr.size(); i++)
        //     {
        //         if (holds_alternative<int>(arr[i]))
        //         {
        //             if (lowIndex > highIndex && (i==lowIndex || i == highIndex))
        //                 cout << "\033[1;31m" << get<int>(arr[i]) << "\033[0m ";
        //             else
        //                 cout << get<int>(arr[i]) << " ";
        //         }
        //         else if (holds_alternative<string>(arr[i]))
        //         {
        //             if (lowIndex > highIndex && (i==lowIndex || i == highIndex))
        //                 cout << "\033[1;31m" << get<string>(arr[i]) << "\033[0m ";
        //             else
        //                 cout << get<string>(arr[i]) << " ";
        //         }
        //     }
        //     cout << "\t\t";
        //     cout << " low index: " << lowIndex << "  high index: " << highIndex << endl;

        return highIndex;
    }

    void swap(variant<int, string> &num1, variant<int, string> &num2, vector<variant<int, string>> &arr, int lowIndex, int highIndex, int low)
    {
        variant<int, string> temp = num1;
        num1 = num2;
        num2 = temp;

        // Print the dataset with swapped elements highlighted
        cout << "Sorting Dataset: ";
        for (int i = 0; i < arr.size(); i++)
        {
            if (holds_alternative<int>(arr[i]))
            {
                if (i == lowIndex || i == highIndex)
                    cout << "\033[1;31m" << get<int>(arr[i]) << "\033[0m ";
                else
                    cout << get<int>(arr[i]) << " ";
            }
            else if (holds_alternative<string>(arr[i]))
            {
                if (i == lowIndex || i == highIndex)
                    cout << "\033[1;31m" << get<string>(arr[i]) << "\033[0m ";
                else
                    cout << get<string>(arr[i]) << " ";
            }
        }
        cout << "\t\t";
        cout << " low index: " << lowIndex << "  high index: " << highIndex << " Pivot Index: " << low << endl;
    }

public:
    void quicksort(vector<variant<int, string>> &arr, int low, int high)
    {
        if (low < high)
        {
            int pivotIndex = partition(arr, low, high);
            quicksort(arr, low, pivotIndex - 1);
            quicksort(arr, pivotIndex + 1, high);
        }
    }
};


class dataArray
{
private:
    // vector<variant<int, string>> data {5,2,"dasg1",3,34,"poi",4,90,99,23,"iojio",67,909,43,"dsfgiuh","poiunjh",56,1} ;
    vector<variant<int, string>> data;

public:
    void addData(variant<int, string> &num)
    {
        data.push_back(num);
    }

    void removeData(variant<int, string> &element)
    {
        auto it = find(data.begin(), data.end(), element);
        if (it != data.end())
        {
            data.erase(it);
        }
        else
        {
            cout << "Value not found in the dataset." << endl;
        }
    }

    void ascending()
    {
        quickSort sorter;
        sorter.quicksort(data, 0, data.size() - 1);
        cout << "Final sorting ";
        printDataArray();
    }

    void descending()
    {
        quickSort sorter;
        sorter.quicksort(data, 0, data.size() - 1);
        for (int i = 0; i < data.size() / 2; i++)
        {
            swap(data[i], data[data.size() - 1 - i]);
        }

        printDataArray();
    }

    void truncateData()
    {
        data.clear();
        cout << "Truncated Successfully" << endl;
        printDataArray();
    }

    void printDataArray()
    {
        cout << "Dataset: ";
        for (auto &element : data)
        {
            if (holds_alternative<int>(element))
            {
                cout << get<int>(element) << " ";
            }
            else if (holds_alternative<string>(element))
            {
                cout << get<string>(element) << " ";
            }
        }
        cout << endl;
    }

    void menu()
    {
        char choice;
        string input, input1;
        variant<int, string> num, num1;

        do
        {
            printDataArray();
            cout << "1) Add data \n";
            cout << "2) Remove data\n";
            cout << "3) Sort Ascending\n";
            cout << "4) Sort Descending\n";
            cout << "5) Truncate data\n";
            cout << "Quit? y/n\n";
            cin >> choice;

            switch (choice)
            {
            case '1':
                system("clear");
                printDataArray();
                cout << "Input Data: ";
                cin >> input;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                try
                {
                    num = stoi(input);
                }
                catch (const invalid_argument &)
                {
                    num = input;
                }

                addData(num);
                break;

            case '2':
                system("clear");
                printDataArray();
                cout << "Remove Data: ";
                cin >> input1;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                try
                {
                    num1 = stoi(input1);
                }
                catch (const invalid_argument &)
                {
                    num1 = input1;
                }

                removeData(num1);
                break;

            case '3':
                system("clear");
                ascending();
                break;

            case '4':
                system("clear");
                printDataArray();
                descending();
                break;

            case '5':
                system("clear");
                printDataArray();
                truncateData();
                break;

            default:
                break;
            }
        } while (choice != 'y');
    }
};

int main()
{
    dataArray dataset;
    dataset.menu();
}
