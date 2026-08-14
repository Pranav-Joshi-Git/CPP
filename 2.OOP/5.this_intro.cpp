#include <iostream>
#include <string>

using namespace std;

class Phone {

    string _name = "";
    int _price = 0;

public:

    Phone(const string &name, int price)
        : _name(name), _price(price) {}

    string getName() const {
        return _name;
    }

    int getPrice();
};


// `this` is a pointer to the current object.
int Phone::getPrice() {

    cout << "Address from inside getPrice(): " << this << endl;

    return _price;
}


int main() {

    Phone onePlus8("One Plus 8", 799);

    // Address of the object from outside the class.
    cout << "Address of onePlus8: " << &onePlus8 << endl;

    // `getPrice()` is called using onePlus8,
    // so inside getPrice(), `this` points to onePlus8.
    cout << "Price: " << onePlus8.getPrice() << endl;


    Phone samsungA1("Samsung A1", 499);

    cout << "Address of samsungA1: " << &samsungA1 << endl;

    // Now `this` points to samsungA1 because samsungA1
    // is the object calling getPrice().
    cout << "Price: " << samsungA1.getPrice() << endl;


    return 0;
}