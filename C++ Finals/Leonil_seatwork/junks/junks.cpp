#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class QuickSort{
    private:
    int partition(vector<int> arr, int low , int high){
        int pivot = arr[low];
        int lowInd = low+1;
        int highInd = high;

            while (lowInd<=highInd){
                while(lowInd <= highInd && arr[lowInd] <= pivot){
                    lowInd++;
                }

                while ( lowInd <= highInd && arr[highInd] > pivot){
                    highInd--;
                }

                if (lowInd < highInd ){
                    swap(arr[lowInd], arr[highInd]);
                }
            }
            swap(arr[low], arr[highInd]);

            return highInd;
    }
        void swap( int a, int b){
            int temp = a;
            a= b;
            b= temp;
        }
    public:
    void sort(vector<int> arr, int low, int high){
        if(low < high){
            int pivotIndex = partition(arr, low, high);

            sort(arr, low, pivotIndex -1 );

            sort(arr, pivotIndex + 1, high);
        }
    }
};
class DataCollection
{
private:
    vector<int> data;

public:
    void addData(int num)
    {
        data.push_back(num);
        printDataCollection();
    }

    void addData(string num)
    {   
        int newNum = stoi(num);
        data.push_back(newNum);
          cout << "String data: " << num << " added to the dataset." << endl;
        printDataCollection();
    }

    void removeData(int num){
        auto it = find(data.begin(), data.end(), num);
        if (it != data.end()){
            data.erase(it);
            cout<< "Value " << num << " removed from the dataset." << endl;
        }
        else {
            cout << "Value not found in the dataset." << endl;
        }
        printDataCollection();
    }

    void truncateData(){
        data.clear();
        cout << "Dataset truncated." << endl;
        printDataCollection();
    }

    void printDataCollection() {
        cout << "Dataset: ";
        for (const auto& value : data) {
            cout << value << " ";
        }
        cout << endl;
    }


};



int main(){
    DataCollection yawa;
    int num,numx,num1;
    cout<<"ENter number to add: "; cin>> num;
    yawa.addData(num);
    cin>>num1;
    yawa.addData(num1);
    cout<<"Enter number to remove: "; cin >> numx;
    yawa.removeData(numx);
    return main();
}
