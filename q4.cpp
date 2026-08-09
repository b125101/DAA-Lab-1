#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    float balance;

public:
    // Enter account details
    void enterDetails()
    {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Account Holder Name: ";
        getline(cin, accountHolderName);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    // Deposit money
    void deposit()
    {
        float amount;
        cout << "\nEnter Amount to Deposit: ";
        cin >> amount;

        balance += amount;
        cout << "Amount Deposited Successfully." << endl;
    }

    // Withdraw money
    void withdraw()
    {
        float amount;
        cout << "\nEnter Amount to Withdraw: ";
        cin >> amount;

        if (amount <= balance)
        {
            balance -= amount;
            cout << "Amount Withdrawn Successfully." << endl;
        }
        else
        {
            cout << "Insufficient Balance." << endl;
        }
    }

    // Display updated account details
    void display()
    {
        cout << "\n----- Account Details -----" << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Balance        : " << balance << endl;
    }
};

int main()
{
    BankAccount b;

    b.enterDetails();
    b.deposit();
    b.withdraw();
    b.display();

    return 0;
}