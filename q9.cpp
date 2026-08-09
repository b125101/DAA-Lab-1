#include <iostream>
using namespace std;

class StudentResult
{
    string name;
    int roll, marks[5], total;
    float percentage;
    char grade;

public:
    void input()
    {
        cout << "Enter Roll Number: ";
        cin >> roll;
        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);

        total = 0;

        cout << "Enter Marks of 5 Subjects:\n";
        for (int i = 0; i < 5; i++)
        {
            cin >> marks[i];
            total += marks[i];
        }
    }

    void calculate()
    {
        percentage = (float)total / 500 * 100;

        if (percentage >= 90)
            grade = 'A';
        else if (percentage >= 80)
            grade = 'B';
        else if (percentage >= 70)
            grade = 'C';
        else if (percentage >= 60)
            grade = 'D';
        else
            grade = 'F';
    }

    void display()
    {
        cout << "\nRoll Number: " << roll;
        cout << "\nStudent Name: " << name;
        cout << "\nTotal Marks: " << total;
        cout << "\nPercentage: " << percentage;
        cout << "\nGrade: " << grade << endl;
    }
};

int main()
{
    StudentResult s;
    s.input();
    s.calculate();
    s.display();
    return 0;
}