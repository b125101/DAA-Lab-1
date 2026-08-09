#include <iostream>
using namespace std;

class Employee
{
    int id;
    string name;
    float basic, hra, da, gross;

public:
    void input()
    {
        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Basic Salary: ";
        cin >> basic;
    }

    void calculate()
    {
        hra = 0.20 * basic;
        da = 0.10 * basic;
        gross = basic + hra + da;
    }

    void display()
    {
        cout << "\nEmployee ID: " << id;
        cout << "\nEmployee Name: " << name;
        cout << "\nBasic Salary: " << basic;
        cout << "\nHRA: " << hra;
        cout << "\nDA: " << da;
        cout << "\nGross Salary: " << gross << endl;
    }
};

int main()
{
    Employee e;
    e.input();
    e.calculate();
    e.display();
    return 0;
}