#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

void basciMultTable(){
     cout<<"\t\t Mult Table"<<endl;
    for(int i = 1; i <= 10; i++){
        cout << string(15,'-')<<endl;
        cout<< "Table: " << i <<endl;
        for(int j=1; j <= 10; j++){            
            cout<< i << " x " << j << " = " << (i*j) << endl;
        }
    }
}

void advancedMultTable(){
    int startTable,endTable, startMultiplier, endMultiplier;
    cout<<"\t\t Advanced Mult Table"<<endl;
    cout<< "Input starting number: ";
    cin >> startTable;
    cout<< "Input last number: ";
    cin >> endTable;
    cout << "Input starting multiplier: ";
    cin >> startMultiplier;
    cout << "Input last multiplier: ";
    cin>> endMultiplier;
    cin.ignore();
    for( int i = startTable; i <= endTable; i++){
         cout<<string(10,'-')<<endl;
            cout<< "Table: " << i <<endl;
        for (int j = startMultiplier; j<=endMultiplier; j++){
           
            cout<< i << " x " << j << " = " << (i*j) << endl;

        }
    }
}

void reverseCase(){
    string sentence;
    cout << "\t\t Reverse Case: "<<endl;
    cout<<"Enter a sentece: ";
    getline(cin,sentence);
    // cin.ignore();

    for(int i = 0; i <= sentence.size(); i++){
        if((sentence[i]>64)&&(sentence[i]< 91)){
            sentence[i] += 32;
        }
        else if((sentence[i]>96)&&(sentence[i]<123)){
            sentence[i] -=32;
        }
        else{
            cout<<sentence[i];
        }
    }
    cout<< "Output: "<<endl;
    cout << sentence << endl;
    // cin.ignore();

}

void reverseSequence(){
    vector<char> reverse;
    string sentence;
    cout<< "\t\t Reverse Sequence"<<endl;
    cout << "Enter a Sentence: ";
    getline(cin,sentence);
    // cin.ignore();
    for(int i = 0; sentence[i] != '\0';i++){

        reverse.push_back(sentence[i]);

    }
    cout << "Output: "<<endl;
    for(int j = reverse.size()-1; j >= 0 ; j--){
        cout << reverse.at(j);
    }
    cout << "\n";

}

void basicCalculator(){
    int firstOperand, secondOperand, choice;
    cout<< "Enter first Operand: ";
    cin >> firstOperand; 
    cout<< "Enter Second Operand: ";
    cin >> secondOperand;
    cout << "(1) Add \n(2) Sub \n(3) Mult \n(4)Div "<<endl;
    cout << "Select operation: ";
    cin >> choice;
    cin.ignore();
        switch (choice)
        {
        case 1:
            cout <<firstOperand + secondOperand;            
            break;
        case 2:
            cout <<  firstOperand - secondOperand;            
            break;
        case 3:
           cout << firstOperand * secondOperand;            
            break;
        case 4:
            cout <<  firstOperand / secondOperand;           
            break;
        default:
            cout<<"Invalid input..."<<endl;
        }

    
}
void advancedCalculator(){
    int choice, 
        firstOperand = 0,
        secondOperand = 0,
        answer = 0;

    cout<< "\t Advanced Calculator " << endl;
    cout<< "Enter first Operand: ";
    cin >> firstOperand;
    do{    
    cout<< "Enter Second Operand: ";
    cin >> secondOperand;
    cout << "(1) Add \n(2) Sub \n(3) Mult \n(4)Div "<<endl;
    cout << "Select operation: ";
    cin >> choice;
        switch (choice)
        {
        case 1:
            answer = firstOperand + secondOperand;
            cout << answer << endl;
            firstOperand = answer;
            break;
        case 2:
            answer = firstOperand - secondOperand;
            cout << answer << endl;
            firstOperand = answer;
            break;
        case 3:
            answer = firstOperand * secondOperand;
            cout << answer << endl;
            firstOperand = answer;
            break;
        case 4:
            answer = firstOperand / secondOperand;
            cout << answer << endl;
            firstOperand = answer;
            break;
        
        default:
            break;
        } 
    }while(true);

}


void I(){
    cout << "I ";
}
void WILL(){
    cout << "WILL ";
}
void PASS(){
    cout << "PASS" <<endl;
}
void SUCCEED(){
    cout <<"SUCCEED\n"<<endl;
}

void wordPrinting(){
    I(),WILL(),PASS();
    I(),WILL(),SUCCEED();
    
}
void basicRandomizer(){
    while(cin.get() == '\n'){
        cout << ((rand() % 50)+1);

    }
}

void advancedRandomizer(){
    int start, end;
    cout<< "Input Starting range: ";
    cin >> start;
    cout<< "Input End range: ";
    cin >> end;
    while(cin.get() == '\n'){
        
        cout << ((rand() % end) + start);

    }
}

void loanCalculator(){
   float loan,yearlyRate,month,principal,interest,payment,cumPay; 
    cout<<"=============Simple interest rate============="<<endl;
    cout<<"How much to borrow: ";cin>>loan;
    cout<<"Rate(% per year): ";cin>>yearlyRate;
    cout<<"How many months: ";cin>>month;
    cin.ignore();
    principal = loan/month;
    interest =((principal*yearlyRate/100)/12)*month;
    payment = principal+interest;

     cout<< left << setw(10) << "Month" 
     << left << setw(14) << "Principal" 
     << left << setw(14) << "Interest"
     << left << setw(14)<< "Payment" 
     << left <<setw(20) << "Cummulative Payment"<<endl;


    for(int i=1; i<=month;i++){
        cumPay +=payment;
        cout<< left << setw(10) << i 
        << left << setw(14) << principal 
        << left << setw(14) << interest 
        << left << setw(14)<< payment 
        << left << setw(20) << cumPay<<endl;      


    }
    cout<<"=============End of Loan============="<<endl;


   
}
void simpLoanCalc()
{
    float toBorrow,interestRate,numberOfMonths;

    cout << "===========Simple interest rate===========\n";
    cout << "How much to borrow: ";cin >> toBorrow;
    cout << "Rate (" << char(37) << " per year): "; cin>>interestRate;
    cout << "How many months: "; cin >> numberOfMonths;
    cin.ignore();
    cout << "Month"<< setw(20)  << "Principal" << setw(20)  << "Interest" << setw(20) << "Payment" << setw(20) << "Cumulative Payment\n";

    float interest = interestRate/100;
    float principal = toBorrow/numberOfMonths;
    float timeInYears = numberOfMonths/12;
    float simpleInterest = (principal*interest*timeInYears);
    float cumulativePayment;
    
    for(int i = 1 ; i<=numberOfMonths;i++)
    {
        cout << i << setw(20) << principal << setw(20) << simpleInterest << setw(20) << (principal+simpleInterest) << setw(20) << (cumulativePayment+=(principal+simpleInterest)) << endl;
    }

    cout << "=============END OF LOAN=============\n";
}

void structure(){
    typedef struct
    {
        int ISBN;
        string title;
        string subject;
        string author;
        int year;
        bool availability;

    } books;
    
    books book1 = 
    {12345,
    "The courage to be disliked",
    "Self-help",
    "Ichiro Kishimi",
    2010,
    true};
    // book1.ISBN = 12345;
    // book1.title = "The courage to be disliked";
    // book1.subject = "Self-help";
    // book1.author = "Ichiro Kishimi";
    // book1.year = 2010;
    // book1.availability = true;
    cout << "ISBN: " << book1.ISBN <<endl;
    cout << "Title: " <<  book1.title<< endl;
    cout << "Subject: " << book1.subject << endl;
    cout << "Author: " << book1.author << endl;
    cout << "Year: " << book1.year <<endl;
    cout << "Available?: " << (book1.availability ? "Yes" : "No")<<endl;


}




int main(){
    int choice;    
    cout << "=====Midterms====="<<endl;
    cout << "(1) Basic Multiplication Table " << endl;
    cout << "(2) Advanced Multiplication Table "<<endl;
    cout << "(3) Reverse Case Words" << endl;
    cout << "(4) Reverse Sequence Words" << endl;
    cout << "(5) Basice Calculator " << endl;
    cout << "(6) Advanced Calculator "<<endl;
    cout << "(7) Word Printing Functions "<<endl;
    cout << "(6) Basic Randomizer "<<endl;
    cout << "(9) Advanced Randomizer "<< endl;
    cout << "(10) Simple Intereset Loan Calculator "<<endl;
    cout << "(11) Struct" << endl;
    cout << "Select number: " ; 
    cin >> choice;
    cin.ignore();


    switch (choice)
    {
    case 1:
        basciMultTable();
        break;
    case 2:
        advancedMultTable();
        break;
    case 3:
        reverseCase();
        break;
    case 4:
        reverseSequence();
        break;
    case 5:
        basicCalculator();
        break;
    case 6:
        advancedCalculator();
        break;
    case 7:
        wordPrinting();
        break;
    case 8:
        basicRandomizer();
        break;
    case 9:
        advancedRandomizer();
        break;
    case 10:
        loanCalculator();
        simpLoanCalc();
        break;
    case 11:
        structure();
        break;

    default:
        cout << "Invalid Input please try again... ";
        cin.clear();
    }
   
   cout << "\nPress any key to continue...";cin.get();
   system("clear");
   return main();

}