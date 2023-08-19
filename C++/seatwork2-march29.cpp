#include <iostream>

using namespace std;




int main(){
    int ans, size, start, end,sum=0,mult=1;
    cout<<"Size: ";cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>ans;
        arr[i] = ans;    
    }
    cout<<"Show segment"<<endl;
    cout<<"start: ";cin>>start;
    cout<<"end: ";cin>>end;
    cout<<"output: ";

    for(int i=start; i<=end;i++){
        cout<<arr[i]<<",";
        sum+=arr[i];
        mult*=arr[i];        
    }
    cout<<endl<<"sum: "<<sum<<endl;
    cout<<"mult: "<<mult<<endl;
}