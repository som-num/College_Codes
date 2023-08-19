#include <iostream>
using namespace std;

int num[5],targetNum;
void checker(int targetNum);
bool primeCheck(int num);

int main(){
    
    // cout<< "enter 5 numbers: "<<endl;
    // for(int i=0;i<=4;i++){
    //     cin>>num[i];
    // }
    cout<<"Enter Target Number: ";cin>>targetNum;
    checker(targetNum);
    if (primeCheck(targetNum))
        cout<<"prime"<<endl;
    else
        cout<<"Composite"<<endl;


}

void checker(int targetNum){
    int number;
    for(int i=0;i<=4;i++){
        for(int l=0;l<=4;l++){
            number = (num[i]+num[l]);

            if(number == targetNum && i < l){
                cout<< i <<endl;
                cout<< l <<endl;
                
                
            }
            // cout<< num[i] << "\t" <<num[l]<<endl;
            
        }

        
    }

}


bool primeCheck(int num){
    if(num<2){
        return false;

    }
    for(int factor = 2;factor<num;factor++){
        if(num%factor==0){
            return false;
        }
     
        }
        return true;
    }
    
