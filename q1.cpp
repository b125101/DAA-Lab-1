#include <iostream>
using namespace std;
class Student
{
private:
    int roll;
    float marks;
    string name;

public:
    void accept()
    {
        cout << "Enter roll number:";
        cin >> roll;
        cin.ignore();
        cout << "Enter name :";
        getline(cin, name);
        cout << "Enter marks in one subject:";
        cin >> marks;
    }
    void display()
    {
        cout << "\n --Enter Student Details --" << endl;
        cout << "Roll :  " << roll << endl;
        cout << "Name :  " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main()
{
    Student s1;
    s1.accept();
    s1.display();
    return 0;
}