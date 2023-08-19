#include <iostream>
using namespace std;

class fruit{
    protected:
    string hatdog = "hatdog";
    private:
         string color;
    public:

     void setcolor(){
        color = "red";
    }

        string getcolor(){
        return color;
    }
};

class fruiten: public fruit{

    public:
    

    void gethatdog(){
        cout<< hatdog;
    }

};
int main(){

    fruit apple;
    fruiten banan;
    banan.gethatdog();
    cout<<endl;
    apple.setcolor();
    cout<<endl<<apple.getcolor()<<endl;
    return 0;
}