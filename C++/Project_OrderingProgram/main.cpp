#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <array>
#include <chrono>
#include <thread>

using namespace std;

const string usrName = "admin";
const string usrPass = "admin";
bool added = false;
int run();

void logIn()
{
    string ans_usrName;
    string ans_usrPass;
    system("clear");
    cout << "======Log In======\n";

    cout << "Enter User Name: ";
    cin >> ans_usrName;
    cout << "Enter User Password: ";
    cin >> ans_usrPass;
    if (usrPass == ans_usrPass && usrName == ans_usrName)
    {
        cout << "Logging In...\n";
        this_thread::sleep_for(chrono::milliseconds(1300));
        cout << "Login successful. Welcome, cashier!\n";
        this_thread::sleep_for(chrono::milliseconds(800));
    }
    else
    {
        cout << "Invalid username or password. Please try again..\n";
        return logIn();
    }
}

class MenuItem
{
private:
    string foodName;
    double foodPrice;
    int foodQty;
    int subtotal;

public:
    MenuItem(string fname, int fprice)
    {
        this->foodName = fname;
        this->foodPrice = fprice;
    }
    MenuItem()
    {
    }

    void set_foodQty(int quantity)
    {
        this->foodQty = quantity;
    }
    string get_foodName()
    {
        return foodName;
    }

    double get_foodPrice()
    {
        return foodPrice;
    }

    int get_foodQty()
    {
        return foodQty;
    }

    int get_subtotal()
    {
        subtotal = foodQty * foodPrice;
        return subtotal;
    }
};

class Menu
{
private:
    array<MenuItem, 6> Orders;
    vector<MenuItem> selectedItem;
    int selectedItemCount = 0;
    float grandTotal = 0;
    float payment;

public:
    Menu()
    {
        Orders[0] = MenuItem("Burger", 49.00);
        Orders[1] = MenuItem("Burger Pro", 69.00);
        Orders[2] = MenuItem("Burger Pro Max", 89.00);
        Orders[3] = MenuItem("Water", 10.00);
        Orders[4] = MenuItem("Water Pro", 20.00);
        Orders[5] = MenuItem("Water Pro Max", 49.00);
    }

    void showMenu()
    {
        cout << setw(20) << left << "Food/Drink " << setw(15) << left << "Price" << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << setw(20) << left << "(" + to_string(i + 1) + ")" + Orders[i].get_foodName() << setw(15) << left << Orders[i].get_foodPrice() << endl;
        }
    }

    void InputQuantity(int num)
    {
        int qty;
        cout << "Input Quantity: ";
        cin >> qty;

        // if(isdigit(qty) == false){
        //     cin.clear();
        //     cin.ignore();
        //     InputQuantity(num);
        // }

        Orders[num].set_foodQty(qty);
    }
    void SetNewQty(int index)
    {
        int qty;
        cout << "Input new Quantity: ";
        cin >> qty;
        selectedItem.at(index).set_foodQty(qty);
    }

    void ItemCheck(int index)
    {

        if (selectedItem.empty())
        {
            return;
        }

        for (int i = 0; i < selectedItem.size(); i++)
        {
            if (selectedItem.at(i).get_foodName() == Orders[index].get_foodName())
            {
                added = true;
                char choice;
                cout << "Item already added, Would you like to change quantity? (y/n) " << endl;
                cin >> choice;
                switch (choice)
                {
                case 'y':

                    grandTotal -= selectedItem.at(i).get_subtotal();
                    SetNewQty(i);
                    break;
                case 'n':
                    break;
                default:
                    cout << "Invalid input please try again..." << endl;
                }
            }
        }
    }

    void addItem()
    {
        int choice;

        cout << "Select the food number: ";
        cin >> choice;
        if (isdigit(choice) == false)
        {
            cin.clear();
        }

        switch (choice)
        {
        case 1:
            ItemCheck(0);
            if (added == false)
            {
                InputQuantity(0);
                selectedItem.push_back(Orders[0]);
                selectedItemCount++;
            }
            break;
        case 2:
            ItemCheck(1);
            if (added == false)
            {
                InputQuantity(1);
                selectedItem.push_back(Orders[1]);
                selectedItemCount++;
            }
            break;
        case 3:
            ItemCheck(2);
            if (added == false)
            {
                InputQuantity(2);
                selectedItem.push_back(Orders[2]);
                selectedItemCount++;
            }
            break;
        case 4:
            ItemCheck(3);
            if (added == false)
            {
                InputQuantity(3);
                selectedItem.push_back(Orders[3]);
                selectedItemCount++;
            }
            break;
        case 5:
            ItemCheck(4);
            if (added == false)
            {
                InputQuantity(4);
                selectedItem.push_back(Orders[4]);
                selectedItemCount++;
            }
            break;
        case 6:
            ItemCheck(5);
            if (added == false)
            {
                InputQuantity(5);
                selectedItem.push_back(Orders[5]);
                selectedItemCount++;
            }
            break;
        default:
            cout << "Invalid Input...." << endl;
        }
    }
    void displaySelectedItems()
    {

        cout << setw(20) << left << "Food/Drink "
             << setw(15) << left << "Price"
             << setw(15) << left << "Qty."
             << setw(15) << left << "Subtotal" << endl;
        grandTotal = 0;

        for (int i = 0; i < selectedItem.size(); i++)
        {

            cout << setw(20) << left << "(" + to_string(i + 1) + ")" + selectedItem.at(i).get_foodName()
                 << setw(15) << left << selectedItem.at(i).get_foodPrice()
                 << setw(15) << left << selectedItem.at(i).get_foodQty()
                 << setw(15) << left << selectedItem.at(i).get_subtotal() << endl;

            // cout << selectedItem.at(i).get_foodName();
            grandTotal += selectedItem.at(i).get_subtotal();
        }

        cout << string(50, '-') << endl;
        cout << setw(50) << right << "Total: " << grandTotal << endl;
    }

    void removeItem()
    {
        displaySelectedItems();
        int choice;
        if (selectedItem.empty() == false)
        {
            cout << "Select which Item to remove: ";
            cin >> choice;
            selectedItem.erase(selectedItem.begin() + (choice - 1));
        }
        else
        {
            cout << "Order list is empty cannot remove anymore...\n";
        }
        return;
    }

    void confirmOrder()
    {
        char ans;
        int choice;
        cout << "Confirm order? (y/n): ";
        cin >> ans;

        if (isdigit(ans) == true)
        {
            cout << "Invalid Input\n";
            displaySelectedItems();
            confirmOrder();
        }

        switch (ans)
        {
        case 'y':
            payOrder();
            printReceipt();
            break;
        case 'n':
            cout << "(1) Remove item" << endl;
            cout << "(2) Add/Edit item" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
                removeOrderProccess();
                displaySelectedItems();
                confirmOrder();
                break;
            case 2:
                orderingProccess();
                displaySelectedItems();
                confirmOrder();
                break;

            default:
                break;
            }

        default:
            break;
        }
    }

    void payOrder()
    {

        cout << string(10, '=') << " Payment " << string(10, '=') << endl;
        cout << "Enter amount: ";
        cin >> payment;

        if (payment >= grandTotal)
        {
            float change = payment - grandTotal;
            cout << setw(10) << left << "To pay: " << setw(20) << left << grandTotal << endl;
            cout << setw(10) << left << "Cash: " << setw(20) << left << payment << endl;
            cout << setw(10) << left << "Change: " << setw(20) << left << change << endl;
        }
        else
        {
            cout << "Insufficient funds" << endl;
            return payOrder();
        }
        cout << "Payment success..." << endl;
    }
    void printReceipt()
    {

        ofstream receipt;

        receipt.open("Receipt.docx", ios::out | ios::trunc);

        receipt << setw(40) << right << "Pagkaon Receipt" << endl;
        receipt << setw(41) << right << "Address:Kuan city" << endl;
        receipt << setw(42) << right << "Contact: 0912334512" << endl;
        receipt << string(65, '-') << endl;
        receipt << setw(20) << left << "Food/Drink "
                << setw(15) << left << "Price"
                << setw(15) << left << "Qty."
                << setw(15) << left << "Subtotal" << endl;

        for (int i = 0; i < selectedItem.size(); i++)
        {

            receipt << setw(20) << left << "(" + to_string(i + 1) + ")" + selectedItem.at(i).get_foodName()
                    << setw(15) << left << selectedItem.at(i).get_foodPrice()
                    << setw(15) << left << selectedItem.at(i).get_foodQty()
                    << setw(15) << left << selectedItem.at(i).get_subtotal() << endl;
        }
        receipt << string(65, '-') << endl;
        receipt << setw(60) << right << "Total: " << grandTotal << endl;
        receipt << setw(60) << right << "Payment: " << payment << endl;
        receipt << setw(60) << right << "Change: " << payment - grandTotal;
    }

    void clearSelectedItems()
    {
        selectedItem.clear();
    }

    void orderingProccess()
    {
        char choice;
        do
        {
            cout << "===== Pagkaon Restaurant =====" << endl;
            showMenu();
            cout << string(30, '=') << endl;
            cout << "Select the item again to change quantity.\n";
            cout << string(30, '=') << endl;
            displaySelectedItems();
            addItem();
            cout << "Add another food? (y/n): ";
            cin >> choice;
            added = false;
            system("clear");
        } while (choice != 'n');
    }
    void removeOrderProccess()
    {
        char choice;
        do
        {
            removeItem();
            cout << "Remove another food? (y/n)";
            cin >> choice;
            system("clear");
        } while (choice != 'n');
    }
};

int run()
{
    Menu menu;

    system("clear");

    menu.orderingProccess();
    menu.displaySelectedItems();
    menu.confirmOrder();
    cin.ignore();

    cin.clear();
    cout << "Press Enter to order again....";
    cin.get();
    menu.clearSelectedItems();
    system("clear");
    return run();
}

int main()
{
    logIn();
    run();
}
