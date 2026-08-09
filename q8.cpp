#include <iostream>
using namespace std;

class LibraryBook
{
    int id, days;
    string title, student;
    float fine;

public:
    void input()
    {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Student Name: ";
        getline(cin, student);

        cout << "Enter Number of Days Issued: ";
        cin >> days;
    }

    void calculateFine()
    {
        if (days > 15)
            fine = (days - 15) * 2;
        else
            fine = 0;
    }

    void display()
    {
        cout << "\nBook ID: " << id;
        cout << "\nBook Title: " << title;
        cout << "\nStudent Name: " << student;
        cout << "\nDays Issued: " << days;
        cout << "\nFine: " << fine << endl;
    }
};

int main()
{
    LibraryBook b;
    b.input();
    b.calculateFine();
    b.display();
    return 0;
}