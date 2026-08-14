#include <iostream>

using namespace std;

class Rectangle {

    double _length;
    double _breadth;

public:

    // Constructor with default parameter values.
    // If no values are provided, length = 2.0 and breadth = 1.5.
    Rectangle(double l = 2.0, double b = 1.5) {
        _length = l;
        _breadth = b;
    }


    double area() {
        return _length * _breadth;
    }


    bool compare(Rectangle rectangle) {

        // `this` points to the object that called the method.
        // Here, if rect1.compare(rect2) is called:
        // this → rect1
        // rectangle → rect2
        //
        // So this->area() means "call area() of rect1".
        return this->area() > rectangle.area();
    }
};


int main() {

    Rectangle rect1(3.0, 2.0);
    Rectangle rect2(4.0, 3.0);

    cout << rect1.compare(rect2) << endl;


    if (rect1.compare(rect2)) {
        cout << "rect1 is bigger" << endl;
    } else {
        cout << "rect2 is bigger" << endl;
    }


    return 0;
}