#include <iostream>

using namespace std;


int sumOdd,sumEven,arr[10],ans,Oddsum,EvenSum;


int main(){
    cout<<"Enter 10 numbers: "; 
    for(int i=0;i<10;i++){
        cin>>ans;
        arr[i] = ans;    
    }
    for(int i=0;i<10;i++){
         if(i%2==0){
            sumEven+=arr[i];
        }
        else if(i%2 !=0){
            sumOdd+=arr[i];
        }
        else if(arr[i]%2==0){
            EvenSum+=arr[i];
        }
        else if(arr[i]%2!=0){
            Oddsum+=arr[i];
        }    
    }
    // for(int i=0;i<10;i++){
    //      if(arr[i]%2==0){
    //         EvenSum+=arr[i];
    //     }
    //     else{
    //         Oddsum+=arr[i];
    //     }    
    // }

       
    cout<<"Sum of even indexes: "<<sumEven<<endl;
    cout<<"Sum of odd indexes: "<<sumOdd<<endl;
    cout<<"Sum of even values: "<<EvenSum<<endl;
    cout<<"Sum of odd values: "<<Oddsum<<endl;

}
