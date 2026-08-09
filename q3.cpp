#include <iostream>
using namespace std;

class Calculator
{
private:
    float num1, num2;

public:
    // Accept two numbers
    void read()
    {
        cout << "Enter First Number: ";
        cin >> num1;

        cout << "Enter Second Number: ";
        cin >> num2;
    }

    // Addition
    void add()
    {
        cout << "Addition = " << num1 + num2 << endl;
    }

    // Subtraction
    void subtract()
    {
        cout << "Subtraction = " << num1 - num2 << endl;
    }

    // Multiplication
    void multiply()
    {
        cout << "Multiplication = " << num1 * num2 << endl;
    }

    // Division
    void divide()
    {
        if (num2 != 0)
            cout << "Division = " << num1 / num2 << endl;
        else
            cout << "Division by zero is not possible." << endl;
    }
};

int main()
{
    Calculator c;

    c.read();
    c.add();
    c.subtract();
    c.multiply();
    c.divide();

    return 0;
}