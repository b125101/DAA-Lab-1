#include <iostream>
using namespace std;

class Distance
{
    int feet1, inches1, feet2, inches2, feet, inches;

public:
    void input()
    {
        cout << "Enter First Distance (Feet Inches): ";
        cin >> feet1 >> inches1;

        cout << "Enter Second Distance (Feet Inches): ";
        cin >> feet2 >> inches2;
    }

    void add()
    {
        feet = feet1 + feet2;
        inches = inches1 + inches2;

        if (inches >= 12)
        {
            feet++;
            inches -= 12;
        }
    }

    void display()
    {
        cout << "Total Distance = " << feet << " Feet " << inches << " Inches";
    }
};

int main()
{
    Distance d;
    d.input();
    d.add();
    d.display();
    return 0;
}