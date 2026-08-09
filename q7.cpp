#include <iostream>
using namespace std;

class Product
{
    int id, quantity, sold;
    string name;
    float price;

public:
    void input()
    {
        cout << "Enter Product ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Product Name: ";
        getline(cin, name);

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Price: ";
        cin >> price;
    }

    void sell()
    {
        cout << "Enter Quantity Sold: ";
        cin >> sold;

        if (sold <= quantity)
            quantity -= sold;
        else
            cout << "Insufficient Stock" << endl;
    }

    void display()
    {
        cout << "\nProduct ID: " << id;
        cout << "\nProduct Name: " << name;
        cout << "\nAvailable Quantity: " << quantity;
        cout << "\nInventory Value: " << quantity * price << endl;
    }
};

int main()
{
    Product p;
    p.input();
    p.sell();
    p.display();
    return 0;
}