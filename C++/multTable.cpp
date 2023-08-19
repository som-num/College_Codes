#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void mult();
void loanCalcu();
void dimRateCalcu();

int main(){
    char ans;
    
    do{
        cout<<"Select an option: "<<endl;
        cout<<"1) Multiplication Table"<<endl;
        cout<<"2) Simple Loan Calculator"<<endl;
        cout<<"3) Diminishing Rate Calculator"<<endl;
        cout<<"4) Exit"<<endl;
        cout<<"Selected: "; cin>>ans;

        switch (ans)
        {
        case '1':
            mult();
            break;
        case '2':
            loanCalcu();
            break;
        
        case '3':
            dimRateCalcu();
            break;
        
        default:
            system("pokemon-colorscripts -r");
            break;
        
        }
    } while(ans != '4' );

    
    
   
}

void mult(){
     int startRange,endRange,startMult,endMult;

    cout<<"====== Multiplication Table ======"<<endl;
    cout <<"Enter start range: "; cin>>startRange; 
    cout<<"Enter end range: ";cin>>endRange;
    cout<<"Enter starting multiplier: ";cin>>startMult;
    cout<<"Enter ending multiplier: ";cin>>endMult;

    for(int start = startRange; start<=endRange; start++){
        cout<<"================="<<endl;
        cout<<"Table "<<start<<endl;
        for(int i=startMult;i<=endMult;i++){
            cout<<start<<" x "<< i << " = " << start*i<<endl;
        }
    }
    cout<<"==============="<<endl;

}


void loanCalcu(){
   float loan,yearlyRate,month,principal,interest,payment,cumPay; 
    cout<<"=============Simple interest rate============="<<endl;
    cout<<"How much to borrow: ";cin>>loan;
    cout<<"Rate(% per year): ";cin>>yearlyRate;
    cout<<"How many months: ";cin>>month;
    cout<< left << setw(10) << "Month" << left << setw(14) << "Principal" << left << setw(14) << "Interest"<< left << setw(14)<< "Payment" << left <<setw(20) << "Cummulative Payment"<<endl;

    principal = loan/month;
    interest =((principal*yearlyRate/100)/12)*month;
    payment = principal+interest;



    for(int i=1; i<=month;i++){
        cumPay +=payment;
        cout<< left << setw(10) << i << left << setw(14) << principal << left << setw(14) << interest << left << setw(14)<< payment << left << setw(20) << cumPay<<endl;      


    }
    cout<<"=============End of Loan============="<<endl;
}


void dimRateCalcu(){
    float loan,yearlyRate,month,Principal,interest,outPrincipal; 
    float inter;
    cout<<"=============Diminishing Rate Calculator============="<<endl;
    cout<<"How much to borrow: ";cin>>loan;
    cout<<"Rate(% per year): ";cin>>yearlyRate;
    cout<<"How many months: ";cin>>month;

    cout<< left << setw(10) << "Month" << left << setw(26) << "Outstanding Principal" << left << setw(18) << "Principal Paid"<< left << setw(14)<< "Interest" << left <<setw(14) << "Payment"<<endl;

    Principal = loan/month;
    outPrincipal = loan;
    // inter = 0.0;



    for(int i=1; i<=month;i++){
        float principal,interest,pay;
        principal = outPrincipal/month;
        interest =((principal*yearlyRate/100)/12)*month;
        pay = Principal+interest;

        cout<< left << setw(10) << i << left << setw(26) << outPrincipal << left << setw(18) << Principal << left << setw(14)<< interest << left <<setw(14) << pay <<endl;

        outPrincipal -= Principal;
        inter+=interest;



    }
    cout<<"=============End of Loan============="<<endl;
    cout<<"Total interest= "<<inter<<endl<<endl;

}

