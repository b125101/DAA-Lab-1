#include <iostream>
using namespace std;

class Rectangle
{
private:
    float length, breadth;

public:
    // Function to read dimensions
    void read()
    {
        cout << "Enter Length: ";
        cin >> length;

        cout << "Enter Breadth: ";
        cin >> breadth;
    }

    // Function to calculate area
    float area()
    {
        return length * breadth;
    }

    // Function to calculate perimeter
    float perimeter()
    {
        return 2 * (length + breadth);
    }

    // Function to display results
    void display()
    {
        cout << "\n----- Rectangle Details -----" << endl;
        cout << "Length    : " << length << endl;
        cout << "Breadth   : " << breadth << endl;
        cout << "Area      : " << area() << endl;
        cout << "Perimeter : " << perimeter() << endl;
    }
};

int main()
{
    Rectangle r;

    r.read();
    r.display();

    return 0;
}