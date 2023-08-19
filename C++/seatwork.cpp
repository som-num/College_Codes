#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;



void mult(float num1, float num2);
void add(float num1, float num2);
void sub(float num1, float num2);
void div(float num1, float num2);
void mod(int num1, int num2);
void arithmethic(float num1,float num2);
void logicalTable(float num1, float num2);
void convert();
void swap(float *ptr);



int main(){
    int ans;
 cout<<"Select a Number:"<<endl;
 cout<<"1) Arithmethic"<<endl;
 cout<<"2) Logical table"<<endl;
 cout<<"3) convert"<<endl;
 cout<<"4) pointer"<<endl;
 cin>>ans;
// cout<<ans<<endl;

switch (ans) {
    int Num1,Num2;
    case 1:
    
        cout<<"Enter Num1: ";cin>>Num1;
        cout<<"Enter Num2: ";cin>>Num2;
        arithmethic(Num1,Num2);
    
    case 2:
   
        cout<<"Enter Num1: ";cin>>Num1;
        cout<<"Enter Num2: ";cin>>Num2;
        logicalTable(Num1,Num2);
    
    case 3:
        convert();
        break;
    
    case 4:
        float a,b,c,d;
        
        cout<<"Input a:";cin>>a;
        cout<<"Input b:";cin>>b;
        cout<<"Input c:";cin>>c;
        cout<<"Input d:";cin>>d;
        float *ptr = &a;
        swap(ptr);

        cout <<" a: "<< a <<" b: "<< b <<" c: "<< c <<" d: "<<d;

} 

}

void swap(float *ptr){
    // int temp = *ptr;
    // *ptr = *(ptr+1);
    // *(ptr+1)=*(ptr+2);
    // *(ptr+3)=*(ptr+4);
    // *(ptr+4)=temp;
     float temp = *ptr;
    *ptr = *(ptr+2);
    *(ptr+2) = temp;
    temp = *(ptr+1);
    *(ptr+1) = *(ptr+3);
    *(ptr+3) = temp;

}



void convert(){
    string name;
    cout<< "Please Enter Name: "<<endl;
    cin.ignore();
    getline(cin,name);

    for(int i=0;i<= name.length();i++){
        if(name[i]==' '){
            cout<<' ';
        }
        cout<< int(name[i]);

        // cout<< name[i]<<endl;

    }
}
void logicalTable(float num1, float num2){
    cout<< "Lgocial Table" << endl;
    cout<<left<< setw(15)<< "Expression"<<left<<setw(10)<<"Value"<<endl;
    cout<<left<< setw(15)<< "Num1"<<left<<setw(10)<< num1 <<endl;
    cout<<left<< setw(15)<< "Num2"<<left<<setw(10)<< num2 <<endl;
    cout<<left<< setw(15)<< "Num1 || Num2 "<<left<<setw(10)<< (num1 || num2) <<endl;
    cout<<left<< setw(15)<< "Num1 && Num2 "<<left<<setw(10)<< (num1 && num2) <<endl;
    cout<<left<< setw(15)<< "!Num2 "<<left<<setw(10)<< (!num2) <<endl;
    cout<<left<< setw(15)<< "!Num1"<<left<<setw(10)<< (!num1) <<endl;

    
   
}

void arithmethic(float num1, float num2){
    cout<< num1 << " + "<< num2 << " = \t"; add(num1,num2);
    cout<< num1 << " - "<< num2 << " = \t"; sub(num1,num2);
    cout<< num1 << " / "<< num2 << " = \t"; div(num1,num2);
    cout<< num1 << " * "<< num2 << " = \t"; mult(num1,num2);

    cout << num1 << " % " << num2 << " = \t"; mod(num1,num2);

    // cout << "X++ "; ++ans;cout <<ans<<endl;
// cout << "X-- "; ans--;cout <<ans<<endl;
// cout << "X++" << ++ans <<endl;
// cout<<"X++ "<<ans++<<endl;

}

void add(float num1, float num2){
    cout<<num1+num2<<endl;
}
void sub(float num1, float num2){
    cout<<num1-num2<<endl;
}
void div(float num1, float num2){
    cout<<num1/num2<<endl;
}
void mult(float num1, float num2){
    cout<<num1*num2<<endl;
}
void mod(int num1, int num2){
    cout<<num1 % num2<<endl;
}


